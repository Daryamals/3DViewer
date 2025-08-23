#include <gtest/gtest.h>
#include "../model/model.h"

TEST(SumTest, BasicTest)
{
    ASSERT_EQ(s21::sum(2, 2), 4);
    ASSERT_EQ(s21::sum(-5, 5), 0);
}
TEST(SumTest, NegativeTest)
{
    ASSERT_NE(s21::sum(2, 2), 5);
}