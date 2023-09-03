#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> S;
	int k;
		bool kolor[n];
	
	for(int i=0 ; i<2*n ; i++){
		cin>>k;
		S.push_back(k);
		if(i<n){
			kolor[i]=false;
		}
	}

	vector<int> D;
	int i=0;
	int x;
	int j;
	int y;
	int s=2*n-1;
	int odp=0;
	vector<int> odpxd;
	while(!S.empty()){
		 x=S[S.size()-1];
		
		 if(kolor[x-1]==false){
		 	kolor[x-1]=true;
		 	S.pop_back();
		 	D.push_back(x);
		 }
		 else{
		 
		 	y=D[D.size()-1];
		 	if(x!=y){
		 		S.push_back(y);
		 		kolor[y-1]=false;
		 		D.pop_back();
		 		swap(S[S.size()-1] ,S[S.size()-2] );
		 		odp++;
		 		odpxd.push_back(S.size()-1);
		 		if(S[S.size()-2]==S[S.size()-3] ){
		 			j=S.size();
		 			S.erase(S.begin()+j- 2);
		 			S.erase(S.begin()+j- 3);
		 			
				 }
			}
			else{
				S.pop_back();
				D.pop_back();
			}
		 }
	}
	cout<<odp<<endl;
	for(int i=0 ; i<odp ; i++){
		cout<<odpxd[i]<<endl;
	}
}