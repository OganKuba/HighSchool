#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n , m, a, b;
struct line{
	int c , id;
};
struct para{
	int x , y;
};
vector<vector<line> > friends(1);
vector<vector<pair<int , int> > > spojne(1);
vector<bool> tabw , tabk , wtorna , tabf;
vector<int> LOW , numer , art , ile , rep;
vector<pair<int , int> > mosty , grupa , con;
int ll=1;
void Union(int a,int b){
	if(ile[a]>ile[b])swap(a, b);
	rep[a]=b;
	ile[b]+=ile[a];
}
int Find(int a){
	if(rep[a]!=a)rep[a]=Find(rep[a]);
	return rep[a];
}
void DFS(int now , int last , int d){
	numer[now]=d;
	LOW[now]=numer[now];
	for(int i=0 ; i<(int)friends[now].size() ;i++){
		int k=friends[now][i].id;
		int v=friends[now][i].c;
		if(v!=last){
			if(tabw[v]==true){
				wtorna[k]=true;
				LOW[now]=min(LOW[now] , numer[v]);
			}
			else{
				tabw[v]=true;
				DFS(v , now , d+1);
				LOW[now]=min(LOW[now] , LOW[v]);
			}
		}
	}
}
void find_art(int now , int last , int lastk , int korzen){
	if(numer[now]==LOW[now] && now!=korzen){
			mosty.push_back({min(now , last) , max(now , last)});
	}
	int dod=0;
	for(int i=0 ; i<(int)friends[now].size(); i++){
		int k=friends[now][i].id;
		int v=friends[now][i].c;
		if(LOW[v]>=numer[now] && numer[v]>numer[now] && wtorna[k]==false){
			if(now!=korzen && dod==0){
				art.push_back(now);
				dod++;
			}
		}
		if(LOW[v]<numer[now])Union(Find(k) , Find(lastk));
		if(numer[v]>numer[now] && tabf[v]==false){
			tabf[v]=true;
			find_art(v , now , k , korzen);
			
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	friends.resize(n+1);
	for(int i=0 ; i<m ; i++){
		cin>>a>>b;
		friends[a].push_back({b , i});
		friends[b].push_back({a , i});
		con.push_back({min(a , b) , max(a , b)});
		wtorna.push_back(false);
		tabk.push_back(false);
		ile.push_back(1);
		rep.push_back(i);
	}
	for(int i=0 ; i<=n ; i++){
		tabf.push_back(false);
		tabw.push_back(false);
		numer.push_back(0);
		LOW.push_back(0);

	}
	for(int i=1 ; i<=n ; i++){
		if(tabw[i]==false){
			tabw[i]=true;
			DFS(i , i , 0);
		}
	}
	int jed=0;
	for(int i=1 ; i<=n ; i++){
		if(tabf[i]==false){
			for(int j=0 ; j<(int)friends[i].size(); j++){
				int k=friends[i][j].id;
				if(wtorna[k]==false)jed++;
			}
			if(jed>1)art.push_back(i);
			jed=0;
			tabf[i]=true;
			find_art(i , i , -1 , i);
		}
	}
	cout<<(int)art.size()<<" ";
	sort(art.begin() , art.end());
	for(int i=0 ; i<(int)art.size() ; i++)cout<<art[i]<<" ";
	cout<<'\n';
	sort(mosty.begin() , mosty.end());
	cout<<(int)mosty.size()<<" ";
	for(int i=0 ; i<(int)mosty.size() ; i++)cout<<mosty[i].first<<" "<<mosty[i].second<<" ";
	cout<<'\n';
	vector<int> grupy;
	spojne.resize(m);
	for(int i=0 ; i<m ; i++){
		spojne[Find(i)].push_back(con[i]);
	}
	for(int i=0 ; i<m ; i++)sort(spojne[i].begin() , spojne[i].end());
	sort(spojne.begin() , spojne.end());
	int p=0;
	for(int i=0 ; i<m ; i++){
		if((int)spojne[i].size()>0){
			p=i;
			break;
		}
	}
	cout<<m-p<<'\n';
	for(int i=p ; i<m ; i++){
		if((int)spojne[i].size()>0){
			cout<<(int)spojne[i].size()<<" ";
			for(int j=0 ; j<(int)spojne[i].size() ; j++)cout<<spojne[i][j].first<<" "<<spojne[i][j].second<<" ";
			cout<<'\n';
		}
	}

}