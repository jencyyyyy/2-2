// Week 1 : STL
// https://vjudge.net/contest/475626#problem/A

// Date: 2022-02-20 00:58:52

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

map<string, int> mp;

void solve()
{
    string str;
    cin >> str;
    if (mp[str] == 0)
    {
        cout << "NO" << endl;
        mp[str]++;
    }
    else
        cout << "YES" << endl;
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