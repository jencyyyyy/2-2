package Akif;

public class NewtonRaphson {

    // A function just holding the equation
    public static double func(double x) {
        return x * x * x - 2 * x - 5;
    }

    public static double funcDerivatives(double x) {
        return 3 * x * x - 2;
    }

    public static void NewtonRaphson(double a, double EPSILON) {
        int iteration = 0;

        double h = func(a) / funcDerivatives(a); // F(Xn) / F'(Xn)

        while (Math.abs(h) >= EPSILON) {

            h = func(a) / funcDerivatives(a);
            a = a - h; // As the formula is : Xn+1 = Xn - (F(Xn) / F'(Xn))
            System.out.println("Iteration :" + (++iteration) + ", Root = " + a);
        }
    }


}

