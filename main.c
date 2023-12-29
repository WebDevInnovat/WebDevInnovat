#include <stdio.h>
#include <stdlib.h>
int choix,choix1,choix2;
/*----------structures----------*/
typedef struct{
    int id_client;
    char nom[20];
    char prenom[20];

}sclient;

typedef struct{
    int id_client;
    int id_compte;
    float solde;
}scompte;
typedef struct{
    int idco;
    char to;
    float mo;
}stransaction;

int rechcl(int numcl)
{
    sclient cl;
    FILE *fich;
    fich=fopen("cl.txt","r+");
    if(fich!=NULL)
             {
        while(fread(&cl,sizeof(cl),1,fich))
        {
        if(cl.id_client==numcl)
        {
            fclose(fich);

            return 1;
        }
        }
             }
    fclose(fich);
    return -1;
}
int rechco(int numco)
{
    scompte co;
    FILE *fich=NULL;
    fich=fopen("ba.txt","r+");
    if(fich!=NULL)
             {
        while(fread(&co,sizeof(co),1,fich))
        {
        if(co.id_compte==numco)
        {
            fclose(fich);
            return 1;
        }
        }
             }
    fclose(fich);
    return -1;
}

/*----------procedure client----------*/
void ajouter_client()
{
    sclient cl;
    FILE *fich=NULL;
    int numc;

    fich=fopen("cl.txt","a+");
    if(fich!=NULL)
    {
    printf("entrer le numero de nouveau client :\n");
    scanf("%d",&numc);
    while(rechcl(numc)==1)
    {
        printf("ce numero client deja!!!");
        printf("entrer le numero de nouveau client :\n");
        scanf("%d",&numc);
    }
    cl.id_client=numc;
    printf("entrer le nom :\n");
    scanf("%s",&cl.nom);
    fflush(stdin);
    printf("entrer le prenom :\n");
    scanf("%s",&cl.prenom);
    fflush(stdin);
    fwrite(&cl,sizeof(cl),1,fich);
    if(fwrite!=0);
     {
         printf("\t****merci****");
     }
    fclose(fich);
    }
    else{printf("impossible ouvrire fichier");}
}
void afficher_client()
{
    int x=0;
    sclient clients[100];
    sclient cl;
    FILE *fich=NULL;
    fich=fopen("cl.txt","r+");

    printf("******la liste de clients******\n");
    printf("id_client\t nom\t     prenom\n");
    while(fread(&cl,sizeof(cl),1,fich))
    {
           clients[x]=cl;
           x++;
    }
    fclose(fich);

    for(int i=0;i<=x;i++)
        {

          printf("\t%d\t\t %s\t %s\n",clients[i].id_client,clients[i].nom,clients[i].prenom) ;
        }
}
void supprimer_client()
{
    sclient cl;
    sclient clients[100];
    FILE *fich;
    int numc,x=0;

    fich=fopen("cl.txt","r");

    if(fich!=NULL)
    {
          printf("entrer le numero de client a  supprimer :\n");
          scanf("%d",&numc);
          if(rechcl(numc)==1)
            {



                 fich = fopen("cl.txt", "r");



                 while(fread(&cl, sizeof(cl), 1, fich)) {
                  clients[x] = cl;
                  x++;
                }
                 fclose(fich);
                 remove("cl.txt");

                 FILE *fich1;
                 fich1= fopen("cll.txt", "a");
                 for ( int i=0 ; i<x ; i++)
                 {
                    if (clients[i].id_client!= numc)
                      fwrite(&clients[i], sizeof(clients[i]), 1, fich1);
                 }
                  fclose(fich1);
                  rename("cll.txt", "cl.txt");
                  printf("le client de id_client[%d]est supprimer",numc);



           }

           else
           {
            printf("le client n'exist deja!!!");
           }
     }

 }
