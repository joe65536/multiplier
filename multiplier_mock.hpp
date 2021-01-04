#ifndef MULTIPLIER_MOCK_HPP
#define MULTIPLIER_MOCK_HPP

#include <gmock/gmock.h>
#include "multiplier.hpp"


class MultiplierMock : public Multiplier {
public:
	MOCK_METHOD(long, multiply, (int x, int y), (override));
};

#endif