//Akif Islam (__SHERLOCK__)
//Date: 2021-06-02 20:59:49

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

const int SIZE = 1e5 + 5;

vector<int> graph[SIZE];
bool visited[SIZE];
int dist[SIZE];
/*  */
vector<int> shortest_path;

void findingShortestPath(int src)
{
    if (src == 1)
    {
        shortest_path.pb(1);
        return;
    }

    shortest_path.push_back(src);

    for (auto x : graph[src])
    {
        cout << "Looping" << endl;
        if (dist[x] == dist[src] - 1)
        {
            findingShortestPath(x);
            break;
        }
    }
}

void BFS(int src)
{
    queue<int> Q;
    visited[src] = true;
    dist[src] = 0;
    Q.push(src);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (auto x : graph[cur])
        {
            if (!visited[x])
            {
                Q.push(x);
                visited[x] = true;
                dist[x] = dist[cur] + 1;
            }
        }
    }
}

void solve()
{
    memset(dist, -1, sizeof(dist));
    shortest_path.clear();

    int n, m;
    cin >> n >> m;

    int from, to;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        graph[from].pb(to);
        graph[to].pb(from);
    }
    BFS(1);

    if (dist[n] == -1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << dist[n] + 1 << endl;
        findingShortestPath(n);

        reverse(All(shortest_path));

        for (auto x : shortest_path)
        {
            cout << x << " ";
        }
        cout << endl;
    }
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