#include <iostream>
using namespace std;

void DrawBoard(char spaces[]) {
    cout << "   " << spaces[0] << "  " << "|  " << spaces[1] << "  " << "|  " << spaces[2] << "  " << endl;
    cout << "-------------------" << endl;
    cout << "   " << spaces[3] << "  " << "|  " << spaces[4] << "  " << "|  " << spaces[5] << "  " << endl;
    cout << "-------------------" << endl;
    cout << "   " << spaces[6] << "  " << "|  " << spaces[7] << "  " << "|  " << spaces[8] << "  " << endl;
}

bool checkGame(char spaces[]) {
    for (int x = 0; x < 9; x+=3) {
        if ((spaces[x] == 'X' && spaces[x+1] == 'X' && spaces[x+2] == 'X') || (spaces[x] == 'O' && spaces[x+1] == 'O' && spaces[x+2] == 'O')) {
            return true;
        }
    }

    for (int x = 0; x < 3; x++) {
        if ((spaces[x] == 'X' && spaces[x+3] == 'X' && spaces[x+6] == 'X') || (spaces[x] == 'O' && spaces[x+3] == 'O' && spaces[x+6] == 'O')) {
            return true;
        }
    }

    if ((spaces[0] == 'X' && spaces[4] == 'X' && spaces[8] == 'X') || (spaces[0] == 'O' && spaces[4] == 'O' && spaces[8] == 'O')) {
        return true;
    }

    if ((spaces[2] == 'X' && spaces[4] == 'X' && spaces[6] == 'X') || (spaces[2] == 'O' && spaces[4] == 'O' && spaces[6] == 'O')) {
        return true;
    }
    return false;
}


void PlayGame() {
    char spaces[9] = {'0','1','2','3','4','5','6','7','8'};
    bool gameFinished = false;
    bool choiceFinished = false;
    int choice;
    int moves = 0;
    string ask = "";

    while (!gameFinished) { 
        choiceFinished = false;
        DrawBoard(spaces);
        cout << "Player 1 (X) turn. Choose a number to fill:" << endl;
        cin >> choice;
        while (!choiceFinished) {
            if (spaces[choice] == 'X' || spaces[choice] == 'O' || choice > 8 || choice < 0) {
                cout << "You cannot choose that space. Choose another:" << endl;
                cin >> choice;
            } else {
                spaces[choice] = 'X';
                choiceFinished = true;
            }
        }
        moves++;

        if (checkGame(spaces) == true) {
            cout << "Player 1 wins" << endl;
            gameFinished = true;
            break;
        }

        if (moves > 8) {
            cout << "The game is tied!" << endl;
            gameFinished = true;
            break;
        }

        choiceFinished = false;
        DrawBoard(spaces);
        cout << "Player 2 (O) turn. Choose a number to fill:" << endl;
        cin >> choice;
        while (!choiceFinished) {
            if (spaces[choice] == 'X' || spaces[choice] == 'O' || choice > 8 || choice < 0) {
                cout << "You cannot choose that space. Choose another:" << endl;
                cin >> choice;
            } else {
                spaces[choice] = 'O';
                choiceFinished = true;
            }
        }
        moves++;

        if (checkGame(spaces) == true) {
            cout << "Player 2 wins" << endl;
            gameFinished = true;
            break;
        }
        
        if (moves > 8) {
            cout << "The game is tied!" << endl;
            gameFinished = true;
            break;
        }
    }
    DrawBoard(spaces);

    cout << "Would you like to play again? Y or N: " << endl;
    cin >> ask;

    if (ask == "Y") {
        for (int x = 0; x < 9; x++) {
            spaces[x] = char(x);
        }
        PlayGame();
        
    } else if (ask == "N") {
        return;
    }
}

int main() {
    PlayGame();
    return 0;
}