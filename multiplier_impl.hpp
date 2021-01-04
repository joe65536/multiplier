#ifndef MULTIPLIER_IMPL_HPP
#define MULTIPLIER_IMPL_HPP

#include "multiplier.hpp"

class MultiplierImpl : public Multiplier {
	public:
		long multiply(int x, int y) override;
};

#endif
