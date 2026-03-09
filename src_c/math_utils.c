#include "math_utils.h"
#include <math.h>
#include <stdlib.h>

double oblicz_odleglosc(double x1,double y1,double x2,double y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
Wektor oblicz_wektor(double x1,double y1,double x2,double y2){
    Wektor wynik;
    double d=oblicz_odleglosc(x1,y1,x2,y2);
    if(d==0.0){
        wynik.x=0.0;
        wynik.y=0.0;
        return wynik;
    }
    double L_x=(x2-x1)/d;
    double L_y=(y2-y1)/d;
    wynik.x=L_x;
    wynik.y=L_y;
    return wynik;
}

Matrix create_matrix(int size){
    Matrix m;
    m.size=size;
    m.values=malloc(size*sizeof(double *));
    for(int i=0;i<size;i++){
        m.values[i]=malloc(size*sizeof(double));
    }
    return m;
}
void gauss_elimination(Matrix m,double *B,double *w){
    double Best=m.values[0][0];
    for(int i=0;i<m.size;i++){
        if(fabs(m.values[i][i+1])>Best){
            double *temp_row=m.values[i];
            m.values[i]=m.values[i+1];
            m.values[i+1]=temp_row;
            double temp_B=B[i];
            B[i]=B[i+1];
            B[i+1]=temp_B;
        }
        for(int j=0;i<m.size;j++){
            double mnoznik=;

        }
    }
}
void free_matrix(Matrix m){
    for(int i=0;i<m.size;i++){
        free(m.values[i]);
    }
    free(m.values);
}