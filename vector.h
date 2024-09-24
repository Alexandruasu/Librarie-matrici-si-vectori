///Satalla Alexandru
///Grupa 164
#pragma once
struct sistem_de_vectori
{
    unsigned int dimensiune,cardinal;
    struct vectore *vet;
};
struct vectore
{
    unsigned int n;
    float *vet;
};
struct matrice inmultire_matrice_vector(struct matrice met,struct vectore vit);
struct sistem_de_vectori creare_sistem_de_vectori(int dimensiune);
struct vectore creaza_vector(int n);
struct vectore produs_scalar(struct vectore vit1,struct vectore vit2);
