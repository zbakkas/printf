
#include "ft_printf.h"

void	ft_putaddr_hex(unsigned long int nbr, char Xx,int *j)
{
	unsigned long int	base_len;
	char				*base;

	base_len = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < base_len)
		ft_putchar(base[nbr % base_len],j);
	else
	{
		ft_putaddr_hex(nbr / base_len, Xx,j);
		ft_putaddr_hex(nbr % base_len, Xx,j);
	}
}

static void	chick_l(unsigned long int nbr,int *x)
{

	if (nbr < 16)
		(*x)++;
	else
	{
		chick_l(nbr / 16,x);
		chick_l(nbr % 16, x);
	}
}

void	ft_putaddr(void *addr, char *format,int *j)
{
	// if(addr == NULL)
	// {
	// 	ft_putstr("(nil)",format,j);
	// 	return;
	// }
    int len =git_n(format);
    int lens = git_n_after_p(format);
    int lens2 = git_n_after_p(format);
    int if_m=0 ;
    chick_l((unsigned long int)addr,&if_m);
    if(check_maiees(format))
    {
	if(check_pluse(format))
		ft_putchar('+',j);
	else if(check_sp(format))
		ft_putchar(' ',j);
	ft_putchar('0',j);
	ft_putchar('x',j);
	len-=2;
	if(check_pluse(format) || check_sp(format))
		len--;
	while(lens - if_m>0 && lens >if_m )
        {
            ft_putchar('0',j);
            lens--;
        }
		ft_putaddr_hex((unsigned long int)addr,'x',j);
	while((len - lens> 0 && len > 0 && git_n(format) >if_m && lens2 >=if_m)||(lens2 <if_m&& len -if_m >0 &&len > 0 && git_n(format) >if_m))
        {
        //    if(check_zero(format) && lens == 0 && !check_poin(format))
          //      ft_putchar('0',j);
            //else
                ft_putchar(' ',j);

            len--;
        }
    }
    else
    {
		
		if((check_zero(format) && lens == 0 && !check_poin(format)))
		{
			if(check_pluse(format))
				ft_putchar('+',j);
			ft_putchar('0',j);
			ft_putchar('x',j);
		}
		len-=2;
		if(check_pluse(format))
			len--;
        while((len - lens> 0 && len > 0 && git_n(format) >if_m && lens2 >=if_m)||(lens2 <if_m&& len -if_m >0 &&len > 0 && git_n(format) >if_m))
        {
            if(check_zero(format) && lens == 0 && !check_poin(format))
                ft_putchar('0',j);
            else
                ft_putchar(' ',j);

            len--;
        }
		if(!(check_zero(format) && lens == 0 && !check_poin(format)))
		{	if(check_pluse(format))
				ft_putchar('+',j);
			ft_putchar('0',j);
			ft_putchar('x',j);
		}
        while(lens2 - if_m>0 && lens2 >if_m )
        {
            ft_putchar('0',j);
            lens2--;
        }
		ft_putaddr_hex((unsigned long int)addr,'x',j);
    }

}

