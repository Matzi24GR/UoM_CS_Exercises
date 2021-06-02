#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[20];
  int  id;                    //(1=υπάλληλος γραφείου, 2=εργάτης, 3=αντιπρόσωπος)
} BinTreeElementType;

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
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);


void BuildBST(BinTreePointer *Root);
void InorderTraversalPart(BinTreePointer Root, int code);

int main() {
  // 1. Create BST
  BinTreePointer ARoot;
  BuildBST(&ARoot);

  // 2. Insert Employees
  char typesArray[3][30] = {"office employees", "factory employees", "sales representatives"};
  for (int type=0; type<3; type++) {
    printf("\nGive data for %s:\n",typesArray[type]);
    for (int i=0; i<3; i++){
      BinTreeElementType Employee;

      printf("Give employee name:");
      //Διάβασμα ονοματεπωνύμου για να μη σταματήσει στο κενό
      fgets(Employee.name,20,stdin);
      Employee.name[strlen(Employee.name)-1]='\0';
      printf("Give employee code:");
      //Διάβασμα κωδικού για να μη διαβάσει και τον επόμενο χαρακτήρα
      scanf("%d",&Employee.id);
      getchar();

      RecBSTInsert(&ARoot, Employee);
    }
  }

  // 3. Search for an employee by name
  printf("Give name for employee to lookup:\n");
  BinTreeElementType Employee;
  fgets(Employee.name,20,stdin);
  Employee.name[strlen(Employee.name)-1]='\0';

  boolean found;
  BinTreePointer LocPtr;
  BSTSearch(ARoot, Employee, &found, &LocPtr);
  if (found) printf("%s, %d\n", LocPtr->Data.name, LocPtr->Data.id);
  else printf("Does not exist\n");

  // 4. List all employees
  printf("\nAll Employees:\n");
  RecBSTInorder(ARoot);
  // 5. List office employees
  printf("\nAll office employees:\n");
  InorderTraversalPart(ARoot, 1);
  // 6. List factory employees
  printf("\nAll factory employees:\n");
  InorderTraversalPart(ARoot, 2);
  // 7. List sale representatives
  printf("\nAll sales representatives:\n");
  InorderTraversalPart(ARoot, 3);

  //8. Delete an employee record
  printf("\nGive employee name for deletion:\n");
  fgets(Employee.name,20,stdin);
  Employee.name[strlen(Employee.name)-1]='\0';

  BSTDelete(&ARoot,Employee);

  return 0;
}

void BuildBST(BinTreePointer *Root){
  FILE *input = fopen("I12F5.TXT","rw");

  CreateBST(Root);

  while (TRUE) {
    BinTreeElementType Employee;
    int nscan = fscanf(input ,"%20[^,], %d\n", &Employee.name, &Employee.id);
    if (nscan == EOF || nscan != 2) break;
    RecBSTInsert(Root, Employee);
  }
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
        if (strcmp(Item.name, (*Root)->Data.name) < 0)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else  if (strcmp(Item.name, (*Root)->Data.name) > 0)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("To %d EINAI HDH STO DDA\n", Item);
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
         if (strcmp(KeyValue.name, (*LocPtr)->Data.name) < 0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
              if (strcmp(KeyValue.name, (*LocPtr)->Data.name) > 0)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void RecBSTInorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        RecBSTInorder(Root->LChild);
        printf("%s %d \n",Root->Data.name, Root->Data.id);
        RecBSTInorder(Root->RChild);
    }
}

void InorderTraversalPart(BinTreePointer Root, int code){
  {
      if (Root!=NULL) {
          InorderTraversalPart(Root->LChild, code);
          if (Root->Data.id == code) {
            printf("%s %d \n",Root->Data.name, Root->Data.id);
          }
          InorderTraversalPart(Root->RChild, code);
      }
  }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του
                και τον πατέρα του κόμβου αυτού.
   Επιστρέφει: Η Found έχει τιμή TRUE, ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue και ο Parent δείχνει στον πατέρα
                αυτού του κόμβου, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE.
*/
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
         if (strcmp(KeyValue.name, (*LocPtr)->Data.name) < 0) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
              if (strcmp(KeyValue.name, (*LocPtr)->Data.name) > 0) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
  Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer
   n,                   //δείχνει στον κόμβο που περιέχει την τιμή KeyValue *)
   Parent,              // πατέρας του n ή του nNext
   nNext,               // ενδοδιατεταγμένος επόμενος του n
   SubTree;             // δείκτης προς υποδέντρο του n
   boolean Found;       // TRUE AN TO ΣΤΟΙΧΕΙΟ KeyValue EINAI ΣΤΟΙΧΕΟ ΤΟΥ ΔΔΑ *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %d DEN EINAI STO DDA\n", KeyValue);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // κόμβος προς διαγραφή με δύο παιδιά
                 //Βρες τον ενδοδιατεταγμένο επόμενο και τον πατέρα του
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* Αντιγραφή των περιεχομένων του nNext στον n και
                αλλαγή του n ώστε να δείχνει στον επόμενο */
                n->Data = nNext->Data;
                n = nNext;
          } //Συνεχίζουμε με την περίπτωση που ο κόμβος έχει το πολύ 1 παιδί
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}
