//Akif Islam (__SHERLOCK__)
//Date: 2021-06-02 20:39:09

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

vector<int> graph[100005];

int visited[100005];
bool gotOneNode = false;
int linkingNode = -1;

void DFS(int x)
{
    if (visited[x])
        return;
    if (!gotOneNode)
    {
        gotOneNode = true;
        linkingNode = x;
    }
    visited[x] = true;

    for (auto x : graph[x])
        DFS(x);
}
void solve()
{
    int n, m;
    cin >> n >> m;

    int from, to;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;

        graph[from].pb(to);
        graph[to].pb(from);
    }

    int connected_comp = 0;

    vector<int> answer;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            connected_comp++;
            answer.pb(linkingNode);
            linkingNode = -1;
            gotOneNode = false;
        }
    }
    cout << connected_comp - 1 << endl;

    for (int i = 0; i < answer.size() - 1; i++)
    {
        cout << answer[i] << " " << answer[i + 1] << endl;
    }

    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}