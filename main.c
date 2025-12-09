#include <stdio.h>
#include <stdlib.h>

#include "dijkstra.h"
#include "struct.h"

int main() {
    Vertex* vertex = NULL;
    if (create_Vertex(&vertex, "tests/test5.txt") != 0) {
        return 1;
    }
    int n = lenght_of_vertex(vertex);
    print_vertex(vertex);

    dijkstra(vertex, 0, n);
    return 0;
}
