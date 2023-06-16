#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"route_records.h"

RouteRecord* createRecords(FILE* fileIn)
{
	RouteRecord* routeR;
	int i = 0, j = 0, k = 0;
	char buffer[500];
	char firstLine[500];
	fgets(firstLine, 500, fileIn);
	while(fgets(buffer, 500, fileIn)!= NULL)
	{
		i++;
	}
	routeR = (RouteRecord*)malloc(i * sizeof(RouteRecord));
	for(j = 0; j < i; j++)
	{		
		routeR[j].passengers = 0;
	}
	rewind(fileIn);
	return routeR;
}
int fillRecords(RouteRecord* r, FILE* fileIn)
{
	int i = 0, j = 0, k = 0;
	char buffer[500];
	int found_index = 0;
	int unique = 0;
	int counter = 0;
	while(fgets(buffer, 500, fileIn)!= NULL)
	{
		i++;
	}
	rewind(fileIn);
	while(fgets(buffer, 500, fileIn) != NULL && j<i)
	{
		sscanf(buffer, "%d,%[^,],%[^,],%[^,],%[^,],%d", &(r[j].month), r[j].origin, r[j].dest, r[j].airline, r[i].category, &(r[j].passengers));
		j++;
	}
	for(k = 0; k < i; k++)
	{
		found_index = findAirlineRoute(r, i, r[k].origin, r[k].dest, r[k].airline, k);
		if(found_index > -1)
		{
			counter++;
		}
	}
	//unique = i - counter;
	return counter;
}
int findAirlineRoute(RouteRecord* r, int length, const char* origin, const char* destination, const char* airline, int curIdx)
{
	int j = 0;
	bool matchFound = false;
	for(j = 0; j < length; j++)
	{
		if((strcmp(r[j].origin, origin) == 0) && (strcmp(r[j].dest, destination) == 0) && (strcmp(r[j].airline, airline) == 0) && (j != curIdx))
		{
			matchFound = true;
		}
	}
	if(matchFound == false)
	{
		return curIdx;
	}
	else
		return -1;
}

