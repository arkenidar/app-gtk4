all:
	gcc $(shell pkg-config --cflags gtk4) -o app main.c $(shell pkg-config --libs gtk4) && ./app
