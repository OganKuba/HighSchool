#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long pole(int w1 , int w2 , int k1 , int k2 , vector<vector<long long>> &tab){
	int maxw=max(w1 , w2);
	int maxk=max(k1 , k2);
	int minw=min(w1 , w2);
	int mink=min(k1 , k2);
	long long wyn=0;
	long long pc=tab[maxw][maxk];
	long long p1=0;
	if(mink>1){
		p1=tab[maxw][mink-1];
	}
	long long p2=0;
	if(minw>1){
		p2=tab[minw-1][maxk];
	}
	long long p3=0;
	if(mink>1 && minw>1){
		p3=tab[minw-1][mink-1];
	}
	long long x1=pc-p1;
	long long x2=p3-p2;
	wyn=x1+x2;
	return wyn;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<long long>> tab(1001);
	int w , k , q;
	cin>>w>>k>>q;
	long long a;
	int i;
	int j;
	long long suma;
	for( i=1 ; i<=w ; i++ ){
		tab[i].push_back(0);
		suma=0;
		for( j=1 ; j<=k ; j++){
			cin>>a;
			tab[i].push_back(a);
			suma=suma+tab[i][j];
			if(i>1){
				tab[i][j]=suma+tab[i-1][j];
			}
			else{
				tab[i][j]=suma;
			}
		}
	}
	long long odp;
	int w1 , w2 , k1 , k2;
	for( i=0 ; i<q ; i++){
		cin>>w1>>k1>>w2>>k2;
		odp=pole(w1 , w2 , k1 , k2 , tab);
		cout<<odp<<endl;
	}
	
	
	
}