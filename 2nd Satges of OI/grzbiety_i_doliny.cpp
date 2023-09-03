#include <bits/stdc++.h>
using namespace std;
vector<int> tab;
vector<bool> tab1 , tab2;
int n , a;
bool DFS_dol(int s){
	list<int> Q;
	Q.push_back(s);
	bool ans=true;
	tab1[s]=true;
	while(!Q.empty()){
		int now=Q.front();
		int i=now/n;
		int j=now%n;
		for(int x=-1 ; x<=1 ; x++){
			for(int y=-1 ; y<=1 ; y++){
				if(i+x>=0 && i+x<n && j+y>=0 && j+y<n && (x!=0 || y!=0)){
					if(tab1[(i+x)*n+j+y]==false && tab[now]==tab[(i+x)*n+j+y]){
						Q.push_back((i+x)*n+j+y);
						tab1[(i+x)*n+j+y]=true;
					}
					if(tab[now]>tab[(i+x)*n+j+y])ans=false;
				}
			}
		}
		Q.pop_front();
	}
	return ans;
}
bool DFS_gora(int s){
	list<int> Q;
	Q.push_back(s);
	tab2[s]=true;
	bool ans=true;
	while(!Q.empty()){
		int now=Q.front();
		int i=now/n;
		int j=now%n;
		for(int x=-1 ; x<=1 ; x++){
			for(int y=-1 ; y<=1 ; y++){
				if(i+x>=0 && i+x<n && j+y>=0 && j+y<n && (x!=0 || y!=0)){
					if(tab2[(i+x)*n+j+y]==false && tab[now]==tab[(i+x)*n+j+y]){
						Q.push_back((i+x)*n+j+y);
						tab2[(i+x)*n+j+y]=true;
					}
					if(tab[now]<tab[(i+x)*n+j+y])ans=false;
				}
			}
		}
		Q.pop_front();
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			cin>>a;
			tab.push_back(a);
		}
	}
	int dol , gora;
	dol=gora=0;
	tab1=tab2=vector<bool>(n*n , false);
	//cerr<<"XD: "<<endl;
	for(int i=0 ; i<n*n ; i++){
		if(tab1[i]==false){
			if(DFS_dol(i)==true)dol++;
		}
	}
	for(int i=0 ; i<n*n ; i++){
		if(tab2[i]==false){
			//cerr<<"weszlo: "<<i<<endl;
			if(DFS_gora(i)==true)gora++;
		}
	}
	cout<<gora<<" "<<dol;

}