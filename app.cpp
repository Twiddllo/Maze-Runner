#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

// size as kaveh wished
const int H = 51;
const int W = 76;


char MAP[H][W+1] = {
",-----------.-----------.--------------------.-----------.-----------------.",
"|           |           |                    |           |                 |",
"|  ,-----   |  ,-----.  |  .  ,-----------.  `--------   |  ,--.  .  ,--   |",
"|  |        |  |     |  |  |  |           |              |  |  |  |  |     |",
"|  |  ,-----'  |  .  |  |  `--\"--------.  \"  ,-----------'  \"  |  `--\"-----:",
"|  |  |        |  |  |  |              |     |                 |           |",
"|  |  |   --.  |  `--:  |  ,--------.  |  ,--:  ,--.-----------\"--------   |",
"|  |  |     |  |     |  |  |        |  |  |  |  |  |                       |",
"|  |  `-----'  |   --'  |  `-----   |  |  |  |  |  |  ,--------.--------.  |",
"|  |           |        |           |  |  |  |  |  |  |        |        |  |",
"|  `-----------\"-----.  `-----------:  |  \"  |  |  |  |  ,--   |  ,--.  |  |",
"|                    |              |  |     |  |  |  |  |     |  |  |  |  |",
"|  ,--------------.  :-----------.  |  `-----:  |  |  |  `-----'  \"  |  |  |",
"|  |              |  |           |  |        |  |  |  |              |  |  |",
"|  |  ,--------.  |  |  ,-----.  |  :-----   |  |  |  `--------------:  \"  |",
"|  |  |        |  |  |  |     |  |  |        |  |  |                 |     |",
"|  |  `-----   |  |  |  |  .  |  |  |  ,-----'  |  `--------------.  `-----:",
"|  |           |  |  |  |  |  |  |  |  |        |                 |        |",
"|  `-----------'  |  |  |  |  |  |  |  |  ,-----'  ,-----------.  :--.  .  |",
"|                 |  |  |  |  |  |  |  |  |        |           |  |  |  |  |",
":-----------------'  |  |  |  |  |  |  |  |  ,--.  |   -----.  |  |  |  |  |",
"|                    |  |  |  |  |  |  |  |  |  |  |        |  |  |  |  |  |",
"|  ,--------   ,-----:  |  |  \"  |  |  |  |  \"  |  |  ,-----'  |  \"  |  |  |",
"|  |           |     |  |  |     |  |  |  |     |  |  |        |     |  |  |",
"|  `-----------'  .  :--'  `-----'  \"  |  :--.  |  :--'  ,--   `--.  |  |  |",
"|                 |  |                 |  |  |  |  |     |        |  |  |  |",
"|  ,-----.--------'  |   -----.   --.  |  |  \"  |  |   --\"--------'  |  |  |",
"|  |     |           |        |     |  |  |     |  |                 |  |  |",
"|  `--   |  ,-----.  :--------\"-----\"--'  |   --:  :-----------------'  |  |",
"|        |  |     |  |                    |     |  |                    |  |",
":-----.  |  |   --:  |  ,-----------.-----\"-----'  |  ,--.--------------'  |",
"|     |  |  |     |  |  |           |              |  |  |                 |",
"|  .  |  |  |  .  \"  |  :--------   `--   ,-----.  |  |  |  ,-----------.--:",
"|  |  |  |  |  |     |  |                 |     |  |  |  |  |           |  |",
"|  `--:  |  `--\"-----'  \"  .  ,--   ,-----'   --'  |  |  \"  |  .   --.  \"  |",
"|     |  |                 |  |     |              |  |     |  |     |     |",
"|  .  |  :-----.-----------\"--\"-----\"--.   --------:  :--.  `--\"--.  `-----:",
"|  |  |  |     |                       |           |  |  |        |        |",
"|  |  |  |  .  |  ,-----------------.  `-----------'  |  `--.--.  |  ,--.  |",
"|  |  |  |  |  |  |                 |                 |     |  |  |  |  |  |",
"|  `--'  |  `--:  |  ,--------------\"--------------.--'  .  |  |  |  |  |  |",
"|        |     |  |  |                             |     |  |  |  |  |  |  |",
"|  ,-----'  .  |  |  |  ,--------.-----.  ,-----.  |  .  |  |  |  |  |  |  |",
"|  |        |  |  |  |  |        |     |  |     |  |  |  |  |  |  |  |  |  |",
"|  `--------:  |  |  |  |  .  .  `--   |  |   --'  |  |  |  \"  |  |  |  |  |",
"|           |  |  |  |  |  |  |        |  |        |  |  |     |  |  |  |  |",
":--------.  |  |  |  \"  `--'  :--------:  |   -----:  |  `-----'  |  \"  |  |",
"|        |  |  |  |           |        |  |        |  |           |     |  |",
"|   -----'  \"  |  `-----------'   --.  |  `--------'  `-----.   --\"-----'  |",
"|              |                    |  |                    |              |",
"`--------------\"--------------------'O `--------------------\"--------------'"
};

