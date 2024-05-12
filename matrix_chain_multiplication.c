#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printParenthesis(int i, int j, int *bracket, int n, char name) {
    if (i == j) {
        printf("%c%d", name, i);
        return;
    }
    printf(" ( ");
    printParenthesis(i, *((bracket + i * n) + j), bracket, n, name);
    printParenthesis(*((bracket + i * n) + j) + 1, j, bracket, n, name);
    printf(" ) ");
}

void matrixChainOrder(int p[], int n) {
    int m[n][n];
    int bracket[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
    printf("Optimal Parenthesization: ");
    printParenthesis(1, n - 1, (int *)bracket, n, 'A');
    printf("\n");

}

int main() {
    int n; // Number of matrices
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dimensions[n + 1];
    printf("Enter the dimensions of each matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the row of matrix %d: ", i + 1);
        scanf("%d", &dimensions[i]);
        printf("Enter the col of matrix %d: ", i + 1);
        scanf("%d", &dimensions[i + 1]);
        printf("\n");
    }

    matrixChainOrder(dimensions, n + 1);

    return 0;
}
