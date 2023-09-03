#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct vex{
	int L_ile , R_ile , L , R;
};
int numer=1;
void add(int deep , int val , int nr , vector<vex> &trie){
	for(int i=deep-1 ; i>=0 ; i--){
		//cerr<<"nr: "<<nr<<endl;
		if(val&(1<<i)){
			trie[nr].R_ile++;
			if(trie[nr].R==-1){
				trie[nr].R=numer;
				trie.push_back({0 , 0 , -1 , -1});
				numer++;
			}
			nr=trie[nr].R;
		}
		else{
			trie[nr].L_ile++;
			if(trie[nr].L==-1){
				trie[nr].L=numer;
				trie.push_back({0 , 0 , -1 , -1});
				numer++;
			}
			nr=trie[nr].L;
		}
	}
}
long long count(int deep , int val , int nr , vector<vex> &trie , int comp){
	long long suma=0;
	for(int i=deep-1 ; i>=0 ; i--){
		//cerr<<"NR: "<<nr<<endl;
		int C=comp&(1<<i);
		int V=val&(1<<i);
		if(C){
			if(V){
				suma+=(long long)(trie[nr].R_ile);
				nr=trie[nr].L;
			}
			else{
				suma+=(long long)(trie[nr].L_ile);
				nr=trie[nr].R;
			}
			if(nr==-1)break;
		}
		else{
			if(V)nr=trie[nr].R;
			else nr=trie[nr].L;
			if(nr==-1)break;
		}
	}
	return suma;
}
void DO(){
	vector<vex> trie;
	int n , k;
	cin>>n>>k;
	int XOR , a;
	long long wyn;
	XOR=0 , wyn=0;
	//cerr<<trie.size()<<endl;
	trie.push_back({0 , 0 , -1 , -1});
	add(31 , 0 , 0 , trie);
	while(n>0){
		//cerr<<"n: "<<n<<endl;
		cin>>a; 
		XOR=(XOR^a);
		//cerr<<"XOR: "<<XOR<<endl;
		wyn=wyn+count(31 , XOR , 0 , trie , k);
		//cerr<<"c: "<<n<<endl;
		add(31 , XOR , 0 , trie);
		n--;
		//cerr<<"------------------------------"<<endl;
	}
	cout<<wyn<<'\n';
	//for(int i=0 ; i<(int)trie.size() ; i++)cerr<<i<<": "<<trie[i].R_ile<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t>0){
		t--;
		DO();
		numer=1;
		//cerr<<"--------------------------"<<endl;
	}
}