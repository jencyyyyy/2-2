//__SHERLOCK__
// Commitment leads to action.
// Date: 2021-05-04 15:33:01

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

vector<vector<ll>> graph(50);
vector<vector<ll>> weight(50);
ll dist[501];
ll n;

int tc = 1;

void dijkstra(ll src)
{
    // Weight, Node
    priority_queue<pair<int, int>> Q;
    Q.push({0, src});

    // INT MAXing for Min Operation
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0; // initializd

    while (!Q.empty())
    {
        auto x = Q.top();
        ll u = x.second; // Node Value
        ll p = -x.first; // Node's Weight
        Q.pop();

        // if (p > dist[u])
        //     continue;
        for (int i = 0; i < graph[u].size(); i++)
        {
            ll v = graph[u][i];  // Node Value
            ll w = weight[u][i]; // Node Weight

            ll temp = max(dist[u], w);

            if (temp < dist[v])
            {
                dist[v] = temp;
                Q.push({-dist[v], v});
            }
        }
    }
}

void solve()
{
    ll m, n1, n2, w;
    cin >> n >> m;
    memset(dist, 0, sizeof(dist));

    graph.resize(n);
    weight.resize(n);
    graph.clear();
    weight.clear();

    for (int i = 0; i < m; i++)
    {
        cin >> n1 >> n2 >> w;

        graph[n1].pb(n2);
        graph[n2].pb(n1);

        // Saving Weight
        weight[n1].pb(w);
        weight[n2].pb(w);
    }

    ll src;
    cin >> src;
    dijkstra(src);
    cout << "Case " << tc++ << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] != INT_MAX)
            cout << dist[i] << endl;
        else
            cout << "Impossible" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}