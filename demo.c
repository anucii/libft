#include "libft.h"

int main(int ac, char **av)
{
	int i;
	int fd;

	if (ac < 3) 
	{
		ft_printf("usage: ./demo <target fd> <string1> … <string n>\n");
		return 1;
	}
	i = 2;
	fd = ft_atoi(av[1]);
	while (i < ac)
	{
		ft_printf_fd(fd, "arg no %d: %s\n", i, av[i]);
		i++;
	}
	ft_printf_fd(fd, "\n\033[33mCrash test:\033[0m\n%s\n%s\n%c%s\n", \
            "Standard commands:\n", \
            "Digest commands:\n\tmd5\n\tsha256",'\n', "Cipher commands");
	return 0;
}
