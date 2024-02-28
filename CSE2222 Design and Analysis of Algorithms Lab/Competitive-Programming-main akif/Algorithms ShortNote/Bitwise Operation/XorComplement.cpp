
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
        XOR and Complement works like Digital System's bit operation
        All the ands and ors work in binary.
    */

    // XOR

    int a = 5;    // 101
    int b = -123; // 111

    cout << "a ^ b (5^7):" << (a ^ b) << endl;
    cout << " NOT b :" << (~b) << endl;
    // Not (123) gives NOT (-123+1)


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

