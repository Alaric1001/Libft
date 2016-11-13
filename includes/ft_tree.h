/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 12:52:18 by asenat            #+#    #+#             */
/*   Updated: 2017/03/14 10:29:29 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_H
# define FT_TREE_H

typedef	struct	s_tree
{
	void			*value;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

t_tree			*ft_tnewnode(void *val);
void			ft_tdelone(t_tree **tree, void (*del)(void*));
void			ft_tdel(t_tree **tree, void (*del)(void*));
void			ft_taddnode(t_tree **tree, t_tree *node);
void			ft_taddrnode(t_tree **tree, t_tree *node);

#endif
