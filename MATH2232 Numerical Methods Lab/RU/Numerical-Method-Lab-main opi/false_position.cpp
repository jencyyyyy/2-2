#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

#define f(x) 3*x*x-6*x+2

class calculate
{
public:
    calculate(float xa,float xb)
    {
        int i=1;
        float x1,f1,fa,fb,e=1;
        do
        {
            fa=f(xa);
            fb=f(xb);
            if(fa*fb>0)
            {
                cout<< "x1 and x2 doesnot bracket the root";
                exit(0);
            }
            else
            {
                x1=(xa-(fa*(xb-xa))/(fb-fa)); //working formula
                f1=f(x1);
                e=fabs((xb-xa)/xb);
                if(fa*f1<0)
                {
                    xb=x1;
                }
                else
                {
                    xa=x1;
                }
                i++;
            }
        }
        while(e>=0.0001 && fa!=0 && i!=100);
        cout<< "nthe root of the equation="<<x1;
    }
};

int main()
{
    int i=1;
    float x0,x1,x2,f0,f1,f2,e=1;
    cout<< "enter the initial guess x1 and x2:";
    cin>>x1>>x2;
    calculate obj(x1,x2);
    return 0;
}