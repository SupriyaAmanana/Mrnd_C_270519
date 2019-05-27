#include<stdio.h>
#include<stdlib.h>

long int sum(int *a,int i,int n)
{
	if (i == n-1)
		return a[n-1];
	return a[i] + sum(a,i+1,n);
}

long int sum_1(int *a, int n)
{
	if (n == 1)
		return a[0];
	return a[n] + sum_1(a, n - 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%ld",sum(a,0,n));
	printf("%ld", sum_1(a,n));
	system("pause");
}