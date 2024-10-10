#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;
	if (!new)
		return ;
	last = (ft_lstlast(*lst));
	if (!last)
		*lst = new;
	else
		last->next = new;
}
/*
#include <stdio.h>
#include <stdlib.h>

// Function to create a new list element
t_list *create_node(int value) {
    t_list *node = malloc(sizeof(t_list));
    if (!node) return NULL;
    node->content = malloc(sizeof(int)); // assuming content is an int
    *(int *)(node->content) = value;
    node->next = NULL;
    return node;
}

// Function to print the list
void print_list(t_list *lst) {
    while (lst) {
        printf("%d -> ", *(int *)(lst->content));
        lst = lst->next;
    }
    printf("NULL\n");
}

int main() {
    t_list *list = NULL;

    // Test case 1: Adding an element to an empty list
    printf("Test Case 1: Adding to empty list\n");
    ft_lstadd_back(&list, create_node(1));
    print_list(list);

    // Test case 2: Normal usage, adding an element to the end of the list
    printf("Test Case 2: Adding element to the end of the list\n");
    ft_lstadd_back(&list, create_node(2));
    print_list(list);

    // Test case 3: Adding an empty element to the list
    printf("Test Case 3: Adding empty element to the list\n");
    ft_lstadd_back(&list, NULL);  // This should cause a segfault if not handled
    print_list(list);  // If no segfault occurs, print the list

    // Test case 4: Adding an empty element to an empty list
    printf("Test Case 4: Adding empty element to an empty list\n");
    t_list *new_list = NULL;
    ft_lstadd_back(&new_list, NULL);  // This should also cause a segfault if not handled
    print_list(new_list);  // If no segfault occurs, print the list

    // Free allocated memory
    // Note: Ensure to free nodes if they were created and added to the list
    // Not shown here for brevity.

    return 0;
}
*/
