/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobles <drobles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:17:54 by drobles           #+#    #+#             */
/*   Updated: 2022/11/16 18:08:13 by drobles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

unsigned int		ft_strlenp(const char	*str);
int					ft_putstrp(char	*s);
int					ft_putnbrp(int n);
int					ft_putnbrbase(unsigned int numero, char *base);
int					ft_putcharp(int c);
int					ft_printf(char const *cadena, ...);
int					ft_puthexa(unsigned long int n);
int					ft_putadress(void *numero);

#endif
