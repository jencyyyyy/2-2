// CPP Program to interpolate using
// newton backward interpolation
#include <bits/stdc++.h>
#define MAX 100
using namespace std;

// Calculation of u mentioned in formula
float u_cal(float u, int n)
{
	float temp = u;
	for (int i = 1; i < n; i++)
		temp = temp * (u + i);
	return temp;
}

// Calculating factorial of given n
int fact(int n)
{
	int f = 1;
	for (int i = 2; i <= n; i++)
		f *= i;
	return f;
}

int main()
{
	// number of values given
	int n,v ;
	float x[MAX];
	float value;

	// y[][] is used for difference
	// table and y[][0] used for input
	float y[MAX][MAX];

    cout<<"Enter the total number of set of points : ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"\nX"<<i<<" = ";
        cin>>x[i];

        cout<<"Y"<<i<<" = ";
        cin>>y[i][0];
    }

    cout<<"\nEnter the value of x for which y is to be computed : ";
    cin>>value;
	// Calculating the backward difference table
	for (int i = 1; i < n; i++) {
		for (int j = n - 1; j >= i; j--)
			y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
	}

	// Displaying the backward difference table
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			cout << setw(4) << y[i][j]
				<< "\t";
		cout << endl;
	}

	// Value to interpolate at


	// Initializing u and sum
	float sum = y[n - 1][0];
	float u = (value - x[n - 1]) / (x[1] - x[0]);
	for (int i = 1; i < n; i++) {
		sum = sum + (u_cal(u, i) * y[n - 1][i]) /
									fact(i);
	}

	cout << "\n Value at " << value << " is "
		<< sum << endl;
	return 0;
}
