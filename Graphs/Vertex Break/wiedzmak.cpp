#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n , m , g , k;
struct line{
	int c , id , ti;
};
multiset<tuple<int , int , int > > Q;
multiset<tuple<int , int , int > >::iterator iter;
vector<int> M , W;
vector<bitset<13> > miasto(1);
vector<bitset<13> > way(1);
vector<vector<line> > friends(1);
vector<vector<int> > T(1);
int a, b;
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m>>g>>k;
	int kl , r , city , t;
	friends.resize(n+1);
	miasto.resize(n+1);
	for(int i=0 ; i<k ; i++){
		cin>>city;
		cin>>kl;
		for(int j=0 ; j<kl ; j++){
			cin>>r;
			miasto[city][r-1]=true;
		}
	}
	way.resize(m);
	for(int i=0 ; i<m ; i++){
		cin>>a>>b>>t>>kl;
		friends[a].push_back({b , i , t});
		friends[b].push_back({a , i ,t});
		for(int j=0 ; j<kl ; j++){
			cin>>r;
			way[i][r-1]=true;
		}
	}
	T.resize(n+1);
	int maxp=(int)pow(2 , g)-1;
	//cerr<<"G: "<<g<<endl;
	M.push_back(0);
	for(int i=1 ; i<=n ; i++){
		for(int j=0 ; j<=maxp ; j++){
			T[i].push_back(100001);
		}
		M.push_back((int)(miasto[i].to_ulong()));
		//cerr<<"miasto: "<<i<<" "<<M[i]<<endl;
	}
	for(int i=0 ; i<m ; i++){
		W.push_back(((int)way[i].to_ulong()));
		//cerr<<"droga: "<<i<<" "<<W[i]<<endl;
	}
	T[1][M[1]]=0;
	Q.insert(make_tuple(T[1][M[1]] , 1 , M[1]));
	while(!Q.empty()){
		iter=Q.begin();
		tuple<int , int , int > now=(*(iter));
		int A=get<0>(now);
		int B=get<1>(now);
		//cerr<<"now: "<<B<<endl;
		int stan=get<2>(now);
		Q.erase(Q.begin());
		for(int i=0 ; i<(int)friends[B].size() ; i++){
			line v=friends[B][i];
			//cerr<<"comp: "<<W[v.id]<<" "<<stan<<" "<<(W[v.id]|stan)<<endl;
			if((W[v.id]|stan)==stan){
				//cerr<<"moze isc z "<<B<<" do "<<v.c<<endl;
				int stanv=(stan|M[v.c]);
				//cerr<<"change: "<<stan<<endl;
				if(A+v.ti<T[v.c][stanv]){
					//cerr<<"wynnew"<<endl;
					int old=T[v.c][stanv];
					Q.erase(make_tuple(old , v.c , stanv));
					T[v.c][stanv]=A+v.ti;
					//cerr<<"ADD: "<<A+v.ti<<" wierz: "<<v.c<<" stanv: "<<stanv<<endl;
					Q.insert(make_tuple(T[v.c][stanv] , v.c , stanv));
				}
			}
		}
	}
	int wyn=100001;
	for(int i=0 ; i<=maxp ; i++){
		//cerr<<"count: "<<T[n][i]<<"  "<<i<<endl;
		 wyn=min(T[n][i] , wyn);
	}
	if(wyn==100001)cout<<-1;
	else cout<<wyn;

	
}