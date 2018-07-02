main.exe: main.o 
	g++ main.o -o main.exe

#NOTA per far analizzare a make il file header della classe templata
#     che contiene l'implementazione, il file header e' stato aggiunto 
#     come dipendenza per la creazione del file oggetto del main
#     I file header si possono mettere come dipendenze ma NON VANNO COMPILATI
main.o: main.cpp Matrice3D.h
	g++ -c main.cpp -o main.o

clean:
	rm *.o main.exe


run: main.exe
	./main.exe
