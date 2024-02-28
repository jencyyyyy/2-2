public class gaussMethod {

    private int N = 0;

    gaussMethod(double[][] mat, int n) {
        this.N = n;

        /* reduction into r.e.f. */
        int singular_flag = reduceEchelonForm(mat);

        /* if matrix is singular */
        if (singular_flag != -1) {
            System.out.println("Matrix is Singular.");

            if (mat[singular_flag][N] != 0)
                System.out.print("Inconsistent System.");
            else
                System.out.print("May have infinitely many solutions.");

            return;
        }

        findResults(mat);
    }


    private void swap_row(double[][] mat, int i, int j) {
        for (int k = 0; k <= N; k++) {
            double temp = mat[i][k];
            mat[i][k] = mat[j][k];
            mat[j][k] = temp;
        }
    }

    // function to reduce matrix to r.e.f.
    private int reduceEchelonForm(double[][] mat) {
        for (int k = 0; k < N; k++) {

            // Initialize maximum value and index for pivot
            int i_max = k;
            int v_max = (int) mat[i_max][k];

            /* find greater amplitude for pivot if any */
            for (int i = k + 1; i < N; i++)
                if (Math.abs(mat[i][k]) > v_max) {
                    v_max = (int) mat[i][k];
                    i_max = i;
                }

            /* if a prinicipal diagonal element is zero,
             * it denotes that matrix is singular, and
             * will lead to a division-by-zero later. */
            if (mat[k][i_max] == 0)
                return k; // Matrix is singular

            /* Swap the greatest value row with current row
             */
            if (i_max != k)
                swap_row(mat, k, i_max);

            for (int i = k + 1; i < N; i++) {

                /* factor f to set current row kth element
                 * to 0, and subsequently remaining kth
                 * column to 0 */
                double f = mat[i][k] / mat[k][k];

		/* subtract fth multiple of corresponding
				kth row element*/
                for (int j = k + 1; j <= N; j++) {
                    mat[i][j] -= mat[k][j] * f;
                }

                /* filling lower triangular matrix with
                 * zeros*/
                mat[i][k] = 0;
            }
        }

        return -1;
    }

    // function to calculate the values of the unknowns
    private void findResults(double[][] mat) {
        double[] solutions = new double[N]; // An array to store solution

	/* Start calculating from last equation up to the
		first */
        for (int i = N - 1; i >= 0; i--) {

            /* start with the RHS of the equation */
            solutions[i] = mat[i][N];

	/* Initialize j to i+1 since matrix is upper
			triangular*/
            for (int j = i + 1; j < N; j++) {

                /* subtract all the lhs values
                 * except the coefficient of the variable
                 * whose value is being calculated */
                solutions[i] -= mat[i][j] * solutions[j];
            }

	/* divide the RHS by the coefficient of the
			unknown being calculated */
            solutions[i] = solutions[i] / mat[i][i];
        }

        System.out.println();
        System.out.println("Solution for the system (Gauss Elimination):");
        for (int i = 0; i < N; i++) {
            System.out.format("%.6f", solutions[i]);
            System.out.println();
        }
    }
}
