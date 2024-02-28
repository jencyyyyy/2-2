#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.001

class calculate{
    public:
    calculate(double x){

    double h = func(x) / dfunc(x);

    while (func(x) >= EPSILON)
    {
        h = func(x) / dfunc(x);
        x = x - h;
            
    }
        
    cout << "The value of Root is : " << x <<endl;
    
    }

    double func(double x){
        return x*x*x - x*x + 2;
    }

    double dfunc(double x){
        return 3*x*x - 2*x;
    }


};

int main()
{
    double x0 = 20;
    calculate c(x0);
    return 0;
}