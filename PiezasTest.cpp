/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

// *********************************
// Tests for dropPiece and pieceAt
// *********************************

TEST(PiezasTest, dropPiecePos0_0)
{
	Piezas board;
	board.dropPiece(0);

	ASSERT_EQ(board.pieceAt(0,0), X);
}

TEST(PiezasTest, dropPiecePos0_1)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);

	ASSERT_EQ(board.pieceAt(1,0), O);
}

TEST(PiezasTest, dropPiecePos0_2)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);

	ASSERT_EQ(board.pieceAt(2,0), X);
}

TEST(PiezasTest, dropPieceRow0Full)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);

	ASSERT_EQ(board.dropPiece(0), Blank);
}

TEST(PiezasTest, dropPiecePos1_0)
{
	Piezas board;
	board.dropPiece(1);

	ASSERT_EQ(board.pieceAt(0,1), X);
}

TEST(PiezasTest, dropPiecePos1_1)
{
	Piezas board;
	board.dropPiece(1);
	board.dropPiece(1);

	ASSERT_EQ(board.pieceAt(1,1), O);
}

TEST(PiezasTest, dropPiecePos1_2)
{
	Piezas board;
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);

	ASSERT_EQ(board.pieceAt(2,1), X);
}

TEST(PiezasTest, dropPieceRow1Full)
{
	Piezas board;
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);

	ASSERT_EQ(board.dropPiece(1), Blank);
}

TEST(PiezasTest, dropPiecePos2_0)
{
	Piezas board;
	board.dropPiece(2);

	ASSERT_EQ(board.pieceAt(0,2), X);
}

TEST(PiezasTest, dropPiecePos2_1)
{
	Piezas board;
	board.dropPiece(2);
	board.dropPiece(2);

	ASSERT_EQ(board.pieceAt(1,2), O);
}

TEST(PiezasTest, dropPiecePos2_2)
{
	Piezas board;
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);

	ASSERT_EQ(board.pieceAt(2,2), X);
}

TEST(PiezasTest, dropPieceRow2Full)
{
	Piezas board;
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);

	ASSERT_EQ(board.dropPiece(2), Blank);
}

TEST(PiezasTest, dropPiecePos3_0)
{
	Piezas board;
	board.dropPiece(3);

	ASSERT_EQ(board.pieceAt(0,3), X);
}

TEST(PiezasTest, dropPiecePos3_1)
{
	Piezas board;
	board.dropPiece(3);
	board.dropPiece(3);

	ASSERT_EQ(board.pieceAt(1,3), O);
}

TEST(PiezasTest, dropPiecePos3_2)
{
	Piezas board;
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);

	ASSERT_EQ(board.pieceAt(2,3), X);
}

TEST(PiezasTest, dropPieceRow3Full)
{
	Piezas board;
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);

	ASSERT_EQ(board.dropPiece(3), Blank);
}


TEST(PiezasTest, dropPieceLessThan0)
{
	Piezas board;
	ASSERT_EQ(board.dropPiece(-1), Invalid);
}

TEST(PiezasTest, dropPieceGreaterThan3)
{
	Piezas board;
	ASSERT_EQ(board.dropPiece(4), Invalid);
}