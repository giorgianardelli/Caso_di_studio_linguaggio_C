/*
 ============================================================================
 Name        : caso_di_studio_3_.c
 Author      : Giorgia Nardelli Francesco Papagno
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "grafiche.h"
#include "specifiche.h"
#include "struct.h"
#include "menu.h"

int main(void)
{
 setbuf(stdout,0);
 apertura();

 if(user == NULL || immagini == NULL || valutazioni == NULL || azioni == NULL)
 {
  printf("ERRORE NELL'APERTURA DEI FILE !! \n");
 }
 else
 {
  sezionePrincipale();
  menuPrincipale();

 }
 chiusura();
 system("pause");
 return EXIT_SUCCESS;
}
