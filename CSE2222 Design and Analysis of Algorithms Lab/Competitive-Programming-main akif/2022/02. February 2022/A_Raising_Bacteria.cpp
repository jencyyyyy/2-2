// Trying bit with STL :)
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll x;
    cin >> x;
    bitset<64> b = x;
    cout << b.count() << endl;
}