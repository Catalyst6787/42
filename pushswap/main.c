/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lfaure <lfaure@student.42lausanne.ch>	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/22 16:17:31 by lfaure			#+#	#+#			 */
/*   Updated: 2024/11/25 13:56:14 by lfaure		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
		return (ft_printf("Not enough arguments"), 0);
	t_stack	*st_og;
	st_og = lst_new(atoi(av[1]));
	if (!st_og)
		return (printf("Memory allocation failed\n"), 0);
	i = 2;
	while (av[i])
	{
		lst_add_back(st_og, lst_new(ft_atoi(av[i])));
		i++;
	}
	t_stack *st_a = copy_list(st_og);
	t_stack *st_b = NULL;
	
	push(&st_a, &st_b);

	ft_printf("st_og:\n");
	print_list(st_og);
	ft_printf("st_a:\n");
	print_list(st_a);
	ft_printf("st_b:\n");
	print_list(st_b);

	free_list(st_og);
	free_list(st_a);
	free_list(st_b);
	return (1);
}
