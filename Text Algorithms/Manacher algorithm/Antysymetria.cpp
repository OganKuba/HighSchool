#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
//	n=500000;
	char S[n];
	
	for(int i=1 ; i<=n ; i++){
		cin>>S[i];
	}
	int R[n+2];
	int t=0;
	int i=1;
	R[0]=0;
	while(i<=n){
		while(S[i-t]!=S[i+t+1] && i>t && i+t+1<=n){
			t++;
		}
		R[i]=t;
		int k=1;
		while(k<=t && R[i-k]!=R[i]-k){
			R[i + k] = min(R[i-k],(R[i]-k));
			k++;
			
		}
		t-=k;
		t=max(0,t);
		i+=k;
	}
	long long suma=0;
	for(int i=1 ; i<n ; i++){
		suma=suma+R[i];
	}
	cout<<suma;
	
	
}