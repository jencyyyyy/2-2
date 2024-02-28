import java.text.*;
import java.math.*;

public class NewtonDivided {


    NewtonDivided(double value, int n, double[] x, double[][] y) {

        dividedDiffTable(x, y, n);

        double ans = applyFormula(value, x, y, n);
        System.out.println("Newton’s Divided Difference Interpolation:");
        System.out.println("Value at " + value + " is " + String.format("%.3f", ans));

    }

    // finding the product term
    private double productTerm(int i, double value, double[] x) {
        double pro = 1;
        for (int j = 0; j < i; j++) {
            pro = pro * (value - x[j]);
        }
        return pro;
    }

    // calculating divided difference table
    private void dividedDiffTable(double[] x, double[][] y, int n) {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
            }
        }
    }

    // Newton's divided difference formula
    private double applyFormula(double value, double[] x, double[][] y, int n) {
        double sum = y[0][0];

        for (int i = 1; i < n; i++) {
            sum = sum + (productTerm(i, value, x) * y[0][i]);
        }
        return sum;
    }

}
