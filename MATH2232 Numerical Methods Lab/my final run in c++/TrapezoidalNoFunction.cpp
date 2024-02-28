


#include<iostream>
#include<iomanip>
#include<cmath>
#define MAX 100

using namespace std;


int main(){

  //  freopen("noFunction.txt","r",stdin);
    int n;
    float a,b,sum=0,h;

    float x[MAX], y[MAX];

    cout<<"Enter no. of Intervals: ";
    cin>>n;

    cout<<"Enter values of X: ";
    for(int j=0;j<=n;j++){
            cin>>x[j];
    }

    cout<<"Enter values of Y: ";
    for(int j=0;j<=n;j++){
            cin>>y[j];
    }

    cout<<"Enter values of a and b: ";
    cin>>a>>b;

    h=(b-a)/(n);

    sum = y[0] + y[n];


    for(int i=1;i<n;i++){
         sum += 2*y[i];
    }
    sum = (h * sum)/2;


    cout<<"\nValue of The integral  = "<<sum;
}

