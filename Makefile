CC=gcc
SRC=src/main.c src/gtk.c src/battery.c

CFLAGS = 
LFLAGS = `pkg-config --cflags gtk+-3.0`
LDLIBS = `pkg-config --libs gtk+-3.0` 

BIN=battery

all:
	$(CC) $(SRC) $(LFLAGS) $(LDLIBS) -o $(BIN)
	
clean:
	rm -f $(BIN)

