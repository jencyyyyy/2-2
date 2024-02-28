#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.001

class calculate{
    public:
    double bisec(double x){
        return x*x*x - x*x + 2;
    }

    calculate(double a, double b){
        if(bisec(a) * bisec(b) >= 0){
            cout <<" Wrong assumption of a and b."<<endl;
            return;
        }

        double c=a;;
        while(b-a >= EPSILON ){
            c = (a+b)/2;
            if(bisec(c) ==0){
                break;
            }
            if(bisec(a)* bisec(c) < 0 ){

                b = c;
            }
            else
                a=c;
        }
        cout << "The value of Root is : " << c <<endl;

    }





};




int main() {
    int a = -500,b = 500;
    calculate bi(-500,500);

    return 0;


}
