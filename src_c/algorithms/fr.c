#include "fr.h"
#include "../io/graph.h"
#include "../utils/math_utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fr(Graph *g, int iterations, double width, double height) {
  if (g->node_count == 0)
    return;
  double ideal_dist = sqrt(height * width / (double)g->node_count);

  Vector *offset = calloc(g->node_count, sizeof(Vector));
  if (!offset)
    return;

  double temp = width / 10;

  for (int i = 0; i < iterations; i++) {
    memset(offset, 0, g->node_count * sizeof(Vector));
    for (int v = 0; v < g->node_count; v++) {
      for (int u = 0; u < g->node_count; u++) {
        if (v == u)
          continue;
        Vector pos_v = {g->nodes[v].x, g->nodes[v].y};
        Vector pos_u = {g->nodes[u].x, g->nodes[u].y};
        Vector sub = vector_sub(pos_v, pos_u);
        Vector direction = vector_normalize(sub);
        double d = vector_mag(sub);
        double force_val;
        if (d > 0) {
          force_val = ideal_dist * ideal_dist / d;
        } else {
          force_val = ideal_dist * ideal_dist;
        }
        offset[v] = vector_add(offset[v], vector_mul(direction, force_val));
      }
    }
  }

  free(offset);
}
