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
	char line[256], ch, opcode[256];
	int i, lineNumber = 0, chCount = 1;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		/*Iterate over each character in the line checking char count*/
		for (i = 0; line[i] != '\0'; i++)
		{
			ch = line[i];
			/*Check if the character is a letter or digit*/
			if (isalpha(ch) || isdigit(ch))
			{
				/*Process the character as needed*/
				if (chCount <= 4 && isalpha(ch) )
				{
					opcode[chCount - 1] = ch;
				}
				
				if (chCount > 4 && isdigit(ch))
				{
					printf("(%c)", ch);
				}
				chCount++; /* count char per line */
			}
		}
		lineNumber++;/* keep track of line number*/
		opcode[chCount - 1] = '\0';/* add null teminater to string opcode*/

		if (strlen(opcode) > 0)/* check is opcode has data*/
		{
			printf("%d -> %s\n", lineNumber, opcode);
		}

		opcode[0] = '\0';
		/*opnum[0] = '\0';*/
		chCount = 1;/* next line start counting char again*/
	}
}
