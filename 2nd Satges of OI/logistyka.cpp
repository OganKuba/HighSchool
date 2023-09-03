#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n , m , a , b , roz;
char q;
struct que{
	char Z;
	int x , y , poz , id;
};
struct val{
	int ile;
	long long suma;
	int l , p;
};
bool compy(que A , que B){return A.y<B.y;}
bool compid(que A , que B){return A.id<B.id;}
vector<int> value , stan;
vector<que> zap;
vector<val> tree;
void create(){
	for(int i=0 ; i<2*roz ; i++){
		tree.push_back({0 , 0 , 0 , 0});
		if(i>=roz){
			tree[i].l=tree[i].p=i-roz+1;
		}
	}
	int now=roz;
	while(now!=1){
		for(int i=now ; i<2*now ; i=i+2){
			tree[i/2].l=tree[i].l , tree[i/2].p=tree[i+1].p;
		}
		now/=2;
	}
}
void usun(int pozy , int k){
	if(tree[roz+pozy-1].ile!=0 && pozy!=0){
		int now=roz+pozy-1;
		while(1){
			//cerr<<"NOWu; "<<now<<endl;
			tree[now].ile-=1 , tree[now].suma=tree[now].suma-(long long)(k);
			now/=2;
			if(now==1)break;
		}
		tree[1].ile-=1 , tree[1].suma=tree[1].suma-(long long)(k);
	}
}
void dodaj(int  pozy ,  int k){
	//cerr<<"NOWD: "<<pozy<<endl;
	int now=roz+pozy-1;
	while(1){
		//cerr<<"NOWd; "<<now<<endl;
		tree[now].ile+=1 , tree[now].suma=tree[now].suma+(long long)(k);
		now/=2;
		if(now==1)break;
	}
	tree[1].ile+=1 , tree[1].suma=tree[1].suma+(long long)(k);
}
int ans_ile(int L , int P , int now){
	if(L>P)return 0;
	//cerr<<"NOW: "<<now<<endl;
	int s=(tree[now].p-tree[now].l+1)/2;
	if(tree[now].l==L && tree[now].p==P)return tree[now].ile;
	else{
		if(tree[now].l+s<=L)return ans_ile(L , P , now*2 + 1);
		if(P<tree[now].l+s)return ans_ile(L , P , now*2);
		if(L<tree[now].l+s && P>=tree[now].l+s){
			int wyn=ans_ile(L , tree[now].l+s-1 , now*2)+ans_ile(tree[now].l+s , P , now*2 + 1);
			return wyn;
		}
	}
	return 0;
}
long long ans_suma(int L , int P , int now){
	if(L>P)return 0;
	//cerr<<"NOW: "<<now<<endl;
	int s=(tree[now].p-tree[now].l+1)/2;
	if(tree[now].l==L && tree[now].p==P)return tree[now].suma;
	else{
		if(tree[now].l+s<=L)return ans_suma(L , P , now*2 + 1);
		if(P<tree[now].l+s)return ans_suma(L , P , now*2);
		if(L<tree[now].l+s && P>=tree[now].l+s){
			long long wyn=ans_suma(L , tree[now].l+s-1 , now*2)+ans_suma(tree[now].l+s , P , now*2 + 1);
			return wyn;
		}
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	for(int i=0 ; i<m ; i++){
		cin>>q>>a>>b;
		zap.push_back({q , a, b , 1 , i});
	}
	stan=vector<int>(n+1 , 0);
	sort(zap.begin() , zap.end() , compy);
	value.push_back(0);
	value.push_back(zap[0].y);
	for(int i=1 ; i<m ; i++){
		if(zap[i].y!=zap[i-1].y){
			zap[i].poz=zap[i-1].poz+1;
			value.push_back(zap[i].y);
		}
		else zap[i].poz=zap[i-1].poz;
	}
	roz=zap[m-1].poz;
	int w=1;
	while(w<roz)w*=2;
	roz=max(w , 2);
	//cerr<<"roz: "<<roz<<endl;
	sort(zap.begin() , zap.end() , compid);
	create();
	//cerr<<"create: "<<endl;
	for(int i=0 ; i<m ; i++){
		if(zap[i].Z=='U'){
			//cerr<<"aktualizajca: "<<endl;
			int old=stan[zap[i].x];
			stan[zap[i].x]=zap[i].poz;
			//cerr<<"old: "<<old<<"    "<<value[old]<<endl;
			usun(old , value[old]);
			dodaj(zap[i].poz , value[zap[i].poz]);
		}
		else{
			//cerr<<"ZAP: "<<endl;
			int A=ans_ile(zap[i].poz , roz , 1);
			long long B=ans_suma(1 , zap[i].poz-1 , 1);
			//cerr<<"wyniki: "<<A<<"   "<<B<<endl;
			if((long long)(A)*(long long)(zap[i].y)+B>=(long long)(zap[i].y)*(long long)(zap[i].x))cout<<"TAK"<<'\n';
			else cout<<"NIE"<<'\n';
		}
		//cerr<<"--------------"<<endl;
	}
	return 0;
}