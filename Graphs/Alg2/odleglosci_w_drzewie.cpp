#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > synowie(100001);
int n , k , x, y , a, b , j;
vector<int> ojciec;
vector<int> TAB1;
vector<int> TAB2;
void DFS(int now ){
	for(int i=0 ; i<(int)synowie[now].size() ; i++){
		x=synowie[now][i];
		if(x!=ojciec[now]){
			ojciec[x]=now;
			DFS(x);
		}
	}

}
void POST(int now){
	for(int i=0 ; i<(int)synowie[now].size() ; i++){
		int x=synowie[now][i];
		if(x!=ojciec[now]){
			if(TAB1[x]==0){
				POST(x);
				TAB1[now]=max(TAB1[now] , TAB1[x]+1);
			}
		}
	}
	
}
int e;
void KON(int now){
	int d=ojciec[now];
	for(j=0 ; j<(int)synowie[d].size() ; j++){
		x=synowie[d][j];
		if(x!=now && x!=ojciec[d]){
			TAB2[now]=max(TAB1[x]+2 , TAB2[now]);
		}
	}
	TAB2[now]=max(TAB2[now] , TAB2[d]+1);
	if(now==1){
		TAB2[now]=0;
	}
	for(int i=0 ; i<(int)synowie[now].size() ; i++){
		 e=synowie[now][i];
		if(e!=d){
			KON(e);
		}
	}
}
int main(){
	cin>>n;
	for(x=0 ; x<n+1 ; x++){
		if(x<n-1){
			cin>>a>>b;
			synowie[a].push_back(b);
			synowie[b].push_back(a);
		}
		ojciec.push_back(0);
		TAB1.push_back(0);
		TAB2.push_back(0);
	}
	DFS(1);
	POST(1);
	KON(1);
	//for(a=1 ; a<=n ; a++){
	//	cout<<TAB2[a]<<endl;
//	}
//	cout<<endl;
	
	for(j=1 ; j<=n ; j++){
		cout<<max(TAB1[j] , TAB2[j])<<endl;
	}
	
	
}