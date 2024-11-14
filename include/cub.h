/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:07:37 by ialdidi           #+#    #+#             */
/*   Updated: 2024/11/14 13:02:13 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <libft.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <types.h>

/*		Parse				*/
void	set_defaults(t_game *game);
void	parse_settings(t_game *game, t_list **ptr);
void	parse_textures(t_game *game, t_list **list);
void	parse_colors(t_game *game, t_list **list);
void	parse_map(t_game *game, t_list **list);
void	game_init(t_game *game, char *filename);

/*		Error handling		*/
void    exit_with_error(t_game *game, char *str);
void	map_error(t_game *game, t_list *node, char *error);

/*		Utils				*/
void	free_array(char **array);
void	clean_exit(t_game *game, int status);
bool	isset(void *ptr);
bool	is_color(char *line);
bool	is_texture(char *line);
bool	is_color_set(t_settings *settings);
bool	is_texture_set(t_settings *settings);

/*		Linked list			*/
int 	ft_lstappend(t_list **lines, void *content);

/*		File utils			*/
t_list	*read_file(int fd);
void	file_error(t_game *game, char *filename);


#endif
