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

	//this loop feels particularly suboptimal
	bool is_verbose = false;
	bool is_fuzzy = false;
	for (int i = 1; i < argc; i++) {
		char* arg = argv[i];
		bool has_vf_flag = !strcmp(arg, "-vf") || !strcmp(arg, "-fv");
		bool has_v_flag = !strcmp(arg, "-v");
		bool has_f_flag = !strcmp(arg, "-f");

		is_verbose = is_verbose || has_vf_flag || has_v_flag;
		is_fuzzy = is_fuzzy || has_vf_flag || has_f_flag;
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
