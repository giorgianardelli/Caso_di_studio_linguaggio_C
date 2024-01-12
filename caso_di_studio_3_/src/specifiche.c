/*
 * specifiche.c
 *
 *  Created on: 19 mag 2021
 *      Author: giorg
 */
#include "struct.h"
#include "grafiche.h"
#include "menu.h"
#include "specifiche.h"


void apertura()
{
	user= fopen("user.dat", "rb+");
	user2=fopen("user2.dat", "wb+");
	immagini= fopen("immagini.dat", "rb+");
	immagini2= fopen("immagini2.dat", "wb+");
	valutazioni= fopen("valutazioni.dat", "rb+");
	azioni= fopen("azioni.dat", "rb+");
}

void chiusura()
{
	fclose(user);
	fclose(immagini);
	fclose(valutazioni);
	fclose(azioni);
}

void registrazione()
{
	sezioneRegistrazione();
	printf("inserisci user name --> ");
	scanf("%s", ut.user_name);

	do
	{
		printf("Inserisci password (Massimo 11 caratteri)-->");
		scanf("%s", ut.password);
	}while(strlen(ut.password)>DIM_PASSWORD);

	do
	{
		printf("Inserisci la tua professione \n");
		printf("C per creatore, U per utente -->");
		scanf("%s", &ut.professione);
	}while((ut.professione != 'C') && (ut.professione !='U'));

	fseek(user,sizeof(utente), SEEK_END);  //sposta il puntatore del file user alla fine del file
	fwrite(&ut, sizeof(ut), 1, user);
	printf("\n");
	login();
}

void login()
{
	char userInput[20];
	char passwordInput[20];
	int flag=0, scelta=0;

	sezioneLogin();
	printf("Inserisci user name -->");
	scanf("%s", userInput);
	printf("Inserisci password -->");
	scanf("%s", passwordInput);

	rewind(user);
	while(!feof(user))
	{
		fread(&ut, sizeof(utente), 1, user);
		if(strcmp(userInput, ut.user_name) == 0 && strcmp(passwordInput, ut.password) == 0)
		{
			if(ut.professione == 'C')
			{
				strcpy(id_sessione, ut.user_name);
				flag = 1;
				printf("\n");
				menuCreatore();
			}
			else if(ut.professione == 'U')
			{
				strcpy(id_sessione, ut.user_name);
				flag = 1;
				printf("\n");
				menuUtilizzatore();
			}
			else if(ut.professione == 'A')
			{
				strcpy(id_sessione, ut.user_name);
				flag = 1;
				printf("\n");
				menuAdmin();
			}
		}
	}
	if(flag==0)
	{
		printf("User Id o Password non corretti !!! \n");
		printf("Riprovare il login o registrarsi \n");
		printf("Inserisci un numero per tornare al menu principale -->");
		scanf("%d", &scelta);
		sezionePrincipale();
		menuPrincipale();
	}
}

/*     MENU' OSPITE     */
void ospite()
{
	int scelta;

	sezioneOspite();
	do
	{
		printf("Inserisci la tua scelta -->");
		scanf("%d", &scelta);
		printf("\n");
	}while(scelta >2);

	switch(scelta)
	{
	case 1:
		printf("| TITOLO \t| TIPOLOGIA \t| FORMATO \n");
		printf("---------------------------------------- \n");
		rewind(immagini);
		while(!feof(immagini))
		{
			fread(&img, sizeof(img), 1, immagini);
			if(!feof(immagini) && (strcmp(img.titolo, "")!=0))
			{
				if(strcmp(ut.user_name, id_sessione) == 0)
				{
					printf("| %s \t| %s \t| %s \n", img.titolo, img.tipologia, img.nome_immagine);
				}
			}
		}
		printf("---------------------------------------- \n");
		printf("premi un qualsiasi tasto per tornare al menu' principale -->");
		scanf("%d", &scelta);
		sezionePrincipale();
		menuPrincipale();
		//FIXME valutazione sito
		break;

	case 2:
		sezionePrincipale();
		menuPrincipale();
		break;
	}
}

