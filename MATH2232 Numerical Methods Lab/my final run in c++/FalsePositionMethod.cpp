#include<iostream>
#include <iomanip>
#include<math.h>
//#define EPSILON 0.0001
using namespace std;

float equation(float x){
    return (x*x*x - 3*x - 5);
}

bool falsePosition(float a, float b, float terror){

    int step=0;

    if(equation(a)*equation(b) >0){
        cout<< "Values of a and b doesn't bracket the equation"<<endl;
        return true;
    }

    double c;

    while(fabs(equation(c))>terror){

        c = ((a*equation(b))-(b*equation(a)))/(equation(b)-equation(a));

         cout<< "Iteration-"<<setw(2) <<step+1 << ":  c: "<< setw(10)<<c << " and f(c) "<< setw(15)<<equation(c)<<endl;



        if(equation(c)==0){
            break;
        }

        if(equation(a)*equation(c)<0){
            b = c;

        }else{
            a = c;
        }
        step++;
    }

    cout<< "The root of the equation within given range: "<<c <<endl;

     return false;
}

int main(){

    bool check=true;
     cout<< setprecision(6)<<fixed;

    while(check){

        cout<<"---------------------"<< endl;
        cout<<"False Position Method"<< endl;
        cout<<"*********************"<< endl;

        float a,b,terror;

        cout<<"Enter lower limit: ";
        cin>> a;
        cout<<"Enter Upper limit: ";
        cin>> b;
        cout<<"Enter Tolerable Error: ";
        cin>> terror;

        check = falsePosition(a,b,terror);
    }

    return 0;
}
