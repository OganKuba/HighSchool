#include <bits/stdc++.h>
using namespace std;
int i , j ,v, zap , teraz;
string tekst;
bool KMP(int n , int m  , int R[] , int P[]){
	 j=0;
	 zap=R[n];
	 R[n]=P[n];
	 teraz=0;
	 //cout<<n<<endl;
	 //for( i=0 ; i<=n ; i++){
	//	cout<<i<<": "<<R[i]<<endl;
	//}
	//cout<<"-----------"<<endl;
	for( i=1 ; i<=m ; i++){
		teraz++;
		while(j>-1 && tekst[j+1]!=tekst[i]){
			j=R[j];
		}
		j++;
		if(j==n){
			if(teraz-n>0){
				return false;
			}
			if(teraz-n<=0){
				teraz=0;
			}
			j=R[n];
		}
		else{
			//cout<<0<<" ";
		}
	}
	R[n]=zap;
	return true;
}
int main(){
	cin>>tekst;
	int l=tekst.size();
	tekst.insert(0 , "#");
	int rozne=0;
	tekst.push_back(0);
	for(i=1 ; i<l ; i++){
		if(tekst[i]!=tekst[i+1]){
			rozne++;
		}
	}
	int dl=1;
	int P[l+1];
	int R[l+1];
	P[0]=-1;
	R[0]=-1;
	
	int prefiks=-1;
	for( i=1;i<=l;i++){
		while (prefiks >=0 && tekst[prefiks + 1] != tekst[i]) prefiks = P[prefiks];
		//if (s[prefiks + 1] == s[i]) prefiks++;
		prefiks++;
		P[i] = prefiks;
		if(i<l){
			if(tekst[P[i]+1]!=tekst[i+1]){
				R[i]=P[i];
			}
			else{
				R[i]=R[prefiks];
			}
		}
		else{
			R[i]=P[i];
		}
	}
	//for(int i=0 ; i<=l ; i++){
	//	cout<<i<<": "<<R[i]<<endl;
	//}
	int y=l;
	int minpre=l;
	vector<int> pre;
	if(rozne==0){
		pre.push_back(1);
	}
	while(y>1){
		prefiks=P[y];
		if(prefiks>1){
			pre.push_back(prefiks);
		}
		y=prefiks;
	}
	pre.push_back(l);
	sort(pre.begin() , pre.end());
	dl=0;
	for(v=0 ; v<pre.size() ; v++){
		if(pre[v]>=dl){
			if(KMP(pre[v] , l , R , P)==true){
				cout<<pre[v];
				break;
			}
			else{
				dl=pre[v]*2;
			}
		}
	}
}