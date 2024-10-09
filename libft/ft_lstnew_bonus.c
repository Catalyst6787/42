#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Test case 1: Create a node with an integer
    int *int_content = malloc(sizeof(int));
    *int_content = 42;
    t_list *int_node = ft_lstnew(int_content);
    
    if (int_node) {
        printf("Node created with int content: %d\n", *(int *)int_node->content);
    } else {
        printf("Failed to create node with int content.\n");
    }

    // Test case 2: Create a node with a string
    char *str_content = ft_strdup("Hello, world!");
    t_list *str_node = ft_lstnew(str_content);
    
    if (str_node) {
        printf("Node created with string content: %s\n", (char *)str_node->content);
    } else {
        printf("Failed to create node with string content.\n");
    }

    // Test case 3: Create a node with NULL content
    t_list *null_node = ft_lstnew(NULL);
    
    if (null_node) {
        printf("Node created with NULL content.\n");
    } else {
        printf("Failed to create node with NULL content.\n");
    }

    // Cleanup
    free(int_node->content);
    free(int_node);
    free(str_node->content);
    free(str_node);
    free(null_node);

    return 0;
}
*/
