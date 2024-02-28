//__SHERLOCK__

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

int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};

void solve()
{
    int no_of_coins, target;
    cin >> no_of_coins >> target;

    vector<int> coins(no_of_coins);

    for (int i = 0; i < no_of_coins; i++)
    {
        cin >> coins[i];
    }

    int INF = 1e6 + 5;

    int dp[target + 1];

    for (int i = 0; i <= target; i++)
    {
        dp[i] = INF;
    }

    dp[0] = 0;

    for (int i = 1; i <= target; i++)
    {
        for (auto c : coins)
        {
            if (i >= c && dp[i] > dp[i - c] + 1)
            {
                dp[i] = dp[i - c] + 1;
            }
        }
    }
    if (dp[target] >= INF)
    {
        cout << -1 << endl;
    }
    else
        cout << dp[target] << endl;

    // for (int i = 0; i <=target; i++)
    // {
    //     cout << dp[i] << " ";
    // }
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