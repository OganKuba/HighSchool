#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<bool> poz , byl;
vector<int> wiel;
vector<int> bony;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n , m , a;
	cin>>n;
	int maxi=0;
	for(int i=0 ; i<n ; i++){
		cin>>a;
		bony.push_back(a) , maxi=max(maxi , a);
	}
	byl=poz=vector<bool>(maxi+1 , false);
	for(int i=0 ; i<n ; i++){
		poz[bony[i]]=true;
	}
	wiel=vector<int>(1000001 , 0);
	cin>>m;
	int ans=0;
	vector<long long> odp;
	long long ile=0;
	for(int i=0 ; i<m ; i++){
		cin>>a;
		int now;
		if(a<=maxi)now=wiel[a]+a;
		else now=maxi+1;
		int j=1;
		while(now<=maxi && j<=a){
			if(!byl[now]){
				byl[now]=true;
				if(poz[now]){
					ans++;
					odp.push_back(ile+(long long)(j));
				}
				j++;
			}
			if(j<=a)now=now+a;
		}
		if(a<=maxi && now<=maxi)wiel[a]=now;
		else wiel[a]=maxi+1;
		ile=ile+(long long)(a);
	}
	cout<<ans<<endl;
	for(int i=0 ; i<(int)odp.size() ; i++)cout<<odp[i]<<'\n';

}
