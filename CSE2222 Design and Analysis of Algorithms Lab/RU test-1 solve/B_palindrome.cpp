#include <iostream>
using namespace std;

void solve();

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}

void solve(){
    int a;
    cin >> a;
    int arr[a];

    for (int i = 0; i < a; i++)
        cin >> arr[i];
    bool flag = false;


    for (int i = 0; i < a; i++)
    {
        for (int j = i + 2; j < a; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
            }
        }
    }

    if (a==1 || flag)cout << "YES" << endl;
        else cout << "NO" << endl;
}
