#include<iostream>
#include <iomanip>
#include<math.h>

#define EPSILON 0.0001
using namespace std;

float equation(float x){
    return (x*x*x - 3*x - 5);
}

void secant(float x0, float x1,float i){

    int step =0;

    float x2,f0,f1,f2;

    do{
        f0 = equation(x0);
        f1 = equation(x1);

        if(f0 == f1){
            cout<<"Lower limit and Upper Limit CANNOT be same.";
            exit(0);
        }

        x2 = x1 - ((f1 * (x1-x0))/(f1-f0));

        f2 = equation(x2);
        cout<< "Iteration-"<<step<< ":  x"<< (step+2) << ": "<< setw(10)<<x2 << " and f(x" <<(step+2) << ") "<<setw(10)<< f2<<endl; //setw() function sets the width of the value

        x0 = x1;
        x1=x2;
        f0=f1;
        f1= f2;

        step++;

        if(step > i){
            cout<<"Not Convergent.";
            exit(0);
        }

    }while(fabs(f2)>=EPSILON);//if the absolute value of f1 is less then the minimum tolerable error

    cout<< "The root of the equation: "<<x2 <<endl;
}

int main(){
    cout<<"---------------"<< endl;
	 cout<<"Secant Method"<< endl;
	 cout<<"**************"<< endl;

    float a,b,i;

    cout<<"Enter lower limit (x0): ";
    cin>> a;

    cout<<"Enter Upper limit (x1): ";
    cin>> b;

    cout<<"Enter No of iteration: ";// give higher number of iteration
    cin>> i;

    secant(a,b,i);

    return 0;
}

