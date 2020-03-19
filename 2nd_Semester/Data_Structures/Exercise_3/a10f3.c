#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Queue */
#define QueueLimit 20  //το όριο μεγέθους της ουράς

typedef int QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

void FillEvenAndOddQueues(QueueType *Even, QueueType *Odd, int *EvenSize, int *OddSize);
void ReorderQueue(QueueType *Queue, int count);

int main() {
	QueueType EvenQueue, OddQueue;
	QueueElementType item;
	CreateQ(&EvenQueue);
	CreateQ(&OddQueue);

	//Αρχικοποίηση της γεννήτριας τυχαίων αριθμών
	time_t t;
	srand((unsigned) time(&t));

	int EvenSize = 0;
	int OddSize = 0;
	FillEvenAndOddQueues(&EvenQueue,&OddQueue,&EvenSize,&OddSize);

	printf("Size of EvenQueue: %d\n", EvenSize);
	TraverseQ(EvenQueue);
	printf("Size of OddQueue: %d\n", OddSize);
	TraverseQ(OddQueue);

	int j = rand() % EvenSize;
	printf("random number of items =%d\n", j);
	ReorderQueue(&EvenQueue, j);
	printf("Size of EvenQueue: %d\n", EvenSize);
	TraverseQ(EvenQueue);

	j = rand() % OddSize;
	printf("random number of items =%d\n", j);
	ReorderQueue(&OddQueue, j);
	printf("Size of OddQueue: %d\n", OddSize);
	TraverseQ(OddQueue);
}

void FillEvenAndOddQueues(QueueType *Even, QueueType *Odd, int *EvenSize, int *OddSize){
	for(int i=0;i<QueueLimit;i++){
		QueueElementType item = rand() % QueueLimit;
		printf("%d\n", item);
		if (item%2 == 0) {
			AddQ(Even, item);
			(*EvenSize)++;
		} else {
			AddQ(Odd, item);
			(*OddSize)++;
		}
	}
}

void ReorderQueue(QueueType *Queue, int count){
	for (int i=0;i<count;i++){
		QueueElementType item;
		RemoveQ(Queue, &item);
		AddQ(Queue, item);
	}
}

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
    int NewRear;

	if(!FullQ(*Queue))
	{
		NewRear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = NewRear;
	}
	else
		printf("Full Queue");
}

void TraverseQ(QueueType Queue) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}
