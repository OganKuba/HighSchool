#include <bits/stdc++.h>
using namespace std;
struct stan
{
	int cena, ile;
};
deque<stan> bak;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int p, a, b, n, koszt, p_now;
	koszt = 0, p_now = 0;
	cin >> p;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		int suma = 0;
		while (!bak.empty())
		{
			stan now = bak.back();
			if (now.cena < a)
				break;
			// koszt=koszt-now.cena*now.ile;
			suma += now.ile;
			bak.pop_back();
		}
		// cerr<<"now: "<<a<<endl;
		if (suma + (p - p_now) != 0)
		{
			bak.push_back({a, suma + (p - p_now)});
			// cerr<<"cena i ilosc: "<<a<<"   "<<suma+(p-p_now)<<endl;
			// koszt+=a*suma+(p-p_now);
			p_now = p;
		}
		p_now -= b;
		while (!bak.empty())
		{
			stan now = bak.front();
			if (now.ile > b)
			{
				(bak.front()).ile -= b;
				koszt += b * now.cena;
				break;
			}
			else
			{
				b -= now.ile;
				koszt += now.ile * now.cena;
				bak.pop_front();
			}
		}
	}
	// cout<<koszt<<endl;

	cout << koszt;
}