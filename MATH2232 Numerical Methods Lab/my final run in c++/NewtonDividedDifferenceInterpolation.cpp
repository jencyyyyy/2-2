// CPP program for implementing
// Newton divided difference formula
#include<iostream>
#include<iomanip>
#include<cmath>
#define MAX 100
using namespace std;


// Function to find the product term
float proterm(int i, float value, float x[])
{
	float pro = 1;
	for (int j = 0; j < i; j++) {
		pro = pro * (value - x[j]);
	}
	return pro;
}

// Function for calculating
// divided difference table
void dividedDiffTable(float x[], float y[][MAX], int n){
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
		}
	}
}

// Function for applying Newton's
// divided difference formula
float applyFormula(float value, float x[],float y[][MAX], int n)
{
	float sum = y[0][0];

	for (int i = 1; i < n; i++) {
	sum = sum + (proterm(i, value, x) * y[0][i]);
	}
	return sum;
}

// Function for displaying
// divided difference table
void printDiffTable(float x[MAX],float y[][MAX],int n)
{
    cout<<endl<<"The difference table"<<endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
                if(j==0){
                    cout<<setw(2) <<x[i]<<"  ";
                }
			cout<< setprecision(4)<<setw(4) << y[i][j] << "\t ";
		}
		cout << "\n";
	}
}

// Driver Function
int main()
{
	// number of inputs given
	int n;
	float value, sum, y[MAX][MAX],x[MAX];

    int i;

    cout<<"Enter no. of terms: ";
    cin>>n;

    cout<<"Enter Values of X:: "<<endl;

    for(i=0;i<n;i++)
        cin>>x[i];

    cout<<"Enter Values of Y:: "<<endl;

    for(i=0;i<n;i++)
         cin>>y[i][0];

	// calculating divided difference table
	dividedDiffTable(x, y, n);

	// displaying divided difference table
	printDiffTable(x,y,n);

	// value to be interpolated
	cout<<"Enter value of x for evaluating value of y"<<endl;
    cin>>value;

	// printing the value
	cout << "\nValue at " << value << " is "<< applyFormula(value, x, y, n) << endl;
	return 0;
}
