#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> GLE;
vector<int> ojciec;
deque<int> kolejka;
vector<int> tab;
vector<vector<int> > synowie(1000001);
int wh=2;
vector<vector<int> > Ancestor(1000001);
int xd1;
int deepx;
int k,y ,f , a, b , n , m , i , l , a1 , b1=0;
int JUMPPOINT(int r , int deep){
	int deepx = GLE[r];
	assert(deep <= deepx);
	int dif = deepx - deep;
	for(int i = 0; i <= 20; i++)
		if(dif & (1 << i))
			r = Ancestor[r][i];
	return r; 
}
int LCA(int A , int B){
	if(GLE[B]<GLE[A]){
		swap(A , B);
	}
	for( y=20 ; y>=0 ; y--){
		if(GLE[Ancestor[B][y]]>=GLE[A]){
			B=Ancestor[B][y];
		}
			if(A==B)return A;
	}
	for( y=20 ; y>=0 ; y--){
		if(Ancestor[B][y]!=Ancestor[A][y]){
			A=Ancestor[A][y];
			B=Ancestor[B][y];
		}
	}
	return ojciec[A];
}
void Make_Ancestor(){
	int x;
	int k;
	ojciec[m]=m;
	for(int x=1 ; x<=n ; x++){
		Ancestor[x][0]=ojciec[x];
	}
	for(int q=1 ; q<=20 ; q++){
		for(int x=1 ; x<=n ; x++){
			Ancestor[x][q]=Ancestor[Ancestor[x][q-1]][q-1];
		}
	}
}
void BFS(int now){
	kolejka.push_back(now);
	while(!kolejka.empty()){
		 l=kolejka.front();
		kolejka.pop_front();
		for( i=0 ; i<synowie[l].size() ; i++){
			xd1=synowie[l][i];
			if(tab[xd1]==false){
				ojciec[xd1]=l;
				GLE[xd1]=GLE[l]+1;
				kolejka.push_back(xd1);
				tab[xd1]=true;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	//vector<vector<int> > synowie(n+1);
	for( i=0 ; i<n+1 ; i++){
		if(i<n-1){
			cin>>a>>b;
			synowie[a].push_back(b);
			synowie[b].push_back(a);
		}
		Ancestor[i].reserve(21);
		GLE.push_back(0);
		ojciec.push_back(0);
		tab.push_back(false);
	}
	GLE[m]=1;
	ojciec[m]=m;
	tab[m]=true;
	int c;
	int t;
	int wyn;
	int now=m;
	BFS(m);
	Make_Ancestor();
//	for(int i=1 ; i<=n ; i++){
		//cout<<GLE[i]<<" ";
//	}
	vector<int> wyniki;
	int przodek;
	int reszta=0;
	int odp;
	int gle;
	int p;
	for(int i=0 ; i<k ; i++){
		cin>>c>>t;
		przodek=LCA(c , now);
		if(GLE[now]+GLE[c]-2*GLE[przodek]<=t){
			now=c;
			wyniki.push_back(c);
		}
		else{
			p=GLE[now]-GLE[przodek];
			if(p<=t && (t-p)+GLE[przodek]<GLE[c]){//zdąży
				reszta=t-p;
				if(reszta==0){
					now=przodek;
					wyniki.push_back(przodek);
				}
				else{
					gle=GLE[przodek]+reszta;
					odp=JUMPPOINT(c , gle);
					now=odp;
					wyniki.push_back(odp);
				}
			}
			else{
				gle=GLE[now]-t;
				odp=JUMPPOINT(now , gle);
				now=odp;
				wyniki.push_back(odp);
			}
		}
	}
	//cout<<"------------"<<endl;
	for(int i=0 ; i<k ; i++){
		cout<<wyniki[i]<<" ";
	}
}