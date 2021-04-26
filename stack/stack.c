#include <stdio.h>


#define		MAX_SIZE	100


int stack[MAX_SIZE];				// represents stack of 100 elements
int *sp = stack;				// initialize pointer to first element of stack
int *initsp = stack;				// initialize pointer to first element of stack


// returns number of elements in the stack
int NumberOfElements(int *sp, int *initsp) {
	/*
	 * int *sp: pointer to top of stack
	 * int *initsp: initial pointer to top of stack
	 * return: number of elements in the stack
	 */
	return (sp - initsp);
}

// calls NumberofElements() to return the size of the stack
int stacksize() {
	/*
	 * return: number of elements in the stack
	 */
	return NumberOfElements(sp, initsp);
}

// insert an element on top of the stack
void push(int **sp, int val) {
	/*
	 * int *sp: pointer to top of stack
	 * int *initsp: initial pointer to top of stack
	 */
	if (stacksize() >= MAX_SIZE) {
		return ;
	}

	**sp = val;
	*sp = *sp + 1;
}

// remove top element from the stack
int pop(int **sp) {
	/*
	 * int *sp: pointer to top of stack
	 * return: top element of the stack
	 */
	if (stacksize() <= 0) {
		return **sp;
	}

	int val = *(*sp - 1);
	*sp = *sp - 1;
	return val;
}

// determine if an element is in the stack or not
int instack(int *sp, int val) {
	/*
	 * int *sp: pointer to top of stack
	 * int val: integer value to push onto top of stack
	 * return: 1, if element is in the stack; 0, otherwise
	 */
	int s = stacksize();
	for (int i = 0; i < s; i++) {
		if (*(--sp) == val) {
			return 1;
		}
	}

	return 0;
}

// print the top element of the stack
void peek(int *sp) {
	/*
	 * int *sp: pointer to top of stack
	 */
	if (stacksize() <= 0) {
		return ;
	}

	printf("%d\n", *(sp - 1));
}

// print stack elements from top to bottom
void stackprint(int *sp) {
	/*
	 * int *sp: pointer to top of stack
	 */
	int i = stacksize() - 1;
	while(i >= 0) {
		printf("Stack[%d] is ", i);
		peek(sp);
		--sp;
		i--;
	}
}

