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

	//TODO : replace code below by a more systematic and broader test suite

	i = 2;
	fd = ft_atoi(av[1]);
	while (i < ac)
	{
		ft_printf_fd(fd, "arg no %d: %s\n", i, av[i]);
		i++;
	}
	ft_printf_fd(fd, "\n\033[33mMultistring test:\033[0m\n%s\n%s\n%c%s\n", \
            "Standard commands:\n", \
            "Digest commands:\n\tmd5\n\tsha256",'\n', "Cipher commands\n");
	ft_printf("ft_printf oddities [apparent but handled mismatches]\n\t- hex(Oxa1) for base10 int: %d\n", 0xa1);
	ft_printf_fd(fd, "ft_printf_fd oddities [apparent but handled mismatches]\n\t- hex(Oxa1) for base10 int: %d\n", 0xa1);

	ft_printf("\n\033[34mft_printf usage tests\033[0m\n");
	ft_printf("ft_printf tricky test [more arguments than tags]\n\t%s\n", "First argument", "Ignored argument");
	ft_printf("ft_printf tricky test [arguments but no tags]\n", "Undue argument");

	ft_printf("\n\033[34mft_printf_fd usage tests\033[0m\n");
	ft_printf_fd(fd, "ft_printf_fd tricky test [more arguments than tags]\n\t%s\n", "First argument", "Ignored argument");
	ft_printf_fd(fd, "ft_printf_fd tricky test [arguments but no tags]\n", "Undue argument");
	
	ft_printf("\n\033[34mEnd of demo\033[0m\n\t\t***\n");
	return 0;
}
