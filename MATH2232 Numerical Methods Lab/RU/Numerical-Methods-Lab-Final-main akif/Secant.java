package Akif;

public class Secant {

    // A function just holding the equation
    public static double func(double x) {
        return Equation.solve(x);
    }

    public static void Secant(double x0, double x1, double EPSILON) {

        int iteration = 0;

        if (func(x0) * func(x1) > 0) {
            System.out.println("Wrong Guess");
            return;
        }


        while (Math.abs(x1 - x0) >= EPSILON) {
            double x2 = ((x0 * func(x1)) - (x1 * func(x0))) / (func(x1) - func(x0));
            x0 = x1;
            x1 = x2;
            System.out.println("Iteration :" + (++iteration) + ", Root = " + x2);
        }
    }


}

