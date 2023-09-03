#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int a , b, c , q, k;
int F[1001];
int bylo[100001];
int tab[1001];
void put(int l , int x ){
	int xd;
	for(int i=0 ; i<=l-x ; i++){
		xd=(int)(F[i]^(F[l-x-i]));
		bylo[xd]=l;
	}
}
void count(int m){
	if(m>=a)put(m , a);
	if(m>=b)put(m , b);
	if(m>=c)put(m , c);
	while(bylo[F[m]]==m)F[m]++;
}
int main(){
	cin>>a>>b>>c>>q;
	int maxi=0;
	for(int i=0 ; i<q ; i++){
		cin>>tab[i];
		maxi=max(maxi , tab[i]);
	}
	F[0]=0;
	for(int i=1 ; i<=maxi ; i++){
		count(i);
	}
	for(int i=0 ; i<q ; i++){
		if(F[tab[i]]==0){
			cout<<2<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
}