/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasilut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 02:12:14 by avasilut          #+#    #+#             */
/*   Updated: 2017/08/14 16:54:32 by avasilut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		latime_baza(int size)
{
	int etaj;
	int latime;
	int linie_etaj;

	etaj = 1;
	latime = 1;
	linie_etaj = 4;
	while (etaj <= size)
	{
		latime += 2 * (2 + etaj);
		etaj++;
		latime += linie_etaj;
		if (etaj % 2 && etaj < size)
			linie_etaj += 2;
	}
	latime -= linie_etaj;
	return (latime);
}

void	afis_spatii(int spatii)
{
	int pozitie;

	pozitie = 0;
	while (pozitie < spatii)
	{
		ft_putchar(' ');
		pozitie++;
	}
	ft_putchar('/');
}

void	afis_stelute(int size, int etaj, int latime, int linie_etaj)
{
	int latime_usa;
	int pozitie;

	latime_usa = 1 + 2 * ((etaj - 1) / 2);
	pozitie = 1;
	while (pozitie < latime - 1)
	{
		if (etaj == size && pozitie >= (latime - latime_usa) / 2
			&& pozitie < (latime + latime_usa) / 2
			&& etaj + 3 - linie_etaj <= latime_usa)
			if (latime_usa >= 5 && linie_etaj == etaj + 2 - latime_usa / 2
				&& pozitie == (latime + latime_usa) / 2 - 2)
				ft_putchar('$');
			else
				ft_putchar('|');
		else
			ft_putchar('*');
		pozitie++;
	}
	ft_putchar('\\');
}

void	sastantua(int size)
{
	int	etaj;
	int	inaltime_etaj;
	int	linie_etaj;
	int	latime;
	int l_baza;

	if (size < 1)
		return ;
	l_baza = latime_baza(size);
	etaj = 1;
	latime = 1;
	while (etaj <= size)
	{
		inaltime_etaj = 2 + etaj;
		linie_etaj = 1;
		while (linie_etaj <= inaltime_etaj)
		{
			latime += 2;
			afis_spatii((l_baza - latime) / 2);
			afis_stelute(size, etaj, latime, linie_etaj);
			ft_putchar('\n');
			linie_etaj++;
		}
		etaj++;
		latime += 4 + 2 * ((etaj - 2) / 2);
	}
}
