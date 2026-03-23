#include "math_utils.h"
#include <math.h>
#include <stdlib.h>

double calculate_distance(double x1,double y1,double x2,double y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
Wektor calculate_vector(double x1,double y1,double x2,double y2){
    Wektor result;
    double d=calculate_distance(x1,y1,x2,y2);
    if(d==0.0){
        result.x=0.0;
        result.y=0.0;
        return result;
    }
    double L_x=(x2-x1)/d;
    double L_y=(y2-y1)/d;
    result.x=L_x;
    result.y=L_y;
    return result;
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
    for(int i=0;i<m.size;i++){
        int max_row=i;
        for(int p=i+1;p<m.size;p++){
        if(fabs(m.values[p][i])>fabs(m.values[max_row][i])){
            max_row=p;
        }
        }
        if(max_row!=i){
            double *temp_row=m.values[i];
            m.values[i]=m.values[max_row];
            m.values[max_row]=temp_row;
            double temp_B=B[i];
            B[i]=B[max_row];
            B[max_row]=temp_B;
        }
        for(int j=i+1;j<m.size;j++){
            double factor=m.values[j][i]/m.values[i][i];
            for(int k=i;k<m.size;k++){
                m.values[j][k]-=m.values[i][k]*factor;
            }
            B[j]-=B[i]*factor;
        }
    }
    for(int i=m.size-1;i>=0;i--){
        double sum=0;
        for(int j=m.size-1;j>i;j--){
            sum+=w[j]*m.values[i][j];
        }
        w[i]=(B[i]-sum)/m.values[i][i];
    }
}
void free_matrix(Matrix m){
    for(int i=0;i<m.size;i++){
        free(m.values[i]);
    }
    free(m.values);
}