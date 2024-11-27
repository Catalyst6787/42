#include "header.h"

int swap_sort(t_stack **st_a, t_stack **st_b)
{
	if (!(*st_a))
		return(0);
	while (*st_a)
	{
		if (is_highest(*st_a, (*st_a)->nbr))
		{
			ft_printf("pb\n");
			push(st_a, st_b);
			//ft_printf("st_a: ");
			//print_list(*st_a);
			//ft_printf("st_b: ");
			//print_list(*st_b);
			ft_printf("rb\n");
			rotate(*st_b);
			//ft_printf("st_a: ");
			//print_list(*st_a);
			//ft_printf("st_b: ");
			//print_list(*st_b);
		}
		else if (is_lowest(*st_a, (*st_a)->nbr))
		{
			ft_printf("pb\n");
			push(st_a, st_b);
			//ft_printf("st_a: ");
			//print_list(*st_a);
			//ft_printf("st_b: ");
			//print_list(*st_b);
		}
		else 
		{
			ft_printf("ra\n");
			rotate(*st_a);
			//ft_printf("st_a: ");
			//print_list(*st_a);
			//ft_printf("st_b: ");
			//print_list(*st_b);
		}
	}
	//ft_printf("ALIGN\n");
	align(st_b);
	//ft_printf("st_a: ");
	//print_list(*st_a);
	//ft_printf("st_b: ");
	//print_list(*st_b);
	while(*st_b)
	{
		ft_printf("pa\n");
		push(st_b, st_a);
		//ft_printf("st_a: ");
		//print_list(*st_a);
		//ft_printf("st_b: ");
		//print_list(*st_b);
	}
	return(1);
}

int	dmb_sort(t_stack **st_a)
{
	t_stack *tail;

	tail = *st_a;

	if (!(*st_a))
		return(0);
	while (tail && !check_sort(*st_a))
	{
		while(tail->next)
		{
			if (tail->nbr > tail->next->nbr)
			{
				ft_printf("sa\n");
				swap(*st_a);
			}
			ft_printf("ra\n");
			if (is_highest((*st_a), tail->nbr))
				rotate(*st_a);
			rotate(*st_a);
		}
	}
	return(1);
}