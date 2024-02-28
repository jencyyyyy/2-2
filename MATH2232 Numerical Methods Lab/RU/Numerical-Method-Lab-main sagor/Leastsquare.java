import java.util.Arrays;

public class Leastsquare {

    Leastsquare(int[] x, int[] y) {
        double[] ans = leastSquare(x, y);
        System.out.println("Least Square Method: ");
        System.out.println("a: " + ans[0]);
        System.out.println("b: " + ans[1]);
        System.out.println("Line is: ");
        System.out.println("Y = " + ans[0] + " + " + ans[1] + " X");
    }

    private double[] leastSquare(int[] x, int[] y) {
        double[] ab = new double[2];

        int n = x.length;

        // sum of array x
        int sumofX = Arrays.stream(x).sum();

        // sum of array y
        int sumofY = Arrays.stream(y).sum();

        // for sum of product of x and y
        int sumofproductofXY = 0;

        // sum of square of x
        int sx2 = 0;
        for (int i = 0; i < n; i++) {
            sumofproductofXY += x[i] * y[i];
            sx2 += x[i] * x[i];
        }
        double b = (double) (n * sumofproductofXY - sumofX * sumofY)
                / (n * sx2 - sumofX * sumofX);

        double meanY = sumofY / n;
        double meanX = sumofX / n;
        double a = meanY - b * meanX;

        ab[0] = a;
        ab[1] = b;

        return ab;
    }
}
