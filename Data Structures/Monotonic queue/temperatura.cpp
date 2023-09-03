#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
priority_queue<pair<int,int> > Qlow;
pair<int, int> pom;
vector<bool> uj;
int popsdone,pushesdone;
//void push(int a){
//	while(!Qlow.empty() && Qlow.back().second>=a)Qlow.pop_back();
//	Qlow.push_back(make_pair(a,pushesdone));
//	pushesdone++;
//}
//void pop(){
//	if(popsdone==Qlow.front().second){
	//	Qlow.pop_front();
//	}
	//popsdone++;
//}
//int min(){
//	if(Qlow.size()==0){
//		return -1;
//	}
	
///	return Qlow.front().first;
//}
vector<int> A , B;
int i , j  , n , m , k , x , y , b;
int odp , l , nowT=0;
int pozmax=0;
int v;
void LOW(int pocz ){
	while(!Qlow.empty()){
		//m=min();
		pom=Qlow.top();
		m=pom.second;
		if(m>=pocz){
			break;
		}
		else{
			Qlow.pop();
		}
	}
}
int t;
void szukaj(int val){
	while(!Qlow.empty()){
		pom=Qlow.top();
		t=pom.first;
		b=pom.second;
		//if(uj[b]==true){
		//	v=-t;
	//	}
	//	else{
			v=t;
	//	}
		if(val<v){
			pozmax=max(pozmax , b);
			Qlow.pop();
		}
		else{
			break;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int now=0;
	int A1 , B1;
	while(now<n){
		cin>>k>>b;
		B.push_back(k);
		A.push_back(b);
		if(k<0){
			uj.push_back(true);
		}
		else{
			uj.push_back(false);
		}
		if(nowT>A[now]){
			A1=A[now];
			B1=B[now];
			szukaj(A1);
			//push(-B1);
			Qlow.push(make_pair(B1 , now));
			LOW(pozmax+1);
			pom=Qlow.top();
			nowT=pom.first;
			//if(uj[pom.second]==true){
			//	nowT=-nowT;
		//	}
		//	else{
				//nowT=abs(nowT);
		//	}
			l=now-pozmax;
			odp=max(odp , l);
			//pozmax=0;
			
		}
		else{
			x=A[now];
			y=B[now];
			nowT=max(nowT , B[now]);
			//push(-y);
			Qlow.push(make_pair(y , now));
			l++;
			odp=max(odp , l);
		}
		now++;
	}
	cout<<odp;
}