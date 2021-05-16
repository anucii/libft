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
	ft_printf_fd(fd, "\n\033[33mMultistring test:\033[0m\n%s\n%s\n%c%s\n", \
            "Standard commands:\n", \
            "Digest commands:\n\tmd5\n\tsha256",'\n', "Cipher commands\n");
	
	ft_printf("\n\033[34mft_printf trivial tests\033[0m\n");
	ft_printf("ft_printf oddities [apparent but handled mismatches]\n\t- hex(Oxa1) for base10 int: %d\n", 0xa1);
	ft_printf_fd(fd, "ft_printf_fd oddities [apparent but handled mismatches]\n\t- hex(Oxa1) for base10 int: %d\n", 0xa1);



	ft_printf("\n\033[34mft_printf crash tests\033[0m\n");
	ft_printf("ft_printf crash test [more tags than arguments]\n\t%s - %s\n", "One arg only");
	ft_printf("ft_printf crash test [more arguments than tags]\n\t%s\n", "First argument", "Ignored argument");
	ft_printf("ft_printf crash test [arguments but no tags]\n", "Undue argument");
	ft_printf("ft_printf crash test [arguments wrong types]\n\t- int for string: %s\n", -1);
	ft_printf("ft_printf crash test [arguments wrong types]\n\t- string for int: %d\n", "not really an int");
	ft_printf("ft_printf crash test [arguments wrong types]\n\t- string for char: %c\n", "too long");
	ft_printf("ft_printf crash test [arguments wrong types]\n\t- float for int: %d\n", 1.5);

	ft_printf("\n\033[34mft_printf_fd crash tests\033[0m\n");
	ft_printf_fd(fd, "ft_printf_fd crash test [arguments wrong types]\n\t- float for int: %d\n", 1.5);	ft_printf_fd(fd, "ft_printf_fd crash test [more tags than arguments]\n\t%s - %s\n", "One arg only");
	ft_printf_fd(fd, "ft_printf_fd crash test [more arguments than tags]\n\t%s\n", "First argument", "Ignored argument");
	ft_printf_fd(fd, "ft_printf_fd crash test [arguments but no tags]\n", "Undue argument");
	ft_printf_fd(fd, "ft_printf_fd crash test [arguments wrong types]\n\t- int for string: %s\n", -1);
	ft_printf_fd(fd, "ft_printf_fd crash test [arguments wrong types]\n\t- string for int: %d\n", "not really an int");
	ft_printf_fd(fd, "ft_printf_fd crash test [arguments wrong types]\n\t- string for char: %c\n", "too long");
	
	return 0;
}
