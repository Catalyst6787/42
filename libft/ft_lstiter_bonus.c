#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (void *))
{
	while(lst->next)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>
// Example function to apply to each list element
void increment(void *data)
{
    int *value = (int *)data;
    (*value)++;
}

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d ", *(int *)(lst->content));
        lst = lst->next;
    }
    printf("\n");
}

int main()
{
    // Create a sample linked list: 1 -> 2 -> 3
    t_list *list = ft_lstnew(&(int){1});
    list->next = ft_lstnew(&(int){2});
    list->next->next = ft_lstnew(&(int){3});

    printf("Original list: ");
    print_list(list);

    // Apply increment function to each element
    ft_lstiter(list, increment);

    printf("Modified list: ");
    print_list(list);

    // Free the list (implement free_list function if necessary)

    return 0;
}
*/
