#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char BinTreeElementType;        /*ο τύπος των στοιχείων του ΔΔΑ
                                        ενδεικτικά τύπου int */
typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);

BinTreeElementType MinBSTValue(BinTreePointer Root);
BinTreeElementType MaxBSTValue(BinTreePointer Root);


int main() {

  BinTreePointer ARoot;
  CreateBST(&ARoot);

  int level;
  char input[] = "PROCEDURE";
  for (int i=0; i<strlen(input); i++) {
    BinTreeElementType item = input[i];
    BSTInsert(&ARoot, item);
  }

  if(!EmptyBST(ARoot)) {
    BinTreeElementType Min = MinBSTValue(ARoot);
    printf("%c\n", Min);
    BinTreeElementType Max = MaxBSTValue(ARoot);
    printf("%c\n", Max);
  }

  return 0;
}

BinTreeElementType MinBSTValue(BinTreePointer Root) {
  BinTreePointer LocPtr = Root;

  while ( LocPtr->LChild != NULL) {
          LocPtr = LocPtr->LChild;
  }

  return LocPtr->Data;
}

BinTreeElementType MaxBSTValue(BinTreePointer Root) {
  BinTreePointer LocPtr = Root;

  while ( LocPtr->RChild != NULL) {
          LocPtr = LocPtr->RChild;
  }

  return LocPtr->Data;
}

void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item < LocPtr->Data)
            LocPtr = LocPtr ->LChild;
        else if (Item > LocPtr ->Data)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found) {
        //printf("To %c EINAI HDH STO DDA\n", Item);
    } else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item < Parent ->Data)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}
