#include <bits/stdc++.h>
using namespace std;
struct point{
	bitset<3001> friends;
};
int main(){
	int n , m;
	cin>>n>>m;
	int a , b;
	point tab[n+1];
	int i,j=0;
	for(int i=0 ; i<m ; i++){
		cin>>a>>b;
		tab[b].friends[a]=true;
		tab[a].friends[b]=true;
	}
	bitset<3001> odp;
	long long suma=0;
	long long g=0;
	for( i=1 ; i<=n-1 ; i++){
		for( j=i+1 ; j<=n ; j++){
			if(tab[i].friends[j]==true){
				odp=tab[i].friends&tab[j].friends;
				g=odp.count();
				suma=suma+g;
			}
		}
	}
	long long ans=suma/3;
	cout<<ans;
}