#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
int n , m, k , d;
int roz;
vector<long long> tab;
struct val{
	long long suma , l , r , maxi;
};
vector<val> tree;
void create(){
	for(int i=0 ; i<2*roz ; i++){
		tree.push_back({0 , 0 , 0 , 0});
		if(i>=roz){
			tree[i].suma=-k , tree[i].l=-k , tree[i].r=-k , tree[i].maxi=-k;
		}
	}
	int now=roz;
	while(now!=1){
		for(int i=now ; i<2*now ; i=i+2){
			tree[i/2].maxi=tree[i/2].l=tree[i/2].r=tree[i/2].suma=tree[i].suma+tree[i+1].suma;
		}
		now/=2;
	}
}
void change(int poz){
	tree[poz].maxi=tree[poz].l=tree[poz].r=tree[poz].suma=tab[poz-roz+1];
	int obok;
	while(poz!=1){
		//cerr<<"pozy: "<<poz<<endl;
		if(poz%2==0)obok=poz+1;
		else obok=poz-1;
		tree[poz/2].suma=tree[poz].suma+tree[obok].suma;
		int poz0=poz;
		if(obok<poz)swap(poz , obok);
		tree[poz/2].maxi=max(tree[poz].maxi , max(tree[poz].r+tree[obok].l , tree[obok].maxi));
		tree[poz/2].l=max(tree[poz].l , tree[poz].suma+tree[obok].l);
		tree[poz/2].r=max(tree[obok].r , tree[obok].suma+tree[poz].r);
		poz=poz0/2; 
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k>>d;
	roz=1;
	while(roz<n)roz*=2;
	tab=vector<long long>(roz+1 , -k);
	create();
	int r , x;
	for(int i=0 ; i<m ; i++){
		cin>>r>>x;
		tab[r]+=(long long)(x);
		change(roz+r-1);
		//cerr<<"wyn: "<<tree[1].maxi<<endl;
		if(tree[1].maxi<=(long long)(d)*(long long)(k))cout<<"TAK"<<'\n';
		else cout<<"NIE"<<'\n';
	}
	//cerr<<"tab: "<<endl;
	//for(int i=1 ; i<=4 ; i++)cerr<<tab[i]<<"   ";
}	