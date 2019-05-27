#include<stdio.h>
#include<stdlib.h>

int found(char **a, int i, int j, int x[], int y[], char *str,int m,int n)
{
	if (a[i][j] != str[0])
		return 0;
	for (int k = 0; k<8; k++)
	{
		int r = i + x[k], c = j + y[k], l;
		for (l = 1; str[l];l++)
		{
			if (r >= m || r < 0 || c >= n || c < 0)
				break;
			if (a[r][c] != str[l])
				break;
			r += x[k], c += y[k];
		}
		if (str[l] == '\0')
		{
			printf("starting point is %d %d\n", i, j);
			printf("ending point is %d %d\n\n", r - x[k], c - y[k]);
			l = 1;
		}
	}
	printf("\n");
	return 0;
}
void search(char **a, char *str,int m,int n)
{
	int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			found(a, i, j, x, y, str, m, n);
}

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	char **a = (char **)malloc(sizeof(char *)*m);

	for (int i = 0; i < m; i++)
	{
		a[i] = (char *)malloc(sizeof(char )*n);
		for (int j = 0; j < n; j++)
			scanf("%s", &a[i][j]);
	}

	int max_string;
	printf("enter max string length");
	scanf("%d", &max_string);
	char *str = (char *)malloc(sizeof(char)*n);
	scanf("%s", str);
	search(a, str, m, n);
	system("pause");
}