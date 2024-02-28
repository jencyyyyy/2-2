// Date: 2022-02-26 01:08:39

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

void f(int n)
{
    cout << "Calling : F(" << n << ")" << endl;
    if (n == 1)
        return;
    f(n - 1);
}
vector<int> totalOutput;

void g(int n)
{
    cout << n << " ";
    totalOutput.push_back(n);

    if (n == 1)
        return;
    g(n - 1);
    g(n - 1);
    g(n - 1);
}

void solve()
{
    g(3); // O(2 ^ (N-1));
    cout << endl;
    cout << "Total Output : " << totalOutput.size() << endl;
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