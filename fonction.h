#ifndef MODELE_H
#define MODELE_H

#include <stdio.h>

// capacit� maximale d'un bloc de donn�es (en nombre d'enregistrements)
#define MAXTAB 18000
#define max 1024



// type d'un bloc de donn�es (et donc des buffers aussi)
typedef struct enreg{ //les champs de l'enregistrement dans la table d'index 1
      long cle;
      int pos;
      int bloc;
      int region;
      int eff;

      }enreg;
typedef struct blc { // la structure des blocs dans la table d'index 2
	   enreg tab[MAXTAB];	// tableau d'enregistremnts (des entiers longs)
	   char eff[MAXTAB];	// indicateurs d'effacement logique ('*' effac� / ' ' non effac�)
	   int nb;		// nombre d'enregistrements dans le bloc
  	   char pad[4];		// pas n�cessaire, juste pour avoir une taille de bloc de 512 octets
        } tbloc;


// type du bloc d'ent�te (les caract�ristiques du fichier)
typedef struct entete {//l'entetede la premiere table d'index
	   // nombre de blocs utilis� par les enreg (c'est aussi le num du dernier bloc)
	   long nb_bloc;
	   // nombre d'enregistrements dans le fichier
	   long nb_ins;
	   // nombre d'enregistrements supprim�s (logiquement) dans le fichier
	   long nb_sup;
	   // pas n�cessire, juste pour compl�ter la taille de l'ent�te jusqu'� 512 octes
	   char pad[488];
	} t_entete;







	typedef struct enreg2{ //les champs de l enregistrement de la table d'index 2
      long cle;
      int pos;
      int bloc;
      int Etablissement;
      int anciente;
      int eff;
      int specialite;
      }enreg2;
typedef struct blc2 { //structure des blocs de la deuxieme table d'index
	   enreg2 tab[MAXTAB];	// tableau d'enregistremnts (des entiers longs)
	   char eff[MAXTAB];	// indicateurs d'effacement logique ('*' effac� / ' ' non effac�)
	   int nb;		// nombre d'enregistrements dans le bloc
  	   char pad[4];		// pas n�cessaire, juste pour avoir une taille de bloc de 512 octets
        } tbloc2;


// type du bloc d'ent�te (les caract�ristiques du fichier)
typedef struct entete2 {//l'entete de la table d'index
	   // nombre de blocs utilis� par les enreg (c'est aussi le num du dernier bloc)
	   long nb_bloc;
	   // nombre d'enregistrements dans le fichier
	   long nb_ins;
	   // nombre d'enregistrements supprim�s (logiquement) dans le fichier
	   long nb_sup;
	   // pas n�cessire, juste pour compl�ter la taille de l'ent�te jusqu'� 512 octes
	   char pad[488];
	} t_entete2;




	//***************************************************************************************************/

typedef struct Tbloc//structure des blocs lobarrevc
{
    char tab[max];  // le tableau de caract�re
    int suivant;    // le numero du bloc suivant dans la liste
}Tbloc;

typedef struct Tbloc Buffer;  // declaration du tampon
typedef struct maillon //la structure definissant la liste
{
    int val;
    int suivant;
}maillon;

typedef struct Entete        // structure de l'entete du fichier en m�moire centrale
{
    int nbbloc;
    int tete;
    int queue;
    int indice_libre;   // l'indice libre dans le bloc de la queue
    int nb_car_sup;

}Entete;

typedef struct LObarreVC //la structure LObarreVC
{
    FILE *fich;
    Entete entete;

}LObarreVC;



//************************************************************************************************************//
// ouvrir un fichier en mode 'N' ou 'A'
// retourne le flux f et l'ent�te ent
void ouvrir( FILE **f, char *nom, char mode, t_entete *ent );

// fermer le fichier en sauvegardant l'ent�te ent dans le 1er bloc (num 0) du fichier
void fermer( FILE *f, t_entete *ent);

// lecture du bloc de donn�es num i dans la variable buf
void lireDir( FILE *f, long i, tbloc *buf );

// ecriture du contenu de la variable buf dans le bloc de donn�es num i
void ecrireDir( FILE *f, long i, tbloc *buf );



//***************************************************************************************************************//




void aff_entete(LObarreVC *fichier,int i , int valeur);//aff l'entete
int entete(LObarreVC *fichier, int i);//l'entete du fichier
void liredir_LObarreVC(LObarreVC *fichier, long i , Tbloc *buf);
void ecriredir_LObarreVC(LObarreVC *fichier, int i, Buffer *buf);
LObarreVC *ouvrir_LObarreVC(char nom_physique[], char mode);//Ouverture du fichier lobarrevc
void fermer_LObarreVC(LObarreVC *fichier);
void alloc_bloc(LObarreVC *fichier);//alloc bloc
void turn_to_string(char chaine[], int n, int longueur);//met n'importe entier en chaine de caractere
void recuperer_chaine(LObarreVC *fichier,int n , int *i, int *j, char chaine[],Buffer *buf); //recuperer chaine du buffer
void ecrire_chaine(LObarreVC *fichier,int n , int *i, int *j, char chaine[],int *cpt,Buffer *buf);//ecrire dans un buffer
void recherche_LObarreVC(LObarreVC *fichier,int cle,int *trouv,int *i, int *j );//recherche lobarrevc
void insertion_LObarreVC(LObarreVC *fichier, int cle, char *info) ;//insertion lobarrevc
void suppression_logique_LObarreVC(LObarreVC *fichier, int cle);//supression lobarrevc
void afficher_bloc(LObarreVC *fichier,int i);//affichage de blocs lobarrevc
void afficher_fichier(LObarreVC *fichier,int *i,int *j);//affichage du fichier
void afficher_info_chevau(LObarreVC *fichier);
void recherche_min(LObarreVC *fichier,int MIN, int *i, int *j,int *val);
int max_fichier(LObarreVC *fichier);
void reordonner_fichier(LObarreVC *fichier1,char *nom_physique);
void suppression_physique_LObarreVC(LObarreVC *fichier,char *nom_physique);
void creation_fichier(LObarreVC *fichier,int n);
void afficher_entete(LObarreVC *fichier);//affichage de l'entete
void chargement_initial(LObarreVC *fichier);//chargement initial du fichier
void insertion2_LObarreVC(LObarreVC *fichier,char *cle_ch,int *i,int *j);//insertion d'un enregistrement dans les positions i,j
void suppression_LObarreVC(LObarreVC *fichier,int *i,int *j);//suppression de l'enregistrement a la position  i j


#endif
