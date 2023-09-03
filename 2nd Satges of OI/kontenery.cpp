#include <bits/stdc++.h>
using namespace std;
vector<int> odp;
int j;
int i;
int y;
int x;
struct que{
	int a , l , d;
};
bool porownaj(que a, que b){
    if (a.d < b.d)
        return true;
    else
        return false;
}
void dodaj( int n , int pocz , int d , int l){
	 j=0;
	for( x=pocz ; x<=n ; x=x+d){
		odp[x]++;
		j++;
		if(j==l){
			break;
		}
	}
}
void prefixy(int p[] , int d , int n ){
	for( y=1 ; y<=d ; y++){
		odp[y]=odp[y]+p[y];
	}
	for( y=d+1 ; y<=n ; y++){
		p[y]=p[y]+p[y-d];
		p[y-d]=0;
		odp[y]=odp[y]+p[y];
		if(y>n-d){
			p[y]=0;
		}
	}
	
}
int main(){
	int n;
	int k;
	cin>>n>>k;
	int p[n+1];
	que tab[k];
	
	for( i=0 ; i<k ; i++){
		cin>>tab[i].a>>tab[i].l>>tab[i].d;
	}
	for( i=0 ; i<n+1 ; i++){
		odp.push_back(0);
		p[i]=0;
	}
	sort(tab, tab + k, porownaj);
	int D=tab[0].d;
	int pop=0;
	for( i=0 ; i<k ; i++){
		if(tab[i].d<sqrt(n)){
			pop++;
			if(tab[i].d==D){
				p[tab[i].a]++;
				if(tab[i].a+(tab[i].d*tab[i].l)<=n){
					p[tab[i].a+(tab[i].d*tab[i].l)]--;
				}
				if(i==k-1){
					prefixy(p , D , n);
				}
			}
			else{
				prefixy(p , D , n);
				D=tab[i].d;
				p[tab[i].a]++;
				if(tab[i].a+(tab[i].d*tab[i].l)<=n){
					p[tab[i].a+(tab[i].d*tab[i].l)]--;
				}
				if(i==k-1){
					prefixy(p , D , n);
				}
			}
		}
		else{
			if(pop>0){
				prefixy(p , D , n);
			}
			dodaj( n , tab[i].a , tab[i].d , tab[i].l);
			pop=0;
		}
	}
	for( i=1 ; i<=n ; i++){
		cout<<odp[i]<<" ";
	}
	
}