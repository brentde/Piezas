#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/

// *****
// DONE
// *****

/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    // Constructor sets an empty board (default 3 rows, 4 columns) and 
    
    board.resize(3);

    for(int row = 0; row < 3; row++){
        board[row].resize(4);
    };


    for(int row = 0; row < 3; row++){
        for(int col = 3; col >= 0; col--){
            board[row][col] = Blank;
        }
    }

    // specifies it is X's turn first

    turn = X;
}

// *****
// DONE
// *****

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for(int row = 0; row < 3; row++){
        for(int col = 3; col >= 0; col--){
            board[row][col] = Blank;
        }
    }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 

// *****
// DONE
// *****

Piece Piezas::dropPiece(int column)
{
    Piece current_piece = turn;
    
    // toggles which Piece's turn it is
    if(turn == X){
        turn = O;
    } else {
        turn = X;
    }

      // Out of bounds coordinates return the Piece Invalid value
    if(column >= 4 || column < 0)
        return Invalid;

    // If column is full placePiece returns Piece Blank value 
    if(board[2][column] != Blank)
        return Blank;

    int row = 0;

    while(row < 3){

        // If current board location is Blank, drop piece
        // This goes from the bottom up
        if(board[row][column] == Blank){
            board[row][column] = current_piece;
            break;
        }

        // If location is filled, check next place up on board

        row++;
    }

    // returns what piece is placed
    return current_piece;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/

// *****
// DONE
// *****

Piece Piezas::pieceAt(int row, int column)
{
    // Blank if there are no pieces there
    if(board[row][column] == Blank)
        return Blank;

    // Invalid if the coordinates are out of bounds
    if(column >= 4 || row >= 3 || row < 0 || column < 0)
        return Invalid;

    //Returns what piece is at the provided coordinates
    return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/

Piece Piezas::gameState()
{
    int X_max = 0;
    int O_max = 0;
    
    for(int col = 0; col < 4; col++){
        for(int row = 0; row < 3; row++){
            int row_inc = row;
            int current_count = 0;
            Piece last_piece = Blank;

            // Check vertical

            while(row_inc < 3){
                if(board[row_inc][col] == Blank){
                    return Invalid;
                };

                // If last_piece is Blank, start of loop
                // Initalize last_piece to current board location
                // OR 
                // If last_piece is not equal to current board location
                // change last_piece, reset counter, check if max
                
                if(last_piece == Blank || last_piece != board[row_inc][col]){
                    last_piece = board[row_inc][col];
                    current_count = 1; // reset every time it changes

                    if(current_count > X_max && last_piece == X){
                        X_max = current_count;
                    } else if(current_count > O_max){
                        O_max = current_count;
                    };
                } else {

                // Else current board location matches last piece
                // Increment counter
                // Check if new max

                    current_count++;

                    if(current_count > X_max && last_piece == X){
                        X_max = current_count;
                    } else if(current_count > O_max){
                        O_max = current_count;
                    }
                };

                row_inc++;
            };
          
            int col_inc = col;
            last_piece = Blank;
            current_count = 0;

            // Check horizontal

            while(col_inc < 4){
                if(board[row][col_inc] == Blank){
                    return Invalid;
                };
                
                if(last_piece == Blank || last_piece != board[row][col_inc]){
                    last_piece = board[row][col_inc];
                    current_count = 1; // reset every time it changes

                    if(current_count > X_max && last_piece == X){
                        X_max = current_count;
                    } else if(current_count > O_max){
                        O_max = current_count;
                    };
                } else {

                    current_count++;

                    if(current_count > X_max && last_piece == X){
                        X_max = current_count;
                    } else if(current_count > O_max){
                        O_max = current_count;
                    };
                };

                col_inc++;
            }
        
        };
    };

    if(X_max == O_max)
        return Blank;

    return X_max > O_max ? X : O;
}