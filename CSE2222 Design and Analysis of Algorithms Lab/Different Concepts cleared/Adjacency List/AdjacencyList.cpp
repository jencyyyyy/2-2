#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


int main(){
    freopen("input.txt","r",stdin);

    vector <int> vec[5];

    int node,edge;

    cin>>node>>edge;

    int n1,n2;

    for(int i=0;i<edge;i++){
        cin>>n1>>n2;
        vec[n1].push_back(n2);
        vec[n2].push_back(n1);
    }

    for(int j=0;j<5;j++){
        for(int i=0;i<vec[j].size(); i++){
            cout<< vec[j][i]<< " ";
        }
        cout<<endl;
    }

    cout<< "Neighbors of 3: ";
     for(int i=0;i<vec[3].size();i++){
        cout<< vec[3][i]<< " ";
    }

    return 0;
}



/*
//how to print all elements of a vector array
int main(){
    int i,j;
    vector <int> vec[3];
    vec[0].push_back(10);
    vec[0].push_back(15);
    vec[2].push_back(31);

    for( j=0;j<3;j++){
        for(i=0;i<vec[j].size(); i++){
            cout<< vec[j][i]<< " ";
        }
        cout<<endl;
    }


    return 0;
}
*/



/*

//vector
int main(){

    vector <int> vec;
    vec.push_back(10);
    vec. push_back(15);

    cout<<vec[2]<<endl;

    for(int i=0;i<vec.size();i++){
        cout<< vec[i]<< " ";
    }

    return 0;
}
*/
