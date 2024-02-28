package Akif;

public class Bisection {

    // A function just holding the equation
    public static double func(double x){
        return Equation.solve(x);
    }


    public static void bisect(double a, double b, double EPSILON) {

        double root =0;
        System.out.println("Using Bisection Method:\n");

        // Case 1 : If initial guess is wrong
        if (func(a) * func(b) >= 0) {
            System.out.println("Initial guess is wrong.(A="+a+",B="+b);
            return;
        }


        int iteration_count = 0;

        while (b - a >= EPSILON) {

            System.out.println("Iteration : " + (++iteration_count));

           root = ((a + b) / 2);

            // Case 2: Root is exactly at middle point
            if (func(root) == 0.0) {
                break;

            // Case 3: F(a)*F(root) < 0
            } else if (func(a) * func(root) < 0) {
                b = root;
            }

            // Case 4: F(a)*F(root) > 0
            else {
                a = root;
            }

            System.out.println("a = " + a + ", b = " +b + ", root = " + root +"\n");
        }
        System.out.println("Finally, Using Bisection Method, the root is " +root);


    }
}
