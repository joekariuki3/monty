#include"monty.h"
/**
 * main - start of the main function
 * @argc: number of arguments subbmited
 * @argv: array of submitted arguments
 * Return: 0 for sucess and 1 for error
 *
 */
int main(int argc, char **argv)
{
	char *filename = NULL, *readFileResult = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];

	readFileResult = readFile(filename);
	if (readFileResult)
	{
		;
	}
	return (0);
}
