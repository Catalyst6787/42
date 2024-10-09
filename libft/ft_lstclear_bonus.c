#include "libft.h"

void	ft_lstdone(t_list **lst, void (*del) (void *))
{
	del(lst->content);
}
