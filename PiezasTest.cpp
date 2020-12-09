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

TEST(PiezasTest, emptyBoard0)
{
	Piezas board;

	ASSERT_EQ(board.pieceAt(0,0), Blank);
}

TEST(PiezasTest, emptyBoard1)
{
	Piezas board;

	ASSERT_EQ(board.pieceAt(0,1), Blank);
}

TEST(PiezasTest, emptyBoard2)
{
	Piezas board;

	ASSERT_EQ(board.pieceAt(0,2), Blank);
}

TEST(PiezasTest, emptyBoard3)
{
	Piezas board;

	ASSERT_EQ(board.pieceAt(0,3), Blank);
}

TEST(PiezasTest, dropPieceRetX)
{
	Piezas board;

	ASSERT_EQ(board.dropPiece(0), X);
}

TEST(PiezasTest, dropPieceRetO)
{
	Piezas board;
	board.dropPiece(0);

	ASSERT_EQ(board.dropPiece(0), O);
}


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

// *********************************
// Tests for gameState
// *********************************

// O O O O
// O O X X
// X X X X

TEST(PiezasTest, gameStateTieHoriz_1)
{
	Piezas board;
	board.dropPiece(0); // X
	board.dropPiece(0); // O
	board.dropPiece(1); // X
	board.dropPiece(0); // O
	board.dropPiece(2); // X
	board.dropPiece(1); // O
	board.dropPiece(3); // X
	board.dropPiece(1); // O
	board.dropPiece(2); // X
	board.dropPiece(2); // O
	board.dropPiece(3); // X
	board.dropPiece(3); // O

	ASSERT_EQ(board.gameState(), Blank);
}

// X O X O 
// O O O O 
// X X X X

TEST(PiezasTest, gameStateTieHoriz_2)
{
	Piezas board;
	board.dropPiece(0); // X
	board.dropPiece(0); // O
	board.dropPiece(1); // X
	board.dropPiece(1); // O
	board.dropPiece(2); // X
	board.dropPiece(2); // O
	board.dropPiece(3); // X
	board.dropPiece(3); // O
	board.dropPiece(0); // X
	board.dropPiece(1); // O
	board.dropPiece(2); // X
	board.dropPiece(3); // O

	ASSERT_EQ(board.gameState(), Blank);
}

// X O O O
// X O O X
// X O X X

TEST(PiezasTest, gameStateTieVertical_1)
{
	Piezas board;
	board.dropPiece(0); // X
	board.dropPiece(1); // O
	board.dropPiece(0); // X
	board.dropPiece(1); // O
	board.dropPiece(0); // X
	board.dropPiece(1); // O

	board.dropPiece(2); // X
	board.dropPiece(2); // O

	board.dropPiece(3); // X
	board.dropPiece(2); // O

	board.dropPiece(3); // X
	board.dropPiece(3); // O

	ASSERT_EQ(board.gameState(), Blank);
}

// O X O X
// X O O X
// O X O X

TEST(PiezasTest, gameStateTieVertical_2)
{
	Piezas board;
	board.dropPiece(3); // X
	board.dropPiece(2); // O
	board.dropPiece(3); // X
	board.dropPiece(2); // O
	board.dropPiece(3); // X
	board.dropPiece(2); // O

	board.dropPiece(1); // X
	board.dropPiece(1); // O
	board.dropPiece(1); // X
	
	board.dropPiece(0); // O
	board.dropPiece(0); // X
	board.dropPiece(0); // O

	ASSERT_EQ(board.gameState(), Blank);
}

// O X O O
// O O O X
// X X X X

TEST(PiezasTest, gameStateXWinHoriz)
{
	Piezas board;
	board.dropPiece(0); // X
	board.dropPiece(0); // O
	board.dropPiece(1); // X
	board.dropPiece(1); // O
	board.dropPiece(1); // X
	board.dropPiece(0); // O
	board.dropPiece(2); // X
	board.dropPiece(2); // O
	board.dropPiece(3); // X
	board.dropPiece(2); // O
	board.dropPiece(3); // X
	board.dropPiece(3); // O

	ASSERT_EQ(board.gameState(), X);
}

// X X O O
// X O O X
// X O X O

TEST(PiezasTest, gameStateXWinVertical)
{
	Piezas board;
	board.dropPiece(0); // X
	board.dropPiece(3); // O
	board.dropPiece(0); // X
	board.dropPiece(1); // O
	board.dropPiece(0); // X
	board.dropPiece(1); // O
	board.dropPiece(2); // X
	board.dropPiece(2); // O
	board.dropPiece(3); // X
	board.dropPiece(2); // O
	board.dropPiece(1); // X
	board.dropPiece(3); // O

	ASSERT_EQ(board.gameState(), X);
}

// X O X O 
// O X X O
// X X O O

TEST(PiezasTest, gameStateOWinVertical)
{
	Piezas board;
	board.dropPiece(0); // X
	board.dropPiece(3); // O
	board.dropPiece(1); // X
	board.dropPiece(2); // O
	board.dropPiece(1); // X
	board.dropPiece(3); // O
	board.dropPiece(2); // X
	board.dropPiece(3); // O
	board.dropPiece(2); // X
	board.dropPiece(0); // O
	board.dropPiece(0); // X
	board.dropPiece(1); // O

	ASSERT_EQ(board.gameState(), O);
}

// X X X O
// O O O O 
// X X X O

TEST(PiezasTest, gameStateOWinHoriz)
{
	Piezas board;
	board.dropPiece(0); // X
	board.dropPiece(0); // O
	board.dropPiece(1); // X
	board.dropPiece(1); // O
	board.dropPiece(2); // X
	board.dropPiece(2); // O
	board.dropPiece(0); // X
	board.dropPiece(3); // O
	board.dropPiece(1); // X
	board.dropPiece(3); // O
	board.dropPiece(2); // X
	board.dropPiece(3); // O

	ASSERT_EQ(board.gameState(), O);
}

// ****************
// Tests Reset
// ****************

TEST(PiezasTest, resetTest)
{
	Piezas board;
	board.dropPiece(0); // X
	board.dropPiece(3); // O
	board.dropPiece(0); // X
	board.dropPiece(1); // O
	board.dropPiece(0); // X
	board.dropPiece(1); // O
	board.dropPiece(2); // X
	board.dropPiece(2); // O
	board.dropPiece(3); // X
	board.dropPiece(2); // O
	board.dropPiece(1); // X
	board.dropPiece(3); // O

	ASSERT_EQ(board.gameState(), X);
	board.reset();
	ASSERT_EQ(board.gameState(), Invalid);
}