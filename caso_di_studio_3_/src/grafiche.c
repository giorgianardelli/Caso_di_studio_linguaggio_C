/*
 * grafiche.c
 *
 *  Created on: 19 mag 2021
 *      Author: giorg
 */
#include "struct.h"

void sezionePrincipale()
{
  system("cls");
  printf(" -------------------------------------------------------- \n");
  printf("|           		 BENVENUTO IN FRANGIOP                 | \n");
  printf(" -------------------------------------------------------- \n");

  printf(" -------------------------------------------------------- \n");
  printf("|               MENU' PRINCIPALE                         | \n");
  printf(" -------------------------------------------------------- \n");
  printf("|   1) REGISTRATI              |   4) MODIFICA PROFILO   | \n");
  printf("|   2) LOGIN                   |   5) ESCI			   | \n");
  printf("|   3) ENTRA COME OSPITE       |   					   | \n");
  printf(" -------------------------------------------------------- \n");
}

void sezioneRegistrazione()
{
  system("cls");
  printf(" --------------------------------------------- \n");
  printf("|            SEZIONE REGISTRAZIONE            | \n");
  printf(" --------------------------------------------- \n");
}

void sezioneLogin()
{
  system("cls");
  printf(" --------------------------------------------- \n");
  printf("|                SEZIONE LOGIN                | \n");
  printf(" --------------------------------------------- \n");
}

void sezioneOspite()
{
  system("cls");
  printf(" ------------------------------------------- \n");
  printf("|              MENU' OSPITE                 | \n");
  printf(" ------------------------------------------- \n");
  printf("|   1) VISUALIZZA      |   2) ESCI          | \n");
  printf(" ------------------------------------------- \n");
}

void sezioneModifica_profilo()
{
  system("cls");
  printf(" ------------------------------------------- \n");
  printf("|         SEZIONE MODIFICA PROFILO          | \n");
  printf(" ------------------------------------------- \n");
  printf("|   1) MODIFICA INFO  |   2) TORNA AL MENU' | \n");
  printf(" ------------------------------------------- \n");
}

void sezioneCreatore()
{
  system("cls");
  printf(" ------------------------------------------- \n");
  printf("|              MENU' CREATORE               | \n");
  printf(" ------------------------------------------- \n");
  printf("|   1) CARICAMENTO  |   4) VISUALIZZA       | \n");
  printf("|   2) MODIFICA     |   5) ESCI             | \n");
  printf("|   3) CANCELLAZIONE|                       |  \n");
  printf(" ------------------------------------------- \n");
}

void sezioneUtilizzatore()
{
  system("cls");
  printf(" ------------------------------------------- \n");
  printf("|              MENU' UTILIZZATORE           | \n");
  printf(" ------------------------------------------- \n");
  printf("|   1) RICERCA      |   3) POPOLARI         | \n");
  printf("|   2) STATISTICA   |   4) ESCI             | \n");
  printf(" ------------------------------------------- \n");
}

void sezioneAdmin()
{
  system("cls");
  printf(" -------------------------------------------  \n");
  printf("|               MENU' ADMIN                 | \n");
  printf(" -------------------------------------------  \n");
  printf("|   1) AZIONI UTENTI  |   3) ESCI           | \n");
  printf("|   2) ELIMINA UTENTI                       | \n");
  printf(" -------------------------------------------  \n");
}

void sezioneCaricamento()
{
  system("cls");
  printf(" ------------------------------------------- \n");
  printf("|            SEZIONE CARICAMENTO            | \n");
  printf(" ------------------------------------------- \n");
  printf("|   1) CARICAMENTO  |   2) TORNA AL MENU'   | \n");
  printf(" ------------------------------------------- \n");
}

void sezioneVisualizza()
{
  system("cls");
  printf(" ------------------------------------------- \n");
  printf("|            SEZIONE VISUALIZZA             | \n");
  printf(" ------------------------------------------- \n");
  printf("|   1) VISUALIZZA   |   2) TORNA AL MENU'   | \n");
  printf(" ------------------------------------------- \n");
}

void sezioneModifica()
{
  system("cls");
  printf(" -------------------------------------------  \n");
  printf("|              SEZIONE MODIFICA             | \n");
  printf(" -------------------------------------------  \n");
  printf("|   1) MODIFICA     |   2) TORNA AL MENU'   | \n");
  printf(" -------------------------------------------  \n");
}

void sezioneCancellazione()
{
  system("cls");
  printf(" -------------------------------------------  \n");
  printf("|           SEZIONE CANCELLAZIONE           | \n");
  printf(" -------------------------------------------  \n");
  printf("|   1) CANCELLA     |   2) TORNA AL MENU'   | \n");
  printf(" -------------------------------------------  \n");
}

void sezioneRicerca()
{
 system("cls");
 printf(" ------------------------------------------- \n");
 printf("|              SEZIONE RICERCA              | \n");
 printf(" -------------------------------------------  \n");
 printf("|   1) PER TITOLO    |  3) TORNA AL MENU'   | \n");
 printf(" -------------------------------------------  \n");
 printf("|   2) PER PAROLA CHIAVE                    | \n");
 printf(" -------------------------------------------  \n");
}

void sezioneDownload()
{
 printf(" ------------------------------------------- \n");
 printf("|              SEZIONE DOWNLOAD             | \n");
 printf(" -------------------------------------------  \n");
 printf("|   1) PER SCARICARE  |  3) TORNA AL MENU'  | \n");
 printf(" -------------------------------------------  \n");
 printf("|   2) PER VALUTARE                         | \n");
 printf(" -------------------------------------------  \n");
}
