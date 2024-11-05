/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:06:39 by ialdidi           #+#    #+#             */
/*   Updated: 2024/10/05 20:49:29 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int main(int ac, char **av)
{
    t_game  game;

    if (ac != 2)
    {
        ft_putstr_fd(USAGE, 2);
        return (1);
    }
    if (game_init(&game, av[1]) == FAILURE)
        return (1);
    //rungame(&game);
    return (0);
}
