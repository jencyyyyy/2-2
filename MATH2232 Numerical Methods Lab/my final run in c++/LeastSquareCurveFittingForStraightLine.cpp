#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main(){
    int n,i;
    float sumX=0, sumY=0, sumXY=0, sumXX=0, a,b;

    cout<<"Enter no. of observations: ";
    cin>>n;

    float x[n],y[n],matrix[2][3];

   cout<<"Enter Values of X:: "<<endl;

    for(i=0;i<n;i++)
         cin>>x[i];

    cout<<"Enter Values of Y:: "<<endl;

    for(i=0;i<n;i++)
         cin>>y[i];

    //... .Computations....
    for(int i=0;i<n;i++){
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i]*y[i];
        sumXX += pow(x[i],2);
    }


    matrix[0][0]=n;
    matrix[0][1]=sumX;
    matrix[0][2]=sumY;
    matrix[1][0]=sumX;
    matrix[1][1]=sumXX;
    matrix[1][2]=sumXY;


    int factor=matrix[1][0]/matrix[0][0];

    for(int i=0;i<3;i++){
         matrix[1][i]=matrix[1][i]-factor*matrix[0][i];
    }


    /*
    cout<<endl<<"::The Augmented Matrix:::"<<endl;
    for (int i=0;i<2;i++){
       for (int j=0;j<3;j++){
         cout<<matrix[i][j] << " ";
       }
       cout<<endl;
    }*/

    b=matrix[1][2]/matrix[1][1];
    a=(matrix[0][2]-matrix[0][1]*b)/matrix[0][0];
    //........ ....Output... .......
    cout<<"Equation of The line: y =" << setprecision(3) <<a << " + "<<b <<"x"<<endl;



 return 0;
}
