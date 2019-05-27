#include<stdio.h>
#include<stdlib.h>

void print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void count(int *a, int start, int n)
{
	if (start == n)
		print(a, n);
	else
		for (int i = start; i < n; i++)
		{
			int temp = a[i];
			a[i] = a[start];
			a[start] = temp;
			count(a, start + 1, n);
			temp = a[i];
			a[i] = a[start];
			a[start] = temp;
		}
}

int main()
{
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	count(a, 0, n);
	system("pause");
}