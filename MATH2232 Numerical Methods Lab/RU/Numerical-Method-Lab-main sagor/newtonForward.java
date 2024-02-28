public class newtonForward {


    newtonForward(double[] x, double[][] y, int n, double interpolationPoint) {

        // Calculating the forward difference
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++)
                y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }

        // initializing u and sum
        double sum = y[0][0];
        double u = (interpolationPoint - x[0]) / (x[1] - x[0]);
        for (int i = 1; i < n; i++) {
            sum = sum + (u_cal(u, i) * y[0][i]) /
                    fact(i);
        }

        System.out.println("Newton's Forward Interpolation:");
        System.out.println("Value at " + interpolationPoint + " is " + String.format("%.6g%n", sum));

    }

    // calculating u mentioned in the formula
    private double u_cal(double u, int n) {
        double temp = u;
        for (int i = 1; i < n; i++)
            temp = temp * (u - i);
        return temp;
    }

    // calculating factorial of given number n
    private int fact(int n) {
        int f = 1;
        for (int i = 2; i <= n; i++)
            f *= i;
        return f;
    }
}
