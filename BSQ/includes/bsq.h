/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:36:10 by hle-hena          #+#    #+#             */
/*   Updated: 2024/08/07 18:15:36 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_map
{
	char	**map;
	char	obstacle;
	char	empty;
	char	full;
	int		nb_lines;
	int		len_lines;
}	t_map;

typedef struct s_sqr
{
	int	x;
	int	y;
	int	val;
}	t_sqr;

//read_files.c
t_map	get_file(char *filename);

//error_handling.c
void	null_list(int **tab, int i);
t_sqr	null_sqr(void);
t_map	null_map(char **str);
void	ft_puterror(char *str);

//solver.c
t_sqr	get_sqr(t_map map);

//handle_list.c
void	add_val(t_map map, int **tab, int x, int y);
char	*ft_rev_str(char *str);

//write.c
void	ft_write_tab(t_map map);
void	fill_sqr(t_sqr max, t_map map);

//readstdin.c
t_map	get_stdin(void);

//freeing.c
void	free_list(int **list_sqr);
void	free_strs(char **str);

//utility1.c
void	*ft_calloc(unsigned count, unsigned size);
void	*ft_realloc(void *ptr, unsigned int size);
char	*ft_strdup_se(char *str, int start, int end);
char	**ft_split(char *str);
int		ft_strlen(char *str);

//utility2.c
int		ft_atoi(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin(int size, char **strs, char *sep);

//utility3.c
void	ft_putstr(char *str);
int		is_not_num(char *str);
void	*ft_calloc_int(unsigned count, unsigned size);
char	*ft_strip(char *str);
int		is_not_valid(char *str);

#endif
