#include <iostream> 
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <vector>
#define N 10000 //taille de a 
#define M 10000 //taille de b

using namespace std;

float* SumOfArrays(float a[], float b[], int lena, int lenb){
    
    int i ;
    int taillemin = min(lena, lenb) ;
    int taillemax = max(lena, lenb) ;
    float* result = new float [taillemax];
    float* temp = ((taillemax == lena) ? a : b);

    for(i=0 ; i<taillemax ; i++){
        if(i<taillemin) 
            result[i] = a[i] + b[i] ;
        else
            result[i] = temp[i];
    }
    return result;
}

int main(int argc, char const *argv[])
{
    float a[N] = {};
    float b[M] = {};
    float * result = SumOfArrays(a,b,N,M) ;
    
    long long time = 0;
    for(int i=0 ; i<1000 ; i++){ //executer la somme 1000 fois
        int n ;
        auto start = std::chrono::high_resolution_clock::now();
        float * result = SumOfArrays(a,b,N,M) ;
        auto end = std::chrono::high_resolution_clock::now();
        
        /* portion du code qui affiche le resultat de la somme.
        std::cout << "v = { ";
        for (n=0 ; n<max(N,M) -1 ; n++) {
            std::cout << result[n] << ", ";
        }
        std::cout << result[n] << "}; \n";
        */
        
        long long nanoseconds = std::chrono::duration_cast <std::chrono::nanoseconds> (end-start).count();
        time = time + nanoseconds; //temps total pour les 1000 execution
    }
    std::cout << time/1000 << std::endl ; //afficher le temps moyen de chaque execution
    return 0;
}


