#include<iostream>
#include<iomanip>

using namespace std;

int main(){

    int  a,b;
    int cnt=-1;

    cin>>a>>b;
    int number;

    number = a;

    up:
    number *=2;
    number = number *10+1;

    if(number!=b){
        goto up;
    }



    return 0;
}
