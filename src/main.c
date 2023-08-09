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

//Structure Definitions
typedef struct Options {
	bool is_fuzzy;
	bool is_verbose;
} Options

//Function Declarations

bool get_options(int argc, char* argv[]);
bool is_valid_arg(char* arg);
bool is_well_structured(char* arg);
int convert_arg(char* arg);

//Constant

//Main Function
int main (int argc, char* argv[]) {
	if (argc == 1) {
		printf(NO_ARG_ERR);
		exit(0);
	}

	Options o = get_options(argc, argv);

	if (o.is_verbose) printf(VERBOSE_MSG);
	if (o.is_verbose && is_fuzzy) printf(FUZZY_MSG);

	for (int i = 1; i < argc; i++) {
		char* arg = argv[i];
		if (arg[0] == '-') continue;

		if (!is_valid_arg(arg)) {
			printf(INVALID_ARG_ERR, arg);
			continue;
		}

		bool is_poor_structure = !is_well_structured(arg);

		if (o.is_verbose && is_poor_structure) print(POOR_STRUCT_ERR, arg);

		if (o.is_verbose && !o.is_fuzzy && is_well_structured(arg)) {
			printf(POOR_STRUCT_SKIP_MSG);
			continue;
		} else {
			printf(POOR_STRUCT_RESOLVE_MSG);
		}

		int value = convert_arg(arg);
		if (is_verbose) {
			printf(RESULT_MSG, arg, value);
		} else {
			printf("%d", value);
		}
	}

	exit(0);
}

bool get_options(int argc, char* argv[]) {
	Options o = {
		.is_fuzzy = false;
		.is_verbose = false;
	}

	for (int i = 1; i < argc; i++) {
		char* arg = argv[i];
		bool has_vf_flag = !strcmp(arg, "-vf") || !strcmp(arg, "-fv");
		bool has_v_flag = !strcmp(arg, "-v");
		bool has_f_flag = !strcmp(arg, "-f");

		o.is_verbose = o.is_verbose || has_vf_flag || has_v_flag;
		o.is_fuzzy = o.is_fuzzy || has_vf_flag || has_f_flag;
	}

	return o;
}

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

int convert_arg(char* arg) {
	//in here we need to check for fuzzy behaviour
	//we can return a -1 if this is invalid and vuzzy
	return 0;
}
