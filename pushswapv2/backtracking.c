#include "header.h"

static int	get_abs(int nbr)
{
	if (nbr < 0)
		return(-nbr);
	else
		return(nbr);
}

int	get_diff_a(t_stack **st)
{
	int totdiff;
	t_stack	*tail;
	
	if (!st || !(*st))
		return(0);
	tail = *st;
	totdiff = 0;
	while(tail)
	{
		totdiff += get_abs(tail->id - tail->optid);
		tail = tail->next;
	}
	return(totdiff);
}

int	get_diff_b(t_stack **st)
{
	int totdiff;
	int listsize;
	t_stack	*tail;
	
	if (!st || !(*st))
		return(0);
	listsize = size_list(st);
	tail = *st;
	totdiff = 0;
	while(tail)
	{
		totdiff += get_abs((listsize - tail->id - 1) - tail->optid);
		tail = tail->next;
	}
	return(totdiff);
}

int get_tot_diff(t_stack **st_a, t_stack **st_b)
{
	int diff_a;
	int diff_b;

	diff_a = get_diff_a(st_a);
	diff_b = get_diff_b(st_b);

	return(diff_a + diff_b);
}

void	init_tree(t_tree **root, t_stack **st_a, t_stack **st_b)
{
	(*root) = malloc(sizeof(t_tree));
	if (!(*root))
		return ;
	(*root)->lvl = 0;
	(*root)->prev = NULL;
	(*root)->st_a = st_a;
	(*root)->st_b = st_b;
	(*root)->diff = get_tot_diff(st_a, st_b);
	(*root)->sa = NULL;
	(*root)->sb = NULL;
	(*root)->ss = NULL;
	(*root)->pa = NULL;
	(*root)->pb = NULL;
	(*root)->ra = NULL;
	(*root)->rb = NULL;
	(*root)->rr = NULL;
	(*root)->rra = NULL;
	(*root)->rrb = NULL;
	(*root)->rrr = NULL;
}

void	free_tree(t_tree **branch)
{
	t_tree *br;

	if (!branch || !(*branch))
		return ;
	br = *branch;
	//if (br->st_a)
	free_lst(br->st_a);
	br->st_a = NULL;
	//if (br->st_b)
	free_lst(br->st_b);
	br->st_b = NULL;
	free_tree(br->sa);
	free_tree(br->sb);
	free_tree(br->ss);
	free_tree(br->pa);
	free_tree(br->pb);
	free_tree(br->ra);
	free_tree(br->rb);
	free_tree(br->rr);
	free_tree(br->rra);
	free_tree(br->rrb);
	free_tree(br->rrr);

	free(*branch);
	(*branch) = NULL;
	free(branch);
	branch = NULL;
}


t_tree	**init_branch(t_tree **prev, t_stack **st_a, t_stack **st_b)
{
	t_tree **branch;

	branch = malloc(sizeof(t_tree *));
	if (!branch)
		return(NULL);
	*branch = malloc(sizeof(t_tree));
	if (!(*branch))
		return (NULL);
	if (!(prev))
		(*branch)->lvl = 0;
	else
		(*branch)->lvl = (*prev)->lvl + 1;
	(*branch)->prev = prev;
	if (st_a)
		(*branch)->st_a = st_a;
	else
		(*branch)->st_a = NULL;
	if (st_b)
		(*branch)->st_b = st_b;
	else
		(*branch)->st_b = NULL;
	(*branch)->diff = get_tot_diff(st_a, st_b);
	(*branch)->sa = NULL;
	(*branch)->sb = NULL;
	(*branch)->ss = NULL;
	(*branch)->pa = NULL;
	(*branch)->pb = NULL;
	(*branch)->ra = NULL;
	(*branch)->rb = NULL;
	(*branch)->rr = NULL;
	(*branch)->rra = NULL;
	(*branch)->rrb = NULL;
	(*branch)->rrr = NULL;
	return(branch);
}

static void	call_br_out(t_tree **branch, int max)
{
	t_tree *br;

	if (!branch)
		return;
	if (!(*branch))
		return;
	br = *branch;

	branch_out(br->sa, max);
	branch_out(br->sb, max);
	branch_out(br->ss, max);
	branch_out(br->pa, max);
	branch_out(br->pb, max);
	branch_out(br->ra, max);
	branch_out(br->rb, max);
	branch_out(br->rr, max);
	branch_out(br->rra, max);
	branch_out(br->rrb, max);
	branch_out(br->rrr, max);
}

