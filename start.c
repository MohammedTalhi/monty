#include "monty.h"

int status = 0;

/**
 * main - Entry point
 * @arv: list of arguments passed to our program
 * @arc: amount of args
 */

int main(int arc, char **arv)
{
	FILE *f;
	size_t len = 0;
	char *buf = NULL;
	char *str = NULL;
	stack_t *s = NULL;
	unsigned int cnt = 1;

	global.data = 1;
	if (arc != 2)
		erusage();
	f = fopen(arv[1], "r");
	if (!f)
		fileer(arv[1]);
	while ((getline(&buf, &len, f)) != (-1))
	{
		if (status)
			break;
		if (*buf == '\n')
		{
			cnt++;
			continue;
		}
		str = strtok(buf, " \t\n");
		if (!str || *str == '#')
		{
			cnt++;
			continue;
		}
		global.arg = strtok(NULL, " \t\n");
		op_code(&s, str, cnt);
		cnt++;
	}
	free(buf);
	freestk(s);
	fclose(f);
	exit(EXIT_SUCCESS);
}

/**
 * fileer - prints file error message and exits
 * @av: argv given by main()
 */
void fileer(char *av)
{
	fprintf(stderr, "Error: Can't open file %s\n", av);
	exit(EXIT_FAILURE);
}

/**
 * erusage - prints usage message and exits
 */
void erusage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
