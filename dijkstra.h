#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

void dijkstra(Vertex* vertex, int start, int n);
void print_results(Vertex* vertex, int start, int n);
void print_result(Vertex* vertex, int start, int end, int n);
void all_free(Vertex *vertex);

#endif