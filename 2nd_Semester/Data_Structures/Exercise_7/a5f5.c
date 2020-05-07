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

int BSTLevel(BinTreePointer Root, BinTreeElementType Item);

int main() {

  BinTreePointer ARoot;
  CreateBST(&ARoot);

  int level;
  char input[] = "PROCEDURE";
  for (int i=0; i<strlen(input); i++) {
    BinTreeElementType item = input[i];
    BSTInsert(&ARoot, item);
  }

  char input2[] = "PROCEDU";
  for (int i=0; i<strlen(input2); i++) {
    BinTreeElementType item = input[i];
    level = BSTLevel(ARoot, item);
    printf("Level of %c: %d\n", item, level);
  }

  return 0;
}

int BSTLevel(BinTreePointer Root, BinTreeElementType Item) {
  BinTreePointer LocPtr = Root;
  int level = 1;

  while ( LocPtr != NULL) {

      if (Item < LocPtr->Data) {
          level++;
          LocPtr = LocPtr->LChild;

      } else if (Item > LocPtr->Data) {
          level++;
          LocPtr = LocPtr->RChild;

      } else {
          return level;
      }

  }

  return -1;
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
    if (Found)
        printf("To %c EINAI HDH STO DDA\n", Item);
    else {
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
