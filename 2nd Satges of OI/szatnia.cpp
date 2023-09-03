#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct val{
	int t , id , r;
};
struct que{
	int p , k , war;
};
vector<val> czas;
vector<que> tab1 , tab2;
int n , m , a, b , c;
bool comptime(val x , val y){
	if(x.t!=y.t)return x.t<y.t;
	else return x.r<y.r;
};
vector<int> date;
int kmax=0;
void dodaj(int d , int cena){
	for(int i=kmax ; i>=cena ; i--){
		//cerr<<"i: "<<i<<"   "<<date[i]<<"   "<<date[i-cena]<<endl;
		date[i]=max(date[i] , min(d , date[i-cena]));
		//cerr<<"i: "<<i<<" wartosc:  "<<date[i]<<endl;
	}
	date[cena]=max(date[cena] , d);
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	for(int i=0 ; i<n; i++){
		cin>>c>>a>>b;
		tab1.push_back({a , b , c});
		kmax=max(kmax , c);
		czas.push_back({a , i , 0});
	}
	cin>>m;
	for(int i=0 ; i<m; i++){
		cin>>a>>b>>c;
		kmax=max(kmax , b);
		tab2.push_back({a , a+c+1 , b});
		czas.push_back({a , i , 1});
	}
	vector<bool> wyn = vector<bool>(m , false);
	date = vector<int>(kmax+1 , 0);
	sort(czas.begin() , czas.end() , comptime);
	//cerr<<"xd: "<<date[7]<<endl;
	for(int i=0 ; i<(int)czas.size() ; i++){
		val now=czas[i];
		//cerr<<"now: "<<now.id<<"   "<<now.r<<endl;
		if(now.r==0){
			//cerr<<"dodaj: "<<tab1[now.id].k<<"   "<<tab1[now.id].war<<endl;
			dodaj(tab1[now.id].k  , tab1[now.id].war);
		}
		else{
			//cerr<<"check: "<<date[tab2[now.id].war]<<"   "<<tab2[now.id].k<<endl;
			wyn[now.id]=bool(date[tab2[now.id].war]>=tab2[now.id].k);
		}
	}
	for(int i=0 ; i<m ; i++){
		if(wyn[i]==true)cout<<"TAK"<<endl;
		else cout<<"NIE"<<endl;
	}
}