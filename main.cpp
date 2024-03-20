#include <iostream>
#include <conio.h>

using namespace std;

class GameModel {
private:
    int score;
    int level;

public:
    GameModel() : score(0), level(1) {}

    void increaseScore() {
        score++;
        if (score % 5 == 0) {
            increaseLevel();
        }
    }

    void increaseLevel() {
        level++;
    }

    int getScore() {
        return score;
    }

    int getLevel() {
        return level;
    }
};

// View
class GameView {
public:
    void displayScoreAndLevel(int score, int level) {
        cout << "Punkty: " << score << " | Level: " << level << endl;
    }
};

// Controller
class GameController {
public:
    void processInput(GameModel &model, char input) {
        if (input == 'b') {
            model.increaseScore();
        }
    }
};

int main() {
    GameModel model;
    GameView view;
    GameController controller;

    char literka;
    cout << "Wprowadz litere 'e' aby wyjsc: ";
    cout << "Wprowadz litere 'b' aby dodac punkt: ";
    while (true) {

        literka = _getch();
        if (literka == 'e') {
            break;
        }
        controller.processInput(model, literka);
        view.displayScoreAndLevel(model.getScore(), model.getLevel());
    }

    return 0;
}