/*
 * struct.h
 *
 *  Created on: 19 mag 2021
 *      Author: giorg
 */
#ifndef STRUCT_H_
#define STRUCT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM_PASSWORD 11
#define NUM_CREATORI 50
#define LUNGHEZZA_USER 20
#define LUNGHEZZA_TITOLO 30
#define LUNGHEZZA_TIPOLOGIA 30
#define LUNGHEZZA_NOME_IMG 30
#define LUNGHEZZA_KEY 30

FILE* user, *user2, *immagini, *immagini2, *valutazioni, *azioni;

typedef struct
{
  char user_name[LUNGHEZZA_USER];
  char password[DIM_PASSWORD];
  char professione;
  int num_vettore;
  int num_icona;
  int num_foto;
}utente;

typedef struct
{
  char titolo[LUNGHEZZA_TITOLO];
  char tipologia[LUNGHEZZA_TIPOLOGIA];
  char nome_immagine[LUNGHEZZA_NOME_IMG];
  char parola_chiave[LUNGHEZZA_KEY];
  int valutazione;
  int copie_scaricate;
  utente ut_cr;
}immagine;

utente ut;
immagine img;

char id_sessione[20];
#endif /* STRUCT_H_*/
