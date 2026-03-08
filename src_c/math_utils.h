#ifndef _MATH_UTILS_H
#define _MATH_UTILS_H

typedef struct{
    double x;
    double y;
}wektor;
typedef struct{
    int size;
    double **values;
}Matrix;

double oblicz_odleglosc(double x1,double y1,double x2,double y2);
wektor oblicz_wektor(double x1,double y1,double x2,double y2);
Matrix create_matrix(int size);
void free_matrix(Matrix m);
#endif