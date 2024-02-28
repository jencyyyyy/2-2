#include<iostream>
#include<cmath>
#define MAX 100

using namespace std;

int main(){

    float a[MAX][MAX],x,r1,r,y;

    int i,j,n,fact;

    cout<<"Enter no. of terms: ";
    cin>>n;

    cout<<"Enter Values of X:: "<<endl;

    for(i=0;i<n;i++)
         cin>>a[i][0];

    cout<<"Enter Values of Y:: "<<endl;

    for(i=0;i<n;i++)
         cin>>a[i][1];

    cout<<"Enter value of x for evaluating value of y"<<endl;
    cin>>x;


    for(j=2;j<n+1;j++){
        for(i=0;i<n-j+1;i++){
            a[i][j] = a[i+1][j-1]- a[i][j-1];
        }
    }

    cout<<"The difference table"<<endl;

    for(i=0;i<n;i++){
        for(j=0;j<=n-i;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    r = (x - a[0][0])/(a[1][0]-a[0][0]);

    y= a[0][1];
    r1=r;
    fact=1;

    for(i=2;i<=n;i++){

        y=y+(r1*a[0][i])/fact;
        fact=fact*i;
        r1 = r1*(r-(i-1));
    }

    cout<<"\n\nValue at "<<x <<" is "<<y<<endl;

    return 0;
}

