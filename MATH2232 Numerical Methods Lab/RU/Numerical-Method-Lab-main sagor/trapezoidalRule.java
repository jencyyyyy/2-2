public class trapezoidalRule {

    trapezoidalRule(double x0, double xn, int n) {
        // n = Number of grids. Higher
        // value means more accuracy

        System.out.println("Trapezoidal Rule:");
        double ans = trapezoidal(x0, xn, n);
        System.out.println("approximation of the integral is: " + String.format("%.5f", ans));
    }

    private double function(double x) {

        return 1 / (1 + x * x);
    }

    // evaluate the value of integral
    private double trapezoidal(double a, double b, double n) {

        double h = (b - a) / n;

        // Computing sum of first and last terms
        double sum = function(a) + function(b);

        // Adding middle terms
        for (int i = 1; i < n; i++) {
            sum += 2 * function(a + i * h);
        }

        return (h / 2) * sum;
    }

}
