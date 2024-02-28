#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll grid_Traveller(ll m, ll n)
{
    if (m == 0 || n == 0)
        return 0;
    else if (m == 1 && n == 1)
        return 1;
    return (grid_Traveller(m - 1, n) + grid_Traveller(m, n - 1));
}

int main()
{
    ll r, c;
    cin >> r >> c;
    cout << grid_Traveller(r, c) << endl;
    //(1,1) == 1
    //(2,3) == 3
    //(3,3) == 6
    // (18,18) == 233606220
}