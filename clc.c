#include "stdio.h"
#include "math.h"
#include "ctype.h"
#include "stdlib.h"
#include "string.h"

float a_global,b_global,c_global,d_global,e_global = 0.00;

void set_global_var(char slot, float num) {
	switch (slot) {
	case 'a':
		a_global = num;
		break;
	case 'b':
		b_global = num;
		break;
	case 'c':
		c_global = num;
		break;
	case 'd':
		d_global = num;
		break;
	case 'e':
		e_global = num;
		break;
	default:
		//
	}
}

float get_global_var(char slot) {
	switch (slot) {
	case 'a':
		return a_global;
	case 'b':
		return b_global;
	case 'c':
		return c_global;
	case 'd':
		return d_global;
	case 'e':
		return e_global;
	default:
		//
	}
}

// prints information about me and the program
void printInfo() {
	printf(
	"Welcome to my Command-Line Calculator (CLC)\n"
	"Developer: Kayra Guner\n"
	"Version: Assignment 1\n"
	"Date: Jan 25, 2024\n"
	);
	printf("----------------------------------------------------\n\n");
}

// prints the program menu
void printMenu() {
	printf(
	"Select one of the following items:\n"
	"B) - Binary Mathematical Operations, such as addition and subtraction.\n"
	"U) - Unary Mathematical Operations, such as square root, and log.\n"
	"A) - Advances Mathematical Operations, using variables, arrays.\n"
	"V) - Define variables and assign them values.\n"
	"E) - Exit\n"
	);
}

// message displayed upon exit
void exitMsg() {
	printf("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!\n");
}
int digits_only(const char *s)
{
    while (*s) {
        if (isdigit(*s++) == 0) return 0;
    }

    return 1;
}

float min(float x, float y) {
	float minim = x;
	if (y < minim) {
		minim = y;
	}
	return minim;
}

float max(float x, float y) {
	float maxim = x;
	if (y > maxim) {
		maxim = y;
	}
	return maxim;
}

float binary_calculate(float num1, float num2, char operator) {
	switch (operator) {
	case '+':
		return (num1+num2);
		break;
	case '-':
		return (num1 - num2);
		break;
	case '/':
		return (num1 / num2);
		break;
	case '*':
		return (num1 * num2);
		break;
	case '%':
		return (remainder(num1,num2));
		break;
	case 'P':
		return (pow(num1, num2));
		break;
	case 'X':
		return (max(num1, num2));
		break;
	case 'I':
		return (min(num1,num2));
		break;
	default:
		// 
	}
}


float unary_calculate(float num, char operator) {
	switch (operator) {
	case 'S':
		return (sqrtf(num));
	case 'L':
		return (logf(num));
	case 'E':
		return (pow(num, 2));
	case 'C':
		return (ceilf(num));
	case 'F':
		return (floorf(num));
	default:
		// 
	}
}

float advanced_binary_calculate(float num1_val, float num2_val, char operator) {
	switch (operator) {
	case '+':
		return (num1_val+num2_val);
		break;
	case '-':
		return (num1_val - num2_val);
		break;
	case '/':
		return (num1_val / num2_val);
		break;
	case '*':
		return (num1_val * num2_val);
		break;
	case '%':
		return (remainder(num1_val,num2_val));
		break;
	case 'P':
		return (pow(num1_val, num2_val));
		break;
	case 'X':
		return (max(num1_val, num2_val));
		break;
	case 'I':
		return (min(num1_val,num2_val));
		break;
	default:
		//
	}
}

float advanced_unary_calculate(float num_val, char operator) {
	switch (operator) {
	case 'S':
		return (sqrtf(num_val));
	case 'L':
		return (logf(num_val));
	case 'E':
		return (pow(num_val, 2));
	case 'C':
		return (ceilf(num_val));
	case 'F':
		return (floorf(num_val));
	default:
		//
	}
}

