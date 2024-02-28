// Date: 2022-02-20 01:07:31

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
    ll N;
    cin >> N;
    map<ll, ll> mp;
    for (int i = 0; i < N; i++)
    {
        ll input;
        cin >> input;
        mp[input]++;
    }

    ll answer = 1;
    for (auto item : mp)
        answer = max(answer, item.second);

    cout << answer << endl;
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