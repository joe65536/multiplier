#include <utility>
#include "multiplier_opti.hpp"

long MultiplierOptimizer::multiply(int x, int y)
{
	if (x > y)
		std::swap(x, y);
	return multi.multiply(x, y);
}

MultiplierOptimizer::MultiplierOptimizer(Multiplier &m)
	: multi(m)
{
}