void advanced_mode() {
	char option;
	puts("Advanced mode initiated");

	while (1) {
		printf("Please select your option: B/U/E\n");
		while (1) {
			scanf(" %c", &option);
			int c;
			while ((c = getchar()) != '\n' && c != EOF) { }
			if (option == 'B' || option == 'U' || option == 'E') {
				break;
			} else {
				printf("Invalid operation entered, please try again\n");
			}			
		}

		if (option == 'B') {
			float result;
			char operator;
			char num1[128], num2[128];
			double num1_val, num2_val;


			// asking the user for numbers and an operator
			printf("Please enter the first number:\n");
			while (1) {
				scanf(" %s", num1);
				int c;
				while ((c = getchar()) != '\n' && c != EOF) { }
				if (!(digits_only(num1))) {
					if (*num1 == 'a' || *num1 == 'b' || *num1 == 'c' || *num1 == 'd' || *num1 == 'e') {
						num1_val = get_global_var((char) *num1);
						break;						
					} else {
						puts("Invalid memory slot entered, please try again");
					}
				} else if (digits_only(num1)) {
					num1_val = atof(num1);
					break;
				} else  {
					printf("Invalid entry: mixed numbers and letters, try again\n");
				}
			}

			printf("Please enter the operation ( + , - , * , / , %% , P (Power) , X (maximum) , I (minimum) ):\n");
			while (1) {
				scanf(" %c", &operator);
				int c;
				while ((c = getchar()) != '\n' && c != EOF) { }
				if (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '%' || operator == 'P' || operator == 'X' || operator == 'I') {
					break;
				} else {
					printf("Invalid operation entered, please try again\n");
				}			
			}

			printf("Please enter the second number:\n");
			while (1) {
				scanf(" %s", num2);
				int c;
				while ((c = getchar()) != '\n' && c != EOF) { }
				if (!(digits_only(num2))) {
					if (*num2 == 'a' || *num2 == 'b' || *num2 == 'c' || *num2 == 'd' || *num2 == 'e') {
						num2_val = get_global_var((char) *num2);
						break;						
					} else {
						puts("Invalid memory slot entered, please try again");
					}
				} else if (digits_only(num2)) {
					num2_val = atof(num2);
					break;
				} else  {
					printf("Invalid entry: mixed numbers and letters, try again\n");
				}
			}
			while (num2_val == 0 && operator == '/') {
				printf("Incorrect value entered, please try again\n");
				scanf(" %lf", &num2_val);
			}


			result = advanced_binary_calculate(num1_val, num2_val, operator);
			printf("The result is %.2f\n", result);
		} else if (option == 'U') {
			char operator;
			float result;
			char num[128];
			double num_val;
			
			printf("Please enter the operation ( S (square root) , L (Log) , E (exponentiation) , C (ceiling) , F (floor) ):\n");
			while (1) {
				scanf(" %c", &operator);
				int c;
				while ((c = getchar()) != '\n' && c != EOF) { }
				if (operator == 'S' || operator == 'L' || operator == 'E' || operator == 'C' || operator == 'F') {
					break;
				} else {
					printf("Invalid operation entered, please try again\n");
				}			
			}

			printf("Please enter your number: ");
			while (1) {
				scanf(" %s", num);
				int c;
				while ((c = getchar()) != '\n' && c != EOF) { }
				if (!(digits_only(num))) {
					if (*num == 'a' || *num == 'b' || *num == 'c' || *num == 'd' || *num == 'e') {
						num_val = get_global_var((char) *num);
						break;						
					} else {
						puts("Invalid memory slot entered, please try again");
					}
				} else if (digits_only(num)) {
					num_val = atof(num);
					break;
				} else  {
					printf("Invalid entry: mixed numbers and letters, try again\n");
				}
			}

			result = advanced_unary_calculate(num_val, operator);
			printf("The result is %.2f\n", result);
		} else if (option == 'E') {
			return;
		} else {
			printf("Invalid option\n");
		}
	}
}

