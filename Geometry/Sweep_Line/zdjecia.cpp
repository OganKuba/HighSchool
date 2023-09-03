#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int x1, x2 ,y2, n;
int yt;
vector<vector<int> > tab(1);
int roz=1;
int maxi=0;
struct point{
    int x, yd , yg, z;
};
struct xd{
    int war, id;
};
struct lef{
    int l1 , p1 , d , vmax;
};
vector<lef> tree;
bool comp(xd a , xd b){
    return a.war<b.war;
}
bool compQ(point p1 , point p2){
    if(p1.x!=p2.x)return p1.x<p2.x;
    else return p1.z>p2.z;
}
void create(){
    for(int i=0 ; i<2*roz ; i++){
   	 tree.push_back({0, 0 , 0 , 0});
   	 if(i>=roz){
   		 tree[i].l1=i-roz;
   		 tree[i].p1=i-roz;
   	 }
    }
    int now=roz;
    while(now!=1){
   	 for(int i=now ; i<now*2 ; i=i+2){
   		 tree[i/2].l1=tree[i].l1;
   		 tree[i/2].p1=tree[i+1].p1;
   	 }
   	 now=now/2;
    }

}
void update(int a1 , int b1 , int q, int now, int dod){
	if(a1==tree[1].l1 && b1==tree[1].p1 && q==1){
		maxi=max(tree[now*2].vmax+q, tree[now*2+1].vmax+q);
	}
    if(a1==tree[now].l1 && b1==tree[now].p1){
   	 //tree[now].vmax=tree[now].vmax+dod+q;
   	 tree[now].d=tree[now].d+q;
    }
    else{
    //dod=dod+tree[now].d;
   	 if(a1>tree[now*2].p1)update(a1, b1, q , now*2+1 , dod);
   	 if(b1<=tree[now*2].p1)update(a1, b1 , q , now*2, dod);
   	 if(a1<=tree[now*2].p1 && b1>=tree[now*2+1].l1){
   		 update(a1, tree[now*2].p1, q , now*2, dod);
   		 update(tree[now*2+1].l1, b1, q , now*2+1, dod);
   	 }
   	 tree[now].vmax=max(tree[now*2].vmax+tree[now*2].d, tree[now*2+1].vmax+tree[now*2+1].d);
    }
}
vector<bool> byl;
vector<xd> Y;
vector<point> Q;
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    tab.resize(n);
    for(int i=0 ; i<n ; i++){
   	 cin>>x1>>yt>>x2>>y2;
   	 tab[i].push_back(x1);
   	 tab[i].push_back(yt);
   	 tab[i].push_back(x2);
   	 tab[i].push_back(y2);
   	 byl.push_back(false);
   	 Y.push_back({yt , i});
   	 Y.push_back({y2 , i});
    }
    sort(Y.begin() , Y.end() , comp);
    //for(int i=0 ; i<2*n ; i++)cerr<<Y[i].war<<" "<<i<<endl;
    //cout<<endl;
    int l=0;
    for(int i=0 ; i<2*n ; i++){
   	 if(i==0){
   		 byl[Y[i].id]=true;
   		 tab[Y[i].id][1]=l;
   	 }
   	 else{
   		 if(Y[i-1].war!=Y[i].war)l++;
   		 if(byl[Y[i].id]==false){
   			 tab[Y[i].id][1]=l;
   			 byl[Y[i].id]=true;
   		 }
   		 else tab[Y[i].id][3]=l;
   	 }
    }
   // for(int i=0 ; i<n ; i++)cerr<<tab[i][1]<<" "<<tab[i][3]<<endl;
    for(int i=0 ; i<n ; i++){
   	 Q.push_back({tab[i][0] , tab[i][1], tab[i][3], 1});
   	 Q.push_back({tab[i][2] , tab[i][1], tab[i][3], -1});
    }
    sort(Q.begin(), Q.end(), compQ);
   // cout<<endl;
    //for(int i=0 ; i<2*n ; i++)cerr<<Q[i].x<<" "<<Q[i].yg<<" "<<Q[i].yd<<" "<<Q[i].z<<endl;
    for(int i=1 ; i<=19 ; i++){
   	 if(roz>=l+1)break;
   	 else roz=roz*2;
    }
    //cerr<<"roz: "<<roz;
    //cout<<endl;
    create();
    for(int i=0 ; i<2*n ; i++){
   	 //cerr<<Q[i].x<<endl;
   	 update(Q[i].yd , Q[i].yg , Q[i].z, 1, 0);
   	 Q.pop_back();
   	 maxi=max(maxi, tree[1].vmax);
   	 //cerr<<maxi<<endl;
    }
    cout<<maxi;

}