void modificaProfilo()
{
	int scelta=0, flag=0, i=0, posizione=-1;
	char userInput[30];
	char passwordInput[30];
	utente temp;

	sezioneModifica_profilo();

	do
	 {
	  printf("Inserisci la tua scelta -->");
	  scanf("%d", &scelta);
	  printf("\n");
	 }while(scelta >2);

	if(scelta == 1)
	{
		printf("Inserisci user name -->");
		scanf("%s", userInput);
		printf("Inserisci password -->");
		scanf("%s", passwordInput);

		rewind(user);
		while(!feof(user))
		{
			fread(&ut, sizeof(utente), 1, user);
			if(strcmp(userInput, ut.user_name) == 0 && strcmp(passwordInput, ut.password) == 0)
			{
				if(ut.professione == 'C')
				{
					strcpy(id_sessione, ut.user_name);
					flag = 1;
					printf("\n");
				}
				else if(ut.professione == 'U')
				{
					strcpy(id_sessione, ut.user_name);
					flag = 1;
					printf("\n");
				}
				else if(ut.professione == 'A')
				{
					flag = 1;
					printf("\n");
				}
			}
		}
		if(flag==0)
		{
			printf("User Id o Password non corretti !!! \n");
			printf("Riprovare il login o registrarsi \n");
			printf("Inserisci un numero per tornare al menu principale -->");
			scanf("%d", &scelta);
			sezionePrincipale();
			menuPrincipale();
		}

		rewind(user);
		while(!feof(user))
		{
			fread(&ut, sizeof(utente), 1, user);
			if(strcmp(userInput, ut.user_name) == 0 && strcmp(passwordInput, ut.password) == 0)
			{
				printf("1) modifica user name \n");
				printf("2) modifica password \n\n");
				do
				{
					printf("Inserisci la tua scelta -->");
					scanf("%d", &scelta);
				}while(scelta >2);

				if(scelta == 1)
				{
					rewind(user);
					while(fread(&ut, sizeof(utente), 1, user)!=0)
					{
						   if(strcmp(userInput, ut.user_name) == 0)
						   {
						    posizione=i;
						    temp=ut;
						   }
						   i++;
					}
						   if(posizione != -1)
						   {
							fseek(user, (sizeof(utente) * (posizione)), SEEK_SET);
							printf("inserisci nuovo user name -->");
							scanf("%s", temp.user_name);
							fwrite(&temp, sizeof(utente), 1, user);

							printf("Inserisci un numero per tornare al menu principale -->");
							scanf("%d", &scelta);
							sezionePrincipale();
							menuPrincipale();
						   }
						   else
						   {
							printf("User name gia' presente, riprovare \n");
							system("pause");
							sezionePrincipale();
							menuPrincipale();
						   }
				}

				else if(scelta == 2)
				{
					rewind(user);
					while(fread(&ut, sizeof(utente), 1, user)!=0)
					{
						if(strcmp(passwordInput, ut.password) == 0)
						{
							posizione=i;
							temp=ut;
						}
						i++;
					}
					if(posizione != -1)
					{
						fseek(user, (sizeof(utente) * (posizione)), SEEK_SET);
						printf("inserisci una nuova password -->");
						scanf("%s", temp.password);
						fwrite(&temp, sizeof(utente), 1, user);

						printf("Inserisci un numero per tornare al menu principale -->");
						scanf("%d", &scelta);
						sezionePrincipale();
						menuPrincipale();
					}
					else
					{
						printf("Password gia' presente, riprovare \n");
						system("pause");
						sezionePrincipale();
						menuPrincipale();
					}
				}
			}
		}
	}
	else if(scelta == 2)
	{
		sezionePrincipale();
		menuPrincipale();
	}
}

