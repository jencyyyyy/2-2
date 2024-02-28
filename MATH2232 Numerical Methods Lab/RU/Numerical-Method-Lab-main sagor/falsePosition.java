public class falsePosition {
    private double a, b, errorPass;

    falsePosition(double x0, double x1, double errorLimit) {
        if (x1 < x0) {
            double temp = x1;
            x1 = x0;
            x0 = temp;
        }
        this.a = x0;
        this.b = x1;
        this.errorPass = errorLimit;

        double ans = false_positionMethode();
        if (ans == -999999.0) {
            System.out.println("Root is not in this range..!");
        } else {
            System.out.println("Root(False Position Method) is: " + ans);
            double err = functionValue(ans);
            System.out.println("Error Detail: " + String.format("%.8f", err));
        }
    }

    private double functionValue(double x) {
        return ((x * x * x) - (x * x) + 2);
    }

    private double false_positionMethode() {
        if (functionValue(a) * functionValue(b) >= 0) {
            return -999999.0;
        }
        double expectedRoot = a;
        while (Math.abs(a - b) > 0) {
            expectedRoot = (a * functionValue(b) - b * functionValue(a)) / (functionValue(b) - functionValue(a));

            if (Math.abs(functionValue(expectedRoot)) <= errorPass) {
                break;
            } else if (functionValue(expectedRoot) * functionValue(a) < 0) {
                b = expectedRoot;
            } else {
                a = expectedRoot;
            }
        }
        return expectedRoot;
    }
}
