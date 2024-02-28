 #include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>


#define   f(x)   x*x*x -3*x - 5

#define   g(x)   pow((3*x +5),(1.0/3))

using namespace std;

int main()
{
	 int step=1, N;
	 float a, c, e;


	 cout<< setprecision(6)<< fixed;

	 cout<<"Enter initial guess: ";
	 cin>>a;

	 cout<<"Enter tolerable error: ";
	 cin>>e;

	 cout<<"Enter maximum iteration: ";
	 cin>>N;

	 cout<<"Fixed Point Iteration Method"<< endl;

	 do
	 {
		  c = g(a);
		  cout<<"Iteration-"<< step<<":\t c = "<< setw(10)<< c<<" and f(c) = "<< setw(10)<< f(c)<< endl;

		  step = step + 1;

		  if(step>N)
		  {
			   cout<<"Not Convergent.";
			   exit(0);
		  }

		  a = c;

	 }while( fabs(f(c)) > e);

	 cout<< endl<<"Root is "<< c;

	 return(0);
}
