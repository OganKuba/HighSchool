#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct war{
	int val , nr;
};
int n;
vector<vector<int> > friends(1);
vector<war> Tab1;
vector<int> Tab2 , W , ojciec;
vector<long long> Suma , wyn;
int licz=0;
long long odc=0;
void Count1(int now , int last , int d){
	//cerr<<"c1: "<<now<<endl;
	int licz0=licz;
	odc+=(long long)(d);
	long long odc0=odc;
	licz++;
	for(int i=0 ; i<(int)friends[now].size() ; i++){
		int v=friends[now][i];
		if(v!=last){
			ojciec[v]=now;
			Count1(v , now , d+1);
			if(Tab1[now].val<Tab1[v].val+1)Tab1[now]={Tab1[v].val+1 , Tab1[v].nr};
		}
	}
	W[now]=licz-licz0;
	Suma[now]=odc-odc0-(long long)((long long)((W[now]-1))*(long long)(d));
}
void Count2(int now){
	if(now!=1){
		int anc=ojciec[now];
		for(int i=0 ; i<(int)friends[anc].size() ; i++){
			int v=friends[anc][i];
			if(v!=now && ojciec[anc]!=v)Tab2[now]=max(Tab2[now] , Tab1[v].val+2);
		}
		Tab2[now]=max(Tab2[now] , Tab2[anc]+1);
	}
	for(int i=0 ; i<(int)friends[now].size() ; i++)if(friends[now][i]!=ojciec[now])Count2(friends[now][i]);
}
int findthis(int x , int xd){
	//int maxib=0;
	//cerr<<"findthis: ";
	if(xd==ojciec[x]){
		//cerr<<x<<" "<<Tab2[x]<<endl;
		return Tab2[x];
	}
	//cerr<<x<<" "<<Tab1[xd].val+1<<endl;
	return Tab1[xd].val+1;
	
}
void Wynik(int now , long long gora){
	war lider={0 , 0};
	//int najws=0;
	//bool najw1=true;
	//bool najw2=false;
	int sum=0;
	long long add=0;
	long long D=Suma[now]+gora;
	//cerr<<"now , suma , gora:  "<<now<<" "<<Suma[now]<<" "<<gora<<endl;
	for(int i=0 ; i<(int)friends[now].size() ; i++){
		int v=friends[now][i];
		if(v!=ojciec[now]){
			if(W[v]>lider.val){
				lider.nr=v;
				lider.val=W[v];
			}
			sum+=W[v];
			add+=(long long)(Suma[v])+(long long)(W[v]);
		}
	}
	if(lider.val<n-1-sum){
		lider.val=n-1-sum;
		lider.nr=ojciec[now];
	}
	if((n-1)%2==0){
		//cerr<<"wyn: "<<max(Tab1[now].val , Tab2[now]);
		if(lider.val<=(n-1)/2)wyn[now]=2*D-(long long)(max(Tab1[now].val , Tab2[now]));
		else wyn[now]=-1;
	}
	else{
		//cerr<<now<<" "<<lider.val<<endl;
		if(lider.val<=n/2){
			if(lider.val==n/2)wyn[now]=2*D-(long long)(findthis(now , lider.nr));
			else wyn[now]=2*D-(long long)(max(Tab1[now].val , Tab2[now]));
		}
		else wyn[now]=-1;
	}
	for(int i=0 ; i<(int)friends[now].size() ; i++){
		int v=friends[now][i];
		if(v!=ojciec[now]){
			//cout<<"add: "<<add<<endl;
			Wynik(v , gora+add-(long long)(Suma[v])-(long long)(W[v])+(long long)(n)-(long long)(W[v]));
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int  a , b;
	cin>>n;
	friends.resize(n+1);
	for(int i=0 ; i<=n ; i++){
		if(i<n-1){
			cin>>a>>b;
			friends[a].push_back(b);
			friends[b].push_back(a);
		}
		Tab1.push_back({0 , i});
		Tab2.push_back(0);
		W.push_back(0);
		Suma.push_back(0);
		ojciec.push_back(0);
		wyn.push_back(0);
	}
	//cerr<<endl;
	Count1(1 ,1 , 0);
	//for(int i=1 ; i<=n ; i++)cerr<<W[i]<<" "<<Suma[i]<<endl;
	Count2(1);
	//for(int i=1 ; i<=n ; i++)cerr<<Tab2[i]<<endl;
	Wynik(1 , 0);
	for(int i=1 ; i<=n ; i++)cout<<wyn[i]<<'\n';
}