#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int a , c;
int n ;
long long k;
int modulo=int(1e9)+7;
struct macierzA{
	int tab[14][1];
};
struct macierzC{
	int tab[14][14];
};
int mnoz(int x, int y){
	return int(x*(long long)(y)%modulo);
}
int dodaj(int x , int y){
	return (int)((x+y)%modulo);
	//return x+y>=modulo?x+y-modulo:x+y;
}
int fun(int x){
	if(x>=0)return x;
	else return modulo+x;
}
long long help;
macierzC mnozM(macierzC C1 , macierzC C2){
	macierzC W;
	for(int i=0 ; i<=n+2 ;i++){
		for(int j=0 ; j<=n+2 ; j++)W.tab[i][j]=0;
	}
	for(int i=0; i<=n+2; ++i){
		for(int d=0; d<=n+2; ++d){
			for(int j=0; j<=n+2; ++j){
				//help=(W.tab[i][j]+mnoz(C1.tab[i][k] , C2.tab[k][j]))%modulo;
		 		W.tab[i][j]=dodaj(W.tab[i][j] , mnoz(C1.tab[i][d] , C2.tab[d][j]));
			}
		}
	}
	return W;
}
macierzC pot(macierzC base, long long power){
	if(power==1)return base;
	if(power%2==0){
		macierzC result=pot(base,power/2);
		return mnozM(result , result);
	}
	else return mnozM(base , pot(base,power-1));
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	macierzA M1;
	macierzC M2;
	cin>>n>>k;
	for(int i=1 ; i<=n ; i++){
		cin>>a;
		a=fun(a);
		M1.tab[n-i][0]=a;
	}
	M1.tab[n][0]=1 , M1.tab[n+1][0]=n , M1.tab[n+2][0]=n*n;
	for(int i=0 ; i<n+3 ; i++){
		cin>>a;
		a=fun(a);
		M2.tab[0][i]=a;
	}
	int q=0;
	for(int i=1 ; i<=n-1 ; i++){
		for(int j=0 ; j<n+3 ; j++){
			if(j==q)M2.tab[i][j]=1;
			else M2.tab[i][j]=0;
		}
		q++;
	}
	for(int i=n ; i<=n+2 ; i++){
		for(int j=0 ; j<n+3 ; j++)M2.tab[i][j]=0;
	}
	M2.tab[n][n]=1 , M2.tab[n+1][n]=1 , M2.tab[n+1][n+1]=1 , M2.tab[n+2][n]=1 , M2.tab[n+2][n+1]=2 , M2.tab[n+2][n+2]=1;
	if(k<=n-1)cout<<M1.tab[n-1-k][0];
	else{
		long long wyk=k-n+1;
		macierzC Wyn=pot(M2 , wyk);
		int ans=0;
		for(int i=0 ; i<n+3 ; i++)ans=dodaj(ans , mnoz(M1.tab[i][0] , Wyn.tab[0][i]));
		cout<<ans;
	}
}