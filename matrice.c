//Satalla Alexandru
//Grupa 164
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matrice.h"
struct matrice matrice_unitate(int n)
{
    struct matrice met = matrice_nula(n, n);
    met.m=n;
    met.n=n;
    for(int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if(i!=j)
            {
                met.mat[i][j]=0;
            }
            else
            {
                met.mat[i][j]=1;
            }
        }
    }
    return met;
}
struct matrice matrice_nula(int m, int n)
{
    struct matrice met;
    met.m=m;
    met.n=n;
    met.mat=malloc(sizeof(float*)*m);
    for(int i=0; i<m; i++)
        met.mat[i]=malloc(sizeof(float)*n);
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            met.mat[i][j]=0;
    return met;
}
struct matrice inmultire_matrice_matrice(struct matrice met1,struct matrice met2)
{
    if (met1.m != met2.n)
    {
        printf("Matricile nu sunt compatibile!");
        return met1;
    }
    struct matrice ret=matrice_nula(met1.m, met2.n);
    ret.m=met1.m;
    ret.n=met2.n;
    for(int i=0; i<met1.m; i++)
    {
        for(int j=0; j<met2.n; j++)
        {
            for(int k=0; k<met2.n; k++)
                ret.mat[i][j]+=met1.mat[i][k]*met2.mat[k][j];
        }
    }
    return ret;
}
float determinant(struct matrice met)
{
    if(met.m!=met.n)
        return 0;
    float det=0;
    if(met.m==0&&met.n==0)
    {
        return 0;
    }
    if(met.m==1&&met.n==1)
    {
        det=met.mat[0][0];
        return det;
    }
    if(met.m==2&&met.n==2)
    {
        det=met.mat[0][0]*met.mat[1][1]-(met.mat[0][1]*met.mat[1][0]);
        return det;
    }
    for(int z=0; z<met.n; z++)
    {
        int k=0;
        struct matrice v= matrice_nula(met.n-1, met.n-1);
        for(int i=1; i<met.n; i++)
            for(int j=0; j<met.n; j++)
            {
                if(z==j)
                    continue;
                v.mat[k/v.n][k%v.n]=met.mat[i][j];
                k++;
            }
        if(z%2==0)
            det+=met.mat[0][z]*determinant(v);
        else
            det-=met.mat[0][z]*determinant(v);
        free(v.mat);
    }
    return det;
}
int baza(struct matrice met)
{
    if(met.m==met.n && determinant(met)!=0)
            return 1;
    return 0;
}
void schimbare_matrice(struct matrice *met, enum mod_schimbare metoda)
{
    switch (metoda)
    {
    case simetric:
    {
        if(met->m<met->n)
            met->n=met->m;
        else if(met->m>met->n)
            met->m=met->n;
        break;
    }
    case liniar:
    {
        met->m--;
        met->n--;
        break;
    }
    }
}
float urma(struct matrice met)
{
    if(met.m!=met.n)
        return 0;
    float ur=0;
    for(int i=0; i<met.m; i++)
        for(int j=0; j<met.n; j++)
            if(i==j)
                ur+=met.mat[i][i];
    return ur;
}
struct matrice matrice_inversabila(struct matrice met)
{
    struct matrice cmet = matrice_transpusa(met);
    if(met.n!=met.m)
        return cmet;
    int x=determinant(met);
    if(x==0)
        return cmet;
    struct matrice inv = matrice_nula(met.n, met.n);
    for(int r=0; r<met.n; r++)
        for(int z=0; z<met.n; z++)
        {
            int k=0;
            struct matrice v= matrice_nula(met.n-1, met.n-1);
            for(int i=0; i<met.n; i++)
                for(int j=0; j<met.n; j++)
                {
                    if(z==j||r==i)
                        continue;
                    v.mat[k/v.n][k%v.n]=cmet.mat[i][j];
                    k++;
                }
            if((z+r)%2==0)
                inv.mat[r][z]=determinant(v);
            else
                inv.mat[r][z]=-determinant(v);
            free(v.mat);
        }
    for(int i=0; i<cmet.n; i++)
        for(int j=0; j<cmet.n; j++)
            inv.mat[i][j]/=x;
    return inv;
}
struct matrice matrice_transpusa(struct matrice met)
{
    struct matrice cmet = matrice_nula(met.n,met.n);
    for(int j=0; j<met.m; j++)
        for(int i=0; i<met.m; i++)
            cmet.mat[j][i]=met.mat[i][j];
    return cmet;
}