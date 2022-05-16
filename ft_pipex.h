/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:22:23 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/02/20 11:55:45 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PIPEX_H
# define FT_PIPEX_H
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>

int		ft_strichr(char *s, char c);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *path, char *bin);
char	*ft_strndup(char *s1, unsigned int n);
int		ft_strichr(char *s, char c);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_stlen(char *s);

#endif
