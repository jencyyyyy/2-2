#include <bits/stdc++.h>
using namespace std;

class bisection
{
public:
    double f(double x)
    {
        return x * x * x + x * x - 1;
    }

    void bisect(double a, double b)
    {
        // double a = -500, b = 500;
        //cin >> a >> b;

        double c;
        double error = 0.001;

        while (abs(b - a) >= error)
        {
            c = (a + b) / 2;

            
         if ((f(a) * f(c)) <= 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        }

        cout << "root = " << c << endl;
    }
};


int main ()
{
    bisection *bi = new bisection();
    bi->bisect(500, -500);
}