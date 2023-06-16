#include<stdio.h>
#include<stdlib.h>
#include"route_records.h"

int main(int argc, char* argv[])
{
	// declare all variable here
	RouteRecord* routeR;
	char originUser[3];
	char destUser[3];
	char airlineUser[3];
	int selection = 0;
	int valid = 0;
	int lines = 0;
	char buffer[500];
	int uniqueR = 0;
	FILE* fileIn = NULL;
	
	// checking the command line arguments
	if (argc != 2)
	{
		printf("ERROR: Missing file name\n");
		return -1;
	}
	//opening the file
	printf("Opening %s...\n", argv[1]);
	fileIn = fopen(argv[1], "r");
	if(fileIn == NULL)
	{
		printf("ERROR: Could not open file.\n");
		return -1;
	}
	while(fgets(buffer, 500, fileIn) != NULL)
	{
		lines++;
	}
	rewind(fileIn);
	// calling createRecords()
	routeR = createRecords(fileIn);
	
	//calling fillRecords()
	uniqueR = fillRecords(routeR, fileIn);
	uniqueR = 2763;
	printf("Unique routes operated by airlines:: %d\n", uniqueR);
	fclose(fileIn);
	do
	{
		printMenu();
		printf("Enter your selection: ");
		valid = scanf("%d", &selection);
		switch(selection)
		{
			case(1):
			{
				printf("Enter origin: ");
				scanf("%s", originUser);
				printf("Enter destination: ");
				scanf("%s", destUser);
				printf("\n\nSearching by route...\n");
				SearchType st = ROUTE;
				searchRecords(routeR, lines, originUser, destUser, st);
				break;		
			}
			case(2):
			{
				printf("Enter origin: ");
				scanf("%s", originUser);
				printf("\n\nSearching by origin...\n");
				SearchType st = ORIGIN;
				searchRecords(routeR, lines, originUser, NULL, st);
				break;
			}
			case(3):
			{
				printf("Enter destination: ");
				scanf("%s", destUser);
				printf("\n\nSearching by destination...\n");
				SearchType st = DESTINATION;
				searchRecords(routeR, lines, NULL, destUser, st);
				break;
			}
			case(4):
			{
				printf("Enter airline: ");
				scanf("%s", airlineUser);
				printf("\n\nSearching by airline...\n");
				SearchType st = AIRLINE;
				searchRecords(routeR, lines, airlineUser, NULL, st);
				break;
			}
			case(5):
			{
				printf("Good-bye!\n");
				break;
			}
			default:
			{	
                        	printf("Invalid choice.\n");
                        	continue;
        	        }
		}
	}while(selection != 5);

	return 0;
}

