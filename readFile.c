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
	char line[256], ch, rawopcode[256], *opcode = NULL;
	int i, chCount = 1, opnum;
	unsigned int lineNumber = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		for (i = 0; line[i] != '\0'; i++)/*Iterate over each char in line*/
		{
			ch = line[i];
			if (isalpha(ch) || isdigit(ch))/*Check if the char letter or digit*/
			{
				rawopcode[chCount - 1] = ch;
				chCount++; /* count char per line */
			}
		}
		lineNumber++;/* keep track of line number*/
		rawopcode[chCount - 1] = '\0';/* add null teminater to string opcode*/
		opcode = getOpcode(rawopcode);
		opnum = getOpnum(rawopcode);
		gbopnum = opnum;
		if (rawopcode[0] != '\0')
			check_key(opcode, lineNumber);
		free(opcode);
		rawopcode[0] = '\0';/* empty array for next loop */
		chCount = 1;/*next line start counting char again*/
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
	stack_t **head = NULL;
	instruction_t key[] = {{"push", push_func},
		{"pall", pall_func}, {"pint", pint_func}, {"pop", pop_func}, {NULL, NULL}};

	for (i = 0; key[i].opcode != NULL; i++)
	{
		if ((strcmp(opcode, key[i].opcode)) == 0)
		{
			key[i].f(head, lineNumber);
			break;
		}
	}
	if (key[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, opcode);
		if (opcode != NULL)
			free(opcode);
		if (head != NULL)
			free(head);
		exit(EXIT_FAILURE);
	}
}

/**
 * getOpcode - extracts opcode from the rawopcode from the file line x
 * @rawopcode: string from file line
 * Return: ocode the
 */
char *getOpcode(char *rawopcode)
{
	int i;
	char *opcode = NULL;

	opcode = malloc(sizeof(rawopcode));
	for (i = 0; rawopcode[i] != '\0'; i++)
	{
		if (i < 4 && isalpha(rawopcode[i]))
			opcode[i] = rawopcode[i];
	}
	opcode[4] = '\0';/* add Null terminater at end*/
	return (opcode);
}

/**
 * getOpnum - extracts int from the rawopcode from the file line x
 * @rawopcode: string from file line
 * Return: returns the int or -1
 */
int getOpnum(char *rawopcode)
{
	int i;
	char *opnum = NULL;

	if (rawopcode[0] == '\0')
		return (-1);
	opnum = malloc(sizeof(rawopcode));
	for (i = 4; rawopcode[i] != '\0'; i++)/*extract digit from line*/
	{
		if (isalpha(rawopcode[i]))
			break;
		if (isdigit(rawopcode[i]))
			opnum[i - 4] = rawopcode[i];
	}
	opnum[i - 4] = '\0';/* add Null terminater at end*/
	return (atoi(opnum));
}
