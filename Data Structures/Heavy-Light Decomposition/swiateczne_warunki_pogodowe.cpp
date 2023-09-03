#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n , a, b;
struct point{
	int l , r;
	bool val;
};
vector<vector<int> > friends(1);
vector<vector<int> > Ancestor(1);
vector<vector<point> > tree(1);
vector<int> grupa , GLE , numer, ILE , dad;
vector<int> ojciec;
void create(int m){
	int roz=1;
	while(roz<ILE[m])roz*=2;
	for(int i=0 ; i<2*roz; i++){
		tree[m].push_back({i, i , true});
		if(i>=roz)tree[m][i].l=tree[m][i].r=i-roz;
	}
	//int t=roz;
	while(roz!=1){
		for(int i=roz ; i<2*roz ; i+=2){
			tree[m][i/2].l=tree[m][i].l;
			tree[m][i/2].r=tree[m][i+1].r;
		}
		roz/=2;
	}
}
void Make_Ancestor(){
	for(int x=1 ; x<=n ; x++)Ancestor[x][0]=dad[x];
	for(int q=1 ; q<=20 ; q++)for(int x=1 ; x<=n ; x++)Ancestor[x][q]=Ancestor[Ancestor[x][q-1]][q-1];
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
	return dad[A];
}
int nr=0;
void DFS(int now , int last){
	//cerr<<now<<endl;
	int k=0;
	//int numer0=nr;
	for(int i=0 ; i<(int)friends[now].size() ; i++){
		int v=friends[now][i];
		if(last!=v){
			if(k!=0)nr++;
			GLE[v]=GLE[now]+1;
			grupa[v]=nr;
			numer[v]=ILE[nr];
			ILE[nr]++;
			if(k!=0)ojciec[nr]=now;
			k++;
			dad[v]=now;
			DFS(v , now);
		}
	}
}
void Change(int x){
	int gr=grupa[x];
	int nr=numer[x];
	int roz=(int)tree[gr].size();
	int now=roz/2+nr;
	if(tree[gr][now].val==false)tree[gr][now].val=true;
	else tree[gr][now].val=false;
	while(now!=1){
		if(now%2==0){
			if(tree[gr][now].val==true && tree[gr][now+1].val==true)tree[gr][now/2].val=true;
			else tree[gr][now/2].val=false;
		}
		else{
			if(tree[gr][now].val==true && tree[gr][now-1].val==true)tree[gr][now/2].val=true;
			else tree[gr][now/2].val=false;
		}
		now/=2;
	}
}
bool Count(int m , int x1 , int x2 , int teraz){
	//cerr<<"teraz: "<<teraz<<"  "<<tree[m][teraz].l<<"  "<<tree[m][teraz].r<<endl;
	if(tree[m][teraz].l==x1 && tree[m][teraz].r==x2){
		return tree[m][teraz].val;
	}
	else{
		int s=tree[m][teraz].r-tree[m][teraz].l+1;
		s/=2;
		if(tree[m][teraz].l+s>x2)return Count(m , x1 , x2 , teraz*2);
		if(tree[m][teraz].l+s<=x1)return Count(m , x1 , x2 , teraz*2 + 1);
		if(tree[m][teraz].l+s>x1 && tree[m][teraz].l+s<=x2){
			if(Count(m , x1 , tree[m][teraz].l+s-1 , teraz*2)==true && Count(m , tree[m][teraz].l+s , x2 , teraz*2 + 1)==true)return true;
			else return false;
		}
	}
	return true;
}
bool GO(int pocz , int kon){
	//pocz=numer[pocz];
	//cerr<<"START"<<endl;
	while(1){
		//cerr<<"Pocz: "<<pocz<<endl;
		//cerr<<pocz<<"  "<<grupa[pocz]<<"  "<<numer[pocz]<<endl;
		//cerr<<tree[grupa[pocz]].size();
		if(grupa[pocz]!=grupa[kon]){
			if(Count(grupa[pocz] , 0 , numer[pocz] , 1)==false)return false;
			else pocz=ojciec[grupa[pocz]];
		}
		else{
			if(Count(grupa[pocz] , numer[kon] , numer[pocz] , 1)==false)return false;
			break;
		}
	}
	//cerr<<"END"<<endl;
	return true;
}
int Ans(int x, int y){
	//cerr<<"X i Y: "<<x<<" "<<y<<endl;
	int L=LCA(x , y);
	//cerr<<"L: "<<L<<endl;
	if(GLE[x]>GLE[y])swap(x , y);
	if(x==L){
		if(GO(y , L)==true)return 1;
		else return 0;
	}
	else{
		if(GO(x , L)==true && GO(y , L)==true)return 1;
		else return 0;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	friends.resize(n+1);
	Ancestor.resize(n+1);
	for(int i=0 ; i<=n; i++){
		if(i<n-1){
			cin>>a>>b;
			friends[a].push_back(b);
			friends[b].push_back(a);
		}
		Ancestor[i].reserve(21);
		grupa.push_back(0);
		GLE.push_back(0);
		numer.push_back(0);
		ojciec.push_back(0);
		ILE.push_back(0);
		dad.push_back(1);
	}
	ILE[0]=1;
	DFS(1 , 1);
	//for(int i=0 ; i<=n ; i++){
	//	cerr<<i<<": "<<endl;
	//	cerr<<grupa[i]<<"   "<<numer[i]<<"  "<<ojciec[i]<<" "<<ILE[i]<<endl;
//	}
	//cerr<<"DFS"<<endl;
	int q;
	cin>>q;
	char zap;
	Make_Ancestor();
	//cerr<<"Anc"<<endl;
	tree.resize(nr+1);
	for(int i=0 ; i<=nr ; i++)create(i);
	//cerr<<"create"<<endl;
	//cerr<<endl;
	//for(int i=0 ; i<=nr ; i++)cerr<<tree[i].size()<<endl;
	//cerr<<endl;
	for(int i=0 ; i<q ; i++){
		cin>>zap;
		if(zap=='!'){
			cin>>a;
			Change(a);
		}
		else{
			cin>>a>>b;
			cout<<Ans(a , b)<<'\n';
			//cerr<<"NEW"<<endl;
		}
	}
	//cerr<<endl;

}