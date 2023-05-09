#include "printf.h"
#include "../libft/libft.h"

int	pf_hexlen(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	pf_puthex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		pf_puthex(num / 16, format);
		pf_puthex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	format_x_X(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		pf_puthex(num, format);
	return (pf_hexlen(num));
}
