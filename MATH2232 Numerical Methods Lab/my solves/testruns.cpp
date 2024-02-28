#include<iostream>
#include<cmath>
#define MAX 100

using namespace std;

int main(){

    int i,k,j,n;

    float ar[MAX][MAX], multi, x[MAX],sum;

    cout<<"Enter no of equations: ";
    cin>>n;

    for(i=0;i<n;i++){
        cout<<"Enter co-efficients of "<< i+1<<"::: ";
        for(j=0;j<n+1;j++){
            cin>>ar[i][j];
        }
    }

    for(k=0;k<n-1;k++){
        for(i=k+1;i<n;i++){
                multi = ar[i][k]/ar[k][k];
                for(j=0;j<n+1;j++){
                    ar[i][j]= ar[i][j]- multi*ar[k][j];
                }
        }
    }

    x[n-1] = ar[n-1][n]/ar[n-1][n-1];

    for(i=n-2;i>=0;i--){
        sum = 0;
        for(j=i+1;j<n;j++){

            sum = sum + ar[i][j]*x[j];
        }
        x[i]= (ar[i][n]-sum)/ar[i][i];
    }

     for(i=0;i<n;i++){
        cout<<"\n"<<"x"<<i<<" is: "<<x[i];
     }

    return 0;
}
