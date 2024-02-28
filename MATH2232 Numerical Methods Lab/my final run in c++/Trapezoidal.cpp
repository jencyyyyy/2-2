//C Program to Implement Trapezoidal Rule

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

float findValueAt(float x)
{
    return 1/(1+x);
}
int main()
{
    int n;
    float i,a,b,sum=0,h;

    //Input
    cout<<"Enter values of a and b: ";
    cin>>a>>b;

    cout<<"Enter no. of Intervals: ";
    cin>>n;


    //....................Computations .....................

    h=(b-a)/n;

    sum = findValueAt(a) + findValueAt(b);// sum of initial and final point

    for(i=a+h;i<b;i=i+h){
        sum = sum + 2*findValueAt(i);
    }
    sum = (h * sum)/2;
    //Print the Output
    cout<<"\nValue of The integral  = "<<sum;

}
