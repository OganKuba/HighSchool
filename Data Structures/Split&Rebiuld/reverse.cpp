#include <bits/stdc++.h>
using namespace std;
struct interval{
	int l , r;
};
int n , m , c;
string tex;
vector<interval> tab;
vector<char> text;
void split(int id , int p , int k , int sr){
	//cerr<<"p i k: "<<p<<" "<<k<<"     "<<sr<<endl;
	if(tab[id].l<tab[id].r){
		interval add={tab[id].l+(sr-p)+1, tab[id].r};
		tab[id].r=tab[id].l+(sr-p);
		//cerr<<"dodany1: "<<add.l<<"  "<<add.r<<" zmienniony: "<<tab[id].l-(sr-p)<<endl;
		tab.insert(tab.begin()+id+1 , add);
	}
	else{
		interval add={tab[id].l-(sr-p)-1, tab[id].r};
		tab[id].r=tab[id].l-(sr-p);
		//cerr<<"dodany2: "<<add.l<<"  "<<add.r<<" zmienniony: "<<tab[id].l-(sr-p)<<endl;
		tab.insert(tab.begin()+id+1 , add);
	}
}
void query(int L , int R){
	//cerr<<"query: "<<L<<" "<<R<<endl;
	int roz=0;
	int roz0 , s , e;
	int plus=0;
	//cerr<<"rozmiar tab: "<<tab.size()<<endl;
	if(L!=R){
	for(int i=0 ; i<(int)tab.size() ; i++){
		roz0=roz;
		roz+=abs(tab[i].l-tab[i].r)+1;
		if(roz0<L && L<=roz){
			if(roz0+1!=L){
				split(i , roz0+1 , roz , L-1);
				plus=1;
			}
			//cerr<<"poczatek: "<<i<<endl;
			s=i+plus;
			break;
		}
	}
	roz=0;
	//int plus=0;
	//cerr<<"rozmiar tab: "<<tab.size()<<endl;
	for(int i=0 ; i<(int)tab.size() ; i++){
		//cerr<<"roz: "<<roz<<"   ";
		roz0=roz;
		roz+=abs(tab[i].l-tab[i].r)+1;
		if(roz0<R && R<=roz){
			if(roz!=R)split(i , roz0+1 , roz , R);
			e=i;
			//cerr<<"koniec: "<<i<<endl;
			break;
		}
	}
	int j=0;
	while(s+j!=e-j && s+j<e-j){
		//cerr<<"CHANGE: "<<s+j<<"   "<<e-j<<endl;
		swap(tab[s+j].l , tab[s+j].r);
		swap(tab[e-j].l , tab[e-j].r);
		swap(tab[s+j] , tab[e-j]);
		j++;
	}
	if(s+j==e-j)swap(tab[s+j].l , tab[s+j].r);
	}
	//cerr<<"ERROR"<<endl;
}
void rebuild(){
	//cerr<<"REBUILD: "<<endl;
	int roz=n;
	int roz0;
	vector<char> help;
	help.reserve(n+1);
	while(!tab.empty()){
		//cerr<<"inrebuild"<<endl;
		interval now=tab.back();
		//cerr<<"przedzialy: "<<now.l<<" "<<now.r<<endl;
		tab.pop_back();
		roz0=roz;
		roz-=abs(now.l-now.r)+1;
		int j=0;
		for(int i=roz0  ; i>=roz+1 ; i--){
			if(now.l<now.r){
				help[i]=text[now.r-j];
				//cerr<<"help[i] oraz nowr-j "<<i<<"  "<<now.r-j<<endl;
				//cerr<<"=== "<<text[now.r-j]<<endl;
			}
			else{
				help[i]=text[now.r+j];
				//cerr<<"help[i] oraz nowr+j "<<i<<"  "<<now.r+j<<endl;
				//cerr<<"=== "<<text[now.r+j]<<endl;
			}
			j++;
		}
	}
	int a , b , d;
	d=1;
	for(int i=1 ; i<=n ; i++){
		text[i]=help[i];
		if(d==1)a=i;
		if(d==c){
			b=i;
			tab.push_back({a , b});
			d=1;
		}
		else{
			d++;
			if(i==n){
				b=i;
				tab.push_back({a , b});
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	cin>>tex;
	c=(int)(sqrt(n));
	int d , a , b;
	d=1;
	text.push_back(0);
	for(int i=0 ; i<n ; i++){
		//cerr<<"i: "<<i<<endl;
		if(d==1)a=i+1;
		if(d==c){
			b=i+1;
			tab.push_back({a , b});
			//cerr<<"start dodany: "<<a<<"   "<<b<<endl;
			d=1;
		}
		else{
			d++;
			if(i==n-1){
				b=i+1;
				tab.push_back({a , b});
				//cerr<<"start dodany: "<<a<<"   "<<b<<endl;
			}
		}
		text.push_back(tex[i]);
	}
	d=1;
	//cerr<<"C: "<<c;
	while(m>0){
		//cerr<<"m: "<<m<<endl;
		cin>>a>>b;
		if(d==c){
			query(a , b);
			rebuild();
			d=1;
		}
		else{ d++ , query(a , b); }
		m--;
	}
	rebuild();
	for(int i=1 ; i<=n ; i++){
		cout<<text[i];
	}
}