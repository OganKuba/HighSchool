#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n , q ,a , b , v , i;
vector<int> power;
vector<int> last;
vector<int> coun;
vector<int> next1;
void change(int p , int val , int lines){
	power[p]=val;
	for(i=p ; i>=0 && i/lines==p/lines ; i--){
		v=i+power[i];
		if(v>=n){
			last[i]=i;
			coun[i]=1;
			next1[i]=v;
		}
		else{
			if(i/lines==v/lines){
				last[i]=last[v];
				coun[i]=coun[v]+1;
				next1[i]=next1[v];
			}
			else{
				last[i]=i;
				coun[i]=1;
				next1[i]=v;
			}
		}
	}
}
int ost;
int suma=0;
void go(int tar){
	ost=last[tar];
	while(tar<n){
		suma=suma+coun[tar];
		ost=last[tar];
		tar=next1[tar];
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cin>>n>>q;
	for(i=0 ; i<n ; i++){
		cin>>a;
		power.push_back(a);
		last.push_back(0);
		next1.push_back(0);
		coun.push_back(0);
	}
	bool que;
	int line=sqrt(n);
	for( i=n-1 ; i>=0 ; i--){
		v=i+power[i];
		if(v>=n){
			last[i]=i;
			coun[i]=1;
			next1[i]=v;
		}
		else{
			if(i/line==v/line){
				last[i]=last[v];
				coun[i]=coun[v]+1;
				next1[i]=next1[v];
			}
			else{
				last[i]=i;
				coun[i]=1;
				next1[i]=v;
			}
		}
	}
	for(int j=0 ; j<q ; j++){
		cin>>que;
		if(que==0){
			cin>>a>>b;
			change(a-1 , b , line);
		}
		else{
			cin>>a;
			go(a-1);
			cout<<ost+1<<" "<<suma<<endl;
		}
		suma=0;
	}
}