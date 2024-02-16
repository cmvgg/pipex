#include "pipex.h"

static void	dup_child_1(char **argv, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		perror_exit("infile error");
	if (dup2(infile, STDIN_FILENO) == -1)
		perror_exit("dup2 error");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror_exit("dup2 error");
	close(infile);
	close(fd[0]);
	close(fd[1]);
}

static void	child_process_1(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		perror_exit("pipe error");
	pid = fork();
	if (pid == -1)
		perror_exit("fork error");
	if (pid == 0)
	{
		dup_child_1(argv, fd);
		execute(argv[2], envp);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror_exit("dup2 error");
	close(fd[0]);
	close(fd[1]);
}

static void	child_process_2(char **argv, char **envp)
{
	pid_t	pid;
	int		outfile;

	pid = fork();
	if (pid == -1)
		perror_exit("fork error");
	if (pid == 0)
	{
		outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
			perror_exit("outfile error");
		if (dup2(outfile, STDOUT_FILENO) == -1)
			perror_exit("dup2 error");
		execute(argv[3], envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		stdin_dup;
	int		stdout_dup;

	stdin_dup = dup(0);
	stdout_dup = dup(1);
	if (argc != 5)
		perror_exit("argument error");
	i = -1;
	while (++i < 2)
	{
		if (i == 0)
			child_process_1(argv, envp);
		else if (i == 1)
			child_process_2(argv, envp);
	}
	dup2(stdin_dup, 0);
	dup2(stdout_dup, 1);
	close(stdin_dup);
	close(stdout_dup);
	i = -1;
	while (++i < 2)
		wait(NULL);
}
