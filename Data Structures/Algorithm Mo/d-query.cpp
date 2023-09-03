#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct liczba{
	int v1 , v2 , nr;
};
struct ans{
	int o , num;
};
int n , q , i , x , s , a , c , b;
vector<liczba> tab;
vector<liczba> tad;
bool comparev1(liczba x , liczba y){
	if(x.v1<y.v1)
		return true;
	else
		return false;
}
bool compareodp(ans x , ans y){
	if(x.num<y.num)
		return true;
	else
		return false;
}
bool comparenr(liczba x , liczba y){
	if(x.nr<y.nr)
		return true;
	else
		return false;
}
bool compareque(liczba x, liczba y) 
{ 
   if (x.v1/c != y.v1/c) 
       return x.v1/c < y.v1/c; 
  
  return x.v2 < y.v2; 
};
void skalowanie(){
	s=0;
	sort(tab.begin() , tab.end() , comparev1);
	for(i=1 ; i<n ; i++){
		if(tab[i-1].v1==tab[i].v1){
			tab[i].v2=s;
		}
		else{
			s++;
			tab[i].v2=s;
		}
	}
	sort(tab.begin() , tab.end() , comparenr);
}
void sortque(){
	c=(int)sqrt(n);
	sort(tad.begin() , tad.end() , compareque);
}
int l , p , wyn=0;
vector<bool> poz;
vector<int> liczby;
int j;
int w;
int wynik(int L , int P ){
	if(P>p){
		for(j=p ; j<=P ; j++){
			if(poz[j]==false){
				poz[j]=true;
				w=tab[j].v2;
				if(liczby[w]==0){
					wyn++;
				}
				liczby[w]++;
			}
		}
	}
	if(L<l){
		for(j=l ; j>=L ; j--){
			if(poz[j]==false){
				poz[j]=true;
				w=tab[j].v2;
				if(liczby[w]==0){
					wyn++;
				}
				liczby[w]++;
			}
		}
	}
	if(L>l){
		for(j=l ; j<L ; j++){
			if(poz[j]==true){
				poz[j]=false;
				w=tab[j].v2;
				if(liczby[w]==1){
					wyn--;
				}
				liczby[w]--;
			}
		}
	}
	if(P<p){
		for(j=p ; j>P ; j--){
			if(poz[j]==true){
				poz[j]=false;
				w=tab[j].v2;
				if(liczby[w]==1){
					wyn--;
				}
				liczby[w]--;
			}
		}
	}
	l=L;
	p=P;
	
	return wyn;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for( i=0 ; i<n ; i++){
		cin>>a;
		tab.push_back(liczba());
		tab[i].nr=i;
		tab[i].v1=a;
		tab[i].v2=0;
		poz.push_back(false);
	}
	skalowanie();
	//for(i=0 ; i<n ; i++){
	//	cout<<tab[i].v1<<" "<<tab[i].v2<<" "<<tab[i].nr<<endl;
	//}
	cin>>q;
	for(i=0 ; i<q ; i++){
		cin>>a>>b;
		tad.push_back(liczba());
		tad[i].nr=i;
		tad[i].v1=a;
		tad[i].v2=b;
	}
	sortque();
	//for(i=0 ; i<q ; i++){
	//	cout<<tad[i].v1<<" "<<tad[i].v2<<" "<<tad[i].nr<<endl;
//	}
//	cout<<endl;
	ans odp[q];
	int a1 ,a2 , a3 , t;
	for(i=0 ; i<=s ; i++){
		liczby.push_back(0);
	}
	wyn=1;
	liczby[tab[0].v2]=1;
	poz[0]=true;
	for(i=0 ; i<q ; i++){
		a1=tad[i].v1;
		a2=tad[i].v2;
		t=wynik(a1-1 , a2-1);
		odp[i].o=t;
		a3=tad[i].nr;
		odp[i].num=a3;
	}
	sort(odp , odp+q , compareodp);
	for(i=0 ; i<q; i++){
		cout<<odp[i].o<<endl;
	}
}