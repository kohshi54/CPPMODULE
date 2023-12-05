#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename N, typename F>
void iter(T* a, N n, F f)
{
	for (N i = 0; i < n; ++i)
	{
		f(a[i]);
	}
}
	
#endif
