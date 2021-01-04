#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "multiplier_impl.hpp"

using testing::Eq;

class MultiplierTest : public ::testing::Test 
{
	protected:
		MultiplierImpl objUnderTest;
};

TEST_F(MultiplierTest, multiply__simple_multiplication)
{
	EXPECT_THAT(objUnderTest.multiply(3, 4), Eq(12));
}
