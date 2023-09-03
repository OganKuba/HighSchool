#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
struct point{
	long long x , y;
};
bool check(point p1 , point p2 , point p3){
	p2.x-=p1.x;
	p3.x-=p1.x;
	p2.y-=p1.y;
	p3.y-=p1.y;
	long long pole=(p3.x*p2.y)-(p3.y*p2.x);
	//cout<<"pole: "<<pole<<endl;
	if(pole==0 && abs(p2.x)+abs(p2.y)>abs(p3.x)+abs(p3.y)){
		return false;
	}
	if(pole<0){
		return false;
	}
	return true;
}
bool go(){
	vector<point> tab;
	int n, a, b;
	cin>>n;
	int u=0;
	for(int i=0 ; i<n ; i++){
		cin>>a>>b;
		tab.push_back({a , b});
		if(tab.size()>=3){
			if(check(tab[i-2] , tab[i-1] , tab[i])==false){
				u=1;
			}
		}
		//cout<<"size: "<<tab.size();
	}
	if(u==0)return true;
	else return false;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	for(int i=0 ; i<t ; i++){
		bool ans=go();
		if(ans==true){
			cout<<"TAK"<<endl;
		}
		else{
			cout<<"NIE"<<endl;
		}
	}
}