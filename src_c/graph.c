#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph *graph_create() {
  Graph *g = malloc(sizeof(Graph));

  if (g == NULL)
    return NULL;

  g->node_count = 0;
  g->node_cap = INIT_CAP;
  g->nodes = malloc(sizeof(Node) * INIT_CAP);

  g->edge_count = 0;
  g->edge_cap = INIT_CAP;
  g->edges = malloc(sizeof(Edge) * INIT_CAP);

  if (g->edges == NULL || g->nodes == NULL) {
    free(g->edges);
    free(g->nodes);
    free(g);
    return NULL;
  }

  return g;
}

void free_graph(Graph *g) {
  if (g == NULL)
    return;
  free(g->edges);
  free(g->nodes);
  free(g);
  return;
}
