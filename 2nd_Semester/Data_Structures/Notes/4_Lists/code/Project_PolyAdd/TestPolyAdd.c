
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "PolyAdd.h"

int main()
{

    PolyPointer pointerA,pointerB,pointerC,ptr;
    int Co, Ex;
    char ch;

    pointerA= (PolyPointer)malloc(sizeof(struct PolyNode));
    ptr=pointerA;
    printf("DWSTE TA STOIXEIA TOY 1OY POLYWNYMOY\n");
    do
    {
        printf("DWSTE TON SYNTELESTH TOY OROY ");
        scanf("%d", &Co);
        printf("DWSTE TON EK8ETH TOY OROY ");
        scanf("%d", &Ex);
        Attach(Co,Ex, &ptr);
        printf("CONTINUE Y/N ");
        do
        {
      	    scanf("%c", &ch);
        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');

    printf("TA STOIXEIA TOY 1OY POLYWNYMOY\n");
    ptr=pointerA->next;
    LinkedTraverse(ptr);

    printf("\nDWSTE TA STOIXEIA TOY 2OY POLYWNYMOY\n");
    pointerB= (PolyPointer)malloc(sizeof(struct PolyNode));

    ptr=pointerB;
    do
    {
        printf("DWSTE TON SYNTELESTH TOY OROY ");
        scanf("%d", &Co);
        printf("DWSTE TON EK8ETH TOY OROY ");
        scanf("%d", &Ex);
        Attach(Co,Ex, &ptr);
        printf("CONTINUE Y/N ");
        do
        {
      	    scanf("%c", &ch);
        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');

    printf("\nTA STOIXEIA TOY 2OY POLYWNYMOY\n");
    ptr=pointerB->next;
    LinkedTraverse(ptr);

    LinkedPolyAdd(pointerA, pointerB, &pointerC);

    printf("\nTA STOIXEIA TOY 3OY POLYWNYMOY\n");
    ptr=pointerC->next;
    LinkedTraverse(ptr);
    system("PAUSE");
    return 0;
}
