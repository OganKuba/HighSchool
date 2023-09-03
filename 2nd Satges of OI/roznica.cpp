#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int roznica(int n , vector<int> &lista ){
	int wynik=0;
	int suma=0;
	int pop=0;
	int mini=100000000;
	int dod=0;
	for(int i=0 ; i<n ; i++){
		
		suma=suma+lista[i];
		if(lista[i]==-1){
			mini=min(mini , pop);
			pop=suma;
		}
		
		wynik=max(wynik , suma - mini);
	}
	return wynik;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	char tab[n];
	vector<vector<int> > pozycje(26);
	int ilosc[26];
	for(int i=0 ; i<26 ; i++){
		ilosc[i]=0;
	}
	for(int i=0 ; i<n ; i++){
		cin>>tab[i];
	
		pozycje[tab[i]-97].push_back(i);
	;
		ilosc[tab[i]-97]++;
	}
	vector<int> lista;
	int zap=0;
	
	int maxi=0;
	int xd=0;
	int k=0;
	int l=0;
	for(int i=0 ; i<26 ;i++){
		if(ilosc[i]>0){
			for(int j=0 ; j<26 ; j++){
				if(ilosc[j]>0 && j!=i){
					do{
						if(k==ilosc[i]){
							lista.push_back(-1);
							l++;
						}
						else{
							if(l==ilosc[j]){
								lista.push_back(1);
								k++;
							}
							else{
								if(pozycje[i][k]<pozycje[j][l] && k<ilosc[i]){
									lista.push_back(1);
									k++;
							
								}
								else{
									lista.push_back(-1);
									if(l<ilosc[j]){
										l++;
									}
								}
							}
						}
						if(k==ilosc[i] && l==ilosc[j]){
								break;
						}
					}while(1==1);
					
					xd=roznica(ilosc[i]+ilosc[j] , lista);
					maxi=max(maxi ,  xd);
					lista.clear();
					zap=0;
					k=0;
					l=0;
				}
				
			
			}
		}
	}
//	for(int i=0 ; i<26 ; i++){
	//	cout<<ilosc[i]<<endl;
	//}
	
	cout<<maxi;
}