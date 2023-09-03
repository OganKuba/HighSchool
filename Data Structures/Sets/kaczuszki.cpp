#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
multiset<int>  Q;
multiset<int>::iterator iter;
multiset<int>::reverse_iterator rit;
int n ,a ;
long long b , d;
long long c;
long long suma=0;
int najmn(){
	if(!Q.empty()){
		iter=Q.begin();
		a=(*(iter));
		Q.erase(Q.begin());
		suma=suma-a;
		return a;
	}
	else{
		return -1;
	}
}
int najw(){
	if(!Q.empty()){
		rit=Q.rbegin();
		a=(*(rit));
		Q.erase(Q.find(a));
		suma=suma-a;
		return a;
	}
	else{
		return -1;
	}
}
int minusx(int x){
	if(Q.find(x)==Q.end()){
		return 0;
	}
	else{
		Q.erase(Q.find(x));
		suma=suma-x;
		return 1;
	}
}
void plusx(int x){
	suma=suma+x;
	Q.insert(x);
}
int przedz(int h , int k){
	iter=Q.upper_bound(h-1);
	a=(*(iter));
	if(a>k || iter==Q.end()){
		return -1;
	}
	else{
		suma=suma-a;
		Q.erase(Q.find(a));
		return a;
	}
}
void srednia(){
	b=(long long)Q.size();
	c=suma;
	if(b!=0 && c!=0){
		while(1){
			d=__gcd(c , b);
			if(d==1){
				break;
			}
			else{
				c=c/d;
				b=b/d;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
cin.tie(0);
	cin>>n;
	string X;
	int q , p;
	int odp=0;
	for(int i=0 ; i<n ; i++){
		cin>>X;
		if(X=="NAJMN"){
			odp=najmn();
			if(odp==-1){
				cout<<"NIE"<<endl;
			}
			else{
				cout<<odp<<endl;
			}
		}
		if(X=="NAJW"){
			odp=najw();
			if(odp==-1){
				cout<<"NIE"<<endl;
			}
			else{
				cout<<odp<<endl;
			}
		}
		if(X=="PRZEDZ"){
			cin>>p>>q;
			odp=przedz(p , q);
			if(odp==-1){
				cout<<"NIE"<<endl;
			}
			else{
				cout<<odp<<endl;
			}
		}
		if(X=="MINUS"){
			cin>>p;
			if(minusx(p)==1){
				cout<<"TAK"<<endl;
			}
			else{
				cout<<"NIE"<<endl;
			}
		}
		if(X=="SREDN"){
			srednia();
			cout<<c<<"/"<<b<<endl;
		}
		if(X=="PLUS"){
			cin>>b;
			plusx(b);
		}
		
	}
}