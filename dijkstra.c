#include "dijkstra.h"

void print_road(Vertex* vertex, Fastest* roads_to_points, int destination, int start) {
    int current = destination;

    int path[1000];
    char* names[1000];
    int count = 0;

    while (current != start && current != -1) {
        path[count] = current;
        names[count] = roads_to_points[current].road_name;
        current = roads_to_points[current].parent;
        count++;
    }
    path[count] = start;

    printf("Start: %d ", start);
    for (int i = count - 1; i >= 0; i--) {
        printf(" --[%s]--> (%d) ", names[i], path[i]);
    }
}

void update_neighbours(Vertex* vertex, int start, Fastest* roads_to_points, double weight) {
    Vertex* actual_point = vertex;
    while (actual_point != NULL && actual_point->ID != start) {
        actual_point = actual_point->next;
    }
    if (actual_point == NULL || actual_point->road == NULL) {
        return;
    }
    Road* current_road = actual_point->road;

    while (current_road != NULL) {
        if (roads_to_points[current_road->directionID].distance > weight + current_road->weight) {
            roads_to_points[current_road->directionID].distance = weight + current_road->weight;
            roads_to_points[current_road->directionID].parent = start;
            roads_to_points[current_road->directionID].road_name = current_road->name;
        }
        current_road = current_road->next;
    }
}

void dijkstra(Vertex* vertex, int start, int n) {
    Fastest roads_to_points[n];
    for (int i = 0; i < n; i++) {
        roads_to_points[i].final = false;
        roads_to_points[i].distance = 99999999;  // INF
        roads_to_points[i].parent = -1;
    }

    roads_to_points[start].distance = 0;

    for (int i = 0; i < n; i++) {
        int minDistant = 99999999;
        int minID = -1;
        for (int j = 0; j < n; j++) {
            if (roads_to_points[j].distance < minDistant && roads_to_points[j].final == false) {
                minID = j;
                minDistant = roads_to_points[j].distance;
            }
        }
        if (minID == -1 || minDistant == 99999999) {
            break;
        }
        roads_to_points[minID].final = true;
        update_neighbours(vertex, minID, roads_to_points, roads_to_points[minID].distance);
    }

    printf("Result: \n");
    for (int i = 0; i < n; i++) {
        if (roads_to_points[i].distance == 99999999) {
            printf("Brak drogi do miasta %i\n", i);
        } else {
            printf("Dystans do %i to jedynie %.2lf ", i, roads_to_points[i].distance);
            print_road(vertex, roads_to_points, i, start);
            printf("\n");
        }
    }
}