//Akif Islam (__SHERLOCK__)
//Date: 2021-06-04 08:50:17

#include <bits/stdc++.h>

using namespace std;

char gap = 32;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << gap << x;
    return os << '}';
}

#define ll long long
#define pb push_back
#define All(x) (x).begin(), (x).end()

int n, m;
vector<int> graph[100005];
vector<int> visited(100005);

void DFS(int x, int color)
{
    if (visited[x])
        return;
    visited[x] = (color % 2) + 1;

    for (auto u : graph[x])
    {
        DFS(u, color + 1);
    }
}

bool bipertite_check()
{
    bool isbipertite = true;

    for (int i = 1; i <= n; i++)
    {
        for (auto x : graph[i])
        {
            if (visited[i] == visited[x])
            {
                return false;
            }
        }
    }
    return true;
}

void solve()
{
    cin >> n >> m;
    int from, to;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        graph[from].pb(to);
        graph[to].pb(from);
    }
    // 1 == Red;
    // 2 == Green;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            DFS(i, 1);
    }

    if (bipertite_check())
    {
        for (int i = 1; i <= n; i++)
        {
            cout << visited[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}