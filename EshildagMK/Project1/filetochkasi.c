#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int formNum(int n);

int main() {
	int gnum, plnum, i, j, ncount, numi, numj, ic = 0, ib=0 ;
	int cows[5] = { 11 };
	int bulls[5] = { 11 };

	printf("Enter ammount of numbers:\n");
	scanf_s("%d", &ncount);

	printf("Enter your number:\n");
	scanf_s("%d", &plnum);
	gnum = formNum(ncount);
	printf("%d\n", gnum);

	for (i = 0; i < ncount; i++) {
		numi = plnum % (10 * (i + 1));
		for (j = 0; j < ncount; j++) {
			numj = gnum % (10 * (j + 1));
			if (numi==numj){
				if (i == j) {
					bulls[ib++] = numi;
				}
				else {
					cows[ic++] = numi;
				}
			}
		}
	}
	printf("Cows: ");
	for (i = 0; i < ncount; i++) {
		if (cows[i] < 10) {
			printf("%d ", cows[i]);
		}
		else continue;
	}
	printf("\nBulls: ");
	for (i = 0; i < ncount; i++) {
		if (bulls[i] < 10) {
			printf("%d ", cows[i]);
		}
		else continue;
	}
}

int formNum(int n) {
	int i=0, rnum, s=0;
	srand(time(NULL));
	int UsedNums[10] = {0};
	while (i < n) {
		rnum = rand() % 10;
		if (UsedNums[rnum] == 1 || (i == 0 && rnum == 0)) {
			continue;
		}
		UsedNums[rnum] = 1;
		s *= 10;
		s += rnum;
		i++;
	}
	return s;
}
