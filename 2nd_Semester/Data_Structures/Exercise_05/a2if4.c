#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType;           /* ο τύπος των στοιχείων της συνδεδεμένης λίστας
                                        ενδεικτικά τύπου int */
typedef struct ListNode *ListPointer;   //ο τύπος των δεικτών για τους κόμβους
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);

void intersection_list(ListPointer AList, ListPointer BList, ListPointer *FinalList);

int main() {

  ListPointer AList, BList, FinalList, PredPtr;
  ListElementType Item;

  CreateList(&AList);
	CreateList(&BList);

	//List Input------------------------------------------------------------------
  printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS 1: ");
  int inputCount;
  scanf("%d", &inputCount);

  for (int i=0; i<inputCount;i++) {
    printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS: ");
    scanf("%d", &Item);

    LinkedInsert(&AList, Item, NULL);
  }

	printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS 2: ");
  scanf("%d", &inputCount);

  for (int i=0; i<inputCount;i++) {
    printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS: ");
    scanf("%d", &Item);

    LinkedInsert(&BList, Item, NULL);
  }
	//End of List Input-----------------------------------------------------------

  printf("*********1i lista*********\n");
  LinkedTraverse(AList);
	printf("\n*********2i lista*********\n");
  LinkedTraverse(BList);

  intersection_list(AList, BList, &FinalList);
  printf("\n*********Teliki lista*********\n");
  LinkedTraverse(FinalList);

  return 0;
}

void intersection_list(ListPointer AList, ListPointer BList, ListPointer *FinalList){
	ListPointer TempPtr1, TempPtr2;
	CreateList(FinalList);

	TempPtr1 = AList;
	while ( TempPtr1!=NULL ) {
		TempPtr2 = BList;
		while ( TempPtr2!=NULL ) {
			if (TempPtr1->Data == TempPtr2->Data) {
				LinkedInsert(FinalList, TempPtr1->Data, NULL);
				break;
			}
			TempPtr2 = TempPtr2->Next;
		}
		TempPtr1 = TempPtr1->Next;
	}
}

void CreateList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
  Επιστρέφει:  Τον μηδενικό δείκτη List
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* Δέχεται:   Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
  Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
  Επιστρέφει: True αν η λίστα είναι κενή και false διαφορετικά
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο,
                ένα στοιχείο δεδομένων Item και έναν δείκτη PredPtr.
   Λειτουργία: Εισάγει έναν κόμβο, που περιέχει το Item, στην συνδεδεμένη λίστα
                μετά από τον κόμβο που δεικτοδοτείται από τον PredPtr
                ή στην αρχή  της συνδεδεμένης λίστας,
                αν ο PredPtr είναι μηδενικός(NULL).
  Επιστρέφει:  Την τροποποιημένη συνδεδεμένη λίστα με τον πρώτο κόμβο της
                να δεικτοδοτείται από τον List.
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
 /*  printf("Insert &List %p, List %p,  &(*List) %p, (*List) %p, TempPtr %p\n",
   &List, List,  &(*List), (*List), TempPtr); */
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedTraverse(ListPointer List)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
   Λειτουργία: Διασχίζει τη συνδεδεμένη λίστα και
                επεξεργάζεται κάθε δεδομένο ακριβώς μια φορά.
   Επιστρέφει: Εξαρτάται από το είδος της επεξεργασίας.
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
         while ( CurrPtr!=NULL )
        {
             printf("%d ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}
