#include <stdio.h>

#define StackLimit 20   // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 50


typedef int StackElementType;   // ο τύπος των στοιχείων  της στοίβας
                                //ενδεικτικά τύπος int
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void TraverseStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

void FillStack(StackType *Stack);
void FilterStack(StackType *Stack, StackElementType Item);

int main() {
  StackType stack;
  CreateStack(&stack);
  FillStack(&stack);
  printf("Dwse to stoixeio gia diagrafh ");
  StackElementType itemToDelete;
  scanf("%d", &itemToDelete);
  TraverseStack(stack);
  FilterStack(&stack,itemToDelete);
  TraverseStack(stack);
  return 0;
}

void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

void FillStack(StackType *Stack){
  printf("Dwse to plh8os twn stoixeivn ");
  int size;
  scanf("%d",&size);
  for (int i=1;i<=size;i++){
    printf("Dwse to %d o stoixeio:",i);
    StackElementType item;
    scanf("%d",&item);
    Push(Stack,item);
  }
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d, ",Stack.Element[i]);
    }
    printf("\n");
}

void FilterStack(StackType *Stack, StackElementType itemToDelete){

  StackElementType poppedItem;
  StackType tempStack;
  CreateStack(&tempStack);

  do {
    Pop(Stack,&poppedItem);
    TraverseStack(*Stack);
    if(poppedItem!=itemToDelete) Push(&tempStack,poppedItem);
    TraverseStack(tempStack);
  } while(poppedItem!=itemToDelete && Stack->Top > -1);

  while (!EmptyStack(tempStack)) {
    Pop(&tempStack,&poppedItem);
    TraverseStack(tempStack);
    Push(Stack,poppedItem);
    TraverseStack(*Stack);
  }
}
