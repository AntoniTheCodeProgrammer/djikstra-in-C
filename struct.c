#include "struct.h"

Vertex* new_Vertex(Vertex** vertex, int i, Vertex* tail) {
    Vertex* v = malloc(sizeof(Vertex));
    v->ID = i;
    v->road = NULL;
    v->next = NULL;

    if (tail != NULL) {
        tail->next = v;
    } else {
        *vertex = v;
    }
    return v;
}

int create_Vertex(Vertex** vertex, char* file_name) {
    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Nie udalo sie otworzyc pliku!\n");
        return 1;
    }

    Vertex* tail = NULL;
    int n = 0;
    int parent, child;
    double weight;
    char name[256];

    while (fscanf(file, "%d %d %lf %s", &parent, &child, &weight, name) == 4) {
        while (parent > n || child > n) {
            tail = new_Vertex(vertex, n, tail);
            n++;
        }

        Road* new_road = malloc(sizeof(Road));
        new_road->directionID = child;
        new_road->name = strdup(name);
        new_road->weight = weight;
        Vertex* current = *vertex;
        while (current != NULL && current->ID != parent) {
            current = current->next;
        }
        if (current != NULL) {
            new_road->next = current->road;
            current->road = new_road;
        }
    }
    fclose(file);

    return 0;
}

void print_vertex(Vertex* vertex) {
    Vertex* current_Vertex = vertex;
    printf("Structure:\n");
    while (current_Vertex != NULL) {
        printf("%i -> { ", current_Vertex->ID);
        Road* current_Road = current_Vertex->road;
        int roads = 0;
        while (current_Road != NULL) {
            printf("[%d via \"%s\" (weight: %.2f)] ", current_Road->directionID, current_Road->name, current_Road->weight);
            current_Road = current_Road->next;
            roads++;
        }
        if (roads == 0) {
            printf("NULL ");
        }
        printf("}\n");
        current_Vertex = current_Vertex->next;
    }
    printf("\n");
}

int lenght_of_vertex(Vertex* vertex) {
    Vertex* current = vertex;
    int i = 0;
    while (current != NULL) {
        current = current->next;
        i++;
    }
    return i;
}