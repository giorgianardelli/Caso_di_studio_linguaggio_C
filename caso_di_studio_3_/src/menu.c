/*
 * menu.c
 *
 *  Created on: 19 mag 2021
 *      Author: giorg
 */
#include "struct.h"
#include "grafiche.h"
#include "specifiche.h"
#include "menu.h"

void menuPrincipale()
{
	int scelta;
	 do
	 {
	  printf("Inserisci la tua scelta --> ");
	  scanf("%d", &scelta);
	  printf("\n");
	 }while(scelta >5);

	 switch(scelta)
	 {
	  case 1:
	  registrazione();
	  break;

	  case 2:
	  login();
	  break;

	  case 3:
	  ospite();
	  break;

	  case 4:
	  modificaProfilo();
	  break;

	  case 5:
		  printf("Grazie per aver utilizzato il nostro sito \n");
		  printf("Arrivederci ");
		  remove("user2.dat");
		  remove("immagini2.dat");
		  chiusura();
		  exit(0);
	 }
}

void menuCreatore()
{
 int scelta;

  sezioneCreatore();
  do
	{
	 printf("Inserisci la tua scelta --> ");
	 scanf("%d", &scelta);
	}while(scelta >5);
  printf("\n");

  switch(scelta)
  {
    case 1:
    caricamento();
    printf("\n");
    break;

    case 2:
    modifica();
    printf("\n");
    break;

    case 3:
    cancellazione();
    printf("\n");
    break;

    case 4:
    visualizza();
    printf("\n");
    break;

    case 5:
    sezionePrincipale();
    menuPrincipale();
  }
}


/*     MENU' UTILIZZATORE     */
void menuUtilizzatore()
{
 int scelta;

 sezioneUtilizzatore();

 do
 {
  printf("Inserisci la tua scelta --->");
  scanf("%d", &scelta);
  printf("\n");
 }while(scelta > 4);

  switch(scelta)
  {
    case 1:
    ricerca();
    break;

    case 2:
    statistica();
    break;

    case 3:
    //popolari
    break;

    case 4:
    sezionePrincipale();
    menuPrincipale();
    break;
  }
}

void menuAdmin()
{
  int scelta;

  sezioneAdmin();
  do
  {
	printf("Inserisci la tua scelta --> ");
	scanf("%d", &scelta);
  }while(scelta >3);

  switch(scelta)
  {
   case 1:
   visualizza_azioni();
   break;

   case 2:
   elimina_utente();
   break;

   case 3:
   sezionePrincipale();
   menuPrincipale();
   break;
  }
}
