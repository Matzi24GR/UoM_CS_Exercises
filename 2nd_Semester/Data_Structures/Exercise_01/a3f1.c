#include <stdio.h>
#include <stdlib.h>
#define megisto_plithos 26

typedef enum
{
    FALSE, TRUE

} boolean;

typedef int stoixeio_synolou;
typedef boolean typos_synolou[megisto_plithos];

void Dimiourgia(typos_synolou synolo);
void DimiourgiaS(typos_synolou synolo);
void DhmhiourgiaT(typos_synolou synolo);

void Katholiko(typos_synolou synolo);

void displayset(typos_synolou set);
void IsaSynola(typos_synolou s1,typos_synolou s2);
boolean Yposynolo(typos_synolou s1,typos_synolou s2);

int main()
{
    typos_synolou keno_synolo,kath_syn,Enosi_sun,tomh,diafora,s_synolo,t_synolo;


    Katholiko(kath_syn);
    displayset(kath_syn);

    DhmhiourgiaS(s_synolo);
    displayset(s_synolo);

    DhmhiourgiaT(t_synolo);
    displayset(t_synolo);

    IsaSynola(s_synolo,t_synolo);
    if(Yposynolo(s_synolo,t_synolo)) printf("S YPOSYNOLO T");
    if(Yposynolo(t_synolo,s_synolo)) printf("T YPOSYNOLO S");

    EnosiSynolou(s_synolo,t_synolo,Enosi_sun);
    displayset(enwsh);

    TomiSynolou(t_synolo,s_synolo,tomh);
    displayset(tomh);

    DiaforaSynolou(s_synolo,t_synolo,diafora);
    displayset(diafora);

    return 0;

}

void Dimiourgia(typos_synolou synolo)
 {
     stoixeio_synolou i;

    for (i = 0; i < 26; i++)
        synolo[i] = FALSE;

}


void Katholiko(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
    {

        synolo[i] = TRUE;
    }
}

void DhmhiourgiaS(typos_synolou synolo){


    Dimiourgia(synolo);

    for(int i = 0; i<4; i++){
        synolo[i] = TRUE;

    }



}
void DhmhiourgiaT(typos_synolou synolo){


    Dimiourgia(synolo);

    for(int i = 0; i<9; i=i+2){
        synolo[i] = TRUE;

    }



}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)

{
    return synolo[stoixeio];
}
void IsaSynola(typos_synolou s1, typos_synolou s2)

{
  stoixeio_synolou i;
  boolean isa;

  isa = TRUE;
  i = 0;
  while (i < megisto_plithos && isa)

    if (Melos(i,s1)!= Melos(i,s2))

      isa = FALSE;
    else
      i = i+1;
  if(isa == TRUE){
    printf("ISA SYNOLA");


  }

}
boolean Yposynolo(typos_synolou s1, typos_synolou s2)

{
    stoixeio_synolou i;
    boolean yposyn;

    yposyn = TRUE;
    i=0;
    while (i < megisto_plithos && yposyn)
        if (Melos(i, s1) && !Melos(i, s2))
            yposyn = FALSE;
        else
            i++;
}
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi)

{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        enosi[i] = Melos(i, s1) || Melos(i, s2);
}

void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi)

{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        tomi[i] = Melos(i, s1) && Melos(i, s2);
}

void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora)

{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        diafora[i] = Melos(i, s1) && (!Melos(i, s2));
}


void displayset(typos_synolou set)
{
	stoixeio_synolou i;
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (i=0;i < megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf("%c ",alphabet[i]);
	}
	printf("\n");
}
