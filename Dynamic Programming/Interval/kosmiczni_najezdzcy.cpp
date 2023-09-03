#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> A,B,C, skala;
int n , j ,a , b ,c , l , k , w ;
int suma=0;
int maxi=0;
set<int>  Q;
vector<vector<int> > TAB(701);
set<int>::iterator iter;
int inf=1000000000;
int najw(int p , int k){
	w=-1;
	maxi=0;
	for( j=0 ; j<n ; j++){
		if(A[j]>=p && k>=B[j]){
			if(maxi<C[j]){
				maxi=C[j];
				w=j;
			}
		}
	}
	return w;
}
int Get(int p , int k){
	if(p<=k){
		return TAB[p][k];
	}
	else{
		return 0;
	}
}
int r=1;
void skaluj(){
	int val , f , g;
	while(!Q.empty()){
		iter=Q.begin();
		val=(*(iter));
		skala[val]=r;
		r++;
		Q.erase(Q.begin());
	}
	for(int i=0 ; i<n ; i++){
		f=A[i];
		g=B[i];
		A[i]=skala[f];
		B[i]=skala[g];
	}
}
void tworz(){
	for(int d=1 ; d<=r ; d++){
		for(int pocz=1 ; pocz+d-1<=r ; pocz++){
			int kon=pocz+d-1;
			int big=najw(pocz , kon);
			if(big==-1){
				TAB[pocz][kon]=0;
			}
			else{
				TAB[pocz][kon]=inf;
				for(int z=A[big] ; z<=B[big] ; z++){
					l=Get(pocz , z-1);
					k=Get(z+1 , kon);
					suma=l+k+C[big];
					TAB[pocz][kon]=min(TAB[pocz][kon] , suma);
					suma=0;
				}
				//cout<<pocz<<" "<<kon<<" "<<TAB[pocz][kon]<<endl;
			}
		}
	}	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	
	for(int i=0 ; i<n ; i++){
		cin>>a>>b>>c;
		A.push_back(a);
		B.push_back(b);
		Q.insert(a);
		Q.insert(b);
		C.push_back(c);
	}
	for(int i=0 ; i<=10000 ; i++){
		skala.push_back(0);
	}
	int m;
	for(int i=0 ; i<=700; i++){
		for(m=0 ; m<=700 ; m++){
			TAB[i].push_back(0);
		}
	}
	
	skaluj();
	r--;
	tworz();
	cout<<TAB[1][r];
}