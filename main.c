#include <stdio.h>
#include <stdlib.h>

#include "djikstra.h"
#include "struct.h"

int main() {
    Vertex* vertex = NULL;
    if (create_Vertex(&vertex, "data.txt") != 0) {
        return 1;
    }

    Vertex* v_ptr = vertex;
    while (v_ptr != NULL) {
        printf("%i \n", v_ptr->ID);
        Road* r_ptr = v_ptr->road;
        while (r_ptr != NULL) {
            printf("[%d (waga: %d)] -> ", r_ptr->directionID, r_ptr->weight);
            r_ptr = r_ptr->next;
        }
        printf("NULL\n");
        v_ptr = v_ptr->next;
    }

    djikstra(vertex, 0, 6);
    return 0;
}