void caricamento()
{
	int i=0, j=0, scelta=0, n_immagini=0;
	int posizione = -1;
	utente temp;


 sezioneCaricamento();
 do
 {
  printf("Inserisci la tua scelta -->");
  scanf("%d", &scelta);
  printf("\n");
 }while(scelta >2);

 switch(scelta)
 {
  case 1:
  printf("Inserisci il numero di immagini che vuoi caricare -->");
  scanf("%d", &n_immagini);
  for(i=0; i<n_immagini;i++)
  {
   printf("Inserisci il titolo dell'immagine -->");
   scanf("%s", img.titolo);

   do
   {
    printf("Inserisci la tipologia dell'immagine (cartteri minuscoli)\n");
    printf("icona, vettore, foto -->");
    scanf("%s", img.tipologia);
   }while((strcmp(img.tipologia, "icona") != 0) && (strcmp(img.tipologia, "vettore") != 0) && (strcmp(img.tipologia, "foto") != 0));

   printf("Inserisci il nome del file -->");
   scanf("%s", img.nome_immagine);
   if(strcmp(img.tipologia, "foto") == 0)
   {
    strcat(img.nome_immagine, ".img");
   }
   else if(strcmp(img.tipologia, "vettore") == 0)
   {
    strcat(img.nome_immagine,".pdf");
   }
    else if(strcmp(img.tipologia, "icona") == 0)
   {
    strcat(img.nome_immagine,".jpg");
   }

   printf("Inserisci la parola chiave -->");
   scanf("%s", img.parola_chiave);
   strcpy(img.ut_cr.user_name, id_sessione);
   printf("\n");
   fseek(immagini ,sizeof(immagine), SEEK_END);
   fwrite(&img, sizeof(img), 1, immagini);

   	rewind(user);
   	while(fread(&ut, sizeof(utente), 1, user) != 0)
   	{
   		if(strcmp(id_sessione, ut.user_name) == 0)
   		{
   			posizione = j;
   			temp = ut;
   		}
   		j++;
   	}

   	if(posizione != -1)
   	{
   		fseek(user, (sizeof(utente) * (posizione)), SEEK_SET);
   		if(strcmp(img.tipologia, "vettoriale") == 0)
   		{
   			temp.num_vettore++;
   		}
   		else if(strcmp(img.tipologia, "foto") == 0)
   		{
   			temp.num_foto++;
   		}
   		else if(strcmp(img.tipologia, "icona") == 0)
   		{
   			temp.num_icona++;
   		}

   		fwrite(&temp, sizeof(utente), 1, user2);
   	}

   	fclose(user2);
   	fclose(user);
   	remove("user.dat");
   	rename("user2.dat", "user.dat");
   	fopen(user);
   }

  menuCreatore();
  break;

  case 2:
  menuCreatore();
  break;
 }
}


void visualizza()
{
 int scelta;

 sezioneVisualizza();

 do
 {
  printf("Inserisci la tua scelta -->");
  scanf("%d", &scelta);
  printf("\n");
 }while(scelta >2);

 switch(scelta)
 {
  case 1:
  printf("| TITOLO\t | TIPOLOGIA\t | FORMATO\t | KEY \n");
  printf("---------------------------------------------- \n");
  rewind(immagini);
  while(!feof(immagini))
  {
   fread(&img, sizeof(img), 1, immagini);
   if(!feof(immagini)  && (strcmp(img.titolo, "") != 0))
   {
    if(strcmp(ut.user_name, id_sessione) == 0)
    {
     printf("|%s\t |%s\t |%s\t |%s\n", img.titolo, img.tipologia, img.nome_immagine, img.parola_chiave);
    }
   }
  }
  printf("---------------------------------------------- \n");
  printf("Premi un numero per tornare al menu' creatore -->");
  scanf("%d", &scelta);
  printf("\n");
  menuCreatore();
  break;

  case 2:
  menuCreatore();
  break;
 }
}

