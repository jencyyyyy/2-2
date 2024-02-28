public class lagrangeInterpolation {


    lagrangeInterpolation(double[] x, double[][] f, int n, double interpolationPoint) {
        double ans = interpolate(x, f, n, interpolationPoint);
//        System.out.println("Value of f(3) is : " + ans);
        System.out.println("lagrange Interpolation:");
        System.out.println("Value at " + interpolationPoint + " is " + String.format("%.6g%n", ans));
    }

    private double interpolate(double[] x, double[][] f, int n, double interpolationPoint) {
        double result = 0; // Initialize result

        for (int i = 0; i < n; i++) {
            // Compute individual terms of above formula
            double term = f[i][0];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    term = term * (interpolationPoint - x[j]) / (x[i] - x[j]);
            }

            // Add current term to result
            result += term;
        }

        return result;
    }

}