static int branch_exists_and_empty(t_tree **branch)
{
	t_tree *br;
	if (!branch || !(*branch))
		return(0);
	br = *branch;
	if (br->sa)
		return(0);
	if (br->sb)
		return(0);
	if (br->ss)
		return(0);
	if (br->pa)
		return(0);
	if (br->pb)
		return(0);
	if (br->ra)
		return(0);
	if (br->rb)
		return(0);
	if (br->rr)
		return(0);
	if (br->rra)
		return(0);
	if (br->rrb)
		return(0);
	if (br->rrb)
		return(0);
	return(1);
}

void	branch_out(t_tree **branch, int max)
{
	t_tree *br;

	if (!branch || !(*branch))
		return ;
	if (!branch_exists_and_empty(branch))
		return ;
	br = *branch;
	if (max <= br->lvl)
		return ;
	ft_printf("level :%d max: %d\n", br->lvl, max);
	t_stack **st_pb_a;
	t_stack **st_pb_b;

	t_stack **st_pa_a;
	t_stack **st_pa_b;

	st_pb_a = lst_copy_new(br->st_a);
	st_pb_b = lst_copy_new(br->st_b);
	st_pa_a = lst_copy_new(br->st_a);
	st_pa_b = lst_copy_new(br->st_b);

	if (br->st_a)
	{
		br->sa = init_branch(branch, swap(lst_copy_new(br->st_a)), lst_copy_new(br->st_b));
		push(st_pb_a, st_pb_b);
		br->pb = init_branch(branch, st_pb_a, st_pb_b);
		br->ra = init_branch(branch, rotate(lst_copy_new(br->st_a)), lst_copy_new(br->st_b));
		br->rra = init_branch(branch, rev_rotate(lst_copy_new(br->st_a)), lst_copy_new(br->st_b));

	}
	else
	{
		free_lst(st_pb_a);
		free_lst(st_pb_b);
	}
	if (br->st_b)
	{
		br->sb = init_branch(branch, lst_copy_new(br->st_a), swap(lst_copy_new(br->st_b)));
		push(st_pa_b, st_pa_a);
		br->pb = init_branch(branch, st_pa_a, st_pa_b);
		br->rb = init_branch(branch, lst_copy_new(br->st_a), rotate(lst_copy_new(br->st_b)));
		br->rrb = init_branch(branch, lst_copy_new(br->st_a), rev_rotate(lst_copy_new(br->st_b)));
	}
	else
	{
		free_lst(st_pa_a);
		free_lst(st_pa_b);
	}
	if (br->st_a && br->st_b)
	{
		br->ss = init_branch(branch, swap(lst_copy_new(br->st_a)), swap(lst_copy_new(br->st_b)));
		br->rr = init_branch(branch, rotate(lst_copy_new(br->st_a)), rotate(lst_copy_new(br->st_b)));
		br->rrr = init_branch(branch, rev_rotate(lst_copy_new(br->st_a)), rev_rotate(lst_copy_new(br->st_b)));
	}
	if (br->lvl < max)
		call_br_out(branch, max);
}

static t_tree	**is_smallest(t_tree **branch, t_tree **smallest)
{
	t_tree **tmp;

	if (!branch || !(*branch))
		return (smallest) ;
	tmp = (get_best_branch(branch));
	if (!tmp || !(*tmp))
		return (smallest);
	if (tmp && !smallest)
		smallest = tmp;
	else if ((*tmp && !(*smallest)) || (*tmp && ((*tmp)->diff < (*smallest)->diff)))
		(*smallest) = *tmp;
	return (smallest);
}

t_tree **get_best_branch(t_tree **branch)
{
	t_tree *br;
	t_tree **smallest;

	smallest = NULL;
	if (!branch)
		return(NULL);
	br = *branch;
	if (!br)
		return(NULL);
	if (br->diff == 0)
		return(branch);

	smallest = is_smallest(br->sa, smallest);
	smallest = is_smallest(br->sb, smallest);
	smallest = is_smallest(br->ss, smallest);
	smallest = is_smallest(br->pa, smallest);
	smallest = is_smallest(br->pb, smallest);
	smallest = is_smallest(br->ra, smallest);
	smallest = is_smallest(br->rb, smallest);
	smallest = is_smallest(br->rr, smallest);
	smallest = is_smallest(br->rra, smallest);
	smallest = is_smallest(br->rrb, smallest);
	smallest = is_smallest(br->rrr, smallest);
	
	return(smallest);
}

void	print_branch(t_tree **branch)
{
	t_tree *br;
	if (!branch || !(*branch))
		return ;
	br = *branch;
	if (!br || !(br->st_a))
		ft_printf("\nerror printing branch\n");
	else
	{
		ft_printf("Branch level: %d\n", br->lvl);
		ft_printf("st_a:\n");
		if (br->st_a)
			print_lst(br->st_a);
		ft_printf("st_b:\n");
		if (br->st_b)
			print_lst(br->st_b);
	}
}
