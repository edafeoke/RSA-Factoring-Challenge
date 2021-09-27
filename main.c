#include "main.h"
/**
 * print_factor - print 2 factors of an integer
 * @n: integer to print its factor
 */
void print_factor(long long int n)
{
	long long int i = 2;

	while (i < n)
	{
		if ((n % i) == 0)
		{
			printf("%lld=%lld*%lld\n", n, n/i, i);
			break;
		}
		i++;
	}
}


/**
 * is_prime - checks if a number is prime
 * @n: number
 *
 * Return 1 or 0 (boolean)
 */
int is_prime(int n)
{
	int i = 0;

	for (i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}

/**
 * main - Entry file
 *
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	FILE *file;
	long long int n;
	size_t len = 0;
	char *e, *line = NULL;
	ssize_t nread;

	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		return (1);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		printf("Can't open file %s\n", argv[1]);
		return (1);
	}
	while ((nread = getline(&line, &len, file)) != -1)
	{
		n = strtoll(line, &e, 10);
		print_factor(n);
	}
	free(line);
	fclose(file);
	return (0);
}
