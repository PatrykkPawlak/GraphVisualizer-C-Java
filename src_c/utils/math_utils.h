#ifndef _MATH_UTILS_H
#define _MATH_UTILS_H

typedef struct{
    double x;
    double y;
} Wektor;
typedef struct{
    int size;
    double **values;
} Matrix;

double calculate_distance(double x1,double y1,double x2,double y2);
Wektor calculate_vector(double x1,double y1,double x2,double y2);
Matrix create_matrix(int size);
void gauss_elimination(Matrix m,double *B,double *w);
void free_matrix(Matrix m);
#endif