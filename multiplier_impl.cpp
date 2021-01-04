#include "multiplier_impl.hpp"

long MultiplierImpl::multiply(int x, int y)
{
	long result = x;
	while (--y>0) {
		result += x;
	}
	return result;
}
