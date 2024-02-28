#include <bits/stdc++.h>
using namespace std;

class NewtonRaphson
{
public:
    double f(double x)
    {
        return x * x * x + 4 * x * x - 1;
    }

    double derif(double x)
    {
        return 3 * x * x + 8 * x;
    }

    void newton_raphson(double x)
    {
        double h;
        for (int i = 0; i < 200; i++)
        {
            h = f(x) / derif(x);
            x = x - h;
        }
        cout << "root = " << x << endl;
    }
};

int main()
{
    double x0;
    NewtonRaphson *NF = new NewtonRaphson();
    NF->newton_raphson(0.5);
}