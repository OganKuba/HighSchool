#include <bits/stdc++.h>
#pragma GCC optimize("fast")
using namespace std;
#define endl '\n'
struct point{
	int x, y;
};
vector<point> tab;
long long suma=0;
bool compx(point x1 , point x2){
	return x1.x<x2.x;
}
bool compy(point x1 , point x2){
	return x1.y>x2.y;
}
void emplace_left(point p , vector<point> &L){
	while(not L.empty() && L.back().x<p.x)L.pop_back();
	L.emplace_back(p);
}
void emplace_right(point p, vector<point> &R){
	while(not R.empty() && R.back().x>p.x)R.pop_back();
	R.emplace_back(p);
}
int bin(int k , vector<point> &B){
	int l1 , r1;
	int sr1;
	l1=0 , r1=(int)B.size()-1;
	//cout<<"bin: "<<k<<" "<<B.size()<<endl;
	while(l1<=r1){
		sr1=(l1+r1)/2;
		if(B[sr1].y<k){
			if(sr1==0)return sr1;
			if(B[sr1-1].y>k)return sr1;
			r1=sr1-1;
		}
		else l1=sr1+1;
	}
	return -1;
}
void count1(vector<point> &P1 , vector<point> &P2){
	int j=0;
	int roz;
	vector<point> L;
	vector<point> R;
	for(int i=0 ; i<(int)P1.size() ; i++){
		emplace_left(P1[i] , L);
		while(P2[j].y>P1[i].y && j<(int)P2.size()){
			emplace_right(P2[j], R);
			j++;
		}
		if((int)L.size()==1)roz=bin(10000001 , R);
		else roz=bin(L[(int)L.size()-2].y , R);
		//cout<<"roz: "<<roz<<endl;
		if(roz!=-1)suma=suma+((int)R.size()-roz);
	}
}
void count2(vector<point> &P1 , vector<point> &P2){
	int j=0;
	int roz;
	vector<point> L;
	vector<point> R;
	for(int i=0 ; i<(int)P2.size() ; i++){
		emplace_right(P2[i] , R);
		while(P1[j].y>P2[i].y && j<(int)P1.size()){
			emplace_left(P1[j] , L);
			j++;
		}
		if((int)R.size()==1)roz=bin(10000001 , L);
		else roz=bin(R[(int)R.size()-2].y , L);
		if(roz!=-1)suma=suma+((int)L.size()-roz);
	}
}
void count(int p1 , int p2){
	int sr=(p1+p2)/2;
	vector<point> P1;
	vector<point> P2;
	for(int i=p1 ; i<=sr ; i++)P1.push_back(tab[i]);
	for(int i=sr+1 ; i<=p2 ; i++)P2.push_back(tab[i]);
	sort(P1.begin() , P1.end() , compy);
	sort(P2.begin() , P2.end() , compy);
	count1(P1 , P2);
	count2(P1 , P2);
	if(p1!=sr)count(p1 , sr);
	if(sr+1!=p2)count(sr+1 , p2);
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int c, e , n;
	point put;
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>c>>e;
		put={c , e};
		tab.push_back(put);
	}
	sort(tab.begin() , tab.end() , compx);
	//cerr<<endl;
	count(0 , (int)tab.size()-1);
	cout<<suma;
}