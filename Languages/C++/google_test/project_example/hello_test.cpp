#include <gtest/gtest.h>

TEST(Hello, Test) {
  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(7 * 6, 42);
}