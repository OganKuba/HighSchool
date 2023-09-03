#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct point{
	int poz , nr;
};
struct krawedz{
	int id , val;
};
struct line{
	bool kierunek;
	int kon;
};
bool compare(point q , point p){
	if(q.nr<p.nr){
		return true;
	}
	else{
		return false;
	}
}
vector< vector<krawedz> > drogi(100001);
vector< vector<krawedz> > wst(100001);
vector<bool> tab;
vector<bool> tab1 , tab2  , tabpocz , tabk , tabkon;
vector<int> CITY;
vector<point> miasto;
vector<int> spojna;
int n , m , i , j , a , b , x , y , k;
int num=1;
void DFS(int v){
	for(int i=0 ; i<(int)drogi[v].size() ; i++){
		k=drogi[v][i].val;
		if(tab[k]==false){
			tab[k]=true;
			DFS(k);
		}
	}
	miasto[v].nr=num;
	num++;
}
void OK(int v , int f){
	for(int i=0 ; i<(int)wst[v].size() ; i++){
		k=wst[v][i].val;
		if(tab1[k]==false){
			spojna[k]=f;
			tab1[k]=true;
			OK(k , f);
		}
	}
}
int l;
int r1 , r2;
bool in1=false;
bool out1=false;
void SIL(int v , vector<vector<line> > &silnie){
	for(int i=0 ; i<(int)drogi[v].size() ; i++){
		k=drogi[v][i].val;
		l=drogi[v][i].id;
		if(spojna[v]!=spojna[k] && tab2[l]==false){
			tab2[l]=true;
			r1=spojna[v];
			r2=spojna[k];
			silnie[r1].push_back(line());
			silnie[r1][(int)silnie[r1].size()-1].kierunek=false;
			silnie[r1][(int)silnie[r1].size()-1].kon=r2;
			silnie[r2].push_back(line());
			silnie[r2][(int)silnie[r2].size()-1].kierunek=true;
			silnie[r2][(int)silnie[r2].size()-1].kon=r1;
			
		}
	}
}
int wyn=0;
int in=0;
int out=0;
int both=0;
void COUNT(int v , vector<vector<line> > &silnie){
	for(int i=0 ; i<(int)silnie[v].size() ; i++){
		if(silnie[v][i].kierunek==false && silnie[v][i].kon!=v){
			out1=true;
		}
		if(silnie[v][i].kierunek==true && silnie[v][i].kon!=v){
			in1=true;
		}
	}
	if(out1==false && in1==false){
		both++;
	}
	else{
		if(in1==true && out1==false){
			in++;
		}
		if(out1==true && in1==false){
			out++;
		}
	}
	out1=false;
	in1=false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=0 ; i<m ; i++){
		cin>>a>>b;
		drogi[a].push_back(krawedz());
		drogi[a][(int)drogi[a].size()-1].val=b;
		drogi[a][(int)drogi[a].size()-1].id=i;
		wst[b].push_back(krawedz());
		wst[b][(int)wst[b].size()-1].val=a;
		wst[b][(int)wst[b].size()-1].id=i;
		tab2.push_back(false);
		tabk.push_back(false);
	}
	for(i=0 ; i<=n ; i++){
		tab.push_back(false);
		tab1.push_back(false);
		
		tabpocz.push_back(false);
		tabkon.push_back(false);
		spojna.push_back(0);
		miasto.push_back(point());
		x=(int)miasto.size()-1;
		miasto[x].poz=i;
		miasto[x].nr=0;
		CITY.push_back(0);
		
	}
	for(i=j ; j<=n ; j++){
		if(tab[j]==false){
			tab[j]=true;
			DFS(j);
		}
	}
	sort(miasto.begin() , miasto.end() , compare);
//	cout<<endl;
//	for(i=1 ; i<=n ; i++){
//		cout<<miasto[i].poz<<" "<<miasto[i].nr<<endl;
//	}
//	cout<<endl;
	int suma=0;
	for(j=n ; j>=1 ; j--){
		x=miasto[j].poz;
		if(tab1[x]==false){
			suma++;
			tab1[x]=true;
			spojna[x]=suma;
			OK(x , suma);
		}
	}
	//for(i=1 ; i<=n ; i++){
	//	cout<<i<<": "<<spojna[i]<<endl;
//	}
	//cout<<suma;
	vector<vector<line> > silnie(suma+1);
	for(j=1 ; j<=n ; j++){
		SIL(j , silnie);
	}
//	for(x=1 ; x<=suma ; x++){
	//	cout<<x<<": ";
	//	for(y=0 ; y<(int)silnie[x].size() ; y++){
	//		cout<<silnie[x][y].kon<<" "<<silnie[x][y].kierunek<<"  ,  ";
	//	}
	//	cout<<endl;
//	}
	for(int g=1 ; g<=suma ; g++){
		COUNT(g , silnie);
	}
	wyn=min(out , in)+wyn;
	if(both==0){
		wyn=wyn+(max(out , in)-min(out , in));
	}
	else{
		wyn=wyn+(max(out , in)-min(out , in))+both;
	}
	if(suma==1){
		wyn=0;
	}
	cout<<wyn;

	
	
	
}