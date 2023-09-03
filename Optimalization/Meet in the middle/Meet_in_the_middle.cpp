#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<long long> wyn1;
vector<long long> wyn2;
int i=0;
int maxi=0;
int u;
void perm(int poz , int k , long long tab[] , long long suma , int kappa , int m , int i){
	for(i=poz ; i<=k ; i++){
		suma=suma+tab[i];
		if(kappa==1){
			wyn1.push_back(suma%m);
		}
		else{
			wyn2.push_back(suma%m);
		}
		u=suma%m;
		maxi=max(maxi , u);
		if(i<k){
			perm(i+1 , k , tab , suma ,kappa ,  m , i);
		}
		suma=suma-tab[i];
	}
}
int bin(int s1 , int s2 , int m){
	int xd;
	int max_suma=0;
	int l;
	int p;
	int sr;
	int rep;
	for( i=0 ; i<s1 ; i++){
		xd=wyn1[i];
		l=0;
		p=s2-1;
		while(l<=p){
			sr=(l+p)/2;
			rep=(wyn2[sr]+xd)%m;
			max_suma=max(max_suma , rep );
			if(wyn2[sr]+xd==m-1){
				return m-1;
			}
			if(wyn2[sr]+xd>=m){
				p=sr-1;
			}
			if(wyn2[sr]+xd<m){
				l=sr+1;
			}
		}
		rep= (wyn2[s2-1]+xd)%m;
		max_suma=max(max_suma , rep);
	}
	return max_suma;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	long long tab[n];
	for( i=0 ; i<n ; i++){
		cin>>tab[i];
	}
	perm(0 , (n/2)-1 ,tab ,  0 , 1 , m , i);
	perm((n/2) , n-1 , tab , 0 , 2 , m , i);
	int s1=wyn1.size();
	int s2=wyn2.size();
	sort(wyn2.begin() , wyn2.end());
//	for(int i=0 ; i<s1 ; i++){
	//	cout<<wyn1[i]<<" ";
//	}
	//cout<<endl;
	//for(int i=0 ; i<s2 ; i++){
	//	cout<<wyn2[i]<<" ";
//	}
//	cout<<endl;
	int odp=bin(s1 , s2 , m);
	odp=max(odp , maxi);
	cout<<odp;
}