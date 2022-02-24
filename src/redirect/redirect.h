/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:36:08 by rusty             #+#    #+#             */
/*   Updated: 2022/02/23 19:56:01 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# define IN 1
# define ONT 2
# define IN_DOC 3
# define OUT_DOC 4

typedef struct s_redir	t_redir;

struct s_redir
{
	int		fd;
	char	*file;
};

#endif