// getting easy x,y for MAP
struct Position { int x, y; };

const int INITIAL_LIVES = 3;
const int NUM_GHOSTS = 3;

// bool isWallChar(char ch) {
//     // checking if next move is avalible or not by true/false
//     return (ch != ' ' && ch != 'O');
// }

void clearScreen() {
    // only thing which is same with py :)
    system("cls");
}

Position findFirstEmptyOnMap() {
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (MAP[x][y] == ' ')
                return {x, y};
        }
    }
    // return {1,1}; // (gpt debugging)
}

Position findExitOnMap() {
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (MAP[x][y] == 'O') return {x, y};
        }
    }
    // ive made it cuz if i wanted to make this game with random seed map i can get exit easier :)
}

Position getRandomEmptyPos() {
    // finding free place for ghosts to spawn
    while (true) {
        int x = rand() % H;
        int y = rand() % W;
        if (MAP[x][y] == ' ' && MAP[x][y] != 'P')
            return {x,y};
    }
}


vector<pair<string,int>> loadHistory(const string &fname="history.txt") { // thx ai :>
    vector<pair<string,int>> h;
    ifstream fin(fname.c_str());
    if (!fin.is_open()) return h;
    string name;
    int score;
    while (fin >> ws && !fin.eof()) {
        if (!(fin >> name >> score)) break;
        h.push_back({name, score});
    }
    fin.close();
    return h;
}


void appendHistory(const string &name, int score, const string &fname="history.txt") { // thx ai x2 :>
    ofstream fout(fname.c_str(), ios::app);
    if (!fout.is_open()) return;
    fout << name << " " << score << "\n";
    fout.close();
}


void displayHistory() {
    clearScreen();
    cout << "[MAZE-CORE] Game history\n\n";
    vector<pair<string,int>> h = loadHistory(); // should i repit?
    if (h.empty()) {
        cout << "No history found.\n";
    } else {
        for (size_t i=0;i<h.size();++i) {
            cout << (i+1) << ". " << h[i].first << "  -  " << h[i].second << "\n";
        }
    }
    cout << "\n[MAZE-CORE] Press any key to return to menu...";
    _getch();
}

// func to print MAP with ghosts and player
void getting_map(const Position &player, const vector<Position> &ghosts) {
    clearScreen();
    // getting copy of map and placing players
    vector<string> digit_char(H, string(W, ' ')); // ily ai :>
    for (int x=0;x<H;++x) for (int y=0;y<W;++y) digit_char[x][y] = MAP[x][y];

    //locating place of ghost by "G"
    for (int i=0;i<ghosts.size();++i) {
        int gx = ghosts[i].x, gy = ghosts[i].y;
        if (gx>=0 && gx<H && gy>=0 && gy<W) {
            digit_char[gx][gy] = 'G';
        }
    }

    //locating place of player by "P"
    if (player.x>=0 && player.x<H && player.y>=0 && player.y<W)
        digit_char[player.x][player.y] = 'P';

    // چاپ
    for (int x=0;x<H;++x) {
        cout << digit_char[x] << "\n";
    }
}


bool canMoveTo(int nx, int ny) {
    if (nx < 0 || nx >= H || ny < 0 || ny >= W)
        return false;

    char ch = MAP[nx][ny];

    if (ch == 'O')
        return true;

    if (ch == ' ')
        return true;

    return false;
}

