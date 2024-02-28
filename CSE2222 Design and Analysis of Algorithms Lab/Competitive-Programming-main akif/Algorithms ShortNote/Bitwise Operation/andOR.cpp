/*
      & bitwise and
      | bitwise or
      ^ bitwise xor
      ~ 1s complement
      << Shift Left
      >> Shift Right

  */

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    /*
        AND and OR works like Digital System's bit operation
        All the ands and ors work in binary.
    */

    int a = 5; // 101
    int b = 7; // 111

    cout << "a & b (5&7):" << (a & b) << endl;
    cout << "a | b (5|7):" << (a | b) << endl;

    a = 8; // 1000
    b = 7; // 0111

    cout << "a & b (7&8):" << (a & b) << endl;
    cout << "a | b (7|8):" << (a | b) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}