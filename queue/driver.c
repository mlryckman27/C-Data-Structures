#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"


int main(int argc, char *argv[]) {

	int maxsize = atoi(argv[1]);
	Queue queue = *queueinit(maxsize);

	char line[20];
	char func[5];
	int val = 0;
	
	// get command from the user and element to push
	printf("Enter command (push, print, or quit): ");
	fgets(line, 20, stdin);
	sscanf(line, "%s %d", func, &val);	// parse to separate command from element

	// loop through user commands until user enters quit
	while (strcmp(func, "quit")) {
		if (strcmp(func, "push") == 0) {
			push(&queue, val);
		}
		else if (strcmp(func, "print") == 0) {
			printqueue(queue);
		}

		printf("Enter command (push, print, or quit): ");
		fgets(line, 20, stdin);
		sscanf(line, "%s %d", func, &val);
	}

	return 0;
}
