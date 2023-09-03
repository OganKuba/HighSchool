#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> partner , side , odw , nk , nw , pw;
set<pair<int , int> > pk;
set<pair<int , int> >::iterator iter;
vector<bool> byl , pokrycie , vis , add;
int licz=0;
int n , m , a , b;
vector<vector<int> > friends(1);
void show(){
	cout<<(int)nk.size()/2<<'\n';
	for(int i=0 ; i<(int)nk.size() ; i++)cout<<nk[i]<<" ";
	cout<<'\n';
	cout<<(int)pk.size()<<'\n';
	while(!pk.empty()){
		iter=pk.begin();
		cout<<(*(iter)).first<<" "<<(*(iter)).second<<" ";
		pk.erase(pk.begin());
	}
	cout<<'\n';
	cout<<(int)nw.size()<<'\n';
	for(int i=0 ; i<(int)nw.size() ; i++)cout<<nw[i]<<" ";
	cout<<'\n';
	cout<<(int)pw.size()<<'\n';
	for(int i=0 ; i<(int)pw.size() ; i++)cout<<pw[i]<<" ";
	cout<<endl;
}
void DFS(int now , int nr){
	byl[now]=true;
	side[now]=nr;
	//cerr<<"now:"<<now<<"  "<<nr<<endl;
	for(int i=0 ; i<(int)friends[now].size() ; i++){
		int v=friends[now][i];
		if(byl[v]==false){
			int d=0;
			if(nr==1)d=2;
			else d=1;
			DFS(v , d);
		}
	}
}
bool Turbo_Match(int x){
	odw[x]=licz;
	for(int i=0 ; i<(int)friends[x].size() ; i++){
		int v=friends[x][i];
		if(partner[v]==0) {
			partner[x]=v , partner[v]=x;
			return true;
		}
	}
	for(int i=0 ; i<(int)friends[x].size() ; i++){
		int v=friends[x][i];
		if(odw[partner[v]]!=licz && Turbo_Match(partner[v])==true){
			partner[x]=v;
			partner[v]=x;
			return true;
		}
	}
	return false;
}
void Match(){
	bool change=true;
	while(change){
		change=false;
		licz++;
		for(int i=1 ; i<=n ; i++){
			if(partner[i]==0){
				if(Turbo_Match(i)==true)change=true;
			}
		}
	}
}
void Check(int now){
	int v=partner[now];
	for(int i=0 ; i<(int)friends[v].size() ; i++){
		int u=friends[v][i];
		if(pokrycie[u]==false){
			pokrycie[u]=true;
			//cerr<<"C: "<<u<<endl;
			pw.push_back(u);
			Check(u);
		}
	}
}
void create(){
	for(int i=1 ; i<=n ; i++){
		if(side[i]==1 && partner[i]!=0){
			nk.push_back(i);
			nk.push_back(partner[i]);
		}
		if(partner[i]!=0){
			for(int j=0 ; j<(int)friends[i].size()  ; j++){
				int v=friends[i][j];
				if(partner[v]==0 && pokrycie[i]==false){
					pokrycie[i]=true;
					//cerr<<"1: "<<i<<endl;
					pw.push_back(i);
				}
			}
		}
	}
	for(int i=1 ; i<=n ; i++)if(pokrycie[i]==true)Check(i);
	for(int i=0 ; i<(int)nk.size() ; i=i+2){
		int a1=nk[i];
		int a2=nk[i+1];
		if(pokrycie[a1]==false && pokrycie[a2]==false){
			if(side[a1]==1){
				pokrycie[a1]=true;
				pw.push_back(a1);
			}
			else{
				pokrycie[a2]=true;
				pw.push_back(a2);
			}
		}
	}
	for(int i=1 ; i<=n ; i++){
		if(pokrycie[i]==false)nw.push_back(i);
		int v=partner[i];
		if(v==0)v=friends[i][0];
		pk.insert(make_pair(min(i , v) , max(i , v)));
	}

}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	friends.resize(n+1);
	for(int i=0 ; i<m; i++){
		cin>>a>>b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	for(int i=0 ; i<=n ; i++){
		odw.push_back(0);
		byl.push_back(false);
		side.push_back(0);
		partner.push_back(0);
		pokrycie.push_back(false);
		vis.push_back(false);
		add.push_back(false);
	}
	for(int i=1 ; i<=n ; i++){
		if(byl[i]==false)DFS(i , 1);
	}
	Match();
	//for(int i=1 ; i<=n ; i++)cout<<i<<": "<<partner[i]<<endl;
	//cout<<endl;
	//cerr<<"Match";
	create();
	//cerr<<"create";
	show();
}