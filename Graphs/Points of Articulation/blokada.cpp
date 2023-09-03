#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long n , m;
struct kraw{
	int c, id;
};
int korzen=0;
vector<vector<kraw> > friends(1);
vector<bool> wtorna;
vector<int> numer , LOW;
vector<long long> ILE;
vector<bool> tabw , tabk , art , tabl , tabf;
int ll=2;
long long all;
void DFS(int now){
	for(int i=0 ; i<(int)friends[now].size() ;i++){
		int k=friends[now][i].id;
		int v=friends[now][i].c;
		if(tabk[k]==false){
			if(tabw[v]==true){
				wtorna[k]=true;
			}
			else{
				numer[v]=ll;
				ll++;
				tabw[v]=true;
				tabk[k]=true;
				DFS(v);
			}
		}
	}
}
void do_LOW(int now , int ojciec){
	tabl[now]=true;
	LOW[now]=numer[now];
	for(int i=0 ; i<(int)friends[now].size(); i++){
		int k=friends[now][i].id;
		int v=friends[now][i].c;
		if(v!=ojciec){
			if(tabl[v]==false){
				do_LOW(v , now);
				LOW[now]=min(LOW[now] , LOW[v]);
			}
			else{
				LOW[now]=min(LOW[now] , numer[v]);
			}
		}
	}
}
void find_art(int now){
	for(int i=0 ; i<(int)friends[now].size(); i++){
		int k=friends[now][i].id;
		int v=friends[now][i].c;
		if(LOW[v]>=numer[now] && numer[v]>numer[now] && wtorna[k]==false){
			if(now!=1)art[now]=true;
			if(now==1 && korzen==1)art[now]=true;
		}
		if(numer[v]>numer[now] && tabf[v]==false){
			tabf[v]=true;
			find_art(v);
		}
	}
}
long long j;
void count_tree(int now){
	//cerr<<"C: "<<now<<endl;
	long long j0;
	long long s=n;
	for(int i=0 ; i<(int)friends[now].size(); i++){
		int k=friends[now][i].id;
		int v=friends[now][i].c;
		if(wtorna[k]==false && numer[v]>numer[now]){
			j0=j;
			j--;
			count_tree(v);
			if(art[now]==true){
				if(LOW[v]>=numer[now]){
					//cout<<"J: "<<j0<<" "<<j<<" "<<now<<" "<<v<<endl;
					ILE[now]+=(long long)((j0-j)*(j0-j-1)/2);
					//cout<<"ILe: "<<ILE[now]<<endl;
					s-=(j0-j);
				}
			}
		}
	}
	if(art[now]==true)ILE[now]+=(long long)((s-1)*(s-2)/2);
	
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	friends.resize(n+1);
	int a, b;
	for(int i=0 ; i<m ; i++){
		cin>>a>>b;
		friends[a].push_back({b , i});
		friends[b].push_back({a , i});
		tabk.push_back(false);
		wtorna.push_back(false);
	}
	j=n;
	all=n*(n-1)/2;
	for(int i=0 ; i<=n ; i++){
		numer.push_back(0);
		tabw.push_back(false);
		LOW.push_back(0);
		art.push_back(false);
		ILE.push_back(0);
		tabl.push_back(false);
		tabf.push_back(false);
	}
	numer[1]=1;
	tabw[1]=true;
	DFS(1);
	for(int i=0 ; i<(int)friends[1].size() ; i++){
		int k=friends[1][i].id;
		if(wtorna[k]==true)korzen=1;
	}
	if(korzen==0 && (int)friends[1].size()>1)art[1]=true;
	do_LOW(1 , 1);
	tabf[1]=true;
	find_art(1);
	//if(art[1]==true)cout<<"XD";
	count_tree(1);
	for(int i=1 ; i<=n ; i++){
		if(art[i]==true){
			long long ans=(all-ILE[i])*2;
			cout<<ans<<endl;
		}
		else cout<<(n-1)*2<<endl;
	}


}