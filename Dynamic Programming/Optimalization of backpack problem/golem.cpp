#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int p , q;
vector<bool> tab;
bool ASK(int tar , vector<int> Q){
	int s=0;
	if((int)Q.size()==0){
		//cout<<tar;
		if(tar!=0)return false;
		else return true;
	}
	for(int i=0 ; i<(int)Q.size(); i++){
		s=s+Q[i];
	}
	//cout<<tar<<endl;
	vector<bool> DP;
	vector<int> C;
	vector<int> ile;
	for(int i=0 ; i<=s; i++){
		DP.push_back(false);
		C.push_back(0);
		ile.push_back(0);
	}
	for(int i=0 ; i<(int)Q.size(); i++)ile[Q[i]]++;
	DP[0]=true;
	for(int j=1 ; j<=s ; j++){
		if (ile[j]>0){
			for (int i=0; i<=s; i++){
				if(DP[i]==false)C[i]=1000000000;
				else C[i]=0;
			}
			for(int i=0; i<=s-j; i++) C[i+j]=min(C[i+j], C[i]+1);
			for(int i=0; i<=s; i++)if(C[i]<=ile[j])DP[i]=true;
		}
	}
	for(int i=0 ; i<=s ; i++){
		if(DP[i]==true){
			if(tar==(i-(s-i)))return true;
			//cout<<i<<" ";
		}
	}
	//cout<<endl;
	return false;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	vector<int> X;
	vector<int> Y;
	int n;
	int dod=0;
	cin>>n;
	bool a;
	bool turn=false;
	int h=0;
	int suma=0;
	for(int i=0 ; i<n ; i++){
		cin>>a;
		if(i==0 && a==false)h++;
		if(a==true){
			if(turn==false){
				if(h==0){
					if(suma!=0)Y.push_back(suma);
				}
				else{
					h=0;
					dod=suma;
				}
				turn=true;
			}
			else{
				if(suma!=0)X.push_back(suma);
				turn=false;
			}
			suma=0;;
		}
		else suma++;
		if(a==false && i==n-1){
			if(turn==false && suma!=0)Y.push_back(suma);
			if(turn==true && suma!=0)X.push_back(suma);
		}
		//cout<<"turn: "<<turn<<endl;
	}
	cin>>p>>q;
	//for(int i=0 ; i<X.size(); i++)cout<<"XD: "<<X[i]<<" ";
	//cout<<endl;
	//for(int i=0 ; i<Y.size(); i++)cout<<Y[i]<<" ";
	//cout<<endl;
	if(ASK(p, X)==true && ASK(q-dod, Y)==true)cout<<"TAK";
	//if(ASK(p-dod, X)==true)cout<<"OKEJ";
	else cout<<"NIE";
	

}