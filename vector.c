///Satalla Alexandru
///Grupa 164
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matrice.h"
struct matrice inmultire_matrice_vector(struct matrice met,struct vectore vit)
{
    struct matrice ret=matrice_nula(met.n, 1);
    for(int i=0; i<met.m; i++)
    {
        for(int j=0; j<met.n; j++)
            ret.mat[i][0]+=met.mat[i][j]*vit.vet[j];
    }
    return ret;
}
struct sistem_de_vectori creare_sistem_de_vectori(int dimensiune)
{
    struct sistem_de_vectori sistem;
    sistem.dimensiune=dimensiune;
    sistem.cardinal=0;
    return sistem;
}
struct vectore creaza_vector(int n)
{
    struct vectore vec;
    vec.n=n;
    vec.vet=malloc(sizeof(float)*n);
    return vec;
}
struct vectore produs_scalar(struct vectore vit1,struct vectore vit2)
{
    struct vectore scalar = creaza_vector(vit1.n);
    if (vit1.n != vit2.n)
        return scalar;
    for(int i=0; i<=vit1.n; i++)
        scalar.vet[i]=vit1.vet[i]*vit2.vet[i];
    return scalar;
}
