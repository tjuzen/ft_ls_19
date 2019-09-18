/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:02:04 by tjuzen            #+#    #+#             */
/*   Updated: 2019/09/17 20:54:21 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <limits.h>

/*
** Code couleur pour fichiers, dossiers et exec
*/

# define BLACK    "\033[1;30m"
# define RED      "\033[1;31m"
# define GREEN    "\033[1;32m"
# define YELLOW   "\033[1;33m"
# define BLUE     "\033[1;34m"
# define PURPLE   "\033[1;35m"
# define CYAN     "\033[1;36m"
# define GREY     "\033[1;37m"
# define DEFAULT_COLOR "\033[0;m"

/*
** Définition de mes structures
*/

typedef	struct	s_arg_ls
{
	int				is_l;
	int				is_rr;
	int				is_a;
	int				is_r;
	int				is_t;
	int				is_n;
	char			*path;
	int				totalsize;
	int				file_printed;
	int				flag_mutiple_folders;
	int				is_in_recu;
	int				malloc_error;
	int				count;
}				t_arg_ls;

typedef	struct	s_arg_lsbig
{
	int			big_hard;
	int			big_pw;
	int			big_gr;
	int			big_size;
	int			big_size_maj;
	int			have_maj_min;
}				t_arg_lsbig;

/*
** Définition d'une liste
*/

typedef struct s_list_ls	t_list_ls;

struct			s_list_ls
{
	char		*file_name;
	char		*file_name_path;
	time_t		date;
	int			is_dir;
	int			hardlinks;
	long long	size;
	char		*pwname;
	char		*grname;
	char		*date_month;
	char		*date_day;
	char		*date_hour_year;
	char		perm[12];
	char		*have_symlink;
	int			major;
	int			minor;
	char		*no_file;
	t_list_ls	*next;
};

/*
** list.c
*/

void			print_list(t_list_ls *mylist);
int				length_int_easy(int x);
void			print_full_list(t_list_ls *mylist, t_arg_ls *arg, int flag);
t_list_ls		*reverse_list(t_list_ls *mylist);
t_list_ls		*add_link_front(t_list_ls *mylist, char *str, t_arg_ls *arg);
int				fill_others(t_list_ls *tmp, struct stat *fs,
				t_arg_ls *arg, char *tmp2);
void			fill_acl(t_list_ls *tmp, struct stat *fs, char *tmp2);
void			fill_perm_right(t_list_ls *tmp, struct stat *fs);
void			fill_perm(t_list_ls *tmp, struct stat *fs);
int				permission_denied(char *path, t_arg_ls *arg,
				int argc, int count_i);
void			fill_major_minor(t_list_ls *tmp, struct stat *fs);

/*
**list_2.c
*/

int				no_file(char **argv, int i, int argc, t_arg_ls *arg);
t_list_ls		*check_sort(t_list_ls *mylist, t_arg_ls *arg);
t_list_ls		*malloc_error(t_arg_ls *arg);
void			print_delete(t_list_ls *mylistfile);

/*
** sort_list.c
*/

t_list_ls		*sort_ascii(t_list_ls *mylist);
t_list_ls		*sort_time(t_list_ls *mylist);
t_list_ls		*add_link_front_dir(t_list_ls *mylistdir, char *str);
t_list_ls		*push(t_list_ls *mylist, t_arg_ls *arg, DIR *d,
					struct dirent *dir);
t_list_ls		*lst_swap(t_list_ls *p1, t_list_ls *p2);

/*
** tools.c
*/

int				ft_strdel_int(char **as);
int				check_point(char *s);
int				check_path(char *str, t_arg_ls *arg);
int				check_arg(char *str, t_arg_ls *arg, int i, int j);
int				init_arg(t_arg_ls *arg);
t_list_ls		*display_my_files(t_list_ls *mylist, t_arg_ls *arg);
t_list_ls		*display_my_dir(t_list_ls *mylist, t_arg_ls *arg);
int				check_options(int i, int argc, char **argv, t_arg_ls *arg);
t_list_ls		*fill_dir(int i, int argc, char **argv, t_arg_ls *arg);
t_list_ls		*fill_file(int i, int argc, char **argv, t_arg_ls *arg);
int				fill_date(struct stat *fs, t_list_ls *tmp);

/*
 ** tools_2
*/

int				free_struct_arg(t_arg_ls *arg, int ret);
int				free_list(t_list_ls *list, int r);
int				free_list_dir(t_list_ls *list, int r);
int				free_list_file(t_list_ls *list, int r);
void			exit_free(t_list_ls *mylistfile,
				t_list_ls *mylistdir, t_arg_ls *arg);
void			init_arg_2(t_arg_lsbig *arg);
void			print_all(t_arg_lsbig *arg2, t_list_ls *mylist);
t_list_ls		*check_mode(struct stat fs, int i, char **argv);

/*
** ft_ls.c
*/

int				main(int argc, char **argv);
int				handle_arg(t_arg_ls *arg);
int				recursive_dir(t_arg_ls *arg, t_list_ls *mylist);
t_list_ls		*params(t_list_ls *mylist, t_arg_ls *arg);

#endif
