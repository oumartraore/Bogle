#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*CETTE FONCTION PERMET D'AFFICHER LA GRILLE ELLE PREND POUR PARAMÈTRE
 UNE UN POINTEUR VERS UN TYPE DE TABLEAU DE DEUX DIMENSION, DEUX ENTIERS 
 REPRESENTANT LE NOMBRE DE LIGNES ET DE COLONNES */

void solveur_de_boggle_afficher_grille(char **tab, int lig, int col)
{
     int i;
     int j;
     printf("------------------------\n");
     for(i=0; i<lig; i++)
     {
	  for(j=0; j<col; j++)
	  {
	  printf("| %c ", tab[i][j]);
	  
	  }
	  printf("\n------------------------\n");
     }
}

/*CETTE FONCTION PERMET DE CREER ET DE REMPLIR LA GRILLE DE JEUX*/

void solveur_de_boggle_creer_grille(char **tab, int ligne, int colonne)
{
     int i;
     int j;
     srand(time(NULL));
     for(i=0; i<ligne; i++)
     {    
	  for(j=0; j<colonne; j++)
	       tab[i][j] = rand () % 26 + 'A';
     }
     
     solveur_de_boggle_afficher_grille(tab,ligne,colonne);
}

/* Procedure qui dimmensionne la taille de la grille */

void solveur_de_boggle_dimension(int *ligne, int *colonne)
{
     int choix;
     printf(" _________________________________________________________\n");
     printf("|1 si vous sohaitez redimensionner la grille de jeux      |\n");
     printf("|2 si vous ne souhaitez rien changer                      |\n");
     printf("|_________________________________________________________| \n");
     
     do
     {
	  printf("Votre choix : ");
	  scanf("%d",&choix);
     }while(choix < 1 || choix >2);
     
     if(choix == 1)
     {
	  printf("Donner le nombre de lignes : ");
	  scanf("%d", ligne);
	  printf("Donner le nombre de colonnes : ");
	  scanf("%d", colonne);
     }
}

/* procedure qui renvoie les mots possibles de chaque caractere de la grille */

/*void solveur_de_boggle_Mot_Possible(char **tab, int ligne, int colonne)
{
     int i, j/*, k, l;
     int car_actuel;
     int car_fichier = 0;
          
     FILE *fichier = NULL;
     fichier = fopen("dictionaire.txt", "r");
     if(fichier == NULL)
     {
	  printf("Erreur lors de l'ouverture du fichier\n");
     }
     
     printf("Listes des mots possibles Dans l'ordre croissant seulement \n");
     printf("Pour cette grille \n\n");
     
     for(i=0; i<ligne; i++)
     {
	  for(j=0; j<colonne; j++)
	  {
	       car_actuel = tab[i][j];  /*On prends le caractere actuelle de la grille
	       do
	       {
		    car_fichier = fgetc(fichier); /* On lit le caractere dans le dictionaire 
		    
		    /* On regarde si la premiere lettre du mot dans le dictionaire est egale à celle de la grille 
		    if(car_actuel == car_fichier)
		    {
			 /* si le mot du dictionnaire commence par la lettre indexe par la grille 
			 do
			 {
			      /* on affiche ce mot au complet 
			      printf("%c", car_fichier);
			      car_fichier = fgetc(fichier);
			 }while(car_fichier != ',' && car_fichier != '\n' && car_fichier != EOF ); /* On sait que un mot est finie lorsque le caractere suivant est evalue a ',' ou \n ou EOF 
			 printf("\n"); 
		    }
		    else /* Si elle n'est pas egale a la lettre de la grille on deplace le curseur jusqu'au mot suivant
		    {    
			 /* Pour qu'au prochaine tour de boucle elle verifie (voir plus haut) 
			 /* On sait que le mot suivant est soit après une ,' ' ou un \n ou qu'il n'est pas EOF *
			 while(car_fichier != ' ' && car_fichier != '\n' && car_fichier != EOF)
			 {
			      car_fichier = fgetc(fichier);
			 }
			 
		    }
	       }while(car_fichier != EOF); /* On continue tant que fgetc n'a pas retourner EOF 
	       
	       /* On est donc à la fin du fichier 
	       fseek(fichier, 0, SEEK_SET); /* On positionne le curseur au debut du fichier 
	       /* Pour traiter la lettre suivante de la grille 
	  }
     }
     fclose(fichier);
}*/

