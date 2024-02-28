public class simpsonRule {


    simpsonRule(double lower_limit, double upper_limit, int n) {

        double ans = simpsons_(lower_limit, upper_limit, n);

        System.out.println("Simpson’s 1/3 Rule:");
        System.out.println("approximation of the integral is: "+String.format("%.5f", ans));
    }

    // Function to calculate f(x)
    private double function(double x) {
//        return (double) Math.log(x);
        return 1 / (1 + x * x);
    }

    // Function for approximate integral
    private double simpsons_(double lowerLimit, double upperLimit, int n) {

        double h = (upperLimit - lowerLimit) / n;

        double[] x = new double[10];
        double[] fx = new double[10];

        // Calculating values of x and f(x)
        for (int i = 0; i <= n; i++) {
            x[i] = lowerLimit + (i * h);
            fx[i] = function(x[i]);
        }

        double res = 0;
        for (int i = 0; i <= n; i++) {
            if (i == 0 || i == n) {
                res += fx[i];
            } else if (i % 2 != 0) {
                res += 4 * fx[i];
            } else {
                res += 2 * fx[i];
            }
        }

        res = res * (h / 3);
        return res;
    }

}
