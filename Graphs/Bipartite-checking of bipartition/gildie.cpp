#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n , m , a, b;
vector<int> val , st;
void Change(int x , int y){
	if(val[x]==0){
		if(val[y]==1)val[x]=2;
		else val[x]=1;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	val=st=vector<int>(n+1 , 0);
	int all=n;
	for(int i=0 ; i<m ; i++){
		cin>>a>>b;
		Change(a , b);
		Change(b , a);
		if(st[a]==0)all--;
		if(st[b]==0)all--;
		st[a]=1;
		st[b]=1;
	}
	if(all==0){
		cout<<"TAK"<<'\n';
		for(int i=1 ; i<=n ; i++){
			if(val[i]==1)cout<<"K"<<endl;
			else cout<<"S"<<'\n';
		}
	}
	else{
		cout<<"NIE"<<'\n';
	}
}