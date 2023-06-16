a.out: main.o route_records.o
	gcc main.o route_records.o
main.o: main.c route_records.h
	gcc -c main.c -o main.o
route_records.o: route_records.c route_records.h
	gcc -c route_records.c -o route_records.o
clean:
	rm *.o
	rm a.out
