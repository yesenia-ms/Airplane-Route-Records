#ifndef ROUTE_RECORDS_H
#define ROUTE_RECORDS_H

typedef struct RouteRecord
{
	int month;
	char origin[3];
	char dest[3];
	char airline[2];
	char category[10];
	int passengers;
} RouteRecord;

typedef enum SearchType 
{	ROUTE,
	ORIGIN,
	DESTINATION,
	AIRLINE
} SearchType;

RouteRecord* createRecords(FILE*);
int fillRecords(RouteRecord*, FILE*);
int findAirlineRoute(RouteRecord*, int, const char*, const char*, const char*, int);
void searchRecords(RouteRecord*, int, const char*, const char*, SearchType);
void printMenu();

#endif