//  finally :_)
void game(const string &player_name) {
    Position player = findFirstEmptyOnMap();
    Position exitpos = findExitOnMap();

    int lives = INITIAL_LIVES;
    int score = 0;
    int turnCounter = 0;

    // spawning ghosts
    vector<Position> ghosts;
    ghosts.reserve(NUM_GHOSTS);
    for (int i=0;i<NUM_GHOSTS;++i) ghosts.push_back(getRandomEmptyPos());

    bool gameOver = false; // to know if game is over or not
    while (!gameOver) {

        getting_map(player, ghosts);
        cout << "\nPlayer: " << player_name << "   Lives: " << lives << "   Score: " << score << "\n";
        cout << "[MAZE-CORE] Move with W A S D  |  exit = O (letter o)\n";


        char cmd = _getch(); // thx kaveh :>

        // changing to lowchars (if user have caplock on)
        if (cmd >= 'A' && cmd <= 'Z') cmd = char(cmd - 'A' + 'a');

        // well, who wants to quit from such a good game be like this? :>
        if (cmd == 'o') {
            // im sure they clicked in 'o' by mistake
            cout << "\nAre you sure you want to exit? (y/n): ";
            char confirm = _getch();
            cout << confirm << "\n";
            if (confirm == 'y' || confirm == 'Y') {
                // they really wanted to exit? 😢
                appendHistory(player_name, score);
                return;
            } else {
                continue;
            }
        }

        // حرکت بازیکن بسته به دستور
        int nx = player.x, ny = player.y;
        if (cmd == 'w') nx = player.x - 1;
        else if (cmd == 's') nx = player.x + 1;
        else if (cmd == 'a') ny = player.y - 1;
        else if (cmd == 'd') ny = player.y + 1;
        else {
            continue;
        }

        if (canMoveTo(nx, ny)) {
            // checking if next move is valid or not + he won or not
            if (MAP[nx][ny] == 'O') {
                score += 20;
                appendHistory(player_name, score);
                clearScreen();
                cout << "CONGRATULATIONS!! " << player_name << " ! You Reached The Gate Of Game.\n";
                cout << "Final Score: " << score << "\n";
                cout << "Press any key to return to menu...";
                _getch();
                return;
            } else {
                // normal movement
                player.x = nx; player.y = ny;
            }
        } else {
            // doing smt if they riched wall (optional if you want to edit code)
        }


        turnCounter++;

            // checking if ghosts found player imidientlly
        for (size_t i=0; i<ghosts.size(); ++i) {
            if (ghosts[i].x == player.x && ghosts[i].y == player.y) {
                // if they caught player, restarting game
                lives--;
                score -= 5;
                if (score < 0) score = 0; // not letting player having - score :>
                player = findFirstEmptyOnMap();
                cout << "\nYou've been caught by a ghost! Lives left: " << lives << "   Press any key...";
                _getch();
                break;
            }
        }

        // if he lose all his hearts -> Game Over
        if (lives <= 0) {
            score = 0;
            appendHistory(player_name, score);
            clearScreen();
            cout << "GAME OVER! You lost all lives.\n";
            cout << "Final Score: " << score << "\n";
            cout << "Press any key to return to menu...";
            _getch();
            return;
        }

        // every 10 move of player -> 1 move for ghosts (ill probably update it to a changeable value so hoster of game can customize it from config.json)
        if (turnCounter % 10 == 0) {
            for (size_t i=0;i<ghosts.size();++i) {

                if (ghosts[i].x < player.x) ghosts[i].x++;
                else if (ghosts[i].x > player.x) ghosts[i].x--;

                if (ghosts[i].y < player.y) ghosts[i].y++;
                else if (ghosts[i].y > player.y) ghosts[i].y--;

            }
        }

        // checking if ghosts were smart or not :)
        for (size_t i=0; i<ghosts.size(); ++i) {
            if (ghosts[i].x == player.x && ghosts[i].y == player.y) {
                lives--;
                score -= 5;
                if (score < 0) score = 0;
                player = findFirstEmptyOnMap();
                cout << "\nA ghost caught you after moving! Lives left: " << lives << "   Press any key...";
                _getch();
                break;
            }
        }

        if (lives <= 0) {
            score = 0;
            appendHistory(player_name, score);
            clearScreen();
            cout << "GAME OVER! You lost all lives.\n";
            cout << "Final Score: " << score << "\n";
            cout << "Press any key to return to menu...";
            _getch();
            return;
        }

        // ill probably update it and give custom score depending on time but im lazy for now :) maybe next version
    }
}

// main menu
int displayMenu() {
    while (true) {
        clearScreen();

        cout << "┌──────────────────────────────────┐\n";
        cout << "│         ★ MAZE RUNNER ★         │\n";
        cout << "├──────────────────────────────────┤\n";
        cout << "│  1)  Start New Game              │\n";
        cout << "│  2)  History                     │\n";
        cout << "│  3)  Exit                        │\n";
        cout << "│  4)  (soon)...                   │\n";
        cout << "└──────────────────────────────────┘\n";
        cout << "\nSelect an option (1-3): ";

        string line;
        getline(cin, line);

        unsigned int start = 0;
        unsigned int len = (unsigned int)line.size();

        while (start < len && isspace((unsigned char)line[start])) {
            start++;
        }

        unsigned int end = len;
        while (end > start && isspace((unsigned char)line[end - 1])) {
            end--;
        }

        string trimmed;
        if (start < end) { // checking if user is in menu
            trimmed = line.substr(start, end - start);
        } else {
            trimmed = "";
        }

        if (trimmed == "1" || trimmed == "2" || trimmed == "3") {
            return trimmed[0] - '0';
        }

        cout << "\n⚠ Invalid choice! Press any key...";
        _getch();
    }
}


// starting game by getting player name
void startGame() {
    clearScreen();
    cout << "Enter player name (no spaces): ";
    string name;
    cin >> name;
    // https://stackoverflow.com/questions/33861470/what-cin-ignore-does-exactly :>
    cin.ignore(9999, '\n'); // like a normal terminal command: while its processing, you can paste the next command, and it will do it after the current process finishes.

    if (name.empty()) name = "Player";

    // random by time. thx kaveh :>
    srand((unsigned int) time(0));

    // runnig game
    game(name);
}


int main() {
    while (true) {
        int choice = displayMenu();
        if (choice == 1) {
            startGame();
        } else if (choice == 2) {
            displayHistory();
        } else if (choice == 3) {
            clearScreen();
            cout << "Goodbye :> ";
            break;
        }
    }
    return 0;
}
