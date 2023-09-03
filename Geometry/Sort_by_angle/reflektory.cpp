#include <bits/stdc++.h>
using namespace std;
struct point{
	int x , y;
};
int odp;
long long  u , k , v , q , p=0;
long long w1 , w2 , wc=0;
bool wektor(long long x1 , long long y1 , long long x2 , long long y2){
	w1=x2*y1;
	w2=x1*y2;
	wc=w1-w2;
	if(wc>0){
		return true;
	}
	else{
		return false;
	}
	return 0;
}
vector<int> ans;
bool same(long long xA , long long yA , long long xB , long long yB){
	w1=xB*yA;
	w2=xA*yB;
	wc=w1-w2;
	if(wc==0)
		return true;
	else
		return false;
		
	return 0;
}
vector<int> rf;
vector<point> c1;
vector<point> c2;
vector<point> reszta;
bool compare(point a, point b) 
{ 
   if (wektor(a.x , a.y , b.x , b.y)==true)
       return true; 
  	else
 	 	return false; 
 	 	
 	return 0;
};
long long i , suma , S=0;
int test(long long x0 , long long y0 , long long r , long long e){
	sort(c1.begin() , c1.end() , compare);
	sort(c2.begin() , c2.end() , compare);
	p=reszta.size();
	for(i=0 ; i<p ; i++){
		c1.push_back(point());
		q=c1.size();
		c1[q-1].x=reszta[i].x;
		c1[q-1].y=reszta[i].y;
	}
//	cout<<endl;
//	for( i=0 ; i<c1.size() ; i++){
//		cout<<c1[i].x+x0<<" "<<c1[i].y+y0<<endl;
//	}
//	cout<<"-----------------"<<endl;
//	for( i=0 ; i<c2.size() ; i++){
//		cout<<c2[i].x+x0<<" "<<c2[i].y+y0<<endl;
//	}
	suma=1;
	u=0;
	q=c1.size();
	for(i=0 ; i<q-1 ; i++){
		if(same(c1[i].x , c1[i].y , c1[i+1].x , c1[i+1].y)==true){
			suma++;
			u=1;
		}
		else{
			rf.push_back(suma);
			suma=1;
			if(i==q-2){
				rf.push_back(1);
			}
		}
		if(i==q-2 && u==1){
			rf.push_back(suma);
		}
		u=0;
	}
	if(q==1){
		rf.push_back(1);
	}
	suma=1;
	u=0;
	q=c2.size() ;
	for(i=0 ; i<q-1 ; i++){
		if(same(c2[i].x , c2[i].y , c2[i+1].x , c2[i+1].y)==true){
			suma++;
			u=1;
		}
		else{
			rf.push_back(suma);
			suma=1;
			if(i==q-2){
				rf.push_back(1);
			}
		}
		if(i==q-2 && u==1){
			rf.push_back(suma);
		}
		u=0;
	}
	if(q==1){
		rf.push_back(1);
	}
	suma=1;
	sort(rf.begin() , rf.end());
//	cout<<"RF: "<<endl;
//	for(i=0 ; i<rf.size() ; i++){
	//	cout<<rf[i]<<" ";
	//}
	//cout<<endl;
	odp=0;
	k=0;
	q=rf.size()-1;
	for(i=q ; i>=0 ; i--){
		odp=odp+rf[i];
		k++;
		if(k==r){
			break;
		}
	}
	u=0;
	return odp;
	
}
int main(){
	long long t;
	cin>>t;
	long long y=0;
	long long ew=0;
	long long rx , ry , n , m ,a , b , j , l=0;
	for( y=0; y<t ; y++){
		cin>>rx>>ry>>n>>m;
		for(j=0 ; j<m ; j++){
			cin>>a>>b;
			if(m==0 && n==0){
				S=1;
			}
			ew=a-rx;
			if(ew>=0){
				if(ew==0 && b-ry<0){
					reszta.push_back(point());
					p=reszta.size();
					reszta[p-1].x=ew;
					reszta[p-1].y=b-ry;
				}
				else{
					c1.push_back(point());
					q=c1.size();
					c1[q-1].x=a-rx;
					c1[q-1].y=b-ry;
				}
			}
			else{
				c2.push_back(point());
				v=c2.size();
				c2[v-1].x=a-rx;
				c2[v-1].y=b-ry;
			}
			
		}
		if(S==0){
			l=test(rx , ry , n , m);	
		}
		else{
			l=0;
		}
		ans.push_back(l);
		c1.clear();
		c2.clear();
		rf.clear();
		reszta.clear();
		S=0;
	}
	q=ans.size();
	for(i=0 ; i<q ; i++){
		cout<<ans[i]<<endl;
	}
}