#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
    int info;
    struct linked_list *prev_node, *next_node;
} l_list;

l_list* l_list_init(int item) {
    l_list *newNode;
    newNode = malloc(sizeof(l_list));
    *newNode = (l_list){.info = item, .prev_node = NULL, .next_node = NULL};
    return newNode;
}

l_list* append(l_list* head, int data) {
    l_list* newNode = l_list_init(data);
    if (head == NULL) {
        return newNode;
    }
    l_list* temp = head;
    while (temp->next_node) {
        temp = temp->next_node;
    }
    temp->next_node = newNode;
    newNode->prev_node = temp;
    return head;
}

void print_list(l_list* head) {
    l_list* temp = head;
    while (temp) {
        printf("%d ", temp->info);
        temp = temp->next_node;
    }
    printf("\n");
}

void free_list(l_list** head) {
    l_list* temp;
    while (*head) {
        temp = *head;
        *head = (*head)->next_node;
        free(temp);
    }
    *head = NULL;
}

void shaker_sort(l_list** head) {
    if (*head == NULL || (*head)->next_node == NULL) return;

    int swapped;
    l_list *start = *head, *end = NULL;

    end = *head;
    while (end->next_node) {
        end = end->next_node;
    }

    swapped = 1;
    while (swapped) {
        swapped = 0;

        l_list* currentNode = start;
        while (currentNode != end) {
            if (currentNode->info > currentNode->next_node->info) {
                int temp = currentNode->info;
                currentNode->info = currentNode->next_node->info;
                currentNode->next_node->info = temp;
                swapped = 1;
            }
            currentNode = currentNode->next_node;
        }

        if (!swapped) break;

        end = end->prev_node;
        swapped = 0;

        currentNode = end;
        while (currentNode != start) {
            if (currentNode->info < currentNode->prev_node->info) {
                int temp = currentNode->info;
                currentNode->info = currentNode->prev_node->info;
                currentNode->prev_node->info = temp;
                swapped = 1;
            }
            currentNode = currentNode->prev_node;
        }

        start = start->next_node;
    }
}

int main() {
    l_list* head = NULL;
    int n, value;
    
    printf("Enter the number of list items: ");
    scanf("%d", &n);
    
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = append(head, value);
    }
        
    printf("List before sorting: ");
    print_list(head);

    shaker_sort(&head);
    
    printf("List after sorting: ");
    print_list(head);
    
    free_list(&head);

    printf("List after freeing memory: ");
    print_list(head);

    return 0;
}
