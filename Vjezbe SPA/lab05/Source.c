#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
	void* ignore;
	int priority;
}Element;

typedef struct {
	Element* array;
}Queue;

int duzina = 10;

void printQueue(Queue* q) {
	for (int i = 0; i < duzina; i++) {
		printf("%d\n", q->array[i].priority);
	}	
}

void fixTop(Queue* q, int number) {
	if (number == 0) {
		return;
	}
	else {
		int roditelj = floor((number - 1) / 2);
		Element roditeljElement = q->array[roditelj];

		if (roditeljElement.priority < q->array[number].priority) {
			Element tmp = q->array[roditelj];
			q->array[roditelj] = q->array[number];
			q->array[number] = tmp;
			fixTop(q, roditelj);
		}
	}
}

void fixBottom(Queue* q, int number) {
	int l = 2 * number + 1;
	int r = 2 * number + 2;

	if (r >= duzina && l >= duzina) {
		return;
	}

	if (l < q->array && r < q->array) {
		if (q->array[number].priority < q->array[l].priority && q->array[l].priority >= q->array[r].priority) {
			Element tmp = q->array[number];
			q->array[number] = q->array[l];
			q->array[l] = tmp;
			fixBottom(q, l);
		}
		else if (q->array[number].priority < q->array[r].priority && q->array[r].priority >= q->array[l].priority) {
			Element tmp = q->array[number];
			q->array[number] = q->array[r];
			q->array[r] = tmp;
			fixBottom(q, r);
		}
	}
	else if (l < q->array && q->array[l].priority > q->array[r].priority) {
		Element tmp = q->array[number];
		q->array[number] = q->array[l];
		q->array[l] = tmp;
		fixBottom(q, l);
	}

}

void add(Queue* q, int number) {
	q->array[number].priority = number;
	fixTop(q, number);
}

void popBack(Queue* q) {
	q->array[0] = q->array[duzina - 1];
	duzina -= 1;

	q->array = (Element*)realloc(q->array, duzina * sizeof(Element));
	fixBottom(q, 0);
}

int main() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->array = (Element*)malloc(duzina * sizeof(Element));

	for (int i = 0; i < duzina; i++) {
		add(q, i);
	}
	
	printf("Citava, fiksana lista\n");
	printQueue(q);
	printf("\n\n");
	printf("Lista nakon popBack() #1\n");
	popBack(q);
	printQueue(q);
	printf("\n\n");
	printf("Lista nakon popBack() #2\n");
	popBack(q);
	printQueue(q);
}