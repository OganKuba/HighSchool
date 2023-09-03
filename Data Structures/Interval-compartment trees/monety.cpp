#include <bits/stdc++.h>
using namespace std;
struct point{
 	int maxi[2] , L[2] , R[2] , dod ,l , p;
};
struct wyn{
	int max0 , l1 , p1 , si;
};
vector<point> tree;
void create(int roz){
	for(int i=0 ; i<2*roz ; i++){
		tree.push_back({0 ,0 , 0 , 0 , 0 , 0 , 0 , 0, 0});
		if(i>=roz)tree[i].L[0]=1 , tree[i].R[0]=1 , tree[i].maxi[0]=1, tree[i].l=i-roz+1, tree[i].p=i-roz+1;
	}
	int i=roz;
	while(i!=1){
		for(int now=i ; now<2*i ; now=now+2){
			tree[now/2].L[0]=2*tree[now].L[0] , tree[now/2].R[0]=2*tree[now+1].R[0] , tree[now/2].l=tree[now].l , tree[now/2].p=tree[now+1].p;
			tree[now/2].L[1]=2*tree[now].L[1] , tree[now/2].R[1]=2*tree[now+1].R[1];
			tree[now/2].maxi[0]=max(tree[now].maxi[0] , max(tree[now+1].maxi[0] , tree[now].R[0]+tree[now+1].L[0]));
			tree[now/2].maxi[1]=max(tree[now].maxi[1] , max(tree[now+1].maxi[1] , tree[now].R[1]+tree[now+1].L[1]));
		}
		i=i/2;
	}
}
void update(int a , int b , int now){
	int s=(tree[now].p-tree[now].l+1)/2;
	if(tree[now].l==a && tree[now].p==b){
		//cerr<<"NOW: "<<now<<endl;
		tree[now].dod=(tree[now].dod+1)%2;
		swap(tree[now].R[0] , tree[now].R[1]);
		swap(tree[now].L[0] , tree[now].L[1]);
		swap(tree[now].maxi[0] , tree[now].maxi[1]);
	}
	else{
		if(b<tree[now].l+s)update(a , b , now*2);
		if(a>=tree[now].l+s)update(a , b , now*2+1);
		if(a<tree[now].l+s && b>=tree[now].l+s){
			update(a , tree[now].l+s-1 , now*2);
			update(tree[now].l+s , b , now*2 + 1);
		}
		int LL0=tree[now*2].L[tree[now].dod];
		int LP0=tree[now*2+1].L[tree[now].dod];
		int PL0=tree[now*2].R[tree[now].dod];
		int PP0=tree[now*2+1].R[tree[now].dod];
		int LL1=tree[now*2].L[(tree[now].dod+1)%2];
		int LP1=tree[now*2+1].L[(tree[now].dod+1)%2];
		int PL1=tree[now*2].R[(tree[now].dod+1)%2];
		int PP1=tree[now*2+1].R[(tree[now].dod+1)%2];
		int MaxL0=tree[now*2].maxi[tree[now].dod];
		int MaxL1=tree[now*2].maxi[(tree[now].dod+1)%2];
		int MaxP0=tree[now*2+1].maxi[tree[now].dod];
		int MaxP1=tree[now*2+1].maxi[(tree[now].dod+1)%2];
		//cerr<<"NOW: "<<now<<endl;
		//cerr<<"maxy: "<<MaxL0<<"    "<<MaxP0<<" ///// "<<MaxL1<<"   "<<MaxP1<<endl;
		//cerr<<"lewy syn: "<<LL0<<"/"<<LL1<<"  "<<PL0<<"/"<<PL1<<"  prawy syn: "<<LP0<<"/"<<LP1<<"  "<<PP0<<"/"<<PP1<<endl;
		//cerr<<"boki: "<<
		///aktualizacja bokow
		tree[now].R[0]=PP0 , tree[now].R[1]=PP1 , tree[now].L[0]=LL0 , tree[now].L[1]=LL1;
		if(MaxL0==s && MaxP0==s)tree[now].maxi[0]=2*s , tree[now].L[0]=2*s , tree[now].R[0]=2*s;//wszytskie zera
		if(MaxL1==s && MaxP1==s)tree[now].maxi[1]=2*s , tree[now].L[1]=2*s , tree[now].R[1]=2*s;//wszytskie jedynki
		if(MaxL0==s && MaxP0!=s)tree[now].L[0]=s+LP0;//wszytskie zera z lewej strony
		if(MaxL0!=s && MaxP0==s)tree[now].R[0]=s+PL0;//wszytskie zera z prawej strony
		if(MaxL1==s && MaxP1!=s)tree[now].L[1]=s+LP1;//wszytskie jedynki z lewej strony
		if(MaxL1!=s && MaxP1==s)tree[now].R[1]=s+PL1;//wszytskie jedynki z prawej strony
		//aktualizacja maximow
		tree[now].maxi[0]=max(MaxL0 , max(MaxP0 , PL0+LP0));
		//cerr<<"suma z krawdzi: "<<PL0+LP0<<endl;
		tree[now].maxi[1]=max(MaxL1 , max(MaxP1 , PL1+LP1));
	}
}
wyn ans(int a, int b , int now , int r){
	int s=(tree[now].p-tree[now].l+1)/2;
	//cerr<<"NOW_S: "<<now<<"   "<<s<<endl;
	if(tree[now].l==a && tree[now].p==b){
		wyn odp;
		if(s!=0)odp={tree[now].maxi[r] , tree[now].L[r] , tree[now].R[r] , s*2};
		else odp={tree[now].maxi[r] , tree[now].L[r] , tree[now].R[r] , 1};
		//cerr<<"now: "<<now<<endl;
		//cerr<<"tu znalazlo wynik: "<<tree[now].maxi[r]<<"   "<<tree[now].L[r]<<"   "<<tree[now].R[r]<<endl;
		return odp;
	}
	else{
		r=(r+tree[now].dod)%2;
		if(b<tree[now].l+s)return ans(a , b , now*2 , r);
		if(a>=tree[now].l+s)return ans(a , b , now*2+1 , r);
		if(a<tree[now].l+s && b>=tree[now].l+s){
			wyn odp1=ans(a , tree[now].l+s-1 , now*2, r);
			wyn odp2=ans(tree[now].l+s , b , now*2 + 1, r);
			//cerr<<"lewy: "<<odp1.l1<<"   "<<odp1.p1<<"  "<<odp1.max0<<"  "<<odp1.si<<endl;
			//cerr<<"prawy: "<<odp2.l1<<"   "<<odp2.p1<<"  "<<odp2.max0<<"  "<<odp2.si<<endl;
			wyn odp0={max(odp1.max0 , max(odp2.max0 , odp1.p1+odp2.l1)) , odp1.l1 , odp2.p1 , odp1.si+odp2.si};
			odp0.l1=odp1.l1 , odp0.p1=odp2.p1;
			if(odp1.max0==odp1.si && odp2.max0==odp2.si)odp0.max0=odp1.si+odp2.si , odp0.l1=odp0.max0 , odp0.p1=odp0.max0;
			if(odp1.max0==odp1.si && odp2.max0!=odp2.si)odp0.l1=odp1.si+odp2.l1;
			if(odp1.max0!=odp1.si && odp2.max0==odp2.si){
				//cerr<<"bylo"<<endl;
				odp0.p1=odp1.p1+odp2.si;
			}
			//cerr<<"now i max:skladanie  "<<now<<" "<<odp0.max0<<endl;
			//cerr<<"BOKI: "<<odp0.l1<<"    "<<odp0.p1<<endl;
			return odp0;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n , q , x1 , x2 , x3;
	cin>>n;
	int m=1;
	while(m<n)m*=2;
	create(m);
	cin>>q;
	//cerr<<endl;
	for(int i=0 ; i<q ; i++){
		//cerr<<"i: "<<i<<endl;
		cin>>x1>>x2>>x3;
		//cerr<<"zap: "<<x2<<"  "<<x3<<endl;
		if(x1==1)update(x2 , x3 , 1);
		else{
			wyn c=ans(x2 , x3 , 1 , 0);
			cout<<c.max0<<'\n';
		}
		//cerr<<endl;
	}
}