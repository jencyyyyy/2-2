#include<iostream>

using namespace std;


int main(){

    int s;
    cin>>s;


    for(int t=0;t<s;t++){

        int n;

        cin>>n;

        vector<pair<int,int>> travel[n];
        map<string,int>city;

        string str;

        for(int i=0; i<n; i++){

            cin>>str;
            city.insert({str,i});

            int p;
            cin>>p;



            for(int i=0;i<p;p++){

                int nr,cost;
                cin>>nr>>cost;
                nr--;// amra to code a index 0 diye korachi, r input a 1 diye hocche tai input a index ta -- kore diyechi
                travel[i].push_back({nr,cost});
            }





        }


    }



    return 0;
}
