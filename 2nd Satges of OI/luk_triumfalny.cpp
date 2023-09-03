#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >ilosci(300000);
vector<vector<int> >synowie(300000);
void wynik(int robotnicy , int tab[], int n , int szukana , int suma ){
	int szukana1=szukana;
	int suma1=0;
	
	int pom=0;
	int pom1=0;
	int xd;
		if(synowie[szukana1-1][0]!=0){
			for(int j=0 ; j<synowie[szukana1-1].size() ; j++){
				if(synowie[synowie[szukana1-1][j]-1][0]!=0){
					xd=synowie[szukana1-1][j];
					wynik(robotnicy , tab , n , xd , suma1);
					pom++;
					
				}
				suma1=suma1+tab[synowie[szukana1-1][j]-1]+1;
			}
		}
		else{
			tab[szukana1-1]=0;
			pom1++;
		}
		
		if( pom==0){
			
			tab[szukana1-1]=max(0 , suma1-robotnicy);
		}
		else{
			suma1=0;
			for(int i=0 ; i<synowie[szukana1-1].size() ; i++){
				suma1=suma1+tab[synowie[szukana1-1][i]-1]+1;
			}
			tab[szukana1-1]=max(0 , suma1-robotnicy);
		}
	
}
void szukaj(int szukana , int A[] , int B[] , int ojciec){
	int szukana1=szukana;
	int ojciec1=ojciec;
	int xd=0;
	int kappa=0;
//	xd=ilosci[szukana1-1].size();
//	synowie[szukana1-1].push_back(xd);
	for(int i=0 ; i<ilosci[szukana1-1].size() ; i++){
		if(A[ilosci[szukana1-1][i]]!=szukana1 && A[ilosci[szukana1-1][i]]!=ojciec1){
			xd=ilosci[szukana1-1][i];
			kappa++;
			synowie[szukana1-1].push_back(A[xd]);
			szukaj(A[xd] ,  A ,  B , szukana1);
		}
		if(B[ilosci[szukana1-1][i]]!=szukana1 && B[ilosci[szukana1-1][i]]!=ojciec1){
			xd=ilosci[szukana1-1][i];
			kappa++;
			synowie[szukana1-1].push_back(B[xd]);
			szukaj(B[xd] ,  A ,  B , szukana1);
		}
	}
	if(kappa==0){
		synowie[szukana1-1].clear();
		synowie[szukana1-1].push_back(0);
		synowie[szukana1-1][0]=0;
	//	cout<<synowie[szukana1-1][0]<<" "<<szukana1<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	synowie.resize(n);
	ilosci.resize(n);
	
	int a[n];
	int b[n];

	for(int i=0 ; i<n-1 ; i++){
		cin>>a[i];
		cin>>b[i];
		ilosci[a[i]-1].push_back(i);
		ilosci[b[i]-1].push_back(i);
	}
	
//	szukaj(1 , tab , tad);
//	for(int i=0 ; i<n ; i++){
	//	cout<<ilosci[i].size()<<endl;
//	}
	
	szukaj(1 , a , b , n+1);
	
//	for(int i=0 ; i<n ; i++){
	//	for(int j=0 ; j<synowie[i].size() ; j++){
		//	cout<<synowie[i][j]<<" ";
//		}
	//	cout<<endl;
//	}
	int wyn[n];

	for(int i=0 ; i<n ; i++){
		wyn[i]=0;
	}
	
	int sr;
	int l=1;
	int p=n;
	int odp;
	
	if(n==1){
		odp=0;
	}
	else{
		while(l<=p)
	{
		sr = (l + p)/2;
		wynik(sr , wyn , n , 1 , 0);
		if(wyn[0] == 0){
			odp=sr;
			p=sr-1;
		}
		if(wyn[0]>0){
			l=sr+1;
		}
			
		
		memset(wyn, 0, n * sizeof(int));
			
	}
	}
	
	cout<<odp;
	
	
}