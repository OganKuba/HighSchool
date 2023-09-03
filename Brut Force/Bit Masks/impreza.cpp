#include <bits/stdc++.h>

using namespace std;
bool compare(int i, int j)
{
	if(__builtin_popcount(i) != __builtin_popcount(j))
		return __builtin_popcount(i) > __builtin_popcount(j);
	return i > j;
}



bool tab[20][20];

int main()
{
	#define endl '\n'
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ogr;
	cin>>ogr;
	
	int xd=1;
	
	for(int i=0;i<ogr;i++)
	{
		xd*=2;
		for(int j=0;j<ogr;j++)
		{
			char slow;
			cin >> slow;
			tab[i][j]=slow!='1'?1:0;
		}
	}
	vector<int> m;
	
	for(int i=1; i<xd;i++){
		m.push_back(i);
	}
		
	sort(m.begin(), m.end(), compare);
	
	for(int i=0;i<xd;i++)
	{
		int d=m[i];
		
		vector<int> t;
		
		for(int j=0;j<ogr;j++)
		{
			if(d%2)t.push_back(ogr-j-1);
			d/=2;
		}
		
		bool kappa=1;
		
		for(int j=0;j<t.size();j++)
		{
			for(int k=j+1;k<t.size();k++)
				if(!tab[t[j]][t[k]])
				{
					kappa=0;
					break;
				}	
			
			if(!kappa)break;
		}
		
		if(kappa)
		{
			cout<<t.size()<<"\n";
			for(int j=t.size()-1;j>=0;j--)cout<<t[j]+1<<" ";
			cout<<"\n";
			return 0;
		}
	}
}