#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For random seed
#include <string>
using namespace std;

// Base class: TwoPlayerGame
class TwoPlayerGame {
protected:
    string player1;
    string player2;

public:
    TwoPlayerGame(string p1, string p2) : player1(p1), player2(p2) {}

    // Virtual function for playing the game
    virtual void play() {
        cout << "Starting a two-player game between " << player1 << " and " << player2 << ".\n";
    }
};

// MultiplicationGame class
class MultiplicationGame : public TwoPlayerGame {
public:
    MultiplicationGame(string p1, string p2) : TwoPlayerGame(p1, p2) {}

    void play() {
        srand(time(0)); // Seed random number generator
        int round = 1;

        while (true) {
            int num1 = rand() % 10 + 1; // Random number 1 to 10
            int num2 = rand() % 10 + 1; // Random number 1 to 10
            int correctAnswer = num1 * num2;

            string currentPlayer = (round % 2 == 1) ? player1 : player2;
            cout << currentPlayer << ", solve: " << num1 << " * " << num2 << " = ";
            int answer;
            cin >> answer;

            if (answer != correctAnswer) {
                cout << currentPlayer << " gave the wrong answer. Game over.\n";
                string winner = (round % 2 == 1) ? player2 : player1;
                cout << "The winner is " << winner << "!\n";
                break;
            }

            cout << "Correct!\n";
            round++;
        }
    }
};

// RockPaperScissors class
class RockPaperScissors : public TwoPlayerGame {
public:
    RockPaperScissors(string p1, string p2) : TwoPlayerGame(p1, p2) {}

    void play() {
        int score1 = 0, score2 = 0;

        while (score1 < 2 && score2 < 2) {
            string move1, move2;
            cout << player1 << ", enter Rock, Paper, or Scissors: ";
            cin >> move1;
            cout << player2 << ", enter Rock, Paper, or Scissors: ";
            cin >> move2;

            if (move1 == move2) {
                cout << "It's a tie! Both chose " << move1 << ".\n";
            } else if ((move1 == "Rock" && move2 == "Scissors") ||
                       (move1 == "Paper" && move2 == "Rock") ||
                       (move1 == "Scissors" && move2 == "Paper")) {
                cout << player1 << " wins this round!\n";
                score1++;
            } else {
                cout << player2 << " wins this round!\n";
                score2++;
            }

            cout << "Scores: " << player1 << " (" << score1 << "), " << player2 << " (" << score2 << ")\n";
        }

        string winner = (score1 == 2) ? player1 : player2;
        cout << "The winner is " << winner << "!\n";
    }
};

// Main function
int main() {
    string player1, player2;

    cout << "Enter name for Player 1: ";
    cin >> player1;
    cout << "Enter name for Player 2: ";
    cin >> player2;

    while (true) {
        cout << "\n--- Game Menu ---\n";
        cout << "1. Play Multiplication Game\n";
        cout << "2. Play Rock Paper Scissors\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        if (choice == 0) {
            cout << "Thank you for playing!\n";
            break;
        }

        if (choice == 1) {
            MultiplicationGame game(player1, player2);
            game.play();
        } else if (choice == 2) {
            RockPaperScissors game(player1, player2);
            game.play();
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
