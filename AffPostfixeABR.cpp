#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <ostream>
#include <iostream>

        //Declaration de la structure d'un ABR avec une liste 
typedef struct cel * Arbre;
typedef struct cel{
   	int cle;
	Arbre FilsG;
	Arbre FilsD;
}Anoeud;


        //Fonction qui verifie si l'arbre est vide 
int ArbreVide (Arbre A){
    if (A==NULL) return 0;
    else return 1;
}   


        //Procedure d'affichage postfixe d'un ABR
void Postfixe (Arbre A){
    if (ArbreVide(A)==1){  //Si l'arbre n'est pas vide 
        Postfixe(A->FilsG);     //Appel recursive sur le fils gauche 
        Postfixe(A->FilsD);     //Appel recursive sur le fils gauche 
        printf("%d \t",A->cle); //Affichage de la racine 
    }
}


        //Fonction de recherche iteratif d'un element dans un ABR
int Existe (Arbre A , Arbre *prd , int x){
    int trouve=0;
    while (trouve == 0 && A != NULL){
        if (x == A->cle){
            trouve = 1;
        } else {
            *prd = A;   //On sauvegarde le dernier element 
            if (x < A->cle){
                A = A->FilsG;
            }else{
                A = A->FilsD;
            }
        }
    }
    return trouve;
}


                         //Procedure d'insertion d'un element dans un ABR
void Insert (Arbre *Racine , int x){
    Arbre A, prd;
    prd = NULL;
    
    if (Existe(*Racine, &prd,x)==1){    //Si l'element existe dans l'arbre
        printf("Cette valeur existe deja");     //On l'insert pas 
    } else {            //S'il existe pas 
                //On a recuperecer par la fonction Existe le dernier element visier 
                //On a mis cette element dans prd 
                //prd est le parent de l'element qu'on doit inserer 
            //On cree la feuille a inserer 
        A=(Arbre)malloc(sizeof(Anoeud)); 
        A->cle = x;
        A->FilsG = NULL;
        A->FilsD = NULL;
        if (prd != NULL){  //Si l'arbre n'est pas vide 
            if (x < prd->cle){  //Si x< cle de prd 
                prd->FilsG = A;     //il devient le fils gauche de prd
            }else {             //Si x> cle de prd 
                prd->FilsD = A;      //il devient le fils droit de prd
            }
        }else{      //Si l'arbre est vide 
            *Racine = A;      //L'element a insere devient la racine 
        }
    }
}

int main (){
    int i , n=0 , x=0;
    Arbre A=NULL;
    
        //Recuperation de la taille de l'arbre
    printf ("Donner le nombre d'elements de l'arbre \n") ;
    scanf ("%d", &n) ;
    
        //Remplissage de l'arbre depuis l'entree clavier 
    for (i = 0 ; i < n; i++) {
        printf ("Donner la %d valeur de l'arbre \n", i+1) ;
        scanf ("%d", &x) ;
        Insert(&A,x);
    }
     
        //L'affichage postfixe de l'arbre 
    printf("L'affichage postfixe de l'arbre \n");

        //Calcule du temps d'execution de la procedure d'affichage postfixe 
    auto start = std::chrono::high_resolution_clock::now();

    Postfixe(A);

    auto end = std::chrono::high_resolution_clock::now();
    long long nanoseconds = std::chrono::duration_cast< std:: chrono :: nanoseconds >(end-start).count();
    std::cout << "\n Le temps d'execution de la procedure d'affichage postfixe est : \t " << 
    nanoseconds << " ns" << std::endl ;
    
    return 0;
}