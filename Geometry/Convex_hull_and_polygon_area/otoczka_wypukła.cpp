#include <bits/stdc++.h>
using namespace std;
struct point{
	int x;
	int y;
	
};
vector<point> tab;
vector<point> otoczka;
vector<point> tabg;
vector<point> tabd;
long long A;
long long B;
long long w1 , w2 , wc , odp;
long double ic , i1 , i2 , i3 , i4 , i5 , i6; 
int r=0;
long long xa , xb , xc , ya , yb , yc , j;
bool porownaj(point a, point b) 
{ 
   if (a.x != b.x) 
       return a.x < b.x; 
  
  return a.y < b.y; 
};
bool il(long long x1 , long long y1 , long long x2 , long long y2 , long long x3 , long long y3){
	w1=(x3-x1)*(y2-y1);
	w2=(x2-x1)*(y3-y1);
	wc=w1-w2;
	if(wc>=0){
		return true;
	}
	else{
		return false;
	}
}
int k;
void gora(int n){
	otoczka.push_back(point());
	otoczka[0].x=tabg[0].x;
	otoczka[0].y=tabg[0].y;
	otoczka.push_back(point());
	otoczka[1].x=tabg[1].x;
	otoczka[1].y=tabg[1].y;
	for( j=2 ; j<tabg.size() ; j++){
		k=otoczka.size();
		xa=otoczka[k-2].x;
		xb=otoczka[k-1].x;
		xc=tabg[j].x;
		ya=otoczka[k-2].y;
		yb=otoczka[k-1].y;
		yc=tabg[j].y;
		if(il(xa , ya , xb  , yb , xc , yc)==false){
			k=otoczka.size();
			otoczka[k-1].x=xc;
			otoczka[k-1].y=yc;
			while(r==0 && k>=3){
				k=otoczka.size();
				xa=otoczka[k-3].x;
				xb=otoczka[k-2].x;
				xc=otoczka[k-1].x;;
				ya=otoczka[k-3].y;
				yb=otoczka[k-2].y;
				yc=otoczka[k-1].y;
				if(il(xa , ya , xb  , yb , xc , yc)==false){
					otoczka[k-2].x=xc;
					otoczka[k-2].y=yc;
					otoczka.pop_back();
				}
				else{
					r=1;
				}
			}
			r=0;
		}
		else{
				otoczka.push_back(point());
				k=otoczka.size();
				otoczka[k-1].x=xc;
				otoczka[k-1].y=yc;
		}
	}
	
}
void dol(int n){
	for( j=tabd.size()-1; j>=0 ; j--){
		k=otoczka.size();
		xa=otoczka[k-2].x;
		xb=otoczka[k-1].x;
		xc=tabd[j].x;
		ya=otoczka[k-2].y;
		yb=otoczka[k-1].y;
		yc=tabd[j].y;
		if(il(xa , ya , xb  , yb , xc , yc)==false){
			k=otoczka.size();
			otoczka[k-1].x=xc;
			otoczka[k-1].y=yc;
			while(r==0 && k>=3){
				k=otoczka.size();
				xa=otoczka[k-3].x;
				xb=otoczka[k-2].x;
				xc=otoczka[k-1].x;;
				ya=otoczka[k-3].y;
				yb=otoczka[k-2].y;
				yc=otoczka[k-1].y;
				if(il(xa , ya , xb  , yb , xc , yc)==false){
					otoczka[k-2].x=xc;
					otoczka[k-2].y=yc;
					otoczka.pop_back();
				}
				else{
					r=1;
				}
			}
			r=0;
		}
		else{
				otoczka.push_back(point());
				k=otoczka.size();
				otoczka[k-1].x=xc;
				otoczka[k-1].y=yc;
				
		}
	}
	while(r==0 && k>=3){
		k=otoczka.size();
		xa=otoczka[k-2].x;
		xb=otoczka[k-1].x;
		xc=otoczka[0].x;
		ya=otoczka[k-2].y;
		yb=otoczka[k-1].y;
		yc=otoczka[0].y;
		if(il(xa , ya , xb  , yb , xc , yc)==false){
			otoczka.pop_back();
		}
		else{
			r=1;
		}
	}
	r=0;
}
long double poletrojkata(long long x1 , long long y1 , long long x2 , long long y2 , long long x3 , long long y3){
	i1=x1*y2;
	i2=x2*y1;
	i3=x2*y3;
	i4=x3*y2;
	i5=x3*y1;
	i6=x1*y3;
	ic=(i1-i2+i3-i4+i5-i6)/2;
	return ic;
}
int main(){
	int n;
	cin>>n;
	int a , b;
	int i;
	for( i=0 ; i<n ; i++){
		cin>>a>>b;
		tab.push_back(point());
		tab[i].x=a;
		tab[i].y=b;
	}
	long double suma=0;
	long long h=0;
	if(n>=3){
		sort(tab.begin(), tab.end(), porownaj);
	//	cout<<"TAB: "<<endl;
	//	for(int i=0 ; i<n ; i++){
		//	cout<<tab[i].x<<" "<<tab[i].y<<endl;
		//}
		tabg.push_back(point());
		tabg[0].x=tab[0].x;
		tabg[0].y=tab[0].y;
		for( i=1 ; i<n-1 ; i++){
			if(il(tab[0].x , tab[0].y , tab[n-1].x , tab[n-1].y , tab[i].x , tab[i].y)==true){
				tabd.push_back(point());
				h=tabd.size()-1;
				tabd[h].x=tab[i].x;
				tabd[h].y=tab[i].y;
				
			}
			else{
				tabg.push_back(point());
				h=tabg.size()-1;
				tabg[h].x=tab[i].x;
				tabg[h].y=tab[i].y;
			}
		}
		tabg.push_back(point());
		h=tabg.size()-1;
		tabg[h].x=tab[n-1].x;
		tabg[h].y=tab[n-1].y;
		//cout<<"TAB GORA: "<<endl;
	//	for(i=0 ; i<tabg.size() ; i++){
		//	cout<<tabg[i].x<<" "<<tabg[i].y<<endl;
		//}
		//cout<<"TAB DOL: "<<endl;
	//	for(i=0 ; i<tabd.size() ; i++){
		//	cout<<tabd[i].x<<" "<<tabd[i].y<<endl;
	//	}
		gora(n);
		dol(n);
		//cout<<"OTOCZKA: "<<endl;
		//for( i=0 ; i<otoczka.size() ; i++){
		//	cout<<otoczka[i].x<<" "<<otoczka[i].y<<endl;
		//}
		xa=otoczka[0].x;
		ya=otoczka[0].y;
		long double xd=0;
		for(i=1 ; i<=otoczka.size()-2 ; i++){
			xb=otoczka[i].x;
			yb=otoczka[i].y;
			xc=otoczka[i+1].x;
			yc=otoczka[i+1].y;
			xd=poletrojkata(xa , ya , xb , yb , xc , yc);
			suma=suma+abs(xd);
		}
	}
	cout<<fixed<<setprecision(6)<<suma;
	
	
}