void modifica()
{
 char titoloInput[30];
 int posizione=-1 , i=0, scelta=0;
 immagine temp;

 sezioneModifica();
 do
 {
  printf("Inserisci la tua scelta -->");
  scanf("%d", &scelta);
  printf("\n");
 }while(scelta >2);

 switch(scelta)
 {
  case 1:
  printf("| TITOLO\t | TIPOLOGIA\t | FORMATO\t | KEY \n");
  printf("---------------------------------------------- \n");
  rewind(immagini);
  while(!feof(immagini))
  {
   fread(&img, sizeof(img), 1, immagini);
   if(!feof(immagini)  && (strcmp(img.titolo, "") != 0))
   {
    if(strcmp(ut.user_name, id_sessione) == 0)
    {
     printf("|%s\t |%s\t |%s\t |%s\n", img.titolo, img.tipologia, img.nome_immagine, img.parola_chiave);
    }
   }
  }
  printf("---------------------------------------------- \n");

  printf("Inserisci il titolo dell'immagine che vuoi modificare -->");
  scanf("%s", titoloInput);

  rewind(immagini);
  while(fread(&img, sizeof(immagine), 1, immagini)!= 0)
  {
   if(strcmp(titoloInput, img.titolo) == 0)
   {
    posizione=i;
    temp=img;
   }
   i++;
  }
  if(posizione != -1)
  {
   fseek(immagini, (sizeof(immagine) * (posizione)), SEEK_SET);
   printf("Inserisci le nuove informazioni: \n");
   printf("Inserisci il titolo dell'immagine -->");
   scanf("%s", temp.titolo);

   do
   {
    printf("Inserisci la tipologia dell'immagine (cartteri minuscoli)\n");
    printf("icona, vettore, foto -->");
    scanf("%s", temp.tipologia);
   }while((strcmp(temp.tipologia, "icona") != 0) && (strcmp(temp.tipologia, "vettore") != 0) && (strcmp(temp.tipologia, "foto") != 0));

   printf("Inserisci il nome del file -->");
   scanf("%s", temp.nome_immagine);
   if(strcmp(temp.tipologia, "foto") == 0)
   {
    strcat(temp.nome_immagine, ".img");
   }
   else if(strcmp(temp.tipologia, "vettore") == 0)
   {
    strcat(temp.nome_immagine,".pdf");
   }
   else if(strcmp(temp.tipologia, "icona") == 0)
   {
    strcat(temp.nome_immagine,".jpg");
   }

   printf("Inserisci la parola chiave -->");
   scanf("%s", temp.parola_chiave);

   fwrite(&temp, sizeof(immagine), 1, immagini);
   printf("Premi un numero per tornare al menu' creatore -->");
   scanf("%d", &scelta);
   menuCreatore();
   }
   else
   {
    printf("Titolo inserito non presente \n");
    printf("Inserire titolo corretto \n");

    printf("Premi un numero per tornare al menu' creatore -->");
    scanf("%d", &scelta);
    menuCreatore();
   }
   break;

   case 2:
   menuCreatore();
   break;
 }
}

void cancellazione()
{

 char titoloInput[30];
 int scelta, flag=0;

 sezioneCancellazione();
 do
 {
  printf("Inserisci la tua scelta -->");
  scanf("%d", &scelta);
  printf("\n");
 }while(scelta >2);

 switch(scelta)
 {
  case 1:
  if(immagini2 == NULL)
  {
  printf("ERRORE NELL'APERTURA DEL FILE ... \n");
  }
  else
  {
   printf("| CREATORE \t|| TITOLO \t| TIPOLOGIA \t| FORMATO \t| KEY \n");
   printf("---------------------------------------- \n");

   rewind(immagini);
   while(!feof(immagini))
   {
    fread(&img, sizeof(immagine), 1, immagini);
    if(!feof(immagini)  && (strcmp(img.titolo, "") != 0))
    {
     if(strcmp(ut.user_name, id_sessione) == 0)
     {
      printf("|%s\t |%s\t |%s\t |%s \n", img.titolo, img.tipologia, img.nome_immagine, img.parola_chiave);
     }
    }
   }
   printf("---------------------------------------- \n");

   printf("Inserisci il titolo dell'immagine che vuoi cancellare -->\n");
   scanf("%s", titoloInput);

   rewind(immagini);
   while(fread(&img, sizeof(immagine), 1, immagini))
   {
    if(strcmp(titoloInput, img.titolo) == 0 && strcmp(id_sessione, ut.user_name)== 0)
    {
     flag= 1;
     printf("Cancellazione avvenuta con successo !!! \n");
    }
    else
    {
     fwrite(&img, sizeof(immagine), 1, immagini2);
    }
   }

   if(flag == 0)
   {
    printf("Titolo inserito non presente \n");
   }

    fclose(immagini2);
    fclose(immagini);
    remove("immagini.dat");
    rename("immagini2.dat","immagini.dat");
    immagini= fopen("immagini.dat", "rb+");
    printf("\n");
    printf("premi un qualsiasi numero per tornare al menu creatore -->");
    scanf("%d", &scelta);
    menuCreatore();
  }
 break;

  case 2:
  menuCreatore();
  break;
 }
}

