#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

#define    f(x)   x*x*x - 3*x - 5
#define   g(x)  3*x*x - 3

using namespace std;
class calculate
{
public:
    calculate(float x0,float e,int N)
    {
        float x1,f0,f1,g0;
        int step=1;
        do
        {
            g0 = g(x0);
            f0 = f(x0);
//            if(g0 == 0.0)
//            {
//                cout<<"Mathematical Error.";
//                exit(0);
//            }


            x1 = x0 - f0/g0;


            cout<<"Iteration-"<< step<<":\t x1 = "<< x1<<" and f(x1) = "<< f(x1)<< endl;
            x0 = x1;

            step = step+1;

            if(step > N)
            {
                cout<<"Not Convergent.";
                exit(0);
            }

            f1 = f(x1);

        }
        while(fabs(f1)>e);
        cout<< endl<<"Root is: "<< x1;
    }
};

int main()
{
    float x0, e;
    int N;

    /* Inputs */
    cout<<"Enter initial guess: ";
    cin>>x0;
    cout<<"Enter tolerable error: ";
    cin>>e;
    cout<<"Enter maximum iteration: ";
    cin>>N;
    cout<<"Newton Raphson Method"<< endl;
    calculate obj1(x0,e,N);

    return 0;
}
