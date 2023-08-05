# This is certainly not necessary 
# however allows us to expand later if we feel the need
build: src/main.c
	gcc src/main.c -o bin/convertrn
