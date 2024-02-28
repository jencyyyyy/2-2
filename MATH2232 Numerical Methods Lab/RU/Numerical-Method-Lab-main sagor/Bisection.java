public class Bisection {
    private double a, b, errorPass;

    Bisection(double x0, double x1, double errorLimit) {
        if (x1 < x0) {
            double temp = x1;
            x1 = x0;
            x0 = temp;
        }
        this.a = x0;
        this.b = x1;
        this.errorPass = errorLimit;
        double ans = bisectionMethod();
        if (ans == -999999.0) {
            System.out.println("Root is not in this range..!");
        } else {
            System.out.println("Root(Bisection Method) is: " + ans);
            double err = functionValue(ans);
            System.out.println("Error Detail: " + String.format("%.8f", err));
        }
    }

    private double functionValue(double x) {
        return ((x * x * x) - (x * x) + 2);
    }

    private double bisectionMethod() {
        if (functionValue(a) * functionValue(b) >= 0) {
            return -999999.0;
        }

        double expectedRoot = a;
        while (Math.abs(a - b) > errorPass) {
            expectedRoot = (a + b) / 2.0;

            if (Math.abs(functionValue(expectedRoot)) <= errorPass) {
                break;
            }
            if (functionValue(a) * functionValue(expectedRoot) < 0) {
                b = expectedRoot;
            } else {
                a = expectedRoot;
            }
        }
        return expectedRoot;
    }
}
