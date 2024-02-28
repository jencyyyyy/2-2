//C Program to Implement Simpson's 1/3 Rule

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

float findValueAt(float x){

    return 1/(1+x);
}


int main(){
    int n;
    float i,a,b,sum=0,h;
    //The initial Position (0) is treated as Even position
    int position_of_term=1;

    //Input
    cout<<"Enter values of a and b: ";
    cin>>a>>b;

    cout<<"Enter no. of Intervals: ";
    cin>>n;

    //....................Computations .....................

    h=(b-a)/n;
    sum = findValueAt(a) +findValueAt(b);

    for(i=a+h;i<b;i=i+h)
    {
       if(position_of_term %2 ==0)
         sum = sum + 2*findValueAt(i);
       else
         sum = sum + 4*findValueAt(i);
       position_of_term++;
    }
    sum = (h * sum)/3;

    //Print the Output
    cout<<"\nValue of The integral  = "<<sum;
}
