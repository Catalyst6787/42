#include "header.h"

void	push_a(t_tree *prev, t_tree **br)
{
	int i;

	i = 1;
	(*br)->size_a = prev->size_a + 1;
	(*br)->st_a = malloc(sizeof(int) * ((*br)->size_a));
	(*br)->st_a[0] = prev->st_b[0];
	while(i < (*br)->size_a)
	{
		(*br)->st_a[i] = prev->st_a[i - 1];
		i++;
	}

	i = 0;
	(*br)->size_b = prev->size_b - 1;
	if ((*br)->size_b == 0)
		return ((void)((*br)->st_b == NULL));
	(*br)->st_b = malloc(sizeof(int) * ((*br)->size_b));
	while(i < (*br)->size_b)
	{
		(*br)->st_b[i] = prev->st_b[i + 1];
		i++;
	}
}

void	push_a_optid(t_tree *prev, t_tree **br)
{
	int i;

	i = 1;
	(*br)->size_a = prev->size_a + 1;
	(*br)->st_a_optid = malloc(sizeof(int) * ((*br)->size_a));
	(*br)->st_a_optid[0] = prev->st_b_optid[0];
	while(i < (*br)->size_a)
	{
		(*br)->st_a_optid[i] = prev->st_a_optid[i - 1];
		i++;
	}

	i = 0;
	(*br)->size_b = prev->size_b - 1;
	if ((*br)->size_b == 0)
		return ((void)((*br)->st_b_optid == NULL));
	(*br)->st_b_optid = malloc(sizeof(int) * ((*br)->size_b));
	while(i < (*br)->size_b)
	{
		(*br)->st_b_optid[i] = prev->st_b_optid[i + 1];
		i++;
	}
}

void	push_b(t_tree *prev, t_tree **br)
{
	int i;

	i = 1;
	(*br)->size_b = prev->size_b + 1;
	(*br)->st_b = malloc(sizeof(int) * ((*br)->size_b));
	(*br)->st_b[0] = prev->st_a[0];
	while(i < (*br)->size_b)
	{
		(*br)->st_b[i] = prev->st_b[i - 1];
		i++;
	}

	i = 0;
	(*br)->size_a = prev->size_a - 1;
	if ((*br)->size_a == 0)
		return ((void)((*br)->st_a == NULL));
	(*br)->st_a = malloc(sizeof(int) * ((*br)->size_a));
	while(i < (*br)->size_a)
	{
		(*br)->st_a[i] = prev->st_a[i + 1];
		i++;
	}
}

void	push_b_optid(t_tree *prev, t_tree **br)
{
	int i;

	i = 1;
	(*br)->size_b = prev->size_b + 1;
	(*br)->st_b_optid = malloc(sizeof(int) * ((*br)->size_b));
	(*br)->st_b_optid[0] = prev->st_a_optid[0];
	while(i < (*br)->size_b)
	{
		(*br)->st_b_optid[i] = prev->st_b_optid[i - 1];
		i++;
	}

	i = 0;
	(*br)->size_a = prev->size_a - 1;
	if ((*br)->size_a == 0)
		return ((void)((*br)->st_a_optid == NULL));
	(*br)->st_a_optid = malloc(sizeof(int) * ((*br)->size_a));
	while(i < (*br)->size_a)
	{
		(*br)->st_a_optid[i] = prev->st_a_optid[i + 1];
		i++;
	}
}