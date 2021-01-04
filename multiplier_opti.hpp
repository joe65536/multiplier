#include "multiplier.hpp"

class MultiplierOptimizer : public Multiplier {
	private:
		Multiplier &multi;
	public:
		MultiplierOptimizer(Multiplier &m);
		long multiply(int x, int y) override;
};
