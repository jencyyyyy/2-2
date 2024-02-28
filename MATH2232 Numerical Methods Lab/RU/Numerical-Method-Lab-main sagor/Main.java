public class Main {

    public static void main(String[] args) {
//        Bisection doBisection = new Bisection(-7, 7, 0.00001);
//        System.out.println();
//        falsePosition falseP = new falsePosition(-7, 7, 0.00001);
//        System.out.println();
//        newtonRaphson newton = new newtonRaphson(-20.0, 0.00001);
//        System.out.println();
//        Secant sec = new Secant(-2, 2, 0.00001);
//        System.out.println();
//
//        int X[] = {95, 85, 80, 70, 60};
//        int Y[] = {90, 80, 70, 65, 60};
//        Leastsquare least = new Leastsquare(X, Y);


//        double mat[][] = {{2.0, 1.0, 1.0, 10.0},
//                {3.0, 2.0, 3.0, 18.0},
//                {1.0, 4.0, 9.0, 16.0}};
//
//        gaussMethod gaussM = new gaussMethod(mat, 3);
//        System.out.println();
//        gaussJordanMethod gaussJM = new gaussJordanMethod(mat);
//        System.out.println();
//
//
//        double x[] = {1, 3, 5, 7};
//
//        // y[][] is used for difference table
//        // with y[][0] used for input
//        double y[][] = new double[4][4];
//        y[0][0] = 24;
//        y[1][0] = 120;
//        y[2][0] = 336;
//        y[3][0] = 720;
//
//        newtonForward newtonInterpo = new newtonForward(x, y, 4, 8);
//        System.out.println();
//
//        lagrangeInterpolation lagrange = new lagrangeInterpolation(x, y, 4, 8);
//        System.out.println();


        System.out.println();

        int n = 4;
        double value, sum;

        double x[] = {5, 6, 9, 11};

        // y[][] is used for divided difference
        // table where y[][0] is used for input
        double y[][] = new double[10][10];
        y[0][0] = 12;
        y[1][0] = 13;
        y[2][0] = 14;
        y[3][0] = 16;

//        NewtonDivided newDiv = new NewtonDivided(7, n, x, y);
        System.out.println();

        trapezoidalRule trapeRule = new trapezoidalRule(0, 1, 6);
        System.out.println();

//        simpsonRule simp = new simpsonRule(4, 5.2, 6);
        simpsonRule simp = new simpsonRule(0, 1, 9);
        System.out.println();

        eulerMethod euler = new eulerMethod(0, 1, 0.025, 0.1);
        System.out.println();

    }
}
