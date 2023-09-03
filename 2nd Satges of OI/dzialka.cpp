#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool tab[2000][2000];
int last[2000];
struct A{
	int p , h;
};
int maxi=0;
int n , a;
void count(int k){
	vector<int> G;
	for(int j=0 ; j<n ; j++){
		if(tab[k][j]==false){
			G.push_back(0);
			last[j]=k;
		}
		else G.push_back(k-last[j]);
	}
	G.push_back(0);
	stack<A> Q;
	A ost;
	int l;
	//for(int i=0 ; i<=n ; i++)cerr<<G[i]<<" ";
	//cerr<<endl;
	//cerr<<"XD";
	bool wywal=false;
	for(int j=0 ; j<=n ; j++){
		//cerr<<j<<" ";
		wywal=false;
		l=j;
		while(!Q.empty()){
			ost=Q.top();
			if(ost.h>G[j]){
				maxi=max(maxi , (j-ost.p)*ost.h);
				wywal=true;
				l=ost.p;
				Q.pop();
			}
			else{
				if(G[j]!=0)Q.push({l , G[j]});
				break;
			}
		}
		if(wywal==true && Q.empty() && G[j]!=0)Q.push({l , G[j]});
		if(wywal==false && Q.empty() && G[j]!=0)Q.push({j , G[j]});
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			cin>>a;
			if(a==1)tab[i][j]=false;
			else tab[i][j]=true;
		}
	}
	for(int i=0 ; i<n ; i++)last[i]=-1;
	//cerr<<endl;
	for(int i=0 ; i<n ; i++){
		count(i);
	}
	cout<<maxi;

}