#include <bits/stdc++.h>
#define endl '\n'
#ifdef WIN32
inline int getchar_unlocked() { return _getchar_nolock(); }
inline void putchar_unlocked(char c) { _putchar_nolock(c); }
#endif

int fastin() {
	int n = 0, c = getchar_unlocked();
	while(c < '0' or '9' < c)
		c = getchar_unlocked();
	while('0' <= c and c <= '9') {
		n = 10 * n + (c - '0');
		c = getchar_unlocked();
	}
	return n;
}

int fastin_negative() {
	int n = 0, negative = false, c = getchar_unlocked();
	while(c != '-' and (c < '0' or '9' < c))
		c = getchar_unlocked();
	if(c == '-') {
		negative = true;
		c = getchar_unlocked();
	}
	while('0' <= c and c <= '9') {
		n = 10 * n + (c - '0');
		c = getchar_unlocked();
	}
	return negative ? -n : n;
}

void fastout(long long x) {
	if(x == 0) {
		putchar_unlocked('0');
		putchar_unlocked(' ');
		return;
	}
	if(x < 0) {
		putchar_unlocked('-');
		x *= -1;
	}
	static char t[17];
	long long i = 0;
	while(x) {
		t[i++] = '0' + (x % 10);
		x /= 10;
	}
	while(--i >= 0)
		putchar_unlocked(t[i]);
	putchar_unlocked(' ');
}
void nl() { putchar_unlocked('\n'); }
using namespace std;
struct line{
	int a1 , a2 , v;
};
vector<int> rep;
vector<int> ile;
bool comp(line x , line y){
	return (x.v<y.v);
}
void Union(int a,int b){
	if(ile[a]>ile[b])swap(a, b);
	rep[a]=b;
	ile[b]+=ile[a];
}
int Find(int a){
	if(rep[a]!=a)rep[a]=Find(rep[a]);
	return rep[a];
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int p, q ,c;
	int n=fastin();
	int m=fastin();
	long long suma=0;
	vector<line> kraw;
	for(int i=0 ; i<=n ; i++){
		rep.push_back(i);
		ile.push_back(1);
	}
	int f1 , f2;
	for(int i=0 ; i<m ; i++){
		p=fastin();
		q=fastin();
		c=fastin();
		f1=Find(p);
		f2=Find(q);
		if(f1!=f2){
			Union(f1 , f2);
			suma=suma+c;
		}
	}
	//sort(kraw.begin() , kraw.end() , comp);
	fastout(suma);
}