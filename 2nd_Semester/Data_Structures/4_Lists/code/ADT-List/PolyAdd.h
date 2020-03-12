//filename PolyAdd.h

typedef int CoefficientType;
typedef  struct PolyNode *PolyPointer;
typedef  struct PolyNode {
        CoefficientType Coef;
	    int  Expo;
	    PolyPointer next;
} PolyNode;

typedef enum {
    FALSE, TRUE
} boolean;

boolean EmptyList(PolyPointer List);
void LinkedTraverse(PolyPointer List);
void Attach(CoefficientType Co,int Ex, PolyPointer *Last);
void LinkedPolyAdd(PolyPointer P,PolyPointer Q,PolyPointer *W);
