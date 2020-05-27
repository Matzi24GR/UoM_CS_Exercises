#include <stdio.h>
#include <stdlib.h>

typedef int BinTreeElementType;             /*ο τύπος των στοιχείων του ΔΔΑ
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
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
//void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
//void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
//void RecBSTInorder(BinTreePointer Root);
//void RecBSTPreorder(BinTreePointer Root);
//void RecBSTPostorder(BinTreePointer Root);

int Ceil(BinTreePointer Root, BinTreeElementType Item);
int Floor(BinTreePointer Root, BinTreeElementType Item);

int main() {

  BinTreePointer ARoot;
  CreateBST(&ARoot);

  while (TRUE) {
    BinTreeElementType input;
    printf("Give number to insert: ");
    scanf("%d", &input);
    if (input < 0) break;
    RecBSTInsert(&ARoot, input);
  }

  while (TRUE) {
    BinTreeElementType input;
    printf("Give number to search: ");
    scanf("%d", &input);
    if (input < 0) break;
    printf("Ceiling : %d\n", Ceil(ARoot, input));
    printf("Floor : %d\n", Floor(ARoot, input));
  }




  return 0;
}

int Ceil(BinTreePointer Root, BinTreeElementType Item){
  int result;
  if (BSTEmpty(Root)){
      return -1;
  } else if (Root->Data == Item) {
      return Root->Data;
  } else if (Root->Data < Item) {
      return Ceil(Root->RChild, Item);
  } else {
      result = Ceil(Root->LChild, Item);
  }
  if (result == -1) {
      return Root->Data;
  }
  return result;
}

int Floor(BinTreePointer Root, BinTreeElementType Item){
  int result;
  if (BSTEmpty(Root)){
      return -1;
  } else if (Root->Data == Item) {
      return Root->Data;
  } else if (Root->Data > Item) {
      return Floor(Root->LChild, Item);
  } else {
      result = Floor(Root->RChild, Item);
  }
  if (result == -1) {
      return Root->Data;
  }
  return result;
}



void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item < (*Root) ->Data)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item > (*Root) ->Data)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("To %d EINAI HDH STO DDA\n", Item);
}
