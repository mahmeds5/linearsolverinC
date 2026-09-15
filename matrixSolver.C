#include <stdio.h>
#include <string.h>
#define MAX 10

int main(){

    int n = 0;
    printf("How many equations/unknowns?  ");
    scanf("%d", &n);

    printf("\n");


    double matrix[MAX][MAX+1];

    

    printf("Filling up the Agumented Matrix (%d x %d) \n", n, n + 1);

    printf("\n");


    for (int i = 0; i < n; i++){
        for (int j = 0; j < n + 1; j++){
            if (j != n){
                printf("Enter the value for row %d, column %d --> ", i + 1, j + 1);
            }
            if (j == n){
                printf("Enter the solution for row %d --> ", i + 1);
            }
            scanf("%lf", &matrix[i][j]);
        }
        printf("\n");
    }

    printf("Printing the (%d x %d) Matrix  \n", n, n + 1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n + 1; j++){
            printf("[ ");
            printf("%+7.2lf", matrix[i][j]);
            printf(" ]");
        }
        printf("\n");
    }


    //MY NOTES FOR FIGURING OUT THE ECHELON ALGORITHM. 
    //i is the row
    //j is the column

    //---------------- x elim ops-------------------------------------------------------------------------------------------------------------------------
    //r2 - r1(r2,1 / r1,1)
    //r3 - r1(r3,1/r1,1)
    //r4 - r1(r4,1/r1,1)


    //WITH VARS

    //rROW - orangeROW(rROW,orangeROW / ORANGE)  -> row 2
    //rROW + 1 - orangeROW(rROW, orangeROW,1/ORANGE) -> row 3
    //rROW + 1 - orangeROW(rROW + 1,orangeROW/ORANGE) -> row 4

    //ORANGE -> OG divisor (the pivot for the row) ->>> row 1, column 1

    //------------------- y elim ops------------------------------------------------------------------------------------------------------------------------
    //r3 - r2(r3,2/r2,2)
    //r4 - r2(r4,2/r2,2)

    //WITH VARS

    //rROW- orangeROW(rROW,orangeROW/ORANGE) > row 3
    //rROW  + 1  - orangeROW(rROW+1,orangeROW/ORANGE) > row 4

    //ORANGE ->>> ROW2, COl2

    //------------------ z elim ops------------------------------------------------------------------------------------------------------------------------
    //r4 - r3(r4,3 - r3,3)

    //WITH VARS
    //rROW - orangeROW(rROW,orangeROW/ORANGE) >>> Row 4

    //ORNG ->>>> r3,c3

    //--------------------a elim opps------------------------------------------------------------------------------------------------------------------------
    //not needed

    /**
    for (int pivot = 0; pivot < n; pivot++){
        for (int row = pivot + 1; row < n; row++){
            factor = matrix[row][pivot] /  matrix[pivot][pivot]; 
            for (int horizontal = pivot; horizontal < n + 1; horizontal++){
                matrix[row][horizontal] = matrix[row][horizontal] - matrix[pivot][horizontal] * factor;
            }
        }
    }
    */

    //echelon form algorithm
    for (int pivot = 0; pivot < n; pivot++){
        for (int row = pivot + 1; row < n; row++){
            double factor = matrix[row][pivot] /  matrix[pivot][pivot]; 
            for (int horizontal = pivot; horizontal < n + 1; horizontal++){
                matrix[row][horizontal] = matrix[row][horizontal] - matrix[pivot][horizontal] * factor;
            }
        }
    }

    printf("\n");
    printf("\n");

    //printing  
    printf("Printing the UPDATED (%d x %d) Matrix in Row Echelon Form  \n", n, n + 1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n + 1; j++){
            printf("[ ");
            printf("%+7.2lf", matrix[i][j]);
            printf(" ]");
        }
        printf("\n");
    }

    //sol algorithm
    double solutions[n];
    for (int row = n - 1; row >= 0; row--){
        double rhs = matrix[row][n];
        for (int column = row + 1; column < n; column++){
            rhs = rhs - (matrix[row][column] * solutions[column]);
        }
        solutions[row] = rhs/matrix[row][row];
    }

    printf("\n");
    printf("\n");

    printf("Printing Solutions\n");
    for (int i = 0; i < n; i++){
        printf("X[%d] = %f \n", i, solutions[i]);
    }






    





    printf("\n");
    printf("\n");
    return 0;
}