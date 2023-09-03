#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<vector<int> > friends(1);
vector<vector<int> > Ancestor(1);
struct war{
	int v, id;
};
struct que{
	int l , r , nr , com;
};
vector<war> val1;
vector<int> val, GLE , In , Out , tab , ojciec , ILE , NodeF;
vector<bool> byl , poz;
vector<que> ask;
int n , q , a , m , b;
int num=2;
bool compv(war x , war y){
	return x.v<y.v;
}
int ll=0;
bool compmo(que x , que y){
	if(x.l/(int)sqrt(num-1)!=y.l/(int)sqrt(num-1)) return x.l/(int)sqrt(num-1)<y.l/(int)sqrt(num-1); 
   return x.r<y.r; 
}
bool compodp(war x , war y){
	return x.id<y.id;
}
int LCA(int A , int B){
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
void Make_Ancestor(){
	for(int x=1 ; x<=n ; x++)Ancestor[x][0]=ojciec[x];
	for(int q=1 ; q<=20 ; q++){
		for(int x=1 ; x<=n ; x++)Ancestor[x][q]=Ancestor[Ancestor[x][q-1]][q-1];
	}
}
void skaluj(){
	sort(val1.begin() , val1.end() , compv);
	for(int i=0 ; i<(int)val1.size(); i++)val.push_back(0);
	//cerr<<endl;
	for(int i=1 ; i<(int)val1.size() ; i++){
		//cerr<<val1[i].v<<" ";
		if(val1[i].v==val1[i-1].v)val[val1[i].id]=ll;
		else{
			ll++;
			val[val1[i].id]=ll;
		}
	}
	//cerr<<endl;
}
void DFS(int now){
	for(int i=0 ; i<(int)friends[now].size() ; i++){
		if(byl[friends[now][i]]==false){
			byl[friends[now][i]]=true;
			GLE[friends[now][i]]=GLE[now]+1;
			In[friends[now][i]]=num;
			tab[num]=friends[now][i];
			ojciec[friends[now][i]]=now;
			num++;
			DFS(friends[now][i]);
		}
	}
	Out[now]=num;
	tab[num]=now;
	num++;
}
int L , P , lp , pp;
int odp=0;
int odp1=0;
void add(int x ){
	int c=tab[x];
	if(NodeF[c]==0){
		if(ILE[val[c]]==0)odp++;
		ILE[val[c]]++;
		NodeF[c]++;
	}
	else{
		if(ILE[val[c]]==1)odp--;
		ILE[val[c]]--;
		NodeF[c]++;
	}
}
void remove(int x){
	int c=tab[x];
	if(NodeF[c]==2){
		if(ILE[val[c]]==0)odp++;
		ILE[val[c]]++;
		NodeF[c]--;
	}
	else{
		if(ILE[val[c]]==1)odp--;
		ILE[val[c]]--;
		NodeF[c]--;
	}
}
int answer(int l1 , int p1 , int LC){
	if(P<p1){
		while(P<=p1){
			if(poz[P]==false)add(P);
			//cerr<<"Padd: "<<P<<" "<<odp<<" / ";
			poz[P]=true;
			if(P==p1)break;
			if(P<p1)++P;
		}
	}
	if(L>l1){
		while(L>=l1){
			if(poz[L]==false)add(L);
			//cerr<<"Ladd: "<<L<<" "<<odp<<" / ";
			poz[L]=true;
			if(L==l1)break;
			if(L>l1)--L;
		}
	}
	while(L<l1){
		if(poz[L]==true)remove(L);
		//cerr<<"Lrem: "<<L<<" "<<odp<<" / ";
		poz[L]=false;
		++L;
	}
	while(P>p1){
		if(poz[P]==true)remove(P);
		//cerr<<"Prem: "<<P<<" "<<odp<<" "<<ILE[2]<<" / ";
		poz[P]=false;
		--P;
	}
	//cerr<<"ODP: "<<odp<<" "<<L<<" "<<P<<endl;
	if(LC!=-1 && ILE[val[tab[LC]]]==0)odp++;
	return odp;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	friends.resize(n+1);
	Ancestor.resize(n+1);
	val1.push_back({0 , 0});
	for(int i=0 ; i<=n ; i++){
		if(i<n){
			cin>>a;
			val1.push_back({a , i+1});
		}
		val.push_back(0);
		NodeF.push_back(0);
		In.push_back(0);
		Out.push_back(0);
		tab.push_back(0);
		tab.push_back(0);
		poz.push_back(false);
		poz.push_back(false);
		Ancestor[i].reserve(21);
		GLE.push_back(0);
		ojciec.push_back(0);
		byl.push_back(false);
	}
	for(int i=0 ; i<n-1 ; i++){
		cin>>a>>b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	int h;
	skaluj();
	//cerr<<endl;
	//for(int i=1 ; i<=n ; i++)cerr<<val[i]<<" ";
	//cerr<<endl;
	for(int i=0 ; i<=ll ; i++)ILE.push_back(0);
	In[1]=1;
	tab[1]=1;
	ojciec[1]=1;
	byl[1]=true;
	DFS(1);
	//cerr<<"LL: "<<ll;
	//cerr<<endl;
	//for(int i=1 ; i<=n ; i++)cerr<<In[i]<<" "<<Out[i]<<" "<<GLE[i]<<endl;
	Make_Ancestor();
	//cerr<<"XD";
	for(int i=0 ; i<m ; i++){
		cin>>a>>b;
		if(In[a]>In[b])swap(a , b);
		h=LCA(a , b);
		if(h==a)ask.push_back({In[a] , In[b] , i , -1});
		else ask.push_back({Out[a] , In[b] , i , In[h]});
	}
	//cerr<<endl;
	//for(int i=1 ; i<num ; i++)cout<<i<<" "<<tab[i]<<endl;
	sort(ask.begin() , ask.end() , compmo);
	//cerr<<endl;
	//for(int i=0 ; i<m ; i++)cerr<<ask[i].l<<" "<<ask[i].r<<" "<<ask[i].com<<" "<<ask[i].nr<<endl;
	L=ask[0].l;
	P=ask[0].l;
	odp=1;
	poz[L]=true;
	ILE[val[tab[L]]]=1;
	NodeF[tab[L]]=1;
	lp=0;
	pp=0;
	vector<war> wyniki;
	for(int i=0 ; i<m ; i++){
		wyniki.push_back({answer(ask[i].l , ask[i].r , ask[i].com) , ask[i].nr});
		if(ask[i].com!=-1 && ILE[val[tab[ask[i].com]]]==0)odp--;
		//cout<<"ODP: "<<odp<<endl;
		//cerr<<endl;
		//cerr<<L<<" "<<P<<endl;
	}
	sort(wyniki.begin() , wyniki.end() , compodp);
	for(int i=0 ; i<m ; i++)cout<<wyniki[i].v<<endl;
}