public class gaussJordanMethod {

    // Java Implementation for Gauss-Jordan
// Elimination Method

    gaussJordanMethod(double[][] mat) {
        int N = 3, flag = 0;

        // Performing Matrix transformation
        flag = PerformOperation(mat, N);

        if (flag == 1)
            flag = CheckConsistency(mat, N, flag);

        // Printing Solutions(if exist)
        PrintResult(mat, N, flag);

    }


    // function to reduce matrix to reduced
// row echelon form.
    private int PerformOperation(double[][] mat, int N) {
        int i, j, k = 0, c, flag = 0, m = 0;
        double pro = 0;

        // Performing elementary operations
        for (i = 0; i < N; i++) {
            if (mat[i][i] == 0) {
                c = 1;
                while ((i + c) < N && mat[i + c][i] == 0)
                    c++;
                if ((i + c) == N) {
                    flag = 1;
                    break;
                }
                for (j = i, k = 0; k <= N; k++) {
                    double temp = mat[j][k];
                    mat[j][k] = mat[j + c][k];
                    mat[j + c][k] = temp;
                }
            }

            for (j = 0; j < N; j++) {

                // Excluding all i == j
                if (i != j) {

                    // Converting Matrix to reduced row
                    // echelon form(diagonal matrix)
                    double p = mat[j][i] / mat[i][i];

                    for (k = 0; k <= N; k++)
                        mat[j][k] = mat[j][k] - (mat[i][k]) * p;
                }
            }
        }
        return flag;
    }


    private void PrintResult(double[][] mat, int N, int flag) {
        System.out.println("Solution for the system (Gauss Jordan): ");

        if (flag == 2)
            System.out.println("Infinite Solutions Exists");
        else if (flag == 3)
            System.out.println("No Solution Exists");


            // Printing the solution by dividing constants by
            // their respective diagonal elements
        else {
            for (int i = 0; i < N; i++)
                System.out.println(mat[i][N] / mat[i][i]);
        }
    }

    private int CheckConsistency(double[][] mat, int N, int flag) {
        int i, j;
        double sum;

        // flag == 2 for infinite solution
        // flag == 3 for No solution
        flag = 3;
        for (i = 0; i < N; i++) {
            sum = 0;
            for (j = 0; j < N; j++)
                sum = sum + mat[i][j];
            if (sum == mat[i][j])
                flag = 2;
        }
        return flag;
    }
}
