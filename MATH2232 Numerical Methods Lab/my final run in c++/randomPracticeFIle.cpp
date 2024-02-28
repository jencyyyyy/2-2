
#include<iostream>
#include<cmath>
#define MAX 100

using namespace std;

int main(){

    float x[MAX],y[MAX],term,sum=0,t;

    int i,j,n;

    cout<<"Enter no. of terms: ";
    cin>>n;

    cout<<"Enter Values of X:: "<<endl;

    for(i=0;i<n;i++)
         cin>>x[i];

    cout<<"Enter Values of Y:: "<<endl;

    for(i=0;i<n;i++)
         cin>>y[i];

    cout<<"Enter value of x for evaluating value of y"<<endl;
    cin>>t;

    //calculation
    for(i=0;i<n;i++){
        term=1;
        for(j=0;j<n;j++){
            if(i!=j){
                term *=(t-x[j])/(x[i]-x[j]);
            }
        }
        sum += term*y[i];
    }



    cout<<"Sum is: "<<sum<<endl;

    return 0;
}



