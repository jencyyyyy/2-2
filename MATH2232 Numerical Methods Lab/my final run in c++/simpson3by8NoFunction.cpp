#include<iostream>
#include<iomanip>
#include<cmath>
#define MAX 100

using namespace std;


int main(){

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

       if(i%3 ==0)
         sum = sum + 2*y[i];
       else
         sum = sum + 3*y[i];
    }
    sum = (3*h * sum)/8;

    //Print the Output
    cout<<endl<<"Value of The integral  = "<<sum;
}

