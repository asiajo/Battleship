#include "gtest/gtest.h"
#include "../include/BoardUser.hpp"

class BoardUserTest : public ::testing::Test
{
public:
    BoardUser boardUser;
};


TEST_F(BoardUserTest, getValueAt11Expect0)
{
    EXPECT_EQ(0, boardUser.getFieldInfo(1,1));
}

TEST_F(BoardUserTest, pushShipExpectTrue)
{
    EXPECT_EQ(true, boardUser.pushShip(1,1));
}

TEST_F(BoardUserTest, getValueAt11Expect1)
{
    boardUser.pushShip(1,1);
    EXPECT_EQ(1, boardUser.getFieldInfo(1,1));
}

TEST_F(BoardUserTest, getFieldSizeExpect12)
{
    EXPECT_EQ(12, boardUser.getFieldSize());
}

TEST_F(BoardUserTest, checkIfSetFieldSetsFieldValue)
{
    boardUser.SetField(1, 1, 2);
    EXPECT_EQ(2, boardUser.getFieldInfo(1,1));
}


TEST_F(BoardUserTest, shootUserAtEmptyUserFieldExpectFalse)
{
    EXPECT_EQ(false, boardUser.shoot(1,1));
}

TEST_F(BoardUserTest, shootUserAtFilledFieldExpectTrue)
{
    boardUser.pushShip(1,1);
    EXPECT_EQ(true, boardUser.shoot(1,1));
}

TEST_F(BoardUserTest, shootUserOutOfBoundsExpectFalse)
{
    int i = boardUser.getFieldSize();
    EXPECT_EQ(false, boardUser.shoot(i+1,i+1));
}