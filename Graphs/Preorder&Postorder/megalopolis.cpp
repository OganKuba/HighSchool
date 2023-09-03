#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n , q, a, b , c;
struct p{
	int l1 , p1 , v;
};
int nr=2;
vector<p> tree;
vector<vector<int> > friends(1);
vector<int> id;
vector<int> pod;
vector<bool> tab;
vector<int> GLE;
void DFS(int now){
	//cout<<"now: "<<now<<endl;
	for(int i=0 ; i<(int)friends[now].size() ; i++){
		if(tab[friends[now][i]]==false){
			tab[friends[now][i]]=true;
			id[friends[now][i]]=nr;
			nr++;
			GLE[friends[now][i]]=GLE[now]+1;
			DFS(friends[now][i]);
			pod[now]=max(pod[now] , pod[friends[now][i]]);
		}
	}
	if((int)friends[now].size()==1)pod[now]=id[now];
	
}
void create(int roz){
	for(int i=0 ; i<2*roz ; i++){
		tree.push_back({0 , 0, 0 });
		if(i>=roz)tree[i]={i-roz+1 , i-roz+1 , 0};
	}
	int now=roz;
	while(now!=1){
		for(int i=now ; i<2*now ; i=i+2)tree[i/2]={tree[i].l1 , tree[i+1].p1 , 0};
		now=now/2;
	}
}

void update(int s1 , int s2 , int w){
	//cout<<"w: "<<w<<"  ||  "<<s1<<" "<<s2<<endl;
	int r=tree[w].p1-tree[w].l1+1;
	r=r/2;
	if(tree[w].l1==s1 && tree[w].p1==s2)tree[w].v++;
	else{
		if(tree[w].l1+r>s2)update(s1 , s2 , w*2);
		if(tree[w].l1+r<=s1)update(s1 , s2 , w*2+1);
		if(s1<tree[w].l1+r && s2>=tree[w].l1+r){
			update(s1 , tree[w].l1+r-1 , w*2);
			update(tree[w].l1+r , s2 , w*2+1);
		}
	}
}
int ans(int x , int roz){
	int odp=0;
	x=x+roz-1;
	while(1){
		odp=odp+tree[x].v;
		if(x!=1)x=x/2;
		else break;
	}
	return odp;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	friends.resize(n+1);
	for(int i=0 ; i<n-1 ; i++){
		cin>>a>>b;
		friends[a].push_back(b);
		friends[b].push_back(a);
		//cout<<"XD";
	}
	for(int i=0 ; i<=n ; i++){
		tab.push_back(false);
		id.push_back(0);
		pod.push_back(0);
		GLE.push_back(0);
	}
	//cout<<"XD";
	pod[1]=-1;
	id[1]=1;
	tab[1]=true;
	GLE[1]=0;
	DFS(1);
	int m=1;
	for(int i=0 ; i<=17 ; i++){
		m=m*2;
		if(m>=n){
			break;
		}
	}
	create(m);
	//for(int i=1 ; i<=n ; i++){
	//	cout<<id[i]<<" "<<pod[i]<<endl;
	//}
	cin>>q;
	char znak;
	for(int i=0 ; i<q+n-1; i++){
		//cout<<"i: "<<i<<endl;
		cin>>znak;
		if(znak=='A'){
			cin>>a>>b;
			if(id[a]>id[b])swap(a , b);
			update(id[b] , pod[b] , 1);
		}
		if(znak=='W'){
			cin>>a;
			if(a==1)cout<<0<<endl;
			else cout<<GLE[a]-ans(id[a] , m)<<endl;
		}
	}
	return 0;
}