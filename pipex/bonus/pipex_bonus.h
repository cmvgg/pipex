#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include "../ft_printf/ft_printf.h"

void	perror_exit(char *opt);
void	here_doc(char *limiter, char *path);
char	**get_env_path(char **envp);
char	*get_cmd(char **path, char *cmd);

void	execute(char *cmd, char **envp);

void	start_process(char **av, char **envp, int i, int is_here_doc);
void	middle_process(char **av, char **envp, int i);
void	last_process(char **av, char **envp, int i, int is_here_doc);

#endif
