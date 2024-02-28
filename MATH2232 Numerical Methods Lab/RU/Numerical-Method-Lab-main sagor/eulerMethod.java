public class eulerMethod {


    eulerMethod(double x0, double y0, double h, double estimationPoint) {
//        double x0 = 0;
//        double y0 = 1;
//        double h = 0.025;

        double ans = euler(x0, y0, h, estimationPoint);

        System.out.println("Euler Method:");
        System.out.println("Approximate solution at x = " + estimationPoint + " is: " + String.format("%.5f", ans));
    }


    double function(double x, double y) {
        // x+y+xy
        return (x + y + x * y);
    }

    private double euler(double x0, double y, double h, double estimationPoint) {

        while (x0 < estimationPoint) {
            y = y + h * function(x0, y);
            x0 = x0 + h;
        }
        return y;
    }

}
