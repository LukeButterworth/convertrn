# This is certainly not necessary 
# however allows us to expand later if we feel the need
build-debug: src/main.c
	gcc src/main.c -o bin/convertrn -g


build: src/main.c
	gcc src/main.c -o bin/convertrn
