#include "monty.h"

/**
 * readFile - open file submitted
 * @filename: path to the file to be opened
 * Return: name of the file
 *
 */
char *readFile(char *filename)
{
	FILE *file;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	/* process each line of the file */
	processLine(file);

	fclose(file);
	return (filename);
}

/**
 * processLine - check line collects 5 first char n digit only
 * @file: opened file
 */
void processLine(FILE *file)
{
	char *line = NULL;
	size_t bufsize = 0;
	unsigned int lineNumber = 0;

	while (getline(&line, &bufsize, file) != -1)
	{
		data.opcode = strtok(line, " \t\n");
		data.opnum = strtok(NULL, " \t\n");
		lineNumber++;/* keep track of line number*/
		if (data.opcode[0] != '\0')
			check_key(data.opcode, lineNumber);
	}
}

/**
 * check_key - look for the opcode in array if it is valid
 * @opcode: opcode or command to validate
 * @lineNumber: line number from the file
 */
void check_key(char *opcode, int lineNumber)
{
	int i;
	instruction_t key[] = {{"push", push_func},
		{"pall", pall_func}, {"pint", pint_func},
		{"pop", pop_func}, {"swap", swap_func}, {"add", add_func},
		{"nop", nop_func}, {"sub", sub_func}, {NULL, NULL}};

	for (i = 0; key[i].opcode != NULL; i++)
	{
		if ((strcmp(opcode, key[i].opcode)) == 0)
		{
			key[i].f(&(data.head), lineNumber);
			break;
		}
	}
	if (key[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, opcode);
		exit(EXIT_FAILURE);
	}
}
