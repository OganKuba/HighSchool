#include <bits/stdc++.h>
using namespace std;
int n , k , a;
struct val{
	int v , id , P;
};
vector<vector<int> > tab(1);
vector<vector<val> > DP(1);
vector<int> ciag;
int add , minus;
int pole(int x1 , int y1 , int x2 , int y2){
	long long Pc=(long long)(tab[y2][x2]);
	long long P1=(long long)(tab[y1-1][x1-1]);
	long long P2=(long long)(tab[y1-1][x2]);
	long long P3=(long long)(tab[y2][x1-1]);
	long long wyn=Pc+P1-P2-P3;
	return (int)(wyn);
}
void ans(int s , int ile){
	for(int i=s ; i<=n-ile ; i++){
		if(DP[s][ile].v<DP[i+1][ile-1].v+pole(i+1 , s , n , i)){
			DP[s][ile].id=i;
			DP[s][ile].P=pole(i+1 , s , n , i);
			DP[s][ile].v=DP[i+1][ile-1].v+pole(i+1 , s , n , i);
			//cerr<<s<<"  "<<i<<" val: "<<DP[s][ile].v<<"   "<<pole(i+1 , s , n , i)<<endl;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	tab.resize(n+1);
	DP.resize(n+1);
	for(int i=0 ; i<=n ; i++){
		tab[i]=vector<int>(n+1 , 0);
		DP[i]=vector<val>(k+1 , {0 , 0 , 0});
	}
	//vector<bool> 
	//cerr<<"XD";
	for(int i=1 ; i<n ; i++){
		for(int j=i+1 ; j<=n ; j++){
			cin>>a;
			tab[i][j]=a;
		}
	}
	//cerr<<"XD";
	for(int i=0 ; i<=n ; i++){
		int suma=0;
		for(int j=0 ; j<=n ; j++){
			suma+=tab[i][j];
			if(i==0)tab[i][j]=suma;
			else tab[i][j]=suma+tab[i-1][j];
			//cout<<tab[i][j]<<" ";
		}
		//cout<<endl;
	}
	//cerr<<"XD";
	for(int ile=1 ; ile<=k ; ile++){
		for(int s=n-1 ; s>=1 ; s--){
			ans(s , ile);
		}
		//cerr<<endl;
	}
	vector<bool> byl=vector<bool>(n+1 , false);
	vector<int> ciag;
	//cout<<DP[1][k].id<<" ";
	ciag.push_back(DP[1][k].id);
	byl[DP[1][k].id]=true;
	int A=DP[1][k].v-DP[1][k].P;
	int q=1;
	int licz=1;
	for(int i=k-1 ; i>=1 ; i--){
		for(int j=1 ; j<=n-1 ; j++){
			if(DP[j][i].v==A){
				byl[DP[j][i].id]=true;
				if(DP[j][i].id!=0)ciag.push_back(DP[j][i].id);
				else{
					for(int l=q ; l<=n ; l++){
						if(byl[l]==false){
							byl[l]=true;
							q=l;
							ciag.push_back(q);
							break;
						}
					}
				}
				A-=DP[j][i].P;
				licz++;
				break;
			}
		}
	}
	sort(ciag.begin() , ciag.end());
	for(int i=0 ; i<k ; i++)cout<<ciag[i]<<" ";
	//cout<<endl;
	//cout<<licz;

}