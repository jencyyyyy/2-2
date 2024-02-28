public class newtonRaphson {
    private double x0, acceptedError;

    newtonRaphson(double x0, double acceptedError) {
        this.x0 = x0;
        this.acceptedError = acceptedError;

        double root = newtonRaphsonMethod(x0);
        System.out.println("Root(Newton Raphson Method) is: " + root);
        double err = functionValue(root);
        System.out.println("Error Detail: " + String.format("%.8f", err));
    }

    private double functionValue(double x) {
        return ((x * x * x) - (x * x) + 2);
    }

    private double derivedFunctionValue(double x) {
        return (3 * x * x - 2 * x);
    }

    private double newtonRaphsonMethod(double expectedRoot) {
        double diff = (functionValue(expectedRoot) / derivedFunctionValue(expectedRoot));
        while (Math.abs(diff) > acceptedError) {
            diff = (functionValue(expectedRoot) / derivedFunctionValue(expectedRoot));
            expectedRoot -= diff;
        }
        return expectedRoot;
    }

}
