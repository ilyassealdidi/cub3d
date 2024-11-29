/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:46:45 by ialdidi           #+#    #+#             */
/*   Updated: 2024/11/29 17:13:28 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static bool	is_wall(char **map, int x, int y)
{
	return (map[y / TILE_SIZE][x / TILE_SIZE] == '1'
		|| map[y / TILE_SIZE][(x + 10) / TILE_SIZE] == '1'
		|| map[y / TILE_SIZE][(x - 10) / TILE_SIZE] == '1'
		|| map[(y + 10) / TILE_SIZE][x / TILE_SIZE] == '1'
		|| map[(y - 10) / TILE_SIZE][x / TILE_SIZE] == '1');
}

static void	rotate_player(t_game *game)
{
	if (mlx_is_key_down(game->mlx.mlx, MLX_KEY_LEFT) == true)
	{
		game->player.dir -= ROTATION_SPEED;
		render_map(game);
		game->player.dir = fmod(game->player.dir, 2 * M_PI);
		if (game->player.dir < 0)
			game->player.dir += 2 * M_PI;
	}
	else if (mlx_is_key_down(game->mlx.mlx, MLX_KEY_RIGHT) == true)
	{
		game->player.dir += ROTATION_SPEED;
		render_map(game);
		game->player.dir = fmod(game->player.dir, 2 * M_PI);
		if (game->player.dir < 0)
			game->player.dir += 2 * M_PI;
	}
}

static void	move_player(t_game *game)
{
	t_point	new_pos;

	new_pos.x = cos(game->player.dir) * SPEED;
	new_pos.y = sin(game->player.dir) * SPEED;
	if (mlx_is_key_down(game->mlx.mlx, MLX_KEY_W) == true)
		set_point(&new_pos, game->player.pos.x + new_pos.x,
				game->player.pos.y + new_pos.y);
	else if (mlx_is_key_down(game->mlx.mlx, MLX_KEY_S) == true)
		set_point(&new_pos, game->player.pos.x - new_pos.x,
			game->player.pos.y - new_pos.y);
	else if (mlx_is_key_down(game->mlx.mlx, MLX_KEY_D) == true)
		set_point(&new_pos, game->player.pos.x - new_pos.y,
			game->player.pos.y + new_pos.x);
	else if (mlx_is_key_down(game->mlx.mlx, MLX_KEY_A) == true)
		set_point(&new_pos, game->player.pos.x + new_pos.y,
			game->player.pos.y - new_pos.x);
	if (is_wall(game->map.map, new_pos.x, new_pos.y) == false)
	{
		set_point(&game->player.pos, new_pos.x, new_pos.y);
		render_map(game);
	}
}

void	key_hook(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (mlx_is_key_down(game->mlx.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx.mlx);
	move_player(game);
	rotate_player(game);
}
