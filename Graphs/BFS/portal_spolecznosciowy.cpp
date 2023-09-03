#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int ja ,a , b ,x , y , n , m;
void BFS(int w , vector<vector<int> > &friends , int ro , deque<int> q , vector<int> &GLE , vector<bool> &odw , vector<int> &ans){
	q.push_back(w);
	GLE[w]=0;
	odw[w]=true;
	while(!q.empty()){
		x=q.front();
		q.pop_front();
		for(int i=0 ; i<friends[x].size() ; i++){
			y=friends[x][i];
			if(odw[y]==false){
				if(ro==0){
					ans.push_back(y);
				}
				q.push_back(y);
				odw[y]=true;
			}
			GLE[y]=min(GLE[y] , GLE[x]+1);
		}
	}
}
int odp=1;
void que(int me , int n , vector<vector<int> > &friends , deque<int> q , vector<int> GLE , vector<bool> odw , vector<int> ans){
	BFS(me , friends , 0 , q , GLE , odw , ans);
	sort(ans.begin() , ans.end());
	cout<<"Znajomi numeru "<<me<<":"<<endl;
	for(int i=0 ; i<ans.size() ; i++){
		cout<<ans[i]<<": "<<GLE[ans[i]]<<endl;
	}
	for(int i=1 ; i<=n ; i++){
		if(odw[i]==false){
			BFS(i , friends , 1 , q , GLE , odw , ans);
			odp++;
		}
	}
}
void pyt(vector<bool> odw , vector<int> GLE){
		cin>>n>>m;
		vector<vector<int> > friends(n+1);
	//	vector<bool> odw;
		//vector<int> GLE;
		//for(int i=0 ; i<10 ; i++){
	//		cout<<"XD1:   "<<odw[i]<<endl;
	//	}
		deque<int> q;
		vector<int> ans;
		for(int i=0 ; i<m ; i++){
			cin>>a>>b;
			friends[a].push_back(b);
			friends[b].push_back(a);
			//cerr<<"HU";
		}
		//cerr<<"XD";
		cin>>ja;
		//cerr<<"XD";
		que(ja , n , friends , q , GLE , odw , ans);
		if(m==0){
			odp=n;
		}
		cout<<"Grup znajomych jest "<<odp<<"."<<endl;
		odp=1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int  qu;
	cin>>qu;
	vector<vector<int> > friends;
	vector<bool> odwm;
	vector<int> GLEm;
	for(int i=0 ; i<=200001 ; i++){
		odwm.push_back(false);
		GLEm.push_back(200001);
	}
	int u=0;
	for(int j=0 ; j<qu ; j++){
		pyt(odwm , GLEm);
	}
	
	
	
}