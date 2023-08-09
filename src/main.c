#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//String Literal Definitions
#define NO_ARG_ERR "No argument provided.\n"
#define INVALID_ARG_ERR "Argument %s is not a valid roman numeral.\n"
#define POOR_STRUCT_ERR "Argument %s is poorly structured.\n"
#define VERBOSE_MSG "Running in verbose mode.\n"
#define FUZZY_MSG "Using fuzzy matching.\n"
#define RESULT_MSG "Converted %s to %d.\n"
#define POOR_STRUCT_RESOLVE_MSG "Attempting to resolve regardless.\n"
#define POOR_STRUCT_SKIP_MSG "Skipping argument.\n"

//Constant Definitions
const char* VALID_NUMERALS = "IVXLCDM";

//Function Declarations
void set_global_options(int argc, char* argv[]);
bool is_valid_arg(char* arg);
bool is_poor_arg(char* arg);
void handle_poor_arg(arg);
int convert_arg(char* arg);

//Global Variable Definiton
bool is_fuzzy = false;
bool is_verbose = false;

//Main Function
int main (int argc, char* argv[]) {
	if (argc == 1) {
		printf(NO_ARG_ERR);
		exit(0);
	}

	set_global_options(argc, argv);

	if (is_verbose) printf(VERBOSE_MSG);
	if (is_verbose && is_fuzzy) printf(FUZZY_MSG);

	for (int i = 1; i < argc; i++) {
		char* arg = argv[i];
		if (arg[0] == '-') continue;

		if (!is_valid_arg(arg)) {
			printf(INVALID_ARG_ERR, arg);
			continue;
		}

		//not sure that I like hiding side effects inside handle_poor_arg
		if (!is_poor_arg(arg) && handle_poor_arg(arg)) continue;

		int value = convert_arg(arg);

		if (is_verbose) {
			printf(RESULT_MSG, arg, value);
		} else {
			printf("%d", value);
		}
	}

	exit(0);
}

void set_global_options(int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		char* arg = argv[i];
		bool has_vf_flag = !strcmp(arg, "-vf") || !strcmp(arg, "-fv");
		bool has_v_flag = !strcmp(arg, "-v");
		bool has_f_flag = !strcmp(arg, "-f");

		is_verbose = is_verbose || has_vf_flag || has_v_flag;
		is_fuzzy = is_fuzzy || has_vf_flag || has_f_flag;
	}
}

//TODO: this function is incomplete
bool is_valid_arg(char* arg) {
	int i = 0;
	char letter = arg[0];
	while (letter != '\0') {
		if () return false;
		i++;
		letter = arg[i];
	}
	return true;
}

bool is_poor_arg(char* arg) {
	return true;
}

//I'm not a fan of the logic in this function
bool handle_poor_arg(char* arg) {
	if (is_verbose) printf(POOR_STRUCT_ERR, arg);

	if (is_verbose && !is_fuzzy) {
		printf(POOR_STRUCT_SKIP_MSG);
		return true;
	}

	if (!is_fuzzy) return true;

	if (is_verbose) printf(POOR_STRUCT_RESOLVE_MSG);
	return false;
}

int convert_arg(char* arg) {
	return 0;
}
