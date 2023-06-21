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
	char line[256], ch, rawopcode[256], opnum[256];
	int i, lineNumber = 0, chCount = 1 /*,match = 0*/;
	instruction_t command[] = {
                {"pall", pall_func},
                {"push", push_func},
                {NULL, NULL}
        };


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
		for (i = 4; rawopcode[i] != '\0'; i++)/*extract digit from line*/
		{
			if (isalpha(rawopcode[i]))
				break;
			if (isdigit(rawopcode[i]))
				opnum[i - 4] = rawopcode[i];
		}
		opnum[i - 4] = '\0';/* add Null terminater at end*/
		if (opnum[0] != '\0')
		{
			;
		}
		if (strlen(rawopcode) > 0)/* check is rawopcode has data*/
		{
			for(i = 0; command[i].opcode != NULL; i++)
			{
				if(strncmp(rawopcode, command[i].opcode, 4) == 0)
					printf("%d --> %s %s\n",lineNumber, command[i].opcode, opnum);
			}
		}
		opnum[0] = '\0';/* empty array for next loop */
		rawopcode[0] = '\0';/* empty array for next loop */
		chCount = 1;/*next line start counting char again*/
	}
}
