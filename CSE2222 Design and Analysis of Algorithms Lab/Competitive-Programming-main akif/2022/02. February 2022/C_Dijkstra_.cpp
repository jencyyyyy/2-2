//__SHERLOCK__
// Commitment leads to action.
// Date: 2022-02-15 18:31:09

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
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

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << gap << p.second << ')';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifdef AKIF
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')' << ':', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ll long long
#define lll __int128_t
#define pb push_back
#define mp make_pair
#define All(x) (x).begin(), (x).end()
#define sz(z) (int)((z).size())
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
mt19937 rng((uint_fast32_t)chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;



ll dist[100005];
int parent[100005];

ll n, m;

vector<pair<ll, ll>> graph[100005];
stack<ll> shortestPath;

void printPath()
{
    ll par = n;

    while (par != -1)
    {
        shortestPath.push(par);
        par = parent[par];
        // cout << par << " ";
    }
}

void dijkstra(ll src)
{

    priority_queue<pair<int, int>> Q;
    Q.push({0, src});

    for (int i = 1; i <= n; i++)
        dist[i] = LLONG_MAX;

    dist[src] = 0; // initializd
    parent[src] = -1;

    while (!Q.empty())
    {
        auto x = Q.top();
        ll u = x.second; // Node Value //1
        ll p = -x.first; // Node's Weight //
        Q.pop();

        if (p > dist[u])
            continue;

        for (int i = 0; i < graph[u].size(); i++)
        {
            ll v = graph[u][i].first; // Node Value
            // cout<<"Node Value: "<<v<<endl;
            ll w = graph[u][i].second; // Node Weight
            // cout<<"Node Weight: "<<w<<endl;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                Q.push({-dist[v], v});
            }
        }
    }
}

void solve()
{
    memset(parent, -1, sizeof(parent));

    cin >> n >> m;
    int from, to, weight;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> weight;
        graph[from].pb({to, weight});
        graph[to].pb({from, weight});
    }

    dijkstra(1);

    if (dist[n] == LLONG_MAX)
    {
        cout << "-1" << endl;
        return;
    }

    printPath();

    while (!shortestPath.empty())
    {
        cout << shortestPath.top() << " ";
        shortestPath.pop();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}