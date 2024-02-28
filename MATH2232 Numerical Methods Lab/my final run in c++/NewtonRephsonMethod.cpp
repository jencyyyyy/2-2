#include<iostream>
#include<math.h>
#define EPSILON 0.0001


using namespace std;

float equation(float x){
    return (x*x*x - 3*x - 5);
}

float derivative(float x){
    return (3*x*x-3);
}

void NewtonRephson(float x0,float terror, float i){

    int step =0;

    float f0,d0,x1,f1;

    do{
        f0 = equation(x0);
        d0 = derivative(x0);

        x1 = x0 - (f0/d0);
        f1 =equation(x1);
        cout<< "Iteration-"<<step << ":  x"<< step+1 << ": "<< x1 << " and f(x" <<step+1 << ") "<< f1<<endl;
        x0= x1;

        step++;

        if(step > i){
            cout<<"Not Convergent.";
            exit(0);
        }



    }while(fabs(f1)>terror);//if the absolute value of f1 is greater then the minimum tolerable error

    cout<< "The root of the equation: "<<x1 <<endl;

}

int main(){

    cout<<"---------------------"<< endl;
    cout<<"**Newton Rephson Method**"<< endl;
    cout<<"  *********************"<< endl;

    float a,terror,i;

    cout<<"Enter initial value: ";
    cin>> a;
    cout<<"Enter Tolerable Error: ";
    cin>> terror;
    cout<<"Enter No of iteration: ";
    cin>> i;

     NewtonRephson(a,terror,i);

    return 0;
}