void solveur_de_boggle_voisins(char **tab, int i, int j, int n, int m, char voisins[8])
{
     int cpt = 0;
     int k = 0;
     

     
     /* Element centraux */
     
     if((i>0 && i<n-1) && (j>0 && j<m-1))
     {
	  for(k=j-1; k<=j+1; k++)
	  {
	       voisins[cpt] = tab[i-1][k];
	       cpt++;
	       if(tab[i][k]!=tab[i][j])
	       {
		    voisins[cpt] = tab[i][k];
			 cpt++;
	       }
	       voisins[cpt] = tab[i+1][k];
	       cpt++;
	  }
     }
     
     /* Element Haut */
     
     if(i == 0 && j < m-1)
     {
	  for(k=j; k<=j+1; k++)
	  {
	       if(tab[i][k]!=tab[i][j])
	       {
		    voisins[cpt] = tab[i][k];
		    cpt++;
	       }
	       voisins[cpt] = tab[i+1][k];
	       cpt++;
	  }
	  if(j > 0 && j < m-1)
	  {
	       voisins[cpt] = tab[i][j-1];
	       cpt++;
	       voisins[cpt] = tab[i+1][j-1];
	       cpt++;
	  }
     }
     
     /* Element Droite */
     
     if(i < n-1 && j == m-1)
     {
	  if(i > 0)
	  {
	       voisins[cpt] = tab[i-1][j-1];
	       cpt++;
	       voisins[cpt] = tab[i-1][j];
	       cpt++;
	  }
	  
	  for(k=j-1; k<=j+1; k++)
	  {
	       if(tab[i][k]!=tab[i][j])
	       {
		    voisins[cpt] = tab[i][k];
		    cpt++;
	       }
	       voisins[cpt] = tab[i+1][k];
		  cpt++;
	  }
     }
     
     /* Element Bas */
     
     if(i == n-1 && j > 0)
     {
	  if(j!= m-1)
	  {
	       voisins[cpt] = tab[i-1][j+1];
	       cpt++;
	       voisins[cpt] = tab[i][j+1];
	       cpt++;
	  }
	  for(k=j-1; k<j+1; k++)
	  {
	       voisins[cpt] = tab[i-1][k];
	       cpt++;
	       if(tab[i][k]!=tab[i][j])
	       {
		    voisins[cpt] = tab[i][k];
		    cpt++;
	       }
	  }
     }
     
     /* Element Gauche */
     
     if(j==0 && i > 0)
     {
	  for(k=j; k<=j+1; k++)
	  {
	       voisins[cpt] = tab[i-1][k];
	       cpt++;
	       if(tab[i][k]!=tab[i][j])
	       {
		    voisins[cpt] = tab[i][k];
		    cpt++;
	       }
	  }
	  if(i < n-1)
	  {
	       voisins[cpt] = tab[i+1][j+1];
	       cpt++;
	       voisins[cpt] = tab[i+1][j];
	       cpt++;
	  }
	  
     }
}
void trouver_lettre_de_mot_dans_grille(char caract,  char **grille, int ligne, int colonne, int indice[2])
{
  int i;
  int j;
  printf("2\n");
   while((i != ligne) && (caract != grille[i][j]))
  {
    j=0;
   while((j != colonne) && (caract != grille[i][j]))
    {
      j++;
    }
    if(caract != grille[i][j])
      i++;
  }
  if(caract == grille[i][j])
  {
    indice[0] = i;
    indice[1] = j;
  }
}
void trouver_mot_dans_grille(char *mot, int ligne, int colonne, int k,char *lettre_trouve, char **grille)
{
  int i,j,w;
  int cpt;
  int cptr;
  char **tab;
  char voisins[8];
  char caract;
  int indice[2] ;
  for(w=0; w<2; w++)
    indice[w] = -1;
  printf("3\n");
  caract = mot[k];
  trouver_lettre_de_mot_dans_grille(caract, grille, ligne, colonne,  indice);
  if(indice[0] != -1 && indice[1] != -1)
  {
      printf("1\n");
      lettre_trouve[cptr] = caract;
      cptr++;
      i = indice[0];
      j = indice[1];
      solveur_de_boggle_voisins(tab, i, j, ligne, colonne, voisins);
      caract = mot[k+1];
      while(caract!= voisins[cpt] && voisins[cpt] != '\0' )
      {
	cpt++;  
      }
      if(caract== voisins[cpt])
      {
	k++;
	trouver_mot_dans_grille(mot, ligne, colonne, k, lettre_trouve, grille);
      }
      else
	exit (0);
  }
  else
    exit (1);
}
void trouver_mot_du_dico(char **grille,int ligne,int colonne)
{
  int k=0;
  char *lettre_trouve = "0";
  char * mot = "0";
  FILE *fich;
  fich = fopen("dictionaire.txt","r");
  if(fich == NULL)
    printf("Erreur d'ouverture du fichier\n");
  while(fgets(mot, 25, fich) != NULL)
  {
    trouver_mot_dans_grille(mot, ligne, colonne, k, lettre_trouve, grille);
    if(strcmp(mot, lettre_trouve)==0)
      printf("%s\n",lettre_trouve);
  }
}
int main()
{
     
     char **grille; /* C'est la grille du jeu */
    /* int K;*/
     int ligne = 4, colonne = 4;
     int i;
     solveur_de_boggle_dimension(&ligne, &colonne);
     
     /* Allocation de la grille */
     grille = malloc(sizeof(char*)*ligne);
     for(i=0; i<ligne; i++)
	  grille[i] = malloc(sizeof(char)*colonne);
     
     solveur_de_boggle_creer_grille(grille, ligne, colonne);
     /*solveur_de_boggle_Mot_Possible(grille, ligne, colonne);*/
    trouver_mot_du_dico(grille, ligne,colonne);
     
 /* cp=solveur_de_boggle_verif_reponse(x);
  printf("%d",cp);
  grilles *gr=NULL;
  solveur_de_boggle_creer_grille(gr);*/
  return 0;
}
