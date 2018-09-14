/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szverhov <szverhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:31:43 by szverhov          #+#    #+#             */
/*   Updated: 2017/11/03 12:23:59 by szverhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "get_next_line.h"
# include "ft_printf.h"
# include <stdlib.h>

struct s_links;

struct s_vars;

char				*g_str;

int					g_err;
int					g_err2;
struct s_vars		g_vars;
int					g_iters;

typedef	struct		s_vars
{
	int				ants;
	char			*tmp;
	int				i;
}					t_vars;

typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	int				count_ants;
	int				start_r_end;
	int				was;
	struct s_rooms	*from;
	struct s_rooms	*next;
	struct s_links	*links;
}					t_rooms;

typedef struct		s_links
{
	char			*name;
	struct s_rooms	*room;
	struct s_links	*next;
}					t_links;

int					ft_atoi(const char *str);
int					ft_is_it_int(char *str);
int					ft_init_first(t_rooms **start,
	char *str, int count_of_ants);
int					ft_add_rooms(t_rooms **start, char *str, int count_of_ants);
char				*ft_sub_str(char *str, char end);
int					ft_check_double_space(char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_clean_nest(t_rooms **nest);
int					ft_read_links_of_ant_nest(t_rooms **nest, char *tmp);
int					ft_make_ant_nest(t_rooms **nest);
char				*ft_inner_substr(char *str, char end);
int					ft_give_me_count_ants(t_rooms *start);
int					ft_move_ants(t_rooms *start);
void				ft_lem_in(void);
int					ft_if_i_zero(char *tmp, int *i, int *ants);
int					ft_inner_coments(t_rooms **nest, char **tmp,
	int i, int ants);
int					ft_inner_l_strt_end(char **tmp, int *i, int *ants);
int					ft_chck_double_spaces(t_rooms **nest, char **tmp);
void				ft_add_to_gstr(char *str);
int					ft_inner_check_d_spaces(t_rooms **nest, char **tmp);
void				ft_start_to_head(t_rooms **start);
void				ft_end_to_tail(t_rooms **end);
void				ft_find_path(t_rooms *start, t_links *link);
int					ft_make_path(t_rooms *start);
int					ft_inner_start_end(char **tmp);
int					ft_start_room(t_rooms **nest, char **tmp, int ants, int *i);
int					ft_end_room(t_rooms **nest, char **tmp, int *i);
int					ft_check_exist_of_start(t_rooms **nest);
int					ft_check_exist_of_end(t_rooms **nest);
int					ft_in_inner_coments(char **tmp);
int					ft_free_return_zero(char **tmp);
char				*ft_itoa(int n);
int					ft_check_start_end(t_rooms *nest);
int					ft_coords(char *str);
int					ft_there_is_space(char *str1, char *str2);
int					ft_coords(char *str);
int					ft_find_links(t_rooms **start, char *name);
int					ft_init_names(char *tmp, char **name1, char **name2);
int					ft_count_of_minuses(char *tmp);
char				*ft_inner_substr(char *str, char end);
int					ft_link_it(t_rooms **from, t_rooms **to, char *name1);
int					ft_check_is_linked(t_rooms *from, t_rooms *to);
int					ft_linking(t_rooms **nest, char *name1, char *name2);
int					ft_try_to_link(t_rooms **nest, char *tmp);
int					ft_check_and_link(t_rooms **nest, char *tmp);
int					ft_init_start_room(t_rooms **nest,
	char **tmp, int *i, int ants);
int					ft_init_end_room(t_rooms **nest, char **tmp, int *i);
int					ft_check_pipe(char *tmp);
int					stop_reading(char *tmp);
void				ft_free_strs(char **str1, char **str2);
int					ft_return_1(char **tmp);

#endif
