#include <iostream>

using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char player = 'X';

void displayBoard() {

    cout << endl;

    for(int i=0; i<3; i++) {

        for(int j=0; j<3; j++) {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
}

bool checkWin() {

    for(int i=0; i<3; i++) {

        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return true;

        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            return true;
    }

    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return true;

    return false;
}

void changePlayer() {
    if(player == 'X')
        player = 'O';
    else
        player = 'X';
}

void makeMove(int choice) {

    char mark = player;

    if(choice == 1) board[0][0] = mark;
    else if(choice == 2) board[0][1] = mark;
    else if(choice == 3) board[0][2] = mark;
    else if(choice == 4) board[1][0] = mark;
    else if(choice == 5) board[1][1] = mark;
    else if(choice == 6) board[1][2] = mark;
    else if(choice == 7) board[2][0] = mark;
    else if(choice == 8) board[2][1] = mark;
    else if(choice == 9) board[2][2] = mark;
}

int main() {

    int choice;
    int moves = 0;

    while(true) {

        displayBoard();

        cout << "Player " << player << ", enter a position: ";
        cin >> choice;

        makeMove(choice);

        moves++;

        if(checkWin()) {

            displayBoard();

            cout << "Player " << player << " Wins!" << endl;

            break;
        }

        if(moves == 9) {

            displayBoard();

            cout << "Game Draw!" << endl;

            break;
        }

        changePlayer();
    }

    return 0;
}