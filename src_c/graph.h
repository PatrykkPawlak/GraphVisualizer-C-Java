#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NAME_LEN 64
#define INIT_CAP 16

typedef struct {
  int id;
  double x, y;
} Node;

typedef struct {
  char name[MAX_NAME_LEN];
  int n_1, n_2; //<- indeksy do tablicy NODE
  double weight;
} Edge;

typedef struct {
  Node *nodes;
  int node_count;
  int node_cap;
  Edge *edges;
  int edge_count;
  int edge_cap;
} Graph;

Graph *create_graph(void);
void free_graph(Graph *g);

#endif
