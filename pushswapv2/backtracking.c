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
	return(get_diff_a(st_a) + get_diff_b(st_b));
}

int init_tree(t_tree **root, t_stack **st_a, t_stack **st_b)
{
	(*root)->level = 0;
	//(*root)->root = NULL;
	(*root)->st_a = *st_a;
	(*root)->st_b = *st_b;
	(*root)->diff = 0;
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

	br = *branch;
	if (!br)
		return ;
	if (br->st_a)
		free_lst(br->st_a);
	if (br->st_b)
		free_lst(br->st_b);
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

void	branch_out(t_tree **branch, t_stack **st_a, t_stack **st_b, int lvl, int max)
{
	t_tree *br;
	br = *branch;

	t_stack *st_a_pa;
	t_stack *st_b_pa;
	t_stack *st_a_pb;
	t_stack *st_b_pb;

	br->level = lvl;
	br->st_a = st_a;
	br->st_b = st_b;
	br->diff = get_tot_diff(br->st_a, br->st_b);

	if (lvl >= max)
		return ;
	if (st_a)
		branch_out(br->sa, swap(lst_copy_new(br->st_a)), st_b, lvl++, max);
	else
		br->sa = NULL;
	if (st_b)
		branch_out(br->sb, st_a, swap(lst_copy_new(br->st_b)), lvl++, max);
	else
		br->sb = NULL;
	if (st_a && st_b)
		branch_out(br->ss, swap(lst_copy_new(br->st_a)), swap(lst_copy_new(br->st_b)), lvl++, max);
	else
		br->ss = NULL;
	if (st_b)
	{
		push(lst_copy(st_b, st_b_pa), lst_copy(st_a, st_a_pa));
		branch_out(br->pa, st_a_pa, st_b_pa, lvl++, max);
	}
	else
		br->pa = NULL;
	if (st_a)
	{
		push(lst_copy(st_a, st_a_pb), lst_copy(st_b, st_b_pb));
		branch_out(br->pb, st_a_pb, st_b_pb, lvl++, max);
	}
	else
		br->pa = NULL;
	if (st_a)
		branch_out(br->ra, rotate(lst_copy_new(st_a)), st_b, lvl++, max);
	else
		br->ra = NULL;
	if (st_b)
		branch_out(br->rb, st_a, rotate(lst_copy_new(st_b)), lvl++, max);
	else
		br->rb = NULL;
	if (st_a && st_b)
		branch_out(br->rr, rotate(lst_copy_new(st_a)), rotate(lst_copy_new(st_b)), lvl++, max);
	else
		br->rr = NULL;
	if (st_a)
		branch_out(br->rra, rev_rotate(lst_copy_new(st_a)), st_b, lvl++, max);
	else
		br->ra = NULL;
	if (st_b)
		branch_out(br->rrb, st_a, rev_rotate(lst_copy_new(st_b)), lvl++, max);
	else
		br->rb = NULL;
	if (st_a && st_b)
		branch_out(br->rrr, rev_rotate(lst_copy_new(st_a)), rev_rotate(lst_copy_new(st_b)), lvl++, max);
	else
		br->rr = NULL;
}

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
