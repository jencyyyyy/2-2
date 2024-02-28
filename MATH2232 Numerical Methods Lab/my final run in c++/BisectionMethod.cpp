#include<iostream>
#include <iomanip>
// #define EPSILON 0.0001
using namespace std;
// input= lower=2 ,upper=5
float equation(float x);

bool bisection(float a, float b, float e);

int main(){
        bool check=true;

        while(check){

        cout<<"---------------------"<< endl;
        cout<<"**Bisection Method**"<< endl;
        cout<<"  ****************"<< endl;

        float a,b,terror;

        cout<<"Enter lower limit: ";
        cin>> a;
        cout<<"Enter Upper limit: ";
        cin>> b;
        cout<<"Enter Tolerable Error: ";
        cin>> terror;

         check = bisection(a,b,terror);
        }

    return 0;
}


float equation(float x){

    return (x*x*x - 3*x - 5);
}

bool bisection(float a, float b, float e){

    int step=0;
    if(equation(a)*equation(b) >0){
        cout<< "Values of a and b doesn't bracket the equation"<<endl;
        return true;
    }

    double c;

    while(equation(b)-equation(a) >= e ){
        c = (a+b)/2;

        if(equation(c)==0){
            break;
        }

        cout<< "Iteration-"<<setw(2) <<step+1 << ":  c: "<< setw(10)<<c << " and f(c) "<< setw(12)<<equation(c)<<endl;

        step++;
        if(equation(a)*equation(c)<0){
            b = c;
        }else{
            a = c;
        }
    }

    cout<<endl<< "The root of the equation within given range: "<<setprecision(4)<<c <<endl;

    return false;
}