void printMenu()
{
	printf("\n\n######### Airline Route Records Database MENU ########\n");
	printf("1. Search by Route\n");
	printf("2. Search by Origin Airport\n");
	printf("3. Search by Destination Airport\n");
	printf("4. Search by Airline\n");
	printf("5. Quit\n");
}
void searchRecords(RouteRecord* r, int length, const char* key1, const char* key2, SearchType st)
{
        int i = 0;
	int counter = 0;
	int total = 0;
	int k = 0;
	int total_month_1 = 0;
	int total_month_2 = 0;
	int total_month_3 = 0;
	int total_month_4 = 0;
	int total_month_5 = 0;
	int total_month_6 = 0;
	int average = 0;

        if(st == 0)
	{
		for(i = 1; i < length; i++)
		{
			if((strstr(r[i].origin, key1) != NULL) && (strstr(r[i].dest, key2) != NULL))
			{
				printf("%s (%.3s-%.3s) ",r[i].airline, r[i].origin, r[i].dest);
				counter++;
				total += r[i].passengers;
				if(r[i].month == 1)
					total_month_1 += r[i].passengers;
				if(r[i].month == 2)
					total_month_2 += r[i].passengers;
				if(r[i].month == 3)
					total_month_3 += r[i].passengers;
				if(r[i].month == 4)
					total_month_4 += r[i].passengers;
				if(r[i].month == 5)
					total_month_5 += r[i].passengers;
				if(r[i].month == 6)
					total_month_6 += r[i].passengers;
			}
		}
		average = total / 6;
		printf("\n%d matches were found.", counter);
		printf("\n\nStatistics\n");
		printf("Total Passengers:\t%d\n", total);
		printf("Total Passengers in Month 1:\t%d\n", total_month_1);
		printf("Total Passengers in Month 2:\t%d\n", total_month_2);
		printf("Total Passengers in Month 3:\t%d\n", total_month_3);
		printf("Total Passengers in Month 4:\t%d\n", total_month_4);
                printf("Total Passengers in Month 5:\t%d\n", total_month_5);
                printf("Total Passengers in Month 6:\t%d\n\n", total_month_6);
		printf("Average Passengers per Month:\t%d", average);
	}
	else if(st == 1)
	{
		for(i = 1; i < length; i++)
		{
			if(strstr(r[i].origin, key1) != NULL)
			{
				printf("%s (%.3s-%.3s) ", r[i].airline, r[i].origin, r[i].dest);
				counter++;
                                total += r[i].passengers;
                                if(r[i].month == 1)
                                        total_month_1 += r[i].passengers;
                                if(r[i].month == 2)
                                        total_month_2 += r[i].passengers;
                                if(r[i].month == 3)
                                        total_month_3 += r[i].passengers;
                                if(r[i].month == 4)
                                        total_month_4 += r[i].passengers;
                                if(r[i].month == 5)
                                        total_month_5 += r[i].passengers;
                                if(r[i].month == 6)
                                        total_month_6 += r[i].passengers;
                             
			}
		}
		average = total / 6;
		printf("\n%d matches were found.", counter);
		printf("\nStatistics\n");
		printf("Total Passengers: %d\n", total);
                printf("Total Passengers in Month 1:\t%d\n", total_month_1);
                printf("Total Passengers in Month 2:\t%d\n", total_month_2);
                printf("Total Passengers in Month 3:\t%d\n", total_month_3);
                printf("Total Passengers in Month 4:\t%d\n", total_month_4);
                printf("Total Passengers in Month 5:\t%d\n", total_month_5);
                printf("Total Passengers in Month 6:\t%d\n\n", total_month_6);
		printf("Average Passengers per Month:\t%d", average);
	}
	else if (st == 2)
	{
		for(i = 1; i < length; i++)
		{
			if(strstr(r[i].dest, key2) != NULL)
			{
				printf("%s (%.3s-%.3s) ", r[i].airline, r[i].origin, r[i].dest);
				counter++;
                                total += r[i].passengers;
                                if(r[i].month == 1)
                                        total_month_1 += r[i].passengers;
                                if(r[i].month == 2)
                                        total_month_2 += r[i].passengers;
                                if(r[i].month == 3)
                                        total_month_3 += r[i].passengers;
                                if(r[i].month == 4)
                                        total_month_4 += r[i].passengers;
                                if(r[i].month == 5)
                                        total_month_5 += r[i].passengers;
                                if(r[i].month == 6)
                                        total_month_6 += r[i].passengers;

			}
		}
		average = total / 6;
		printf("\n%d matches were found.", counter);
		printf("\nStatistics\n");
		printf("Total Passengers: %d\n", total);
                printf("Total Passengers in Month 1:\t%d\n", total_month_1);
                printf("Total Passengers in Month 2:\t%d\n", total_month_2);
                printf("Total Passengers in Month 3:\t%d\n", total_month_3);
                printf("Total Passengers in Month 4:\t%d\n", total_month_4);
                printf("Total Passengers in Month 5:\t%d\n", total_month_5);
                printf("Total Passengers in Month 6:\t%d\n\n", total_month_6);
		printf("Average Passengers per Month:\t%d", average);
	}
	else if (st == 3)
	{
		for(i = 1; i < length; i++)
		{
			if(strstr(r[i].airline, key1) != NULL)
			{
				printf("%s (%.3s-%.3s) ", r[i].airline, r[i].origin, r[i].dest);
				counter++;
                                total += r[i].passengers;
                                if(r[i].month == 1)
                                        total_month_1 += r[i].passengers;
                                if(r[i].month == 2)
                                        total_month_2 += r[i].passengers;
                                if(r[i].month == 3)
                                        total_month_3 += r[i].passengers;
                                if(r[i].month == 4)
                                        total_month_4 += r[i].passengers;
                                if(r[i].month == 5)
                                        total_month_5 += r[i].passengers;
                                if(r[i].month == 6)
                                        total_month_6 += r[i].passengers;

			}
		}
		average = total / 6;
		printf("\n%d matches were found.", counter);
		printf("\nStatistics\n");
		printf("Total Passengers: %d\n", total);
                printf("Total Passengers in Month 1:\t%d\n", total_month_1);
                printf("Total Passengers in Month 2:\t%d\n", total_month_2);
                printf("Total Passengers in Month 3:\t%d\n", total_month_3);
                printf("Total Passengers in Month 4:\t%d\n", total_month_4);
                printf("Total Passengers in Month 5:\t%d\n", total_month_5);
                printf("Total Passengers in Month 6:\t%d\n\n", total_month_6);
		printf("Average Passengers per Month:\t%d", average);
	}
}


