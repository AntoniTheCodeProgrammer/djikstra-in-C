#include <stdio.h>
#include <stdlib.h>

#include "dijkstra.h"
#include "struct.h"

int main(int argc, char **argv) {
    Vertex* vertex = NULL;

    // Dane z konsoli
    char *file_name = (argc > 1) ? argv[1] : "tests/test0.txt";
    int start = (argc > 2) ? atoi(argv[2]) : 0;
    int end = (argc > 3) ? atoi(argv[3]) : 0;

    // Funkcja pobrania danych
    if (create_Vertex(&vertex, file_name) != 0) {
        return 1;
    }

    int n = lenght_of_vertex(vertex);
    print_vertex(vertex);

    dijkstra(vertex, start, n);

    // print_results(vertex, start, n);
    // printf("\n");
    print_result(vertex, start, end, n);
    all_free(vertex);
    return 0;
}
