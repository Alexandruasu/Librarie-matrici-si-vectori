///Satalla Alexandru
///Grupa 164
#include <stdio.h>
#include <stdlib.h>
#include "fisiere.h"
#include "vector.h"
#include "matrice.h"
void afisare_matrice(struct matrice m1) {
    for(int i=0;i<m1.m;i++) {
        for(int j=0;j<m1.n;j++)
            printf("%f ", m1.mat[i][j]);
        printf("\n");
    }
}
void afisare_vector(struct vectore vt) {
    for(int i=0;i<vt.n;i++)
        printf("%2.f ", vt.vet[i]);
}
int main()
{
    int n;
    scanf("%d", &n);
    switch (n)
    {
        //1=inmultire_matrice_matrice
    case 1: {
        struct matrice mt1 = citire_matrice("matrice1.txt");
        struct matrice mt2 = citire_matrice("matrice2.txt");
        struct matrice mt3 = inmultire_matrice_matrice(mt1, mt2);
        afisare_matrice(mt3);
        salveaza_matrice("matrice.txt",mt3);
        break;
    }
    //2=inmultire_matrice_vector
    case 2: {
        struct matrice mt1 = citire_matrice("matrice1.txt");
        struct vectore vt1 = citire_vector("vector1.txt");
        struct matrice mt3 = inmultire_matrice_vector(mt1, vt1);
        afisare_matrice(mt3);
        salveaza_matrice("matrice.txt",mt3);
        break;
    }
    //3=matrice_unitate
    case 3: {
        int v;
        scanf("%d", &v);
        struct matrice m1 = matrice_unitate(v);
        afisare_matrice(m1);
        salveaza_matrice("matrice.txt", m1);
        break;
    }
    //4=determinant
    case 4:{
        struct matrice mt1 = citire_matrice("matrice1.txt");
        printf("%f", determinant(mt1));
        break;
    }
    //5=urma
    case 5: {
        struct matrice mt1 = citire_matrice("matrice1.txt");
        printf("%f", urma(mt1));
        break;
    }
    //6=matrice_inversabila
    case 6: {
        struct matrice mt1 = citire_matrice("matrice1.txt");
        struct matrice mt3 = matrice_inversabila(mt1);
        salveaza_matrice("matrice.txt",mt3);
        afisare_matrice(mt3);
        break;
    }
    //7=matrice_transpusa
    case 7: {
        struct matrice mt1 = citire_matrice("matrice1.txt");
        struct matrice mt3 = matrice_transpusa(mt1);
        salveaza_matrice("matrice.txt",mt3);
        afisare_matrice(mt3);
        break;
    }
    //8=produs_scalar
    case 8: {
        struct vectore vt1 = citire_vector("vector1.txt");
        struct vectore vt2 = citire_vector("vector2.txt");
        struct vectore vt3 = produs_scalar(vt1,vt2);
        salveaza_vector("vector.txt",vt3);
        afisare_vector(vt3);
        break;
    }
    //9=editare_matrice
    case 9: {
        char *s = malloc(sizeof(char)*50);
        scanf("%s", s);
        int m,n;
        scanf("%d %d",&m, &n);
        struct matrice mt1 = matrice_nula(m, n);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                scanf("%f", &mt1.mat[i][j]);
        salveaza_matrice(s, mt1);
        break;
    }
    //10=scoaterea unei linii si coloane din matrice
    case 10: {
        struct matrice mt1 = citire_matrice("matrice1.txt");
        schimbare_matrice(&mt1, liniar);
        afisare_matrice(mt1);
        break;
    }
    //11=face matricea de acelasi numar de linii si coloane 
    case 11: {
        struct matrice mt1 = citire_matrice("matrice1.txt");
        schimbare_matrice(&mt1, simetric);
        afisare_matrice(mt1);
        break;
    }
    //12=editare_vector
    case 12: {
        char *s = malloc(sizeof(char)*50);
        scanf("%s", s);
        int m;
        scanf("%d",&m);
        struct vectore m1 = creaza_vector(m);
        for(int i=0;i<m;i++)
                scanf("%f", &m1.vet[i]);
        salveaza_vector(s, m1);
        break;
    }
    //13=afisare_matrice
    case 13: {
        char *s = malloc(sizeof(char)*50);
        scanf("%s", s);
        struct matrice mt1 = citire_matrice(s);
        afisare_matrice(mt1);
        break;
    }
    //14=afisare_vector
    case 14: {
        char *s = malloc(sizeof(char)*50);
        scanf("%s", s);
        struct vectore mt1 = citire_vector(s);
        afisare_vector(mt1);
        break;
    }
    //15=baza
     case 15:{
        struct matrice mt1 = citire_matrice("matrice1.txt");
        printf("%d",baza(mt1));
        break;
    }
    }
    return 0;
}
