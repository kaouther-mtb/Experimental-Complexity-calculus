#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <ostream>
#include <iostream>

int rec (int tab[],int min,int max,int e){

    int mid;


    if (min == max){
        if (tab[min] == e) return min;
            else return -1;
    }
    mid = (min+max)/2;
    if (tab[mid] < e)
        return rec(tab,mid+1,max,e);
    else return rec(tab,min,mid,e);

}


int it(int tab[],int min,int max,int e){

    int mid;

    while (min<max){
        mid=(max+min)/2;
        if (tab[mid]<e)
            min = mid+1;
        else
            max = mid;
    }

    if (tab[min] == e) return min;
    else return -1;

}

void tri(int T[],int N){

    int i,j,c;
    for(i=0;i<N-1;i++)
        for(j=i+1;j<N;j++)
            if ( T[i] > T[j] ) {
                c = T[i];
                T[i] = T[j];
                T[j] = c;
            }
}

void affiche(int tab[],int N){

    int i;
    printf("|");
    for (i=0;i<N;i++){
        printf("%d|",tab[i]);
    }
    printf("\n");
}


int main() {

    int n=0;
    //Recuperer la taille du tableau
    printf("Donner la taille du tableau\n");
    scanf ("%d", &n) ;
    
    int tab[n];
    int i=0;


    


    //Generation des valeurs du tableau
    for (i=0;i<n;i++){
        tab[i]=rand();
    }

    printf("Le tableau non trié, il faut d'abord le trier pour appliquer la methode dichotomique\n");
    affiche(tab,n);

    tri(tab,n);
    printf("Le tableau trie:\n");
    affiche(tab,n);

    int min,max,mid,e;

    //Affecter 0 a min car 0 est le premier indice et n-1 pour l'indice du dernier element
    min=0;
    max=n-1;


    printf("Donner la valeur de l'element que tu souhait rechercher dans le tableau\n");
    scanf ("%d", &e) ;;

    int trouv;

    auto start = std::chrono::high_resolution_clock::now();
    trouv = rec(tab,min,max,e);
    auto end = std::chrono::high_resolution_clock::now();
    long long nanoseconds = std::chrono::duration_cast< std:: chrono :: nanoseconds >(end-start).count();
    std::cout << "\n Le temps d'execution de la procedure recherche dichotomique : \t " << 
    nanoseconds << " ns" << std::endl ;


    if (trouv==-1){
        printf("Le fonction a retourner -1 donc l'element recherche n'existe pas");
    }
    else {
        printf("L'element %d existe son indice est %d",e,trouv);
    }
}
