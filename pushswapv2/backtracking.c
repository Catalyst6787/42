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
	if (br->st_a)
	{
		free_lst(br->st_a);
		//free(br->st_a);
	}
	if (br->st_b)
	{
		free_lst(br->st_b);
		//free(br->st_b);
	}
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
}
/*
void	branch_out(t_tree **prev, t_tree **branch, t_stack **st_a, t_stack **st_b, int lvl, int max)
{
	if (lvl >= max)
		return ;
	ft_printf("%d\n", lvl);
	t_tree	*br;
	br = malloc(sizeof(t_tree)); // MOVING BR -> TREE IS EMPTY MUST REWRITE FUCNTION
	branch = &br;

	//t_tree *br;
	br = *branch;
	t_stack *st_a_pa = NULL;
	t_stack *st_b_pa = NULL;
	t_stack *st_a_pb = NULL;
	t_stack *st_b_pb = NULL;

	br->lvl = lvl;
	br->st_a = st_a;
	br->st_b = st_b;
	br->diff = get_tot_diff(br->st_a, br->st_b);
	br->prev = prev;

	if (*st_a)
		branch_out(branch, br->sa, swap(lst_copy_new(st_a)), lst_copy_new(st_b), lvl + 1, max);
	else
		br->sa = NULL;
	if (*st_b)
		branch_out(branch, br->sb, lst_copy_new(st_a), swap(lst_copy_new(st_b)), lvl + 1, max);
	else
		br->sb = NULL;
	if (*st_a && *st_b)
		branch_out(branch, br->ss, swap(lst_copy_new(st_a)), swap(lst_copy_new(st_b)), lvl + 1, max);
	else
		br->ss = NULL;
	if (*st_b)
	{
		lst_copy(st_b, &st_b_pa);
		lst_copy(st_a, &st_a_pa);
		push(&st_b_pa, &st_a_pa);
		branch_out(branch, br->pa, &st_a_pa, &st_b_pa, lvl + 1, max);
	}
	else
		br->pa = NULL;
	if (*st_a)
	{
		lst_copy(st_a, &st_a_pb);
		lst_copy(st_b, &st_b_pb);
		push(&st_a_pb, &st_b_pb);
		branch_out(branch, br->pb, &st_a_pb, &st_b_pb, lvl + 1, max);
	}
	else
		br->pa = NULL;
	if (*st_a)
		branch_out(branch, br->ra, rotate(lst_copy_new(st_a)), lst_copy_new(st_b), lvl + 1, max);
	else
		br->ra = NULL;
	if (*st_b)
		branch_out(branch, br->rb, lst_copy_new(st_a), rotate(lst_copy_new(st_b)), lvl + 1, max);
	else
		br->rb = NULL;
	if (*st_a && *st_b)
		branch_out(branch, br->rr, rotate(lst_copy_new(st_a)), rotate(lst_copy_new(st_b)), lvl + 1, max);
	else
		br->rr = NULL;
	if (*st_a)
		branch_out(branch, br->rra, rev_rotate(lst_copy_new(st_a)), lst_copy_new(st_b), lvl + 1, max);
	else
		br->ra = NULL;
	if (*st_b)
		branch_out(branch, br->rrb, lst_copy_new(st_a), rev_rotate(lst_copy_new(st_b)), lvl + 1, max);
	else
		br->rb = NULL;
	if (*st_a && *st_b)
		branch_out(branch, br->rrr, rev_rotate(lst_copy_new(st_a)), rev_rotate(lst_copy_new(st_b)), lvl + 1, max);
	else
		br->rr = NULL;
}
*/

