//filename PolyAdd.c
//                 *ΠΡΟΣΘΕΣΗ ΠΟΛΥΩΝΥΜΩΝ*
//          ΥΛΟΠΟΙΗΣΗ ΚΑΘΕ ΠΟΛΥΩΝΥΜΟΥ ΩΣ ΣΥΝΔΕΔΕΜΕΝΗ ΛΙΣΤΑ ΜΕ ΚΟΜΒΟ ΚΕΦΑΛΗ

#include <stdio.h>
#include <stdlib.h>
#include "PolyAdd.h"


boolean EmptyList(PolyPointer List)
/* DEXETAI:    MIA SYNDEDEMENH LISTA ME TON PRWTO KOMBO NA DEIKTODOTEITAI APO TON
               DEIKTH List.
   LEITOYRGIA: ELEGXEI AN H SYNDEDEMENH LISTA EINAI KENH.
   EPISTREFEI: True AN H SYNDEDEMENH LISTA EINAI KENH, false DIAFORETIKA 
*/
{
  return (List==NULL);
}

void Attach(CoefficientType Co,int Ex, PolyPointer *Last)
/* Δέχεται:    Έναν συντελεστή Coef, έναν εκθέτη Exp και έναν δείκτη Last. 
   Λειτουργία: Δημιουργεί έναν κόμβο που περιέχει τους Coef και Exp, 
                τον συνδέει με τον κόμβο στον οποίο δείχνει ο Last και κάνει 
                τον Last να δείχνει σ' αυτόν τον νέο κόμβο. 
   Επιστρέφει: Τον τροποποιημένο δείκτη Last 
*/
{ 
  PolyPointer TempPtr;

  TempPtr= (PolyPointer)malloc(sizeof(struct PolyNode));
  TempPtr->Coef=Co;
  TempPtr->Expo=Ex;
  TempPtr->next=NULL;
  (*Last)->next=TempPtr;
  *Last=TempPtr;
}

void LinkedPolyAdd(PolyPointer P,PolyPointer Q,PolyPointer *W)
/* Δέχεται:   Δύο πολυώνυμα, P και Q. 
  Λειτουργία: Υπολογίζει το άθροισμα W = P + Q. 
  Επιστρέφει: Το πολυώνυμο W. 
  Σημείωση:   Τα πολυώνυμα παριστάνονται ως συνδεδεμένες λίστες με κόμβο κεφαλή 
*/
{
    PolyPointer ptrP,ptrQ,ptrW,TempPtr;
    CoefficientType sum;

    ptrP=P->next;
    ptrQ=Q->next;
    *W=(PolyPointer)malloc(sizeof(struct PolyNode));

    ptrW=*W;
    while (ptrP!=NULL && ptrQ!=NULL) 
    {
      if (ptrP->Expo<ptrQ->Expo)             //αντιγραφή του όρου από το Ρ
      {
          Attach(ptrP->Coef, ptrP->Expo,&ptrW);
	      ptrP=ptrP->next;
	   }
      else
            if (ptrQ->Expo<ptrP->Expo)     //αντιγραφή του όρου από το Q
            {
                Attach(ptrQ->Coef, ptrQ->Expo,&ptrW);
	            ptrQ=ptrQ->next;
	        }
	        else                           //ίδιοι εκθέτες
            {
	               sum=ptrP->Coef+ptrQ->Coef;
   	                if (sum!=0) 
	                   Attach(sum,ptrP->Expo,&ptrW);
	      
	               ptrP=ptrP->next;
	               ptrQ=ptrQ->next;
	       }
    }
    //Αντιγραφή των υπόλοιπων όρων του P ή του Q στο W
    if (ptrP!=NULL) 
        TempPtr=ptrP;
    else
        TempPtr=ptrQ;
    while (TempPtr!=NULL) 
    {
        Attach(TempPtr->Coef, TempPtr->Expo, &ptrW);
        TempPtr=TempPtr->next;
    }
    ptrW->next=NULL;
}

void LinkedTraverse(PolyPointer List)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
   Λειτουργία: Διασχίζει τη συνδεδεμένη λίστα και
                επεξεργάζεται κάθε δεδομένο ακριβώς μια φορά.
   Εξοδος    : Εμφανίζει τα στοιχεία της συνδεδεμένης λίστας αν εν είναι κενή 
                διαφορετικά εμφανίζει μήνυμα
*/
{
    PolyPointer CurrPtr;

    if (!EmptyList(List)) 
    {
        CurrPtr=List;
        while (CurrPtr!=NULL) 
        {
          printf("(%d %d)", CurrPtr->Coef, CurrPtr->Expo);
          CurrPtr=CurrPtr->next;
        }
        printf("\n");
   }
  else printf("Empty List\n");
}