void rechercher_client()
{
    FILE *fich;
    sclient cl;
    sclient clients[100];
    int numcl,x;
    printf("entrer le id_client a rechercher :\n");
    scanf("%d",&numcl);
    if(rechcl(numcl==1))
    {
       printf("le client exist ");

    }
    else
           {
            printf("le client  n'exist pas!!!");
           }
}
/*----------procedure_compte----------*/
void ajouter_compte()
{
    scompte co;
    FILE *fich=NULL;
    int numcl,numco;

    fich=fopen("ba.txt","a+");
    if(fich!=NULL)
    {
    printf("entrer le numero de client a faire le compte :\n");
    scanf("%d",&numcl);
    if(rechcl(numcl)==1)
    {
       printf("entrer le numero de nouveau compte :\n");
       scanf("%d",&numco);
       while(rechco(numco)==1)
       {
        printf("ce compte existe deja!!!");
        printf("entrer le numero de nouveau compte :\n");
        scanf("%d",&numco);
        }
        co.id_client=numcl;
        co.id_compte=numco;
        printf("entrer le sold initale :\n");
        scanf("%f",&co.solde);
        fflush(stdin);
        fwrite(&co,sizeof(co),1,fich);
        if(fwrite!=0);
        {
         printf("\t\t****merci a choisir E-Bank****");
        }
        fclose(fich);
       }
       else{
        printf("if faut faire un compte client avant");
        menu();
           }
    }
        else{printf("impossible ouvrire fichier");}
}
void afficher_compte()
{
    int x=0;
    scompte comptes[100];
    scompte co;
    FILE *fich=NULL;
    fich=fopen("ba.txt","r+");

    printf("******la liste de comptes******\n");
    printf(" id_client\t id_compte \t solde\n");
    while(fread(&co,sizeof(co),1,fich))
    {
           comptes[x]=co;
           x++;
    }
    fclose(fich);

    for(int i=0;i<=x;i++)
        {

          printf("\t%d\t\t\t %d\t\t  %f\n",comptes[i].id_client,comptes[i].id_compte,comptes[i].solde) ;
        }
}
void supprimer_compte()
{
    scompte co;
    scompte comptes[100];
    FILE *fich;
    int numco,x=0;

    fich=fopen("ba.txt","r");

    if(fich!=NULL)
    {
          printf("entrer le numero de compte a  supprimer :\n");
          scanf("%d",&numco);
          if(rechco(numco)==1)
            {
                 fich = fopen("ba.txt", "r");
                 while(fread(&co, sizeof(co), 1, fich)) {
                  comptes[x] = co;
                  x++;
                }
                 fclose(fich);
                 remove("ba.txt");

                 FILE *fich1;
                 fich1= fopen("baa.txt", "a");
                 for ( int i=0 ; i<x ; i++)
                 {
                    if (comptes[i].id_compte!= numco)
                      fwrite(&comptes[i], sizeof(comptes[i]), 1, fich1);
                 }
                  fclose(fich1);
                  rename("baa.txt", "ba.txt");
                  printf("le compte de id_compte[%d]est supprimer",numco);



           }

           else
           {
            printf("le compte n'exist deja!!!");
           }
     }
     else
           {
            printf("le FICHIER n'exist pas");
           }

 }
void transaction()
{
        FILE *fich;
        scompte co;
        stransaction tr;
        scompte comptes[100];
        float m,as;
        int numco;
        int rep,x;
        printf("choisir le type d'operation versement(1)||retrait(2)\n");
        scanf("%d",&rep);
        if(rep==1)
          {
              printf("entrer id_compte\n");
              scanf("%d",&numco);
              if(rechco(numco)==1);
                 {
                   printf("donner le montant a verser:\n") ;
                   scanf("%f",&m);
                   fich = fopen("ba.txt", "r");

                    while(fread(&co, sizeof(co), 1, fich))
                           {
                        comptes[x] = co;
                                x++;
                           }
                    fclose(fich);
                    remove("compte.txt");
                    FILE *fich1,*fich2;
                    fich1 = fopen("baa.txt", "a");
                    fich2 = fopen("op.txt", "a");
                    for ( int i=0 ; i<x ; i++)
                       {
                          if (comptes[i].id_compte == numco)
                            {
                                as=comptes[i].solde;
                                comptes[i].solde= comptes[i].solde + m;
                                printf("\n id_compte %d", comptes[i].id_compte);
                                printf("\n id_client %d", comptes[i].id_client);
                                printf("\n ancien solde  : %f", as);
                                printf("\n nouveau solde somme : %f", comptes[i].solde);
                                tr.idco=numco;
                                tr.to='v';
                                tr.mo=m;
                                fwrite(&tr, sizeof(tr), 1, fich2);
                            }
                          fwrite(&comptes[i], sizeof(comptes[i]), 1, fich1);

                       }
                    fclose(fich2);
                    fclose(fich1);
                    rename("baa.txt", "ba.txt");
                 }


          }
          else
          {
           printf("entrer id_compte\n");
              scanf("%d",&numco);
              if(rechco(numco)==1);
                 {
                   printf("donner le montant a retrait\nle solde minimale est 10 DT !!!\n") ;
                   scanf("%f",&m);
                   fich = fopen("ba.txt", "r");

                    while(fread(&co, sizeof(co), 1, fich))
                           {
                        comptes[x] = co;
                                x++;
                           }
                    fclose(fich);
                    remove("compte.txt");
                    FILE *fich1,*fich2;
                    fich1 = fopen("baa.txt", "a");
                    fich2 = fopen("op.txt", "a");
                    for ( int i=0 ; i<x ; i++)
                       {
                          if (comptes[i].id_compte == numco)
                            {
                                as=comptes[i].solde;

                                if((comptes[i].solde-m)>=10)
                                   {
                                comptes[i].solde= comptes[i].solde - m;
                                printf("\n id_compte %d", comptes[i].id_compte);
                                printf("\n id_client %d", comptes[i].id_client);
                                printf("\n ancien solde  : %f", as);
                                printf("\n nouveau solde somme : %f", comptes[i].solde);
                                tr.idco=numco;
                                tr.to='r';
                                tr.mo=m;
                                fwrite(&tr, sizeof(tr), 1, fich2);
                                   }
                               else
                               printf("********solde insuffisant********");
                            }
                          fwrite(&comptes[i], sizeof(comptes[i]), 1, fich1);

                       }
                    fclose(fich2);
                    fclose(fich1);
                    rename("baa.txt", "ba.txt");
                }
        }

}
void detail_operation(int numco)
{
    if(rechco(numco)==1)
       {
    FILE *fich;
    stransaction tr;
    stransaction transactions[100];
    int x;
    fich = fopen("op.txt", "r");
    while(fread(&tr, sizeof(tr), 1, fich))
    {  if(tr.idco==numco)
         transactions[x] = tr;
         x++;
    }
    fclose(fich);
    printf("******les operation de compte %d******\n",numco);
    printf(" type_operation\t montant \n");
    for(int i=0;i<=x;i++)
        {

          printf("\t\t%c\t\t %f\n",transactions[i].to,transactions[i].mo) ;
        }
        }
        else
            printf("ce compte n'exist pas");
}

