#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//String Literal Definitions
#define NO_ARG_ERR "No argument provided.\n"
#define INVALID_ARG_ERR "Argument %s is not a valid roman numeral.\n"

//Constant Definitions
const char* valid_numerals = "IVXLCDM";

//Function Declarations
bool is_valid_arg(char* arg);

int convert_arg(char* arg);

//Main Function
int main (int argc, char* argv[]) {
	if (argc == 1) {
		printf(NO_ARG_ERR);
		exit(0);
	}

	bool is_verbose = false;
	bool is_fuzzy = false;
	for (int i = 1; i < argc; i++) {
		char* arg = argv[i];
		is_verbose = is_verbose || !strcmp(arg, "-v");
		is_fuzzy = is_fuzzy || !strcmp(arg, "-f");
	}

	if (is_verbose) printf("Running in verbose mode.\n");
	if (is_fuzzy) printf("Using fuzzy matching.\n");

	for (int i = 1; i < argc; i++) {
		char* arg = argv[i];
		if (!is_valid_arg(arg)) {
			printf(INVALID_ARG_ERR, *arg);
			continue;
		}

		int value = convert_arg(arg);
		printf("Converted %s to %d.\n", arg, value);
	}

	exit(0);
}

bool is_valid_arg(char* arg) {
	//test characters
	//test structure
	return true;
}

int convert_arg(char* arg) {
	return 0;
}
