#include "../io/graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *input_path = NULL;
  char *output_path = NULL;
  char *algorithm = "fr";
  int iterations = 200;
  int binary_output = 0;
  int verbose = 0;

  int opt;
  while ((opt = getopt(argc, argv, "i:o:a:n:bvh")) != -1) {
    switch (opt) {
    case 'i':
      input_path = optarg;
      break;
    case 'o':
      output_path = optarg;
      break;
    case 'a':
      algorithm = optarg;
      break;
    case 'n':
      iterations = atoi(optarg);
      break;
    case 'b':
      binary_output = 1;
      break;
    case 'v':
      verbose = 1;
      break;
    case 'h':
      printf("Użycie: %s -i wejście [-o wyjście] [-a fr|tutte] [-n iteracje] "
             "[-b] [-v]\n",
             argv[0]);
      return 0;
    default:
      return ERR_ARGS;
    }
  }

  if (!input_path) {
    fprintf(stderr, "Błąd: Brak pliku wejściowego (-i)\n");
    return ERR_ARGS;
  }

  Graph *graph = graph_create();
  if (!graph || graph_load_text(graph, input_path, verbose) != 0) {
    free_graph(graph);
    return ERR_FILE;
  }

  if (verbose) {
    if (strcmp(algorithm, "tutte") == 0) {
      printf("Algorytm: Tutte\n");
    } else {
      printf("Algorytm: FR (%d iteracji)\n", iterations);
    }
  }

  int result = (binary_output && output_path)
                   ? graph_save_binary(graph, output_path)
                   : graph_save_text(graph, output_path);

  free_graph(graph);
  return result;
}
