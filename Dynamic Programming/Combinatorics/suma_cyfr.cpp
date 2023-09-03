#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int s , m , q;
int potegi[201];
long long ustal(int x1 , int x2 , int w){
   	 x1=(x1*potegi[w-1])%m;
     x2+=m*1000000;
     int wyn=(x2-x1)%m;
     return wyn;
     
}
long long ustal2(int r , int c1 , int w){
	c1=(c1*potegi[w-1])%m;
	int m1=m*1000000;
	int wyn=(m1-((r+c1)%m))%m;
	return wyn;
}
vector< vector< vector<long long> > > DP(201, vector< vector<long long> >(201 , vector<long long>(201, 0)));
void ans(long long k){
    vector <int> wynik;
    int reszta=0;
    int suma=0;
    int endf=0;
    int e2=0;
     int pocz=0;
    for(int i=200; i>0; i--){
    	if(endf!=0)break;
    	if(k<=0){
    		while(i>0){
    			i--;
    			wynik.push_back(0);
			}
    		break;
		}
   	 for(int c=0; c<=9; c++){
   	 	if(s-suma-c<0){
   	 		endf++;
   	 		break;
		}
   		 long long dokoncz=min(DP[i-1][s-suma-c][ustal2(reszta, c, i)], k+1);
   		 if (dokoncz>=k){
   			 wynik.push_back(c);
   			 reszta+=(c*potegi[i-1])%m;
   			 reszta=reszta%m;
   			 suma+=c;
   			 break;
   		 }
   		 else k-=dokoncz;
   		 }
    }
    if(pocz==(int)wynik.size()-1 || (int)wynik.size()==0 || endf!=0)cout<<"NIE"<<endl;
    else{
    	while(wynik[pocz]==0)pocz++;
    	for (int i=pocz; i<(int)wynik.size(); ++i)cout<<wynik[i];
    		cout<<endl;
    }
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s>>m>>q;
    DP[0][0][0]=1;
    int x=10%m;
    potegi[0]=1%m;
    int val=1;
    for(int i=1 ; i<=200 ; i++){
    	potegi[i]=(potegi[i-1]*x)%m;
	}
    for(int i=0 ; i<=9 ; i++)if(i<=s)DP[1][i][i%m]++;
    for(int i=2 ; i<=200 ; i++){
   	 for(int j=0 ; j<m ; j++){
   		 for(int k=0 ; k<=s ; k++){
   			 for(int l=0 ; l<=min(9 , s); l++){
   				 if(k-l>=0){
					DP[i][k][j]+=DP[i-1][k-l][ustal(l, j, i)];
					DP[i][k][j]=min(DP[i][k][j] , 1000000000000000001);
					}
   				 else break;
   				 //if(DP[i][k][j]<0)cout<<i<<endl;
   			 }
   		 }
   	 }
    }
   // cout<<endl;
    //for(int i=1 ; i<=200 ; i++)cout<<DP[i][s][0]<<" ";
    //cout<<endl;
    long long  p;
    for(int i=0 ; i<q ; i++){
   	 cin>>p;
   	 ans(p);
    }
}
