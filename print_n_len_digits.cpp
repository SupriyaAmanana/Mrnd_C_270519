#include<stdio.h>
#include<stdlib.h>

void print(int *a, int n)
{
	int val = 0;
	for (int i = 0; i < n; i++)
	{
		val = val * 10 + a[i];
	}
	printf("%d\n", val);
}
void count(int *a,int start, int n)
{
	if (start == n)
		print(a, n);
	else
	for (int i = 0; i <= 9; i++)
	{
		a[start] = i;
		count(a, start + 1, n);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(sizeof(int)*n);
	count(a, 0,n);
	system("pause");
}