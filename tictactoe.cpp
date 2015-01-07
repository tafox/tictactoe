#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


enum Shape { X, O };

class TicTacToe {
  public:
    static char board[3][5];
    void printBoard();
    void placeShape();
    char playerShape;
};


char TicTacToe::board[3][5] = {
                                { ' ', '|', ' ', '|', ' ' },
                                { ' ', '|', ' ', '|', ' ' },
                                { ' ', '|', ' ', '|', ' ' },
                              };

void TicTacToe::printBoard() {
  for (int i = 0; i < 3; i++) {
    cout << endl;  
    for (int j = 0; j < 5; j++) {
      cout << board[i][j];
    }
  }
  cout << endl;
}

void TicTacToe::placeShape() {
  int pos;
  cout << "Input position from 1 - 9 to play." << endl;
  cin >> pos;
  switch (pos) {
    case 1:
      board[0][0] = playerShape;
      break;
    case 2:
      board[0][2] = playerShape;
      break;
    case 3:
      board[0][4] = playerShape;
      break;
    case 4:
      board[1][0] = playerShape;
      break;
    case 5:
      board[1][2] = playerShape;
      break;
    case 6:
      board[1][4] = playerShape;
      break;
    case 7:
      board[2][0] = playerShape;
      break;
    case 8:
      board[2][2] = playerShape;
      break;
    case 9:
      board[2][4] = playerShape;
      break;
    default:
      cout << "Error incorrect position." << endl;
  }
}
      
 
int main(int argc, char* args[]) {
  
  srand(time(NULL));

  Shape playerShape;

  playerShape = static_cast<Shape>(rand() % 2);
  
  cout << "Welcome to Tic-Tac-Toe!" << endl;
  if (playerShape == X) {
    cout << "You are Xs." << endl;
  } else {
    cout << "You are Os." << endl;
  }
  TicTacToe game;
  (playerShape == X) ? game.playerShape = 'X' : game.playerShape = 'O';
   
  game.printBoard();
  return 0;
}
