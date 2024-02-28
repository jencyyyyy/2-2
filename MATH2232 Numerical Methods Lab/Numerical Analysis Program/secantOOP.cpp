#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.001

class calculate {

    public:
    calculate(double x0, double x1){

        double dx1 = (func(x1) - func(x0)) / (x1 - x0);
        double x2 = x1 - (func(x1) / dx1);

        while (func(x2) >= EPSILON)
        {
            x2 = x1 - (func(x1) / dx1);

            x0 = x1;
            x1 = x2;
        }
        
        cout << "The value of Root is : " << x2 <<endl;
    }

    double func(double x){
        return x*x*x - x*x + 2;
    }
};

int main()
{
    double x0 = -10, x1 = 10;
    calculate secant(x0,x1);
    return 0;
}