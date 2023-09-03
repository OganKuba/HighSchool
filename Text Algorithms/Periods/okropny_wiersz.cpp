#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> simp;
string text;
int n , q, a, b , p;
int mod=int(1e9)+7;
vector<int> prefix;
vector<int> potegi;
vector<int> najm;
int dodaj(int x , int y){
	return (x+y)%mod;
}
int mnoz(int x, int y){
	return int(x*(long long)(y)%mod);
}
int hasz(int l , int r){
	if(l==0)return prefix[r];
	else return (((prefix[r]-(mnoz(prefix[l-1] , potegi[r-l+1])))+mod)%mod);
	return 0;
}
bool presuf(int q1 , int q2 , int l){
	//cout<<"L "<<l<<endl;
	if(hasz(q1 ,q1+l-1)==hasz(q2-l+1 , q2))return true;
	else return false;
	return false;
}
int ans(int l1 , int p1){
	int roz=p1-l1+1;
	int need=1;
	int pot=1;
	//if(presuf(l1 , l1+roz-1 , roz-1)==true)return 1;
	int d1;
	while(need!=roz && najm[roz/need]!=1){
		d1=najm[roz/need];
		if(presuf(l1 , l1+roz-1 , roz-(roz/d1))==true)roz=roz/d1;
		else{
			pot=1;
			while((roz/need)%pot==0){
				pot=pot*d1;
			}
			pot/=d1;
			need=need*pot;
		}
	}
	return roz;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	cin>>text;
	//vector<bool> tab;
	//for(int i=0 ; i<=n ; i++)tab.push_back(false);
	for(int i=0 ; i<=n ; i++)najm.push_back(i);
	for(int i=2 ; i<=sqrt(n) ; i++){
		for(int j=2*i ; j<=n ; j+=i){
			//tab[j]=true;
			if(najm[i]==i)najm[j]=min(najm[j] , i);
		}
	}
	//for(int i=2 ; i<=n ; i++)if(tab[i]==false)simp.push_back(i);
	//for(int i=0 ; i<najm.size() ; i++)cout<<najm[i]<<" ";
	//cout<<endl;
	prefix.push_back(text[0]-'a'+1);
	cin>>q;
	p='z'-'a'+1;
	potegi.push_back(1);
	for(int i=1 ; i<=(int)text.size() ; i++)potegi.push_back(mnoz(potegi[i-1] , p));
	for(int i=1 ; i<(int)text.size() ; i++)prefix.push_back(dodaj(mnoz(prefix[i-1] , p) , text[i]-'a'+1));
	for(int i=0 ; i<q ; i++){
		cin>>a>>b;
		cout<<ans(a-1, b-1)<<endl;
	}
}