void ricerca()
{
 char titoloInput[30];
 char parola_chiaveInput[30];
 int scelta, flag= 0;

 sezioneRicerca();

	do
	{
	 printf("Inserisci la tua scelta -->");
	 scanf("%d", &scelta);
	}while(scelta>3);

	if(scelta == 1)//FIXME 1
	{
		printf("Inserisci il titolo dell'immagine che si vuole visualizzare -->");
		scanf("%s", titoloInput);

    printf("| TITOLO \t| TIPOLOGIA \t| FORMATO \t| KEY \n");
    printf("---------------------------------------- \n");
    rewind(immagini);
    while(!feof(immagini))
    {
     fread(&img, sizeof(immagine), 1, immagini);
     if(strcmp(titoloInput, img.titolo) == 0)
     {
      flag= 1;
      printf("| %s \t| %s \t |%s \t| %s \n", img.titolo, img.tipologia, img.nome_immagine, img.parola_chiave);
     }
    }
    printf("---------------------------------------- \n");

    if(flag == 0)
    {
     printf("Titolo non trovato !!! \n");
     printf("Premi un numero per tornare al menu' Utilizzatore -->");
     scanf("%d", &scelta);
     menuUtilizzatore();
    }

    else if(flag == 1)
    {
		sezioneDownload();
		do
		{
		 printf("Inserisci la tua scelta -->");
		 scanf("%d", &scelta);
		}while(scelta>3);


     switch(scelta)
     {
      case 1:
      printf("Download avvenuto con successo !!!\n\n");
			img.copie_scaricate=img.copie_scaricate+1;

			strcpy(img.ut_cr.user_name, id_sessione);
			fwrite(&img, sizeof(immagine), 1, azioni);

			printf("%s, vuoi lasciare una valutazione?\n", id_sessione);
			printf("1)Valuta\n");
			printf("2)Non ora\n");
			printf("Inserisci la tua scelta -->");
			scanf("%d", &scelta);

      if(scelta == 1)//FIXME 3
			{
			 printf("%s, come valuteresti l'immagine appena visualizzata? \n", id_sessione);

				do
				{
				 printf("Inserisci una valutazione compresa da 1 a 5 -->");
				 scanf("%d", &img.valutazione);
				}while(img.valutazione<1 || img.valutazione>5);

				strcpy(img.ut_cr.user_name, id_sessione);
				fwrite(&img, sizeof(immagine), 1, valutazioni);

				printf("inserisci un numero per tornare al menu Utilizzatore -->");
				scanf("%d", &scelta);

				menuUtilizzatore();
			}
			else if(scelta == 2)//FIXME 3
			{
			 printf("inserisci un numero per tornare al menu Utilizzatore -->");
			 scanf("%d", &scelta);

			 menuUtilizzatore();
			}
      break;

      case 2:
      printf("%s, come valuteresti l'immagine appena visualizzata? \n", id_sessione);

			do
			{
			 printf("Inserisci una valutazione compresa da 1 a 5 -->");
			 scanf("%d", &img.valutazione);
			}while(img.valutazione<1 || img.valutazione>5);

			strcpy(img.ut_cr.user_name, id_sessione);
			fwrite(&img, sizeof(immagine), 1, valutazioni);

			printf("inserisci un numero per tornare al menu Utilizzatore -->");
			scanf("%d", &scelta);
			menuUtilizzatore();
      break;

      case 3:
      printf("inserisci un numero per tornare al menu Utilizzatore -->");
			scanf("%d", &scelta);
			menuUtilizzatore();
      break;
     }
    }
   }
   else if(scelta == 2)
   {
    printf("Inserisci la parola chiave dell'immagine che si vuole visualizzare -->");
		scanf("%s", parola_chiaveInput);

    printf("| TITOLO \t| TIPOLOGIA \t| FORMATO \t| KEY \n");
    printf("---------------------------------------- \n");
    rewind(immagini);
    while(!feof(immagini))
    {
     fread(&img, sizeof(immagine), 1, immagini);
     if(strcmp(parola_chiaveInput, img.parola_chiave) == 0)
     {
      flag = 1;
      printf("%s %s %s %s \n", img.titolo, img.tipologia, img.nome_immagine, img.parola_chiave);
     }
    }
    printf("---------------------------------------- \n");

    if(flag == 0)
    {
     printf("Parola chiave non trovata !!! \n");
     printf("Premi un numero per tornare al menu' Utilizzatore -->");
     scanf("%d", &scelta);
     menuUtilizzatore();
    }
    else if(flag == 1)
    {
    sezioneDownload();
    do
		{
		 printf("Inserisci la tua scelta -->");
		 scanf("%d", &scelta);
		}while(scelta>3);

    switch(scelta)
    {
     case 1:
     printf("Download avvenuto con successo !!!\n\n");
			img.copie_scaricate=img.copie_scaricate+1;

			strcpy(img.ut_cr.user_name, id_sessione);
			fwrite(&img, sizeof(immagine), 1, azioni);

			printf("%s, vuoi lasciare una valutazione?\n", id_sessione);
			printf("1)Valuta\n");
			printf("2)Non ora\n");
			printf("Inserisci la tua scelta -->");
			scanf("%d", &scelta);

      if(scelta == 1)//FIXME 3
			{
			 printf("%s, come valuteresti l'immagine appena visualizzata? \n", id_sessione);

			do
			{
			 printf("Inserisci una valutazione compresa da 1 a 5 -->");
			 scanf("%d", &img.valutazione);
		  }while(img.valutazione<1 || img.valutazione>5);

			strcpy(img.ut_cr.user_name, id_sessione);
			fwrite(&img, sizeof(immagine), 1, valutazioni);

			printf("inserisci un numero per tornare al menu Utilizzatore -->");
			scanf("%d", &scelta);

			menuUtilizzatore();
		 }
		 else if(scelta == 2)//FIXME 3
		 {
			printf("inserisci un numero per tornare al menu Utilizzatore -->");
			scanf("%d", &scelta);

			menuUtilizzatore();
		 }
     break;

     case 2:
     printf("%s, come valuteresti l'immagine appena visualizzata? \n", id_sessione);

		 do
		 {
			printf("Inserisci una valutazione compresa da 1 a 5 -->");
			scanf("%d", &img.valutazione);
		 }while(img.valutazione<1 || img.valutazione>5);

		 strcpy(img.ut_cr.user_name, id_sessione);
		 fwrite(&img, sizeof(immagine), 1, valutazioni);

		 printf("inserisci un numero per tornare al menu Utilizzatore -->");
		 scanf("%d", &scelta);
		 menuUtilizzatore();
     break;

     case 3:
     printf("inserisci un numero per tornare al menu Utilizzatore -->");
		 scanf("%d", &scelta);
		 menuUtilizzatore();
     break;
    }
    }
   }
   else if(scelta == 3)
   {
    printf("Premi un numero per tornare al menu' Utilizzatore -->");
    scanf("%d", &scelta);
    menuUtilizzatore();
   }
}


