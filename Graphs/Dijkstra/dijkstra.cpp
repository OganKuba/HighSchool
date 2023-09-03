#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n , m , s , t , i;
struct way{
	int nr , d;
};
vector<long long> D;
vector<int> wyn;
multiset<pair<long long , long long> > Q;
multiset<pair<long long , long long> >::iterator iter;
vector<bool> tab;
vector<vector<way> > synowie(100001);
long long porownaj(long long x , int r){
	if(D[r]==-1){
		return x;
	}
	else{
		return min(x , D[r]);
	}
	return 0;
}
long long k;
long long zap;
void done(long long v , int w , int val){
	k=D[v]+val;
	zap=D[w];
	D[w]=porownaj(k , w);
	if(!Q.empty() && zap!=-1){
		Q.erase(Q.find(make_pair(zap , w)));
	}
	Q.insert(make_pair(D[w] , w));
}
int q , p;
void wierz(long long u){
	for(i=0 ; i<(int)synowie[u].size() ; i++){
		p=synowie[u][i].nr;
		q=synowie[u][i].d;
		if(tab[p]==false){
			done(u , p , q);
		}
	}
}
int now;
int kon;
void odzyskaj(){
	for(i=0 ; i<(int)synowie[now].size() ; i++){
		p=synowie[now][i].nr;
		q=synowie[now][i].d;
		if(D[now]==D[p]+q){
			wyn.push_back(p);
			now=p;
			break;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s>>t;
	for(i=0 ; i<=n ; i++){
		D.push_back(-1);
		tab.push_back(false);
	}
	D[s]=0;
	int a, b , c;
	for(i=0 ; i<m ; i++){
		cin>>a>>b>>c;
		synowie[a].push_back(way());
		synowie[a][(int)synowie[a].size()-1].nr=b;
		synowie[a][(int)synowie[a].size()-1].d=c;
		synowie[b].push_back(way());
		synowie[b][(int)synowie[b].size()-1].nr=a;
		synowie[b][(int)synowie[b].size()-1].d=c;
	}
	Q.insert(make_pair(0 , s));
	long long y;
	while(!Q.empty()){
		iter=Q.begin();
		y=(*(iter)).second;
		//war=abs((*(iter)).first);
		tab[y]=true;
		Q.erase(Q.begin());
		wierz(y);
	}
	Q.clear();
	//for(i=1 ; i<=n ; i++){
	//	cout<<i<<": "<<D[i]<<endl;
//	}
	if(D[t]==-1){
		cout<<-1;
	}
	else{
		wyn.push_back(t);
		now=t;
		kon=s;
		while(now!=kon){
			odzyskaj();
		
		}	
		cout<<D[t]<<" "<<(int)wyn.size()<<endl;
		for(i=(int)wyn.size()-1 ; i>=0 ; i--){
			cout<<wyn[i]<<" ";
		}
	}
}