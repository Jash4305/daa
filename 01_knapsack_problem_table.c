/*
1. Init : no_of_obj(n), max_cap(m), profit[], weight[], matrix[n+1][m+1] and maxFun()
2. for i = 0 to <= n then
    for j = 0 to <= m then
        if i or j anything == 0 then
            matrix[i][j] = 0
        else if weight[i] obj <= max_cap then
            matrix[i][j] = maxFun(arg1, arg2)
            arg1 = profit[previous obj] + matrix[previous row][max_cap - weight[previous obj]]
            arg2 = matrix[previous row][j]
        else 
            copy the above cell data
            matrix[i][j] = matrix[i - 1][j] 
*/

#include <stdio.h>
#include <stdlib.h>

int maxFunction(int a, int b) {
    if (a > b)
        return a;
    return b;
}

void knapsack(int max, int n, int p[], int wt[]) {
    int k[n + 1][max + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= max; j++) {
            if (i == 0 || j == 0)
                k[i][j] = 0;
            else if (wt[i - 1] <= j) {
                k[i][j] = maxFunction(p[i - 1] + k[i - 1][j - wt[i - 1]], k[i - 1][j]);
            } else
                k[i][j] = k[i - 1][j];
        }
    }
    printf("Filled Matrix:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= max; j++)
            printf("%d ", k[i][j]);
        printf("\n");
    }
    printf("Max Profit : %d\n", k[n][max]);

    int i = n;
    int j = max;
    int result[n];
    int count = 0;
    while (i >= 0 && j >= 0) {
        if (k[i][j] == k[i - 1][j]) {
            result[count] = 0;
            count++;
            i--;
        } else {
            result[count] = 1;
            count++;
            j -= wt[i];
        }
    }
    printf("Objects Included: ");
    for (int m = n; m >= 1; m--) {
        printf("%d ", result[m]);
    }
}

int main() {
    int max, n;
    printf("Enter the max capacity : ");
    scanf("%d", &max);
    printf("Enter the no. of objects : ");
    scanf("%d", &n);

    int p[n], wt[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the profit of %d : ", i + 1);
        scanf("%d", &p[i]);
        printf("Enter the weight of %d : ", i + 1);
        scanf("%d", &wt[i]);
        printf("\n");
    }

    knapsack(max, n, p, wt);

    return 0;
}
