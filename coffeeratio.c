#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	/*
	 * Intended syntax: 'ratio <coffee> <water> <amount> <arguments>'
	 * for example, if you want a ratio of 1:16 with 650 grams of water
	 * the user would type: 'ratio 1 16 650'
	 */

	if(argc >= 4)
	{
		/* Variables */
		char *str_coffee = argv[1];
		char *str_water = argv[2];
		char *str_amount = argv[3];
		int arg;
		int result;

		/* Convert string to integer */
		int coffee = atoi(str_coffee);
		int water = atoi(str_water);
		int amount = atoi(str_amount);

		if(coffee > 1)
			printf("WARNING: ratio irregular, calculations may not be accurate!\n");

		while((arg = getopt(argc, argv, "c")) != -1)
		{
			switch(arg)
			{
				case 'c' :
					result = amount * water;
					printf("Ratio %d:%d = %dg of water\n", coffee, water, result);
					return 0;

				default :
					break;
			}
		}

		result = amount / water;
		printf("Ratio %d:%d = %dg of coffee\n", coffee, water, result);
	}

	else
	{
		printf("ERROR: Invalid syntax\n");
		printf("'ratio <coffee> <water> <amount> <arguments>'\n");
	}
}
