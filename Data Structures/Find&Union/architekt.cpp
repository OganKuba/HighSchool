#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> rep;
vector<int> ile;
vector<int> val;
vector<bool> tab;
void Union(int a,int b, int war, int r1 , int r2){
	if(ile[a]>ile[b]){
		war=-war;
		swap(a, b);
		swap(r1 , r2);
	}
	rep[a]=b;
	val[a]+=war+r1-r2;
	ile[b]+=ile[a];
}
int wyn1=0;
int Find(int a){
	int old=0;
	if(rep[a]!=a){
		rep[a]=Find(rep[a]);
		old=val[a];
		val[a]+=wyn1;
		//cout<<"new_val: "<<val[a]<<" tego: "<<a<<" rep a: "<<rep[a]<<endl;
		//cout<<"wyn1: "<<wyn1<<endl;
	}
	wyn1=wyn1+old;
	//cout<<"wyn1: "<<wyn1<<"   "<<a<<endl;
	return rep[a];
}
int wyn=0;
int check(int a){
	if(rep[a]!=a)wyn+=check(rep[a]);
	return wyn+val[a];
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n , z, a1, b1, c1;
	cin>>n>>z;
	for(int i=0 ; i<=n ; i++){
		ile.push_back(1);
		rep.push_back(i);
		val.push_back(0);
	}
	int p1 , p2 , v1 , v2 , k1 , k2;
	for(int i=0 ; i<z ; i++){
		cin>>a1>>b1>>c1;
		wyn1=0;
		p1=Find(a1);
		wyn1=0;
		p2=Find(b1);
		//cout<<"porownujemy: "<<a1<<" i "<<b1<<endl;
		//if(i==9){
		//	for(int j=1 ; j<=n ; j++)cout<<j<<": "<<val[j]<<" reprezentant: "<<rep[j]<<endl;
		//}
		if(p1==p2){
			wyn=0;
			v1=check(a1);
			wyn=0;
			v2=check(b1);
			//cout<<v1<<" wartosc wzgledem: "<<p1<<"  ||  "<<v2<<" wartosc wzgledem: "<<p2<<endl;
			if(v1==v2+c1)cout<<"TAK"<<endl;
			else cout<<"NIE"<<endl;
			//cout<<check(a1)<<" "<<check(b1)<<endl;
			
		}
		else{
			wyn=0;
			k1=check(a1);
			wyn=0;
			k2=check(b1);
			//cout<<k1<<" wartosc wzgledem: "<<p1<<"  ||  "<<k2<<" wartosc wzgledem: "<<p2<<endl;
			 Union(p1 , p2, c1, k2, k1);
			 cout<<"TAK"<<endl;
		}
		//if(i==8){
		//	for(int j=1 ; j<=n ; j++)cout<<j<<": "<<val[j]<<" reprezentant: "<<rep[j]<<endl;
		//}
		//for(int i=1 ; i<=n ; i++)cout<<i<<"rep: "<<rep[i]<<"val: "<<val[i]<<endl;
		//cout<<endl;
	}
}