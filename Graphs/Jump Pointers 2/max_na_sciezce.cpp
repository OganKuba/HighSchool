#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n , z , a, b;
int maxi=0;
struct point{
	int c , v;
};
vector<vector<point> > Ancestor(1);
vector<vector<int> > friends(1);
vector<int> GLE , val , ojciec;
void DFS(int now , int last){
	for(int i=0 ; i<(int)friends[now].size() ; i++){
		if(friends[now][i]!=last){
			GLE[friends[now][i]]=GLE[now]+1;
			ojciec[friends[now][i]]=now;
			DFS(friends[now][i] , now);
		}
	}
}
void Make_Ancestor(){
	for(int x=1 ; x<=n ; x++){
		Ancestor[x][0].v=max(val[x] , val[ojciec[x]]);
		Ancestor[x][0].c=ojciec[x];
	}
	for(int q=1 ; q<=20 ; q++){
		for(int x=1 ; x<=n ; x++){
			Ancestor[x][q].v=max(Ancestor[Ancestor[x][q-1].c][q-1].v , Ancestor[x][q-1].v);
			Ancestor[x][q].c=Ancestor[Ancestor[x][q-1].c][q-1].c;
		}
	}
}
int LCA(int A , int B){
	if(GLE[B]<GLE[A]){
		swap(A , B);
	}
	for(int y=20 ; y>=0 ; y--){
		if(GLE[Ancestor[B][y].c]>=GLE[A]){
			B=Ancestor[B][y].c;
		}
			if(A==B)return A;
	}
	for(int y=20 ; y>=0 ; y--){
		if(Ancestor[B][y].c!=Ancestor[A][y].c){
			A=Ancestor[A][y].c;
			B=Ancestor[B][y].c;
		}
	}
	return ojciec[A];
}
void GO(int p , int k){
	while(1){
		//cerr<<"p i r: "<<p<<" ";
		int r=(int)log2(GLE[p]-GLE[k]);
		//cerr<<r<<endl;
		maxi=max(maxi , Ancestor[p][r].v);
		p=Ancestor[p][r].c;
		if(GLE[p]==GLE[k]){
			break;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	Ancestor.resize(n+1);
	friends.resize(n+1);
	for(int i=0 ; i<n-1 ; i++){
		cin>>a>>b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	val.push_back(0);
	ojciec.push_back(1);
	GLE.push_back(0);
	Ancestor[0].reserve(21);
	for(int i=1 ; i<=n ; i++){
		cin>>a;
		val.push_back(a);
		Ancestor[i].reserve(21);
		ojciec.push_back(1);
		GLE.push_back(0);
	}
	DFS(1 , 1);
	//cerr<<"XD";
	Make_Ancestor();
	//cerr<<"XD";
	cin>>z;
	for(int i=0 ; i<z; i++){
		cin>>a>>b;
		int L=LCA(a , b);
		if(L!=a)GO(a , L);
		maxi=max(val[a] , maxi);
		if(L!=b)GO(b , L);
		maxi=max(val[b] , maxi);
		cout<<maxi<<endl;
		maxi=0;
	}
}