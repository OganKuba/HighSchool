#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n , k, a;
vector<int> N;
vector<int> K;
vector<int> prefix;
struct c{
    int v;
    int p;
};
vector<c> dp;
int newp(int l, int war){
    int r=k-1;
    int sr;
    int y1, y2;
    int l1=l;
    //cout<<"NEW"<<endl;
    while(l<=r){
   	 sr=(l+r)/2;
   	 //if(war==15)cout<<sr<<" ";
   	 if(l1==0)y1=prefix[sr];
   	 else y1=prefix[sr]-prefix[l1-1];
   	 if((y1<=war && sr!=k-1 && y1+K[sr+1]>war) || (sr==k-1 && y1<=war))return sr;
   	 else{
   		 if(y1>war)r=sr-1;
   		 else l=sr+1;
   	 }
    }
    return -1;
}
void count(int i){
    int h;
    for(int j=0 ; j<n ; j++){
   	 if(i&(1<<j)){
   		 if(dp[i^(1<<j)].p==k-1){
   			 dp[i].v=max(dp[i^(1<<j)].v+N[j], dp[i].v);
   			 dp[i].p=k-1;
   		 }
   		 else{
   			 if(dp[i].p!=k-1){
   				 h=newp(dp[i^(1<<j)].p+1, N[j]);
   				 if(h!=-1){
   					 dp[i].p=max(dp[i].p , h);
   				 }
   			 }
   		 }
   	 }
    }
}
int pot;
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
     pot=(int)pow(2 , n);
    for(int i=0 ; i<n ; i++){
   	 cin>>a;
   	 N.push_back(a);
    }
    for(int i=0 ; i<k ; i++){
   	 cin>>a;
   	 K.push_back(a);
   	 if(i==0)prefix.push_back(a);
   	 else prefix.push_back(prefix[i-1]+a);
    }
    for(int i=0 ; i<=pot-1; i++)dp.push_back({0 , -1});
    //for(int i=0 ; i<pot-1 ; i++)cout<<dp[i].p<<endl;
    for(int m=0; m<=pot-1 ; m++){
		count(m);
	}
	if(dp[pot-1].p==k-1)cout<<dp[pot-1].v;
	else cout<<-1;
}
