CC = gcc
CFLAGS = -Wall -g -fsanitize=address

# Nazwa pliku wynikowego (programu)
TARGET = main

# Pliki obiektowe potrzebne do zbudowania programu
# DODANO: dijkstra.o
OBJS = main.o struct.o dijkstra.o

# Reguła domyślna: buduj program
all: $(TARGET)

# Linkowanie (łączenie plików .o w program)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Kompilacja main.c -> main.o
main.o: main.c struct.h dijkstra.h
	$(CC) $(CFLAGS) -c main.c

# Kompilacja struct.c -> struct.o
struct.o: struct.c struct.h
	$(CC) $(CFLAGS) -c struct.c

# DODANO: Kompilacja dijkstra.c -> dijkstra.o
dijkstra.o: dijkstra.c dijkstra.h struct.h
	$(CC) $(CFLAGS) -c dijkstra.c

# Czyszczenie (usuwanie plików tymczasowych)
clean:
	rm -f *.o $(TARGET)