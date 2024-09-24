///Satalla Alexandru
///Grupa 164
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "matrice.h"
#include "vector.h"
#include "fisiere.h"
void salveaza_matrice(char* locatie,struct matrice met)
{
    FILE* f= fopen(locatie, "w");
    fwrite(&met.m, sizeof(int), 1, f);
    fwrite(&met.n, sizeof(int), 1, f);
    for (int i=0; i<met.m; i++)
        for (int j=0; j<met.n; j++)
            fwrite(&met.mat[i][j], sizeof(float), 1, f);
    fclose(f);
}
struct matrice citire_matrice(char* locatie)
{
    int m, n;
    FILE* f=fopen(locatie, "r");
    fread(&m, sizeof(int), 1, f);
    fread(&n, sizeof(int), 1, f);
    struct matrice met = matrice_nula(m, n);
    for (int i=0; i<met.m; i++)
        fread(met.mat[i], sizeof(float)*met.n, 1, f);
    fclose(f);
    return met;
}
void salveaza_vector(char* locatie,struct vectore vit)
{
    FILE* f=fopen(locatie, "w");
    fwrite(&vit.n, sizeof(int), 1, f);
    fwrite(vit.vet, sizeof(float)*vit.n, 1, f);
    fclose(f);
}
struct vectore citire_vector(char* locatie)
{
    int n;
    FILE* f=fopen(locatie, "r");
    fread(&n, sizeof(int), 1, f);
    struct vectore vit = creaza_vector(n);
    fread(vit.vet, sizeof(float)*vit.n, 1, f);
    fclose(f);
    return vit;
}
