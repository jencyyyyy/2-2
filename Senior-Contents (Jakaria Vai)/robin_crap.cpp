#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string text, patt;
    cin >> n;
    for (int l = 0; l < n; l++){
        int counts = 0;
        long long int pattvalue = 0, x, subtxt = 0;
        cin >> text >> patt;

        int lentxt, lenpatt;
        lentxt = text.size();
        lenpatt = patt.size();

        for (int i = 0; i < lenpatt; i++){
            pattvalue = pattvalue + patt[i] * pow(3, i);
        }
        int temp = lenpatt;

        for (int k = 0; k < lenpatt; k ++){
            subtxt = subtxt + text[k] * pow(3, k);
        }

        for (int j = 0; j < (lentxt - lenpatt + 1); j ++){
            x = text[j];
            if (pattvalue == subtxt){
                counts = counts + 1;
            }

            subtxt = ((subtxt - x)/3) + (text[temp] * pow(3, (lenpatt - 1)));
            temp++;
        }
        cout << endl << "Case "<< l + 1 << " : " << counts <<" times" << endl;
    }
    return 0;
}
