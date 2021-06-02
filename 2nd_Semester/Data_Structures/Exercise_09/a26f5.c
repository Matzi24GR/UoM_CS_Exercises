#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int code;
  char surname[20];
  char givenName[20];
  char gender;
  int year;
  float grade;
} studentT;

typedef struct{
  int code;
  int fileIndex;
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
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTInorder(BinTreePointer Root);


int menu();
int BuildBST(BinTreePointer *Root);
void PrintStudent(int RecNum);
void printStudentsWithGrade();

int main() {

  BinTreePointer ARoot, LocPtr;
  int choice, size;

  do {
    choice = menu();
    switch (choice) {
      case 1: {size = size=BuildBST(&ARoot); break;}
      case 2: {

        FILE *file = fopen("foitites.dat", "a");
        BinTreeElementType searchItem;
        printf("Give student's AM: ");
        scanf("%d", &(searchItem.code) );
        boolean Found = FALSE;
        BinTreePointer LocPtr = ARoot;
        RecBSTSearch(ARoot, searchItem, &Found, &LocPtr);

        if (Found) {
          printf("O φοιτητής υπάρχει ήδη στο αρχείο\n");
        } else {
          studentT student;
          student.code = searchItem.code;
          printf("Επώνυμο: ");
          scanf("%s", &student.surname);
          printf("Όνομα: ");
          scanf("%s", &student.givenName);
          printf("Φύλλο: ");
          scanf(" %c", &student.gender);
          printf("Έτος: ");
          scanf("%d", &student.year);
          printf("Βαθμός: ");
          scanf("%f", &student.grade);
          size++;
          BinTreeElementType indexRec;
          indexRec.code = student.code;
          indexRec.fileIndex = size;
          RecBSTInsert(&ARoot, indexRec);
          fflush(file);
          fprintf(file, "%d, %s, %s, %c, %d, %g\n", student.code, student.surname, student.givenName, student.gender, student.year, student.grade);
        }
        fclose(file);
        break;
      }
      case 3: {
        BinTreeElementType searchItem;
        printf("Give student's code: ");
        scanf("%d", &(searchItem.code) );
        boolean Found = FALSE;
        BinTreePointer LocPtr = ARoot;
        RecBSTSearch(ARoot, searchItem, &Found, &LocPtr);

        if (Found) {
          PrintStudent(LocPtr->Data.fileIndex);
        } else {
          printf("δε βρέθηκε\n");
        }
        break;
      }
      case 4: {
        printf("\nPrint all students data\n");
        RecBSTInorder(ARoot);
        printf("\n");
        break;
      }
      case 5: {printStudentsWithGrade();
          break;
      }
    }

  } while (choice != 6);

  return 0;
}

int menu() {
  printf("\n                    ΜΕΝΟΥ\n");
  printf("----------------------------------------------------------------------\n");
  printf("1. Build BST\n");
  printf("2. Insert new student\n");
  printf("3. Search for a student\n");
  printf("4. Print all students (Traverse Inorder)\n");
  printf("5. Print students with a >= given grade\n");
  printf("6. Quit\n");
  int choice;
  do {
    printf("\nEpilogh: ");
    scanf("%d", &choice);
  } while (choice <1 || choice >6);
  return choice;
}

int BuildBST(BinTreePointer *Root) {

  CreateBST(Root);
  FILE *file = fopen("foitites.dat", "r");
  int size = 0;

  if (file != NULL) {
    while (TRUE) {
      studentT student;
      int nscan = fscanf(file,"%d, %20[^,], %20[^,], %c, %d, %g",
                                                                &student.code,
                                                                &student.surname,
                                                                &student.givenName,
                                                                &student.gender,
                                                                &student.year,
                                                                &student.grade);
      if (nscan != 6) break;
      else {
          BinTreeElementType indexRec;
          indexRec.code = student.code;
          indexRec.fileIndex = size +1;
          RecBSTInsert(Root, indexRec);
          size++;
      }
    }
  }
  fclose(file);

  return size;
}

void PrintStudent(int RecNum) {
    studentT student;
    FILE *file = fopen("foitites.dat","r");
    int lines = 0;
    while ( lines< RecNum) {
      int nscan = fscanf(file,"%d, %20[^,], %20[^,], %c, %d, %g",
                                                                &student.code,
                                                                &student.surname,
                                                                &student.givenName,
                                                                &student.gender,
                                                                &student.year,
                                                                &student.grade);
      if (nscan != 6) break;
      else {
          lines++;
      }
    }
    if (lines == RecNum) {
      printf( "%d,%s,%s,%c,%d,%g", student.code, student.surname, student.givenName, student.gender, student.year, student.grade);
    }
    fclose(file);
}

void printStudentsWithGrade() {
  printf("\nPrint students with a >= given grade\n");
  printf("Give the grade: ");
  float grade;
  scanf("%g", &grade);

  FILE *file = fopen("foitites.dat", "r");
  if (file != NULL) {
      while (TRUE) {
        studentT student;
        int nscan = fscanf(file,"%d, %20[^,], %20[^,], %c, %d, %g",
                                                                  &student.code,
                                                                  &student.surname,
                                                                  &student.givenName,
                                                                  &student.gender,
                                                                  &student.year,
                                                                  &student.grade);
        if (nscan != 6) break;
        else {
            if(student.grade >= grade) {
                printf( "%d,%s,%s,%c,%d,%g\n", student.code, student.surname, student.givenName, student.gender, student.year, student.grade);
            }
        }
      }
  }
}

//----------------------------------------------------------------------------------
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
        if (Item.code < (*Root) ->Data.code)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item.code > (*Root) ->Data.code)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("To %d EINAI HDH STO DDA\n", Item);
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{
    boolean stop;

    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue.code < Root->Data.code)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue.code > Root->Data.code)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
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
        printf("(%d, %d), ",Root->Data.code,Root->Data.fileIndex);
        RecBSTInorder(Root->RChild);
    }
}
