#include <stdio.h>
#include <stdlib.h>

typedef int QueueElementType;           /*ο τύπος των στοιχείων της συνδεδεμένης ουράς
                                        ενδεικτικά τύπου int*/
typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType Item);

void TraverseQ(QueueType Queue);

int main() {

  QueueType AQueue;
  CreateQ(&AQueue);

  QueuePointer CurrPtr, PredPtr;

  int prisonerCount;
  printf("DWSE TO PLITHOS TWN FYLAKISMENWN: ");
  scanf("%d", &prisonerCount);

  for (int i = 0; i < prisonerCount; i++) {
    QueueElementType item = i+1;
    AddQ(&AQueue, item);
  }

  int executionCycle;
  printf("DWSE TON ARITHMO TOY KYKLOU EKTELESIS: ");
  scanf("%d", &executionCycle);


  CurrPtr = AQueue.Front;
  int j=1;
  while (j < prisonerCount) {
		//TraverseQ(AQueue);
    for (int i=0; i < executionCycle; i++) {
      printf("%d ", CurrPtr->Data);
			if (i+1 != executionCycle) {
				PredPtr = CurrPtr;
	      CurrPtr = CurrPtr->Next;
			}
    }
    printf("EXECUTION %d\n", CurrPtr->Data);
    RemoveQ(&AQueue, CurrPtr->Data);
		PredPtr = CurrPtr;
		CurrPtr = CurrPtr->Next;
    j++;
  }
	printf("SURVIVAL %d\n", CurrPtr->Data);

  return 0;
}

void CreateQ(QueueType *Queue)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά Queue και ένα  στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στο τέλος της συνδεδεμένης ουράς Queue.
   Επιστρέφει: Την τροποποιημένη ουρά
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
    Queue->Rear->Next = Queue->Front;
}

void RemoveQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την  κορυφή της συνδεδεμένης ουράς,
                αν δεν είναι  κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη συνδεδεμένη ουρά.
   Έξοδος:     Μήνυμα κενής ουράς, αν η ουρά είναι  κενή
*/
{
	QueuePointer CurrPtr, PredPtr;
	CurrPtr = Queue->Front;
	while (CurrPtr->Data != Item) {
		if (CurrPtr->Data==Item )
		  break;
		else {
		  PredPtr = CurrPtr;
			CurrPtr = CurrPtr->Next;
		}
	}
	if(Item == 1) {
		Queue->Rear->Next = Queue->Front;
		//printf("%d %d\n", PredPtr->Data, CurrPtr->Data);
	} else {
		PredPtr->Next = CurrPtr->Next;
	}
}

void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
				int i = 0;
         while ( i< 10 )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
						 i++;
        }
   }
    printf("\n");
}
