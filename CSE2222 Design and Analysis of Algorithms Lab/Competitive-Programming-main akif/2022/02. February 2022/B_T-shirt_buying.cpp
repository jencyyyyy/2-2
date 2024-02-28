// Now my 1st solution should also work :)
// Date: 2022-02-20 02:03:36

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
int n;

void F(int n)
{
    if (n == 1)
        return;
        
    F(n-1);
}



void solve()
{
    ll no_of_shirts;
    cin >> no_of_shirts;

    // Both Part Matching Map
    vector<ll> prices(no_of_shirts);
    vector<ll> fronts(no_of_shirts);
    vector<ll> backs(no_of_shirts);

    map<ll, pair<ll, ll>> pricesWithColours;
    map<ll, set<ll>> colourWithPrice;

    for (int i = 0; i < no_of_shirts; i++)
    {
        cin >> prices[i];
    }
    for (int i = 0; i < no_of_shirts; i++)
    {
        cin >> fronts[i];
    }
    for (int i = 0; i < no_of_shirts; i++)
    {
        cin >> backs[i];
    }

    // Mapping
    for (int i = 0; i < no_of_shirts; i++)
    {
        pricesWithColours[prices[i]] = make_pair(fronts[i], backs[i]);
        colourWithPrice[fronts[i]].insert(prices[i]);
        colourWithPrice[backs[i]].insert(prices[i]);
    }

    ll q;
    cin >> q;

    while (q--)
    {
        ll choice, sold = 0;
        cin >> choice;

        if (colourWithPrice[choice].size() > 0)
        {
            auto x = colourWithPrice[choice].begin();
            sold = *x;
        }

        if (sold)
        {

            cout << sold << " ";
            ll shirt_front = pricesWithColours[(sold)].first;
            ll shirt_back = pricesWithColours[(sold)].second;

            colourWithPrice[shirt_front].erase(sold);
            colourWithPrice[shirt_back].erase(sold);
            // pricesWithColours[*sold].first = -1;
            // pricesWithColours[*sold].second = -1;
            pricesWithColours.erase(sold);
        }
        else
            cout << -1 << " ";
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
