#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define megisto_plithos 59

typedef enum
{
    FALSE, TRUE

} boolean;

typedef int stoixeio_synolou;
typedef boolean typos_synolou[megisto_plithos];

void Katholiko(typos_synolou synolo);
void Dimiourgia_keno(typos_synolou synolo);
void odd_numbers(typos_synolou synolo);
void prime_numbers(typos_synolou set);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void displayset(typos_synolou set);
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi);
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi);
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora);

int main(){


    typos_synolou odds,primes,tomh,enwsh,diafora_set,katholiko,symblhrwma;

    odd_numbers(odds);
    displayset(odds);

    prime_numbers(primes);
    displayset(primes);


    TomiSynolou(primes,odds,tomh);
    displayset(tomh);

    EnosiSynolou(primes,odds,enwsh);

    displayset(enwsh);

    DiaforaSynolou(odds,primes,diafora_set);
    displayset(diafora_set);

    Katholiko(katholiko);
    DiaforaSynolou(katholiko,primes,symblhrwma);
    displayset(symblhrwma);

}
void Katholiko(typos_synolou synolo)

{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = TRUE;
}


void Dimiourgia_keno(typos_synolou synolo)
 {
     stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++){
        synolo[i] = FALSE;
    }

}


boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)

{
    return synolo[stoixeio];
}


void odd_numbers(typos_synolou synolo)
{
    Dimiourgia_keno(synolo);
    stoixeio_synolou i;


    for(int i=1; i<=megisto_plithos; i++){
        if(i%2== 1){
            synolo[i] = TRUE;
        }
    }
}

boolean isPrime(int n){
    int i,limit;
    if(n <=1){return (FALSE);}
    if(n ==2){return (TRUE);}
    if(n % 2 == 0){return (FALSE);}
    limit = sqrt(n) +1;
    for(i=3;i<=limit;i+=2){
        if(n%i==0){return (FALSE);}
    }
    return TRUE;
}
void prime_numbers(typos_synolou set){

    Dimiourgia_keno(set);
    stoixeio_synolou i;
    for (i=1;i <= megisto_plithos;i++)
	{
		if(isPrime(i)){
            set[i] = TRUE;
		}
	}
}
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi)

{
    stoixeio_synolou i;
    for (i = 0; i <= megisto_plithos; i++)
        tomi[i] = Melos(i, s1) && Melos(i, s2);
}
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi)

{
    stoixeio_synolou i;
    for (i = 0; i <= megisto_plithos; i++)
        enosi[i] = Melos(i, s1) || Melos(i, s2);
}
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora)

{
    stoixeio_synolou i;
    for (i = 0; i <= megisto_plithos; i++)
        diafora[i] = Melos(i, s1) && (!Melos(i, s2));
}

void displayset(typos_synolou set)
{
	stoixeio_synolou i;
	for (i=1;i <= megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf("%d",i);
	}
	printf("\n");
}
