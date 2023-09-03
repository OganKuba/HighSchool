#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int i , j , k , l ,n , m  ,a , b; 
string q;
vector<int> odw;
vector<int> partner;
vector<bool> V;
int nr=0;
void dodaj(int v , int s , vector<vector< int > > &synowie){
	if(V[s]!=false){
		synowie[v].push_back(s);
	}
}
void wierz(int kol , int ver ,vector<vector<int> > &synowie){
	for(a=kol-1 ; a<=kol+1 ; a++){
		if(a>=0 && a<=n-1 && a!=kol){
			dodaj(kol*m + ver , a*m + ver, synowie);
		}
	}
	for(a=ver-1 ; a<=ver+1 ; a++){
		if(a>=0 && a<=m-1 && a!=ver){
			dodaj(kol*m + ver , kol*m +a, synowie);
		}
	}
}
bool Match(int os , vector<vector<int> > &synowie){
	odw[os]=nr;
	for(int i=0 ; i<(int)synowie[os].size() ; i++){
		if(partner[synowie[os][i]]==-1){
			partner[synowie[os][i]]=os;
			partner[os]=synowie[os][i];
			return true;
		}
	}
	for(int i=0 ; i<(int)synowie[os].size() ; i++){
		if(odw[partner[synowie[os][i]]]!=nr && Match(partner[synowie[os][i]] , synowie)==true){
			partner[synowie[os][i]]=os;
			partner[os]=synowie[os][i];
			return true;
		}
	}
	return false;
}
int nie=0;
bool w;
bool ROB(vector<vector<int> > &synowie){
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<m ; j++){
			if(V[i*m + j]==true){
				wierz(i , j , synowie);
			}
		}
	}
	//cout<<endl;
	///	for(i=0 ; i<n*m ; i++){
	//	cout<<i<<": ";
	//	for(j=0 ; j<(int)synowie[i].size() ; j++){
	//		cout<<synowie[i][j]<<" ";
	//	}
	//	cout<<endl;
//	}
	for( j=0 ; j<n*m ; j++){
		if(V[j]==true && partner[j]==-1){
			Match(j , synowie);
			if(partner[j]==-1){
				nie++;
				break;
			}
		}
		nr++;
	}
	if(nie==0){
		return true;
	}
	else{
		return false;
	}	
	
	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int que;
	cin>>que;
	vector<vector<int> > synowie;
	for(int z=0 ; z<que ; z++){
		cin>>n>>m;
		synowie.resize(n*m + 1);
		
		for(i=0 ; i<n ; i++){
				cin>>q;
			for(j=0 ; j<m ; j++){
				if(q[j]=='.'){
					V.push_back(true);
				}
				else{
					V.push_back(false);
				}
				odw.push_back(-1);
				partner.push_back(-1);
			}
		}
		if(ROB(synowie)==true){
			cout<<"TAK"<<endl;
		}
		else{
			cout<<"NIE"<<endl;
		}
		V.clear();
		odw.clear();
		synowie.clear();
		partner.clear();
		nr=0;
		nie=0;
	}
}