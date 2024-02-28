public class Secant {
    Secant(double x0, double x1, double acceptedError) {
        double root = secantMethod(x0, x1, acceptedError);

        if (root == -999999.0) {
            System.out.println("Root is not in this range..!");
        } else {
            System.out.println("Root(Secant Method) is: " + root);
            double err = functionValue(root);
            System.out.println("Error Detail: " + String.format("%.8f", err));
        }
    }

    private double functionValue(double x) {
        return ((x * x * x) - (x * x) + 2);
    }

    private double secantMethod(double x0, double x1, double acceptedError) {
        int maxIteration = 10000;
        double expectedRoot = -999999.0;
        while (maxIteration != 0) {
            double res0 = functionValue(x0);
            double res1 = functionValue(x1);

            expectedRoot = x1 - (res1 * (x1 - x0) / (res1 - res0));
            double expRootvalue = functionValue(expectedRoot);

            double error = Math.abs((expRootvalue - x1) / expRootvalue);
            if (Math.abs(expRootvalue) <= acceptedError) break;
            x0 = x1;
            x1 = expectedRoot;
            maxIteration--;
        }
        return expectedRoot;
    }
}
