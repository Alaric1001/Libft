/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:28:54 by asenat            #+#    #+#             */
/*   Updated: 2019/06/04 11:35:24 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

#include <stddef.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int		ft_map_file(const char *path, t_map *map)
{
	int			fd;
	struct stat	stat;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	if ((fstat(fd, &stat)) == -1)
		return (0);
	map->size = stat.st_size;
	map->map = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (map->map == MAP_FAILED)
		return (0);
	return (1);
}

void	ft_unmap_file(t_map *map)
{
	munmap(map->map, map->size);
}
