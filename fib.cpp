#include<stdio.h>
#include<stdlib.h>

long int fib(int n)
{
	if (n == 1 || n==0)
		return 0;
	if (n == 2)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

long int fib_dp(int *a, int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (a[n - 1]>=0)
	{
		return a[n-1];
	}
	a[n-1] = fib_dp(a, n - 2) + fib_dp(a, n - 1);
	return a[n-1];
}

int main()
{
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(sizeof(int)*(n+1));
	printf("%ld using recursion \n", fib(n));
	printf("%ld using dynamic programming", fib_dp(a,n));
	system("pause");
}