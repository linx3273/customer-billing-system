ob = ..\obj

a.exe: main.o customerfunctions.o billfunctions.o initialization.o writedata.o itemfunctions.o
	gcc $(ob)\main.o $(ob)\customerfunctions.o $(ob)\billfunctions.o $(ob)\initialization.o $(ob)\writedata.o $(ob)\itemfunctions.o -o ..\a.exe

main.o: main.c header.h
	gcc -c main.c -o $(ob)\main.o

customerfunctions.o: customerfunctions.c header.h
	gcc -c customerfunctions.c -o $(ob)\customerfunctions.o

billfunctions.o: billfunctions.c header.h
	gcc -c billfunctions.c -o $(ob)\billfunctions.o
	
initialization.o: initialization.c header.h
	gcc -c initialization.c -o $(ob)\initialization.o

writedata.o: writedata.c header.h
	gcc -c writedata.c -o $(ob)\writedata.o

itemfunctions.o: itemfunctions.c header.h
	gcc -c itemfunctions.c -o $(ob)\itemfunctions.o