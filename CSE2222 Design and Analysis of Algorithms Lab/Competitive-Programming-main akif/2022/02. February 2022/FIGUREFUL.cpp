// Date: 2022-02-20 01:43:23

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace std;
#ifdef AKIF
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')' << ':', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ll long long
#define All(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;

    ll x, y;
    map<pair<int, int>, string> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        string name;
        cin >> name;
        mp[make_pair(x, y)] = name;
    }

    // Search
    ll q;
    cin >> q;

    while (q--)
    {
        cin >> x >> y;
        cout << mp[{x, y}] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef AKIF
#endif
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}