/*----------menu principal----------*/
void menu()
{
  printf("\t\t\t\t\t\t------------------------------\n");
  printf("\t\t\t\t\t\t*****Gestion d'une banque*****\n");
  printf("\t\t\t\t\t\t------------------------------\n\n\n");
  printf("\t\t\t\t\t\t\t[1]client\n");
  printf("\t\t\t\t\t\t\t[2]compte\n");
  printf("\t\t\t\t\t\t\t[3]quit\n");


  do
  {
      printf("\t\t\t\t\t\tsaisir le numero du choix s'il vous plais\n");
      scanf("%d",&choix);
  }
  while((4<=choix)&&(choix<=0));
}
/*----------sous menu client----------*/
void menu_client()
{

    printf("\t\t\t\t\t\t------------------------------\n");
  printf("\t\t\t\t\t\t\t  **client**\n");
  printf("\t\t\t\t\t\t------------------------------\n\n");
  printf("\t\t\t\t\t\t\t[1] :ajouter un client\n");
  printf("\t\t\t\t\t\t\t[2] :supprimer un client\n");

  printf("\t\t\t\t\t\t\t[3] :recherche d'un client\n");
  printf("\t\t\t\t\t\t\t[4] :afficher la list des client\n");
  printf("\t\t\t\t\t\t\t[5] :retour au menu principale\n\n");

  do
  {
      printf("\t\t\t\t\t\tsaisir le numero du choix s'il vous plais\n");
      scanf("%d",&choix1);
  }
  while((6<=choix1)||(choix1<=0));
}
/*----------sous menu compte----------*/
void menu_compte()
{

  printf("\t\t\t\t\t\t------------------------------\n");
  printf("\t\t\t\t\t\t\t  **compte**\n");
  printf("\t\t\t\t\t\t------------------------------\n\n");
  printf("\t\t\t\t\t\t\t[1] :Greer un nouveau compte\n");
  printf("\t\t\t\t\t\t\t[2] :supprimer un compte\n");

  printf("\t\t\t\t\t\t\t[3] :affichage de detail  compte\n");
  printf("\t\t\t\t\t\t\t[4] :transaction(\"VERSEMENT\";\"REITRAIT\")\n");
  printf("\t\t\t\t\t\t\t[5] :detail operation d'un compte\n");
  printf("\t\t\t\t\t\t\t[6] :retour au menu principale\n\n");

  do
  {
      printf("\t\t\t\t\t\tsaisir le numero du choix s'il vous plais\n");
      scanf("%d",&choix2);
  }
  while((7<=choix2)||(choix2<=0));


}
int main()
{
     int nu;
     menu();
    do
    {

    if (choix==1)
        {
        menu_client();
        switch(choix1)
            {
             case 1:
                 ajouter_client();
                 break;
             case 2:
                 supprimer_client();
                 break;
             case 3:
                 rechercher_client();
                 break;
             case 4:
                 afficher_client();
                 break;
             case 5:
                 menu();
                 break;


            }
        }
    else
        {
        menu_compte();
        switch(choix2)
             {
             case 1:
                 ajouter_compte();
                 break;
             case 2:
                 supprimer_compte();
                 break;
             case 3:
                 afficher_compte();
                 break;
             case 4:
                 transaction();
                 break;
             case 5:
                 printf("entrer le numero de compte");
                scanf("%d",&nu);
                detail_operation(nu);
                 break;
             case 6:
                menu();
                break;
             }
        }
    }while(choix!=3);

    return 0;
}