int main() {
	// print our info and menu
	printInfo();
	printMenu();

	// which option user picked variable
	char option;
	// how many rounds this app has been going for (used to manage when to print out "Please select your option" message)
	int rounds = 0;

	// main loop to get constant input from user
	while (option != 'E') {
		// incrementing rounds
		rounds += 1;
		
		// get input using scanf
		scanf(" %1c", &option);
		int c;
		while ((c = getchar()) != '\n' && c != EOF) { }

		// if option is B we ask for the numbers and operator and do the calculations
		// have to add checks for the numbers somewhere
		if (option == 'B') {
			float num1, num2, result;
			char operator;

			// asking the user for numbers and an operator
			printf("Please enter the first number:\n");
			while (scanf(" %f", &num1) != 1) {
				printf("Incorrect value entered, please try again\n");
				scanf(" %*s");
			}
			int c;
			while ((c = getchar()) != '\n' && c != EOF) { }

			printf("Please enter the operation ( + , - , * , / , %% , P (Power) , X (maximum) , I (minimum) ):\n");
			while (1) {
				scanf(" %c", &operator);
				int c;
				while ((c = getchar()) != '\n' && c != EOF) { }
				if (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '%' || operator == 'P' || operator == 'X' || operator == 'I') {
					break;
				} else {
					printf("Invalid operation entered, please try again\n");
				}			
			}

			printf("Please enter the second number:\n");
			while (scanf(" %f", &num2) != 1) {
				printf("Incorrect value entered, please try again\n");
				scanf("%*s");
			}
			while (num2 == 0 && operator == '/') {
				printf("Incorrect value entered, please try again\n");
				scanf(" %f", &num2);
			}

			result = binary_calculate(num1, num2, operator);
			printf("The result is %.2f\n", result);

		} else if (option == 'U') {
			char operator;
			float num, result;

			printf("Please enter the operation ( S (square root) , L (Log) , E (exponentiation) , C (ceiling) , F (floor) ):\n");
			while (1) {
				scanf(" %c", &operator);
				int c;
				while ((c = getchar()) != '\n' && c != EOF) { }
				if (operator == 'S' || operator == 'L' || operator == 'E' || operator == 'C' || operator == 'F') {
					break;
				} else {
					printf("Invalid operation entered, please try again\n");
				}		
			}

			printf("Please enter your number: ");
			while (scanf(" %f", &num) != 1) {
				printf("Incorrect value entered, please try again\n");
				scanf("%*s");
			}

			result = unary_calculate(num, operator);
			printf("The result is %.2f\n", result);

		} else if (option == 'V') {
			char slot;
			float num;
			printf("Please enter the slot you would like to save in (a/b/c/d/e): "); 
			while (1) {
				scanf(" %c", &slot);
				int c;
				while ((c = getchar()) != '\n' && c != EOF) { }
				if (slot == 'a' || slot == 'b' || slot == 'c' || slot == 'd' || slot == 'e') {
					break;
				} else {
					printf("Invalid variable selected, please try again\n");
				}		
			}

			printf("Enter the number value to insert: ");
			while (scanf(" %f", &num) != 1) {
				printf("Incorrect value entered, please try again\n");
				scanf("%*s");
			}

			set_global_var(slot, num);
			printf("Number %f has been assigned to global variable %c\n", num, slot);

		} else if (option == 'A') {
			advanced_mode();
		} 
		else if (option != 'B' || option != 'V' || option != 'A' || option != 'U'){
			if (option != 'E') 
				printf("Invalid operation selected, please try again.\n");
		}
		// printing select your options using the rounds variable so that we dont print at the wrong time!
		if (rounds != 0 && option != 'E') {
			printf("Please select your option ( B , U , A , V , E )\n");
		}
	}
	// printing exit message.
	exitMsg();
	// end of program
	return 0;
}