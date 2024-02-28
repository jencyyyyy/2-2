
#include<iostream>

using namespace std;
//Converts the Augmented matrix to Upper Triangular Matrix form
void convertToUpperTriangular(float a[3][4],int n){
    int i,j,x,y,k;
    float ratio;
    for( i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
         if(j>i)
         {
             ratio=a[j][i]/a[i][i];

             for(k=0;k<n+1;k++)
                a[j][k]=a[j][k] -( ratio * a[i][k]);

         }
      }
     }
}

//Performs Back Substitution to find values of Unknowns
void ApplyBackSubstitution(float a[3][4],float value[],int n)
{
    int i,j;
    float sum;
    value[n-1]=a[n-1][n]/a[n-1][n-1];

    for(i=n-2;i>=0;i--)
    {
        sum=0;
        for(j=i+1;j<n;j++)
            sum=sum+a[i][j]*value[j];
        value[i] = (a[i][n]-sum)/a[i][i];
    }
}
int main()
{
    int n;
    float sx=0,sy=0,sxy=0,sx2y=0,sx2=0,sx3=0,sx4=0,a,b,c;
    float value[3];

    cout<<"Enter no. of observations"<<endl;
    cin>>n;

    float x[n],y[n],augmented_matrix[3][4];

    cout<<"Enter values of x"<<endl;
    for(int i=0;i<n;i++)
      cin>>x[i];

    cout<<"Enter values of y\n"<<endl;

    for(int i=0;i<n;i++)
      cin>>y[i];

    //....................Computations ............
    for(int i=0;i<n;i++)
    {
        sx=sx+x[i];
        sy=sy+y[i];
        sxy=sxy+x[i]*y[i];
        sx2y=sx2y+x[i]*x[i]*y[i];
        sx2=sx2+x[i]*x[i];
        sx3=sx3+x[i]*x[i]*x[i];
        sx4=sx4+x[i]*x[i]*x[i]*x[i];
    }

    //....................finding a,b,c......................
    //Creating Augmented Matrix
    augmented_matrix[0][0]=sx2;
    augmented_matrix[0][1]=sx;
    augmented_matrix[0][2]=n;
    augmented_matrix[0][3]=sy;
    augmented_matrix[1][0]=sx3;
    augmented_matrix[1][1]=sx2;
    augmented_matrix[1][2]=sx;
    augmented_matrix[1][3]=sxy;
    augmented_matrix[2][0]=sx4;
    augmented_matrix[2][1]=sx3;
    augmented_matrix[2][2]=sx2;
    augmented_matrix[2][3]=sx2y;

    //Applying Gauss Elimination Method to find a,b,c
    convertToUpperTriangular(augmented_matrix,3);
    ApplyBackSubstitution(augmented_matrix,value,3);

    cout<<endl<<"Value of a = "<<value[0]<<endl<< "Value of b = " << value[1]<<endl<< "Value of c = "<<value[2]<<endl<<endl;
    //..........................Output...................
    cout<<endl<<"Equation of The Parabola: y="<< value[0] <<"x^2 +" << value[1] <<"x + "<<value[2]<<endl;
}
