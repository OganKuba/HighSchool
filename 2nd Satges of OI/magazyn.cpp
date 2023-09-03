#include <bits/stdc++.h>
using namespace std;
struct point{
	int t , x , y , xs , ys;
};
int n , a, b , c;
int xmax=0;
int ymax=0;
int ymin=500000000;
int xmin=500000000;
vector<point> S;
bool compx(point A , point B){return A.xs<B.xs;}
bool compy(point A , point B){return A.ys<B.ys;}
int findminX(){
	long long ile=0;
	for(int i=0 ; i<n ; i++){
		ile+=(long long)(S[i].t);
	}
	long long med=0;
	if(ile%(long long)(2)==1){
		med=(ile+1)/2;
		long long now=0;
		for(int i=0 ; i<n ; i++){
			if(now<med && med<=now+(long long)(S[i].t))return S[i].xs;
			now+=(long long)(S[i].t);
		}
	}
	else{
		long long med1;
		med=ile/2 , med1=med+1;
		int w1 , w2 , e;
		e=0;
		long long now=0;
		for(int i=0 ; i<n ; i++){
			if(now<med && med<=now+(long long)(S[i].t)){w1=S[i].xs , e++;}
			if(now<med1 && med1<=now+(long long)(S[i].t)){w2=S[i].xs , e++;}
			if(e>=2)break;
			now+=(long long)(S[i].t);
		}
		int X=(w1+w2)/2;
		return X;
	}
}
int findminY(){
	long long ile=0;
	for(int i=0 ; i<n ; i++){
		ile+=(long long)(S[i].t);
	}
	long long med=0;
	if(ile%(long long)(2)==1){
		med=(ile+1)/2;
		long long now=0;
		for(int i=0 ; i<n ; i++){
			if(now<med && med<=now+(long long)(S[i].t))return S[i].ys;
			now+=(long long)(S[i].t);
		}
	}
	else{
		long long med1;
		med=ile/2 , med1=med+1;
		int w1 , w2 , e;
		e=0;
		long long now=0;
		for(int i=0 ; i<n ; i++){
			if(now<med && med<=now+(long long)(S[i].t)){w1=S[i].ys , e++;}
			if(now<med1 && med1<=now+(long long)(S[i].t)){w2=S[i].ys , e++;}
			if(e>=2)break;
			now+=(long long)(S[i].t);
		}
		int X=(w1+w2)/2;
		return X;
	}
}
long long check(int Lx , int Ly){
	long long suma=0;
	for(int i=0 ; i<(int)S.size() ; i++)suma+=(long long)(max(abs(Lx-S[i].x) , abs(Ly-S[i].y)))*(long long)(S[i].t);
	return suma;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>a>>b>>c;
		S.push_back({c , a , b , a-b , a+b});
		xmax=max(xmax , a-b) , ymax=max(ymax , a+b) , xmin=min(xmin , a-b) , ymin=min(ymin , a+b);
	}
	//cerr<<"kon"<<endl;
	sort(S.begin() , S.end() , compx);
	//cerr<<"S: "<<endl;
	//for(int i=0 ; i<S.size() ; i++){
	//	cout<<S[i].xs<<" "<<S[i].ys<<endl;
	//}
	//cerr<<endl;
	int A1=findminX();
	int wx , wy;
	sort(S.begin() , S.end() , compy);
	int A2=findminY();
	if(A1%2==A2%2){
		wx=(A1+A2)/2;
		wy=(A2-A1)/2;
	}
	else{
		long long por=-1;
		for(int i=-1 ; i<=1 ; i=i+2){
			for(int j=-1 ; j<=1 ; j=j+2){
				long long wyn=check((A1+A2+i)/2 , (A2-A1+j)/2);
				//cerr<<"wyn: "<<wyn<<endl;
				//cout<<"x: "<<(A1+A2+i)/2<<"    y: "<<(A2-A1+j)/2<<"    "<<wyn<<endl;
				if(wyn<por || por==-1){
					//cerr<<"XD";
					wx=(A1+A2+i)/2 , wy=(A2-A1+j)/2;
					por=wyn;
				}
			}
		}

	}
	//cout<<"a1 i a2: "<<A1<<" "<<A2<<endl;
	cout<<wx<<" "<<wy;

}