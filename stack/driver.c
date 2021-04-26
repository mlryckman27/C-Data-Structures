#include <stdio.h>
#include "stack.h"


int main() {

	extern int *sp;			// declare pointer from library to top of stack

	int option;			// options -1, 0, 1, 2, 3, 4, or 5
	printf("Stack options: (0 = push, 1 = pop, 2 = Instack, 3 = SizeofStack, 4 = Print_Stack, 5 = Peek or -1 to quit): ");
	scanf("%d", &option);

	// control user input
	while ((option < -1) || (option > 5)) {
		printf("Invalid entry... please try again.\n");
		printf("Stack options: (0 = push, 1 = pop, 2 = Instack, 3 = SizeofStack, 4 = Print_Stack, 5 = Peek or -1 to quit): ");
		scanf("%d", &option);
	}

	// execute user's selected options until user enters -1
	while (option != -1) {

		int val;
		switch (option) {
			case 0:
				printf("Enter value to push: ");
				scanf("%d", &val);

				push(&sp, val);
				break;

			case 1:
				printf("Element popped from the stack is %d\n", pop(&sp));
				break;

			case 2:
				printf("Enter value to check for in stack: ");
				scanf("%d", &val);

				if (instack(sp, val)) {
					printf("%d is in the stack.\n", val);
				}
				else {
					printf("%d is not in the stack.\n", val);
				}

				break;

			case 3:
				printf("Stack contains %d elements.\n", stacksize());
				break;

			case 4:
				stackprint(sp);
				break;

			case 5:
				if (stacksize()) {
					printf("Element on top of stack is ");
					peek(sp);
				}
				else {
					printf("Stack is empty.\n");
				}

				break;

			default:
				break;
		}

		// get option from user for next pass through loop
		printf("Stack options: (0 = push, 1 = pop, 2 = Instack, 3 = SizeofStack, 4 = Print_Stack, 5 = Peek or -1 to quit): ");
		scanf("%d", &option);

		// control user input
		while ((option < -1) || (option > 5)) {
			printf("Invalid entry... please try again.\n");
			printf("Stack options: (0 = push, 1 = pop, 2 = Instack, 3 = SizeofStack, 4 = Print_Stack, 5 = Peek or -1 to quit): ");
			scanf("%d", &option);
		}
	}
	
}
