#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct line{
	int v , id;
};
int n , m, a , b;
bool c , d;
vector<bool> S1 , S2 , tab1 , tabw;
vector<vector<line> > friends(1);
vector<deque<line> > graph(1);
vector<vector<int> > ans(1);
vector<bool> odw;
vector<int> Check1 , Check2 , ILE;
int suma=0;
void sprawdz(int now){
	for(int i=0 ; i<(int)friends[now].size() ; i++){
		int v=friends[now][i].v;
		int k=friends[now][i].id;
		if(S1[k]==true){
			//Check1[now]*=1;
			Check1[v]*=1;
		}
		else{
			//Check1[now]*=-1;
			Check1[v]*=-1;
		}
		if(S2[k]==true){
			//Check2[now]*=1;
			Check2[v]*=1;
		}
		else{
			//Check2[now]*=-1;
			Check2[v]*=-1;
		}
		if(tab1[v]==false){
			tab1[v]=true;
			sprawdz(v);
		}
	}
}
void Euler(int now , deque<int> &kraw){
	while(!graph[now].empty()){
		line ost=graph[now].back();
		graph[now].pop_back();
		int w=ost.v;
		int k=ost.id;
		if(odw[k]==false){
			tabw[w]=true;
			odw[k]=true;
			Euler(w, kraw);
			kraw.push_back(w);
			//cout<<v<<" ";
		}
	}
}
void create(deque<int> &kraw , vector<bool> past){
	//int i=0;
	deque<int> juz;
	while(!kraw.empty()){
		int v=kraw.front();
		//cerr<<"V: "<<v<<endl;
		if(past[v]==false){
			//cout<<"ADD";
			kraw.pop_front();
			juz.push_back(v);
			past[v]=true;
		}
		else{
			ans[suma].push_back(v);
			//cerr<<"BEGIN"<<endl;
			//kraw.pop_front();
			while(1){
				int k=juz.back();
				//cerr<<"K: "<<k<<endl;
				ans[suma].push_back(k);
				juz.pop_back();
				past[k]=false;
				//cerr<<"past: "<<k<<endl;
				if(k==v)break;
			}
			suma++;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	//cout<<n<<" "<<m<<endl;
	friends.resize(n+1);
	graph.resize(n+1);
	vector<bool> byl;
	for(int i=0 ; i<m ; i++){
		cin>>a>>b>>c>>d;
		//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		odw.push_back(false);
		friends[a].push_back({b , i});
		friends[b].push_back({a , i});
		S1.push_back(c);
		S2.push_back(d);
		odw.push_back(false);
		if(c!=d){
			graph[a].push_back({b , i});
			graph[b].push_back({a , i});
		}
	}
	//ILE.push_back(0);
	for(int i=0 ; i<=n ; i++){
		//ILE.push_back((int)graph[i].size());
		Check1.push_back(1);
		Check2.push_back(1);
		tab1.push_back(false);
		tabw.push_back(false);
		byl.push_back(false);
	}
	tab1[1]=true;
	sprawdz(1);
	//cerr<<"XD";
	bool next=true;
	for(int i=1 ; i<=n ; i++){
		if(Check1[i]!=Check2[i]){
			cout<<"NIE";
			next=false;
			break;
		}
	}
	//cerr<<"XD";
	if(next==true){
		//cerr<<"IN";
		//cout<<"NEXT"<<endl;
		ans.resize(5*m+1);
		for(int i=1 ; i<=n ; i++){
			//cerr<<i<<" ";
			if(tabw[i]==false){
				//cerr<<i<<": "<<endl;
				tabw[i]=true;
				deque<int> kraw;
				//cout<<"cykl Eulera: ";
				Euler(i , kraw);
				//cout<<endl;
				kraw.push_back(i);
				//cerr<<"Euler: ";
				//cout<<kraw.size()<<endl;
				create(kraw , byl);
			}
		}
		//cerr<<"SUma: "<<endl;
		cout<<suma<<'\n';
		for(int i=0 ; i<suma ; i++){
			cout<<(int)ans[i].size()-1<<" ";
			for(int j=0 ; j<(int)ans[i].size() ; j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<'\n';
		}
	}

}