#include "tutte.h"
#include "../io/graph.h"
#include "../utils/math_utils.h"
#include <math.h>

void run_tutte(Graph *G) {
    int radius=10;
    for(int i=0;i<3;i++){
        G->nodes[i].x = radius*cos(i*((2*M_PI)/3.0));
        G->nodes[i].y = radius*sin(i*((2*M_PI)/3.0));
    }
    Matrix m = create_matrix(G->node_count-3);
    double *B_X = calloc(G->node_count-3,sizeof(double));
    double *B_Y = calloc(G->node_count-3,sizeof(double));
    double *w_x = calloc(G->node_count-3,sizeof(double));
    double *w_y = calloc(G->node_count-3,sizeof(double));
    for(int j=0;j<G->edge_count;j++){
        int n1=G->edges[j].n_1;
        int n2=G->edges[j].n_2;
        double w=G->edges[j].weight;
        if(n1>=3){
            m.values[n1-3][n1-3]+=w;
            if(n2>=3){
                m.values[n1-3][n2-3]=-w;
            }
            else{
                B_X[n1-3]+=G->nodes[n2].x*w;
                B_Y[n1-3]+=G->nodes[n2].y*w;
            }
        }
        if(n2>=3){
            m.values[n2-3][n2-3]+=w;
            if(n1>=3){
                m.values[n2-3][n1-3]=-w;
            }
            else{
                B_X[n2-3]+=G->nodes[n1].x*w;
                B_Y[n2-3]+=G->nodes[n1].y*w;
            }
        }
    }
    gauss_elimination(m,B_X,w_x);
    gauss_elimination(m,B_Y,w_y);
    for(int i=3;i<G->node_count;i++){
        G->nodes[i].x=w_x[i-3];
        G->nodes[i].y=w_y[i-3];
    }
    free_matrix(m);
    free(B_X);
    free(B_Y);
    free(w_x);
    free(w_y);

}