void elimina_utente()
{
 int scelta, flag=0;
 char userInput[20];

 sezioneCancellazione();
 do
 {
  printf("Inserisci la tua scelta -->");
  scanf("%d", &scelta);
  printf("\n");
 }while(scelta >2);

 switch(scelta)
 {
   case 1:
   if(user2 == NULL)
   {
    printf("ERRORE NELL'APERTURA DEL FILE ... \n");
   }
   else
   {
    printf("| USER NAME \t| PASSWORD \t| PROFESSIONE \n");
    printf("---------------------------------------- \n");
    rewind(user);
    while(!feof(user))
    {
     fread(&ut, sizeof(utente), 1, user);
     if(!feof(user) && strcmp(ut.user_name, "") !=0)
     {
    	 if(strcmp(id_sessione, ut.user_name)==0)
    	 {
    	 }
      printf("|%s\t |%s\t |%c\n", ut.user_name, ut.password, ut.professione);
     }
    }
    printf("---------------------------------------- \n");

   printf("Inserisci l'user name che vuoi cancellare -->\n");
   scanf("%s", userInput);

   rewind(user);
   while(fread(&ut, sizeof(utente), 1, user))
   {
    if(strcmp(userInput, ut.user_name) == 0)
    {
     flag= 1;
     printf("Cancellazione avvenuta con successo !!! \n");
    }
    else
    {
     fwrite(&ut, sizeof(utente), 1, user2);
    }
   }
   if(flag == 0)
   {
    printf("User name inserito non presente \n");
   }

    fclose(user2);
    fclose(user);
    remove("user.dat");
    rename("user2.dat","user.dat");
    immagini= fopen("user.dat", "rb+");
    printf("\n");
    printf("premi un qualsiasi numero per tornare al menu creatore -->");
    scanf("%d", &scelta);
    menuAdmin();
   }
   break;

   case 2:
   menuAdmin();
   break;
 }
}

