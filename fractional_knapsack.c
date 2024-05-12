#include <stdio.h>
#define ITEMS 5

int P[ITEMS], W[ITEMS];
double PW[ITEMS], ratio[ITEMS], X[ITEMS];
int kCapacity;

void calcPW() {
	int i;
	for (i = 0; i < ITEMS; i++)
		PW[i] = (double) P[i] / W[i];
}

void sortPW() {
	int i, j;
	double temp;
	for (i = 0; i < ITEMS; i++)
		for (j = i + 1; j < ITEMS; j++)
			if (PW[i] < PW[j]) {
				temp = PW[i];
				PW[i] = PW[j];
				PW[j] = temp;
				temp = P[i];
				P[i] = P[j];
				P[j] = temp;
				temp = W[i];
				W[i] = W[j];
				W[j] = temp;
			}
}


double FractionalKnapsack() {
	
	int U = kCapacity, i = 0;
	double value = 0;
	
	while (i <= ITEMS && U != 0) {
		
		if (W[i] <= U) {
			X[i] = 1;
			value += P[i];
			U -= W[i];
		} else {
			
			X[i] = (double) U / W[i];
			value += (double) X[i] * P[i];
			U = 0;
		}
		i++;
	}
	return value;
}

int main() {
	int i;
	double maxProfit;
	printf("\nEnter the profits and weights of the items: ");
	for (i = 0; i < ITEMS; i++)
		scanf("%d %d", &P[i], &W[i]);
	printf("\nEnter the capacity of the knapsack: ");
	scanf("%d", &kCapacity);
	calcPW();
	sortPW();
	maxProfit = FractionalKnapsack();
	printf("\nThe max profit is: %.2f in the ratio:\n", maxProfit);
	
	for (i = 0; i < ITEMS; i++)
		printf("%.2f: %d\n", X[i], P[i]);
	return 0;
}