// LPChADT.h

typedef char ListElementType;            /* � ����� ��� ��������� ��� ������������ ������
                                        ���������� ����� char */
typedef struct ListNode *ListPointer;   //� ����� ��� ������� ��� ���� �������
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
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void OrderedLimearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
