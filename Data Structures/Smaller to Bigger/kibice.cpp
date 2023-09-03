#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int t , n , m ,a, b , c;
int LCA(int A , int B , vector<int> &GLE , vector<vector<int> > &Ancestor , vector<int> &ojciec){
	if(GLE[B]<GLE[A])swap(A , B);
	for(int y=20 ; y>=0 ; y--){
		if(GLE[Ancestor[B][y]]>=GLE[A])B=Ancestor[B][y];
		if(A==B)return A;
	}
	for(int y=20 ; y>=0 ; y--){
		if(Ancestor[B][y]!=Ancestor[A][y]){
			A=Ancestor[A][y];
			B=Ancestor[B][y];
		}
	}
	return ojciec[A];
}
void Make_Ancestor(vector<vector<int> > &Ancestor , vector<int> &ojciec){
	for(int x=1 ; x<=n ; x++)Ancestor[x][0]=ojciec[x];
	for(int q=1 ; q<=20 ; q++){
		for(int x=1 ; x<=n ; x++)Ancestor[x][q]=Ancestor[Ancestor[x][q-1]][q-1];
	}
}
void DFS(int now , vector<vector<int> > &friends , int last , vector<int> &ojciec , vector<int> &GLE){
	//cerr<<now;
	for(int i=0 ; i<(int)friends[now].size() ; i++){
		if(friends[now][i]!=last){
			ojciec[friends[now][i]]=now;
			GLE[friends[now][i]]=GLE[now]+1;
			DFS(friends[now][i] , friends , now , ojciec , GLE);
		}
	}
}
void Count(int now , vector<int> &val , vector<vector<int> > &friends , vector<int> &which , vector<multiset<int> > &Q , vector<int> &ojciec , vector<vector<int> > &put , vector<vector<int> > &cancel){
	//cerr<<now<<endl;
	multiset<int>::iterator iter;
	multiset<int>::reverse_iterator rit;
	for(int i=0 ; i<(int)friends[now].size() ; i++){
		if(friends[now][i]!=ojciec[now]){
			Count(friends[now][i] , val , friends , which , Q , ojciec , put , cancel);
			if((int)Q[which[now]].size()<(int)Q[which[friends[now][i]]].size()){
				while(!Q[which[now]].empty()){
					iter=Q[which[now]].begin();
					Q[which[friends[now][i]]].insert((*(iter)));
					//cout<<"ADD: "<<now<<" "<<(*(iter))<<endl;
					Q[which[now]].erase((*(iter)));
				}
				which[now]=which[friends[now][i]];
			}
			else{
				while(!Q[which[friends[now][i]]].empty()){
					iter=Q[which[friends[now][i]]].begin();
					Q[which[now]].insert((*(iter)));
					//cout<<"ADD: "<<now<<" "<<(*(iter))<<endl;
					Q[which[friends[now][i]]].erase((*(iter)));
				}
			}
		}
	}
	//cerr<<now<<endl;
	for(int i=0 ; i<(int)put[now].size() ; i++){
		//cout<<"ADD: "<<now<<" "<<put[now][i]<<endl;
		Q[which[now]].insert(put[now][i]);
	}
	if(!Q[which[now]].empty()){
		rit=Q[which[now]].rbegin();
		//cout<<"TO: "<<which[now]<<" "<<now<<" "<<(*(iter))<<" "<<Q[which[now]].size()<<endl;
		val[now]=(*(rit));
	}
	else val[now]=0;
	for(int i=0 ; i<(int)cancel[now].size() ; i++){
		//cout<<"REMOVE: "<<now<<" "<<cancel[now][i]<<endl;
		Q[which[now]].erase(cancel[now][i]);
	}
	//cerr<<now<<endl;
}
void GO(){
	vector<multiset<int> > Q(n+1);
	vector<vector<int> > friends(n+1);
	vector<vector<int> > cancel(n+1);
	vector<vector<int> > put(n+1);
	vector<vector<int> > Ancestor(n+1);
	vector<int> GLE;
	vector<int> val;
	vector<int> which;
	vector<int> ojciec;
	for(int i=0 ; i<=n ; i++){
		if(i<n-1){
			cin>>a>>b;
			friends[a].push_back(b);
			friends[b].push_back(a);
		}
		Ancestor[i].reserve(21);
		val.push_back(0);
		ojciec.push_back(1);
		which.push_back(i);
		GLE.push_back(0);
	}
	DFS(1 , friends , 1 , ojciec , GLE);
	//cerr<<"XD";
	Make_Ancestor(Ancestor , ojciec);
	//cerr<<"XD";
	for(int i=0 ; i<m ; i++){
		cin>>a>>b>>c;
		if(a>b)swap(a , b);
		int y=LCA(a , b , GLE , Ancestor , ojciec);
		if(y==a){
			cancel[y].push_back(c);
			put[b].push_back(c);
		}
		else{
			cancel[y].push_back(c);
			cancel[y].push_back(c);
			put[b].push_back(c);
			put[a].push_back(c);
		}
	}
	//cerr<<endl;
	//for(int i=1 ; i<=n ; i++){
		//cerr<<i<<": ";
	//	for(int j=0 ; j<put[i].size() ; j++)cout<<put[i][j]<<" ";
	//	cerr<<endl;
	//}
	//cerr<<endl;
	Count(1 , val , friends , which , Q , ojciec , put , cancel);
	//cerr<<"XD";
	//cerr<<"ODP: ";
	for(int i=1 ; i<=n ; i++)cout<<val[i]<<" ";
	cout<<endl;

}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>t;
	for(int i=0 ; i<t ; i++){
		cin>>n>>m;
		GO();
	}
}