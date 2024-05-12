#include <stdio.h>

int coinChange(int coins[], int n, int amount) {    
    int dp[amount + 1];
    dp[0] = 0; 

    for (int i = 1; i <= amount; i++) {
        dp[i] = amount + 1; 
    }
    
    for (int i = 1; i <= amount; i++) {
        
        for (int j = 0; j < n; j++) {
            
            if (coins[j] <= i) {
                
                dp[i] = dp[i] < (1 + dp[i - coins[j]]) ? dp[i] : (1 + dp[i - coins[j]]);
            }
        }
    }
    if (dp[amount] == amount + 1) {
        return -1;
    }
    return dp[amount];
}

int main() {
    int coins[] = {1, 2, 5}; 
    int n = sizeof(coins) / sizeof(coins[0]); 
    int amount = 11; 
    int minCoins = coinChange(coins, n, amount);
    if (minCoins == -1) {
        printf("It is not possible to make change for %d\n", amount);
    } else {
        printf("Minimum number of coins required to make change for %d: %d\n", amount, minCoins);
    }

    return 0;
}
