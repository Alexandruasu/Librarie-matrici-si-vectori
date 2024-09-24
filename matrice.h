///Satalla Alexandru
///Grupa 164
#pragma once
struct matrice
{
    unsigned int m, n;
    float **mat;
};
enum mod_schimbare
{
    simetric,
    liniar
};
struct matrice matrice_unitate(int n);
struct matrice matrice_nula(int m, int n);
struct matrice inmultire_matrice_matrice(struct matrice met1,struct matrice met2);
float determinant(struct matrice met);
int rang(struct matrice met);
void schimbare_matrice(struct matrice *met, enum mod_schimbare metoda);
float urma(struct matrice met);
struct matrice matrice_inversabila(struct matrice met);
struct matrice matrice_transpusa(struct matrice met);
int baza(struct matrice met);