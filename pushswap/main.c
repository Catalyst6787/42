/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:17:31 by lfaure            #+#    #+#             */
/*   Updated: 2024/11/25 13:27:55 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_stack	*lst_new(int content)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->nbr = content;
	elem->next = NULL;
	return (elem);
}

t_stack	*lst_add_back(t_stack *list, t_stack *elem)
{
	if (!list)
		return (elem);
	while(list->next)
	{
		list = list->next;
	}
	list->next = elem;
	return (list);
}
void free_list(t_stack *list)
{
    t_stack *tmp;
    while (list)
    {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}
void print_list(t_stack *list)
{
    while (list)
    {
        printf("%d -> ", list->nbr);
        list = list->next;
    }
    printf("NULL\n");
}

int	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
		return (ft_printf("Not enough arguments"), 0);
	t_stack	*st_a;
	st_a = lst_new(atoi(av[1]));
	if (!st_a)
		return (printf("Memory allocation failed\n"), 0);
	i = 2;
	while (av[i])
	{
		lst_add_back(st_a, lst_new(ft_atoi(av[i])));
		i++;
	}
	print_list(st_a);
	free_list(st_a);
	return (1);
}
