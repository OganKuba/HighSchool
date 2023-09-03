#include <bits/stdc++.h>
using namespace std;
int n , p , k , m , a, b , r , poz , ile;
struct val{
	int tar , c , id;
};
bool dp[2001][301];
int mini=1000000;
vector<vector<int> > trasy(1);
vector<vector<val> > wyc(1);
vector<val> tab;
void DFS(int now , vector<bool> &odw , int ILE){
	odw[now]=true;
	if(now<=p)mini=min(mini , ILE);
	for(int i=0 ; i<(int)wyc[now].size() ; i++){
		if(ILE>=wyc[now][i].c){
			dp[ILE-wyc[now][i].c][wyc[now][i].id]=true;
			if(wyc[now][i].tar<=p)mini=min(mini , ILE-wyc[now][i].c);
		}
	}
	for(int i=0 ; i<(int)trasy[now].size() ; i++){
		if(!odw[trasy[now][i]])DFS(trasy[now][i] , odw , ILE);
	}
}
void que(int stan , vector<bool> odw){
	for(int i=0 ; i<m ; i++){
		if(dp[stan][i] && !odw[tab[i].tar])DFS(tab[i].tar , odw , stan);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>p;
	cin>>k;
	trasy.resize(n+1);
	wyc.resize(n+1);
	for(int i=0 ; i<k ; i++){
		cin>>a>>b;
		trasy[a].push_back(b);
	}
	cin>>m;
	for(int i=0 ; i<m ; i++){
		cin>>a>>b>>r;
		wyc[a].push_back({b , r , i});
		tab.push_back({b , r , i});
	}
	cin>>poz>>ile;
	vector<bool> byl=vector<bool>(n+1 , false);
	vector<bool> byl1=vector<bool>(n+1 , false);
	//for(int i=0 ; i<=n ; i++)cerr<<byl[i]<<" ";
	if(poz<=p)mini=ile;
	DFS(poz , byl , ile);
	//cerr<<"DFS"<<endl;
	for(int i=ile-1 ; i>=0; i--){
		que(i , byl1);
	}
	cout<<mini;
}