t_tree	**init_branch(t_tree **prev, t_stack **st_a, t_stack **st_b)
{
	t_tree **branch;

	branch = malloc(sizeof(t_tree *));
	*branch = malloc(sizeof(t_tree));
	if (!branch || !(*branch))
		return (NULL);

	if (!(prev))
		(*branch)->lvl = 0;
	else
		(*branch)->lvl = (*prev)->lvl + 1;
	(*branch)->prev = prev;
	(*branch)->st_a = st_a;
	(*branch)->st_b = st_b;
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

void	branch_out(t_tree **branch, int max)
{
	t_tree *br;

	if (!branch || !(*branch))
		return ;
	br = *branch;
	if (max <= br->lvl)
		return ;
	ft_printf("level :%d max: %d\n", br->lvl, max);
	t_stack **st_pb_a;
	t_stack **st_pb_b;

	t_stack **st_pa_a;
	t_stack **st_pa_b;

	st_pb_a = NULL;
	st_pb_b = NULL;
	st_pa_a = NULL;
	st_pa_b = NULL;

	if (br->st_a)
	{
		br->sa = init_branch(branch, swap(lst_copy_new(br->st_a)), lst_copy_new(br->st_b));
		st_pb_a = lst_copy_new(br->st_a);
		st_pb_b = lst_copy_new(br->st_b);
		push(st_pb_a, st_pb_b);
		br->pb = init_branch(branch, st_pb_a, st_pb_b);
		br->ra = init_branch(branch, rotate(lst_copy_new(br->st_a)), lst_copy_new(br->st_b));
		br->rra = init_branch(branch, rev_rotate(lst_copy_new(br->st_a)), lst_copy_new(br->st_b));

	}
	if (br->st_b)
	{
		br->sb = init_branch(branch, lst_copy_new(br->st_a), swap(lst_copy_new(br->st_b)));
		st_pb_a = lst_copy_new(br->st_a);
		st_pb_b = lst_copy_new(br->st_b);
		push(st_pa_b, st_pa_a);
		br->pb = init_branch(branch, st_pa_a, st_pa_b);
		br->rb = init_branch(branch, lst_copy_new(br->st_a), rotate(lst_copy_new(br->st_b)));
		br->rrb = init_branch(branch, lst_copy_new(br->st_a), rev_rotate(lst_copy_new(br->st_b)));
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
/*
t_tree **get_best_branch(t_tree **branch)
{
	t_tree *br;
	t_tree *smallest;

	smallest = NULL;
	br = *branch;
	if (!br)
		return(NULL);
	if (br->diff = 0)
		return(branch);
	if (br->sa && br->sa->diff && (!smallest || br->sa->diff < smallest->diff))
		smallest = br->sa;
	if (br->sb && br->sb->diff && (!smallest || br->sb->diff < smallest->diff))
		smallest = br->sb;
	if (br->ss && br->ss->diff && (!smallest || br->ss->diff < smallest->diff))
		smallest = br->ss;
	if (br->pa && br->pa->diff && (!smallest || br->pa->diff < smallest->diff))
		smallest = br->pa;
	if (br->pb && br->pb->diff && (!smallest || br->pb->diff < smallest->diff))
		smallest = br->pb;
	if (br->ra && br->ra->diff && (!smallest || br->ra->diff < smallest->diff))
		smallest = br->ra;
	if (br->rb && br->rb->diff && (!smallest || br->rb->diff < smallest->diff))
		smallest = br->rb;
	if (br->rr && br->rr->diff && (!smallest || br->rr->diff < smallest->diff))
		smallest = br->rr;
	if (br->rra && br->rra->diff && (!smallest || br->rra->diff < smallest->diff))
		smallest = br->rra;
	if (br->rrb && br->rrb->diff && (!smallest || br->rrb->diff < smallest->diff))
		smallest = br->rrb;
	if (br->rrr && br->rrr->diff && (!smallest || br->rrr->diff < smallest->diff))
		smallest = br->rrr;
	return(smallest);
}
*/

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
	if (!br || !(br->st_a) || !(br->st_b))
		ft_printf("\nerror printing branch\n");
	else
	{
		ft_printf("Branch level: %d\n", br->lvl);
		ft_printf("st_a:\n");
		print_lst(br->st_a);
		ft_printf("st_b:\n");
		print_lst(br->st_b);
	}
}
