#include <bits/stdc++.h>
using namespace std;
vector<int> B, C;
vector<vector<int>> DP(1);
vector<vector<int>> ILE(1);
int n, a, k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    B.push_back(0), C.push_back(0);
    DP.resize(n + 1), ILE.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        B.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        C.push_back(a);
    }
    int inf = 20001;
    cin >> k;
    for (int i = 0; i <= k; i++)
    {
        DP[0].push_back(inf), ILE[0].push_back(0);
    }
    DP[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        // cerr<<"i: "<<i<<endl;
        for (int j = 0; j <= k; j++)
        {
            DP[i].push_back(inf), ILE[i].push_back(0);
        }
        DP[i][0] = 0;
        for (int x = 0; x < B[i]; x++)
        {
            list<int> Q;
            int y = 0;
            vector<int> F;
            while (x + y * B[i] <= k)
            {
                F.push_back(DP[i - 1][x + y * B[i]] - y);
                while (!Q.empty())
                {
                    if (F[Q.back()] >= F[y])
                        Q.pop_back();
                    else
                        break;
                }
                Q.push_back(y);
                if (DP[i][x + y * B[i]] > F[Q.front()] + y)
                {
                    DP[i][x + y * B[i]] = F[Q.front()] + y;
                    ILE[i][x + y * B[i]] = y - Q.front();
                }
                if (Q.front() == y - C[i])
                    Q.pop_front();
                y++;
            }
        }
    }
    list<int> wyn;
    int now = k;
    for (int i = n; i >= 1; i--)
    {
        wyn.emplace_front(ILE[i][now]);
        now -= ILE[i][now] * B[i];
    }
    cout << DP[n][k] << endl;
    while (!wyn.empty())
    {
        cout << wyn.front() << " ";
        wyn.pop_front();
    }
}