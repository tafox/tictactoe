#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class TicTacToe {
  public:
    static char board[3][5];

    void printBoard();
    char* getShape(int pos);
    void playerTurn();
    void computerTurn();
    bool isGameOver();
    

    char playerShape;
    char computerShape;
    char nextTurn;
    int numberOfTurns;
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

char* TicTacToe::getShape(int pos) {
  switch (pos) {
    case 1:
      return &board[0][0];
    case 2:
      return &board[0][2];
    case 3:
      return &board[0][4];
    case 4:
      return &board[1][0];
    case 5:
      return &board[1][2];
    case 6:
      return &board[1][4];
    case 7:
      return &board[2][0];
    case 8:
      return &board[2][2];
    case 9:
      return &board[2][4];
    default:
      cout << "Error incorrect position." << endl;
      return NULL;
  }
}

void TicTacToe::playerTurn() {
  int pos;
  bool validMove = false;
  char* place = NULL;
  while (!validMove) {  
    cout << "Input position from 1 - 9 to play." << endl;
    cin >> pos;
    if (pos >= 1 && pos <= 9) {
      place = getShape(pos);
      if (*place == ' ') {
        *place = playerShape;
        validMove = true;
      } else {
        cout << "Invalid move." << endl;
      }
    } else {
      cout << "Invalid move." << endl;
    }
  }
  nextTurn = computerShape;
  numberOfTurns++;
}

void TicTacToe::computerTurn() {
  bool validMove = false;
  char* place;
  int pos;
  while (!validMove) {
    pos = rand() % 10 + 1;
    if (pos == 10) {
      pos -= 1;
    } 
    place = getShape(pos);
    if (*place == ' ') {
      *place = computerShape;
      validMove = true;
    }
  }
  nextTurn = playerShape;
  numberOfTurns++;
}

bool TicTacToe::isGameOver() {
  bool gameOver = false;
  int count = 0;
  
  if (numberOfTurns >= 9) {
    gameOver = true;
  }
  
  for (int i = 0; i < 3; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][2] && board[i][0] == board[i][4]) {
      gameOver = true;
    }
  }
  for (int i = 0; i < 5; i+=2) {
    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
      gameOver = true;
    }
  }
  if (board[0][0] != ' ' && board[0][0] == board[1][2] && board[0][0] == board[2][4]) {
    gameOver = true;
  }
  if (board[0][4] != ' ' && board[0][4] == board[1][2] && board[0][4] == board[2][0]) {
    gameOver = true;
  }
  if (gameOver) {
    if (nextTurn == 'O') {
      cout << "Xs win!" << endl;
    } else {
      cout << "Os win!" << endl;
    }
  }
  return gameOver;
}
 
int main(int argc, char* args[]) {
  
  bool quit = false;

  TicTacToe game;

  int playerShape;

  srand(time(NULL));
  playerShape = rand() % 2;
  
  cout << "Welcome to Tic-Tac-Toe!" << endl;
  if (playerShape == 0) {
    cout << "You are Xs. You go first." << endl;
  } else {
    cout << "You are Os. Computer goes first." << endl;
  }
   
  game.printBoard();

  if  (playerShape == 0) {
     game.playerShape = 'X';
     game.computerShape = 'O';
     game.playerTurn();
  } else {
     game.playerShape = 'O';
     game.computerShape = 'X';
     game.computerTurn();
  }
  game.numberOfTurns = 0;

  game.printBoard();

  while (!quit) {
    if ((game.nextTurn == 'O' && game.playerShape == 'O') || (game.nextTurn == 'X' && game.playerShape == 'X')) {
      game.playerTurn();
    } else {
      game.computerTurn();
    }
    game.printBoard();
    quit = game.isGameOver();
  } 
  cout << "Game over." << endl;
  return 0;
}
