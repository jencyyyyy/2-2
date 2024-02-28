#include<iostream>
#include <cmath>

using namespace std;

int main(){

    int i,k,j,n;

    float am[20][20],multiplyFactor,x[10],sum;

    cout<<"How many equations: ";
    cin>>n;

    for(i=0;i<n;i++){
        cout<<"Enter the co-efficients of Equation: "<<i+1 <<" ";
        for(j=0; j<n+1;j++){

            cin>>am[i][j];
        }
    }

/*
    //Check if the input is taken correctly

        for(i=0;i<n;i++){

        for(j=0; j<n+1;j++){

            cout<<am[i][j] << " ";
        }
        cout<<endl;
    }
*/

    for(k=0;k<n-1;k++){

        for(i=k+1;i<n;i++){

            multiplyFactor=am[i][k]/am[k][k];//  e.g: am10 / am00

            for(j=0;j<n+1;j++){

                am[i][j]=am[i][j]-(am[k][j]*multiplyFactor);// R1 = R1 - R0*mul
            }
        }
    }

    //calculate the last variable value
    x[n-1]=am[n-1][n]/am[n-1][n-1];

    for(i=n-2;i>=0; i--){
        sum=0;

        for(j=i+1;j<n; j++){

            sum=sum+am[i][j]*x[j];
        }
        x[i]=(am[i][n]-sum)/am[i][i];
    }

     for(i=0;i<n;i++){
        cout<<"\n"<<"x"<<i<<" is: "<<x[i];
     }

    return 0;
}


/*
3
2 3 5 23
3 4 1 14
6 7 2 26

x0 =1
x1 = 2
x2= 3

*/
