#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <limits>
#include "multiplier_impl.hpp"
#include "multiplier_opti.hpp"
#include "multiplier_mock.hpp"

using testing::Eq;

class MultiplierTest : public ::testing::Test 
{
	protected:
		MultiplierImpl objUnderTest;
};

class MultiplierOptimizerTest : public ::testing::Test
{
	protected:
		MultiplierMock mock;
		MultiplierOptimizer objUnderTest { mock };
};

TEST_F(MultiplierTest, multiply__simple_multiplication)
{
	EXPECT_THAT(objUnderTest.multiply(3, 4), Eq(12));
}

TEST_F(MultiplierTest, multiply__large_multiplication)
{
	EXPECT_THAT(objUnderTest.multiply(std::numeric_limits<int>::max(), 4), Eq(std::numeric_limits<int>::max()*4));
}

TEST_F(MultiplierTest, multiply__large_multiplication_swapped)
{
	EXPECT_THAT(objUnderTest.multiply(4, std::numeric_limits<int>::max()), Eq(std::numeric_limits<int>::max()*4));
}

TEST_F(MultiplierOptimizerTest, multiply__optimized_multiplication)
{
	EXPECT_CALL(mock, multiply(3, 4));
	objUnderTest.multiply(3, 4);
}

TEST_F(MultiplierOptimizerTest, multiply__optimized_multiplication_swap)
{
	EXPECT_CALL(mock, multiply(3, 4));
	objUnderTest.multiply(4, 3);
}
TEST_F(MultiplierOptimizerTest, multiply__large_optimized_multiplication)
{
	EXPECT_CALL(mock, multiply(4, std::numeric_limits<int>::max()));
	objUnderTest.multiply(std::numeric_limits<int>::max(), 4);
}

TEST_F(MultiplierOptimizerTest, multiply__large_optimized_multiplication_swap)
{
	EXPECT_CALL(mock, multiply(4, std::numeric_limits<int>::max()));
	objUnderTest.multiply(4, std::numeric_limits<int>::max());
}