void visualizza_azioni()
{
	int scelta;

	sezioneVisualizza();
	do
	{
		printf("Inserisci la tua scelta -->");
		scanf("%d", &scelta);
		printf("\n");
	}while(scelta >2);

	switch(scelta)
	{
	case 1:
		printf("---------------------------------------------- \n");
		rewind(azioni);
		while(!feof(azioni))
		{
			fread(&img, sizeof(img), 1, azioni);
			if(!feof(immagini) && strcmp(img.titolo, "") !=0)
			{ //FIXME visualizza 2 volte l'ultima
				printf("L'utente: %s, ha scaricato %d copie della seguente immagine: \n", img.ut_cr.user_name, img.copie_scaricate);
				printf("Titolo --> %s \n", img.titolo);
				printf("Tipologia --> %s \n", img.tipologia);
				printf("Formato --> %s \n", img.nome_immagine);
				printf("Parola chiave --> %s \n\n", img.parola_chiave);

			}
		}
		printf("---------------------------------------------- \n");

		rewind(immagini);
		while(!feof(immagini))
		{
			fread(&img, sizeof(img), 1, immagini);

			if(!feof(immagini) && strcmp(img.titolo, "")!=0)
			{
				printf("Il creatore: %s, ha caricato la seguente immagine: \n ", img.ut_cr.user_name);
				printf("Titolo --> %s \n", img.titolo);
				printf("Tipologia --> %s \n", img.tipologia);
				printf("Formato --> %s \n", img.nome_immagine);
				printf("Parola chiave --> %s \n\n", img.parola_chiave);
			}
		}
		printf("---------------------------------------------- \n");

		printf("Premi un numero per tornare al menu' creatore -->");
		scanf("%d", &scelta);
		printf("\n");
		menuAdmin();
		break;

	case 2:
		menuAdmin();
		break;
	}
}

void statistica()
{
	//var. locali
	int scelta = 0;


	rewind(user);
	while(fread(&ut, sizeof(utente), 1, user))
	{
		if(!feof(user))
		{
			if(ut.professione == 'C')
			{
				printf("\t%s \t\t%d   \t\t%d        \t%d\n", ut.user_name, ut.num_vettore, ut.num_foto, ut.num_icona);
			}
		}
	}
        printf("\npremi un numero per tornare al menu creatore_> ");
        scanf("%d", &scelta);
        menuUtilizzatore();
}
