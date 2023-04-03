#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIMPLES 0
#define PONDERADO 1
#define DIRECIONADO 2
#define DIRECIONADO_PONDERADO 3

typedef struct __node {
    int value;
    int weight; // peso para grafo ponderado
    struct __node* next;
} Node;

void init_lista(Node** lista, int qtt_nodes) {
    for (int i = 0; i < qtt_nodes; i++) {
        lista[i] = NULL;
    }
}

void insert_in(Node** lista, int node, int index, int weight) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = node;
    new_node->weight = weight;
    new_node->next = lista[index];
    lista[index] = new_node;
    new_node = NULL;
}

void print_lista(Node** lista, int qtt_nodes) {
    for (int i = 0; i < qtt_nodes; i++) {
        printf("[%d] -> ", i);

        Node* current = lista[i];

        while (current != NULL) {
            printf("%d->", current->value);
            current = current->next;
        }

        printf("\n");
    }
}

int get_degree(Node** lista, int node) {
    int deg = 0;

    Node* current = lista[node];

    while (current != NULL) {
        deg++;
        current = current->next;
    }

    return deg;
}

void print_degrees(Node** lista, int qtt_nodes) {
    for (int i = 0; i < qtt_nodes; i++) {
        printf("g(%d) = %d\n", i, get_degree(lista, i));
    }
}

void check_isolated_node(Node** lista, int qtt_nodes) {
    for (int i = 0; i < qtt_nodes; i++) {
        if (get_degree(lista, i) == 0) {
            printf("%d é um nó isolado\n", i);
            return;
        }
    }

    printf("Não há vértices isolados\n");
}

void check_parallel_edges(Node** lista, int qtt_nodes) {
    for (int i = 0; i < qtt_nodes; i++) {
        Node* current = lista[i];

        while (current != NULL) {

            current = current->next;
        }
    }
}

bool check_loops(Node** lista, int qtt_nodes) {
    int total = 0;
    for (int i = 0; i < qtt_nodes; i++) {
        Node* current = lista[i];

        while (current != NULL) {
            if (current->value == i) {
                printf("%d possui um loop\n", i);
                total++;
            }
            current = current->next;
        }
    }

    if (total > 0) {
        printf("Há %d loops\n", total);
        return true;
    } else {
        printf("Não há loops\n");
        return false;
    }
}

bool is_regular(Node** lista, int qtt_nodes) {
    int deg = get_degree(lista, 0);

    for (int i = 1; i < qtt_nodes; i++) {
        if (get_degree(lista, i) != deg) {
            return false;
        }
    }

    return true;
}

void check_if_is_regular(Node** lista, int qtt_nodes) {
    if (is_regular(lista, qtt_nodes)) {
        printf("Grafo é regular\n");
        return;
    }

    printf("Grafo não é regular\n");
}

void check_if_is_complete(Node** lista, int qtt_nodes) {
    if (!is_regular(lista, qtt_nodes)) {
        printf("Grafo não é completo!\n");
        return;
    }

    for (int i = 0; i < qtt_nodes; i++) {
        if (get_degree(lista, i) != qtt_nodes - 1) {
            printf("Grafo não é completo!\n");
            return;
        }
    }
}

int max_degree(Node** lista, int qtt_nodes) {
    int max = get_degree(lista, qtt_nodes);
    for (int i = 1; i < qtt_nodes; i++) {
        int deg = get_degree(lista, qtt_nodes);

        if (deg > max) {
            max = deg;
        }
    }

    return max;
}

int min_degree(Node** lista, int qtt_nodes) {
    int min = get_degree(lista, qtt_nodes);
    for (int i = 1; i < qtt_nodes; i++) {
        int deg = get_degree(lista, qtt_nodes);

        if (deg < min) {
            min = deg;
        }
    }

    return min;
}

void populate_list(Node** lista, int node1, int node2, int type, int weight) {
    switch (type)
    {
    case SIMPLES:
        if (node1 != node2) {
            insert_in(lista, node2, node1, 0);
            insert_in(lista, node1, node2, 0);
        } else {
            insert_in(lista, node1, node2, 0);
        }
        break;
    case PONDERADO:
        if (node1 != node2) {
            insert_in(lista, node2, node1, weight);
            insert_in(lista, node1, node2, weight);
        } else {
            insert_in(lista, node1, node2, weight);
        }
        break;
    case DIRECIONADO:
        insert_in(lista, node2, node1, 0);
        break;
    case DIRECIONADO_PONDERADO:
        insert_in(lista, node2, node1, weight);
        break;
    default:
        break;
    }
}

int main() {
    int qtt_nodes;
    int qtt_edges;
    int type;

    scanf("%d %d %d", &qtt_nodes, &qtt_edges, &type);
    Node* lista_adj[qtt_nodes];

    init_lista(lista_adj, qtt_nodes);

    for (int i = 1; i <= qtt_edges; i++) {
        int node1, node2, val;

        if (type == SIMPLES || type == DIRECIONADO)
            scanf("%d %d", &node1, &node2);
        else
            scanf("%d %d %d", &node1, &node2, &val);

        populate_list(lista_adj, node1 - 1, node2 - 1, type, val);
    }

    print_lista(lista_adj, qtt_nodes);
    print_degrees(lista_adj, qtt_nodes);
    check_isolated_node(lista_adj, qtt_nodes);
    check_loops(lista_adj, qtt_nodes);
}
