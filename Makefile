all: build run

build:
	gcc -g -o app.exe *.c $(shell pkg-config  --cflags --libs gtk4)

run:
	./app.exe
