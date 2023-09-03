#include <bits/stdc++.h>
using namespace std;
bool odw[13];
int n;
int tab[13][13];
bool tab2[13][13];
int xd[10];
int sum, dif;
int sprawdz()
{
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        dif = 0;
        for (int j = 1; j < 10; j++)
        {
            if (xd[j] == tab[i][j + 2])
                sum += xd[j];
            if (odw[j] == tab2[i][j] && odw[j] == 1)
                dif += j;
        }
        dif -= sum;
        if (sum != tab[i][1])
            return 1;
        if (dif != tab[i][2])
            return 1;
    }
    return 0;
}
int bylo = 0;
void xdob(int pos)
{
    if (pos == n + 1)
    {
        if (bylo == 0 && sprawdz() == 0)
        {
            bylo = 1;
            for (int i = 1; i <= n; i++)
            {
                cout << xd[i] << " ";
            }
        }
    }
    else
    {
        for (int i = 1; i < 10; i++)
        {
            if (odw[i] == 0)
            {
                odw[i] = 1;
                xd[pos] = i;
                xdob(pos + 1);
                odw[i] = 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 2; j++)
        {
            cin >> tab[i][j];
            if (j > 2)
                tab2[i][tab[i][j]] = 1;
        }
    xdob(1);
}