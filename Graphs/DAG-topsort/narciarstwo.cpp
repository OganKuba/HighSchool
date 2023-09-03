#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n , m , i , a , b , j;
struct point{
	long long h , nr;
};
long long dodaj(long long r , long long p , long long mod){
	return (r+p)%mod;
}
bool compare(point r , point p){
	if(r.h>p.h){
		return true;
	}
	else{
		return false;
	}
}
vector<vector<long long> > IN(500000);
vector<long long> H;
vector<point> H2;
vector<long long> VAL;
long long suma;
int main(){\
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	H.push_back(0);
	H2.push_back(point());
	H2[0].h=0;
	H2[0].nr=0;
	VAL.push_back(0);
	for(i=1 ; i<=n ; i++){
		cin>>a;
		H.push_back(a);
		H2.push_back(point());
		H2[i].h=a;
		H2[i].nr=i;
		VAL.push_back(0);
	}
	for(i=0 ; i<m ; i++){
		cin>>a>>b;
		if(H[a]>H[b]){
			IN[b].push_back(a);
		}
		else{
			IN[a].push_back(b);	
		}
	}
	//for(i=1 ; i<=n ; i++){
	//	cout<<i<<": ";
	//	for(j=0 ; j<(int)IN[i].size() ; j++){
	//		cout<<IN[i][j]<<" ";
	//	}
	//	cout<<endl;
//	}
	long long y , t;
	sort(H2.begin() , H2.end() , compare);
	//for(i=0 ; i<n ; i++){
	//	cout<<H2[i].h<<" ";
	//}
	for(i=0 ; i<n ; i++){
		t=H2[i].nr;
		if((int)IN[t].size()>0){
			for(j=0 ; j<(int)IN[t].size() ; j++){
				y=IN[t][j];
				suma=dodaj(suma , VAL[y]+1 , 1098219877);
			}
			VAL[t]=suma;
		}
		suma=0;
	}
	for(i=1; i<=n ; i++){
		suma=dodaj(suma , VAL[i] , 1098219877);
	}
	cout<<suma%1098219877;
	
}