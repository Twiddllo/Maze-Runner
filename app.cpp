#include <iostream>
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

// declaring varis for settings in here cuz i dont want to declare them in all functions :>
int max_hearts = 3;
int ghost_count = 3;
int ghost_movement_speed_v1 = 10; // basic mode
bool smart_scoring = false;
bool ghost_movement_model = true;
int ghost_time_per_move = 3;
// bool isWallChar(char ch) {
//     // checking if next move is avalible or not by true/false
//     return (ch != ' ' && ch != 'O');
// }

void clssystem() {
    // only thing which is same with py :)
    system("cls");
}
        
// respecting to legends 🫡
bool cheat_name_checker(const string &a, const string &b) {
    if ((a == "kaveh" || a == "Kaveh") && (b == "kaveh" || b == "Kaveh")) return true;
    if ((a == "arad" || a == "Arad") && (b == "arad" || b == "Arad")) return true;
    return false;
}

// to add spaces in history (thx ai)
string padRight(const string &s, int width) {
    string result = s;
    while ((int)result.length() < width) {
        result += " ";
    }
    return result;
}

string padLeft(const string &s, int width) {
    string result = s;
    while ((int)result.length() < width) {
        result = " " + result;
    }
    return result;
}

void getting1stspace(int &x, int &y) {
    for (x = 0; x < H; x++) {
        for (y = 0; y < W; y++) {
            if (MAP[x][y] == ' ')
                return;
        }
    }
}

void gettingwinpoint(int &x, int &y) {
    for (x = 0; x < H; x++) {
        for (y = 0; y < W; y++) {
            if (MAP[x][y] == 'O')
                return;
        }
    }
    // ive made it cuz if i wanted to make this game with random seed map i can get exit easier :)    
    // edit: ive got no more time so it will stay as memory
}

void gettingrandspace(int &x, int &y) {
    // finding place for ghosts to spawn 
    while (true) {
        long long t = clock() + time(0);

        x = (t % H);
        y = ((t / H) % W);

        if (MAP[x][y] == ' ')
            return;
    }
}

// saving data in vector instead of history.txt in previus version cuz our ta mentioned we are not allwed to use ofstream :<
vector<string> history_names;
vector<int> history_scores;
void append2history(const string &name, int score) {
    history_names.push_back(name);
    history_scores.push_back(score); // resone of using vector instead of array

    for (int i = 0; i < history_scores.size(); i++) {
        for (int j = i + 1; j < history_scores.size(); j++) {
            if (history_scores[j] > history_scores[i]) {
                swap(history_scores[i], history_scores[j]);
                swap(history_names[i], history_names[j]);
            }
        }
    }

    // keep only top 20  (who wants to play this shit for 30 times? 💀)
    while (history_names.size() > 20) {  
        history_names.pop_back();
        history_scores.pop_back();
    }
}


void display_history() {
    clssystem();
    
    // modern user interface panel :)
    cout << "╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║                    📊 GAME HISTORY 📊                        ║\n";
    cout << "╠══════════════════════════════════════════════════════════════╣\n";
    
    if (history_names.empty()) {
        cout << "║                                                             ║\n";
        cout << "║              No game history available yet.                 ║\n";
        cout << "║              Play some games to see your scores!            ║\n";
        cout << "║                                                             ║\n";
    } else {
        cout << "║  Rank │ Player Name         │ Score                         ║\n";
        cout << "╠═══════╪═════════════════════╪═══════════════════════════════╣\n";
        
        int display_count = history_names.size() > 20 ? 20 : (int)history_names.size();
        for (int i = 0; i < display_count; ++i) {
            string name_display = history_names[i];
            if (name_display.length() > 20) name_display = name_display.substr(0, 17) + "...";
            
            // Formatting with proper spacing
            string rank_str = padLeft(to_string(i + 1), 3);
            string name_str = padRight(name_display, 19);
            string score_str = padLeft(to_string(history_scores[i]), 27);
            
            cout << "║  " << rank_str << "  │ " << name_str << " │ " << score_str << " ║\n";
        }

    }
    
    cout << "╚══════════════════════════════════════════════════════════════╝\n";
    cout << "\n[MAZE-CORE] Press any key to return to menu...";
    _getch();
}

// func to print MAP with ghosts and player
void getting_map(int player_x, int player_y, const vector<int> &ghost_x, const vector<int> &ghost_y) {
    clssystem();
    // getting copy of map and placing players
    vector<string> digit_char(H, string(W, ' ')); // ily ai :>
    for (int x=0;x<H;++x) for (int y=0;y<W;++y) digit_char[x][y] = MAP[x][y];

    //locating place of ghost by "G"
    for (int i=0;i<ghost_x.size();++i) {
        int gx = ghost_x[i], gy = ghost_y[i];
        if (gx>=0 && gx<H && gy>=0 && gy<W) {
            digit_char[gx][gy] = 'G';
        }
    }

    //locating place of player by "P"
    if (player_x>=0 && player_x<H && player_y>=0 && player_y<W)
        digit_char[player_x][player_y] = 'P';

    for (int x=0; x<H; ++x) { // printing map
        cout << digit_char[x] << "\n";
    }
}


bool moveable(int nx, int ny, bool canPassWalls = false) {
    if (nx < 0 || nx >= H || ny < 0 || ny >= W)
        return false;

    char ch = MAP[nx][ny];

    if (ch == 'O')
        return true;

    if (ch == ' ')
        return true;

    // special cheat: Arad can pass through walls XD
    if (canPassWalls)
        return true;

    return false;
}

//  finally :_)
void game(const string &player_name) {
    int player_x, player_y;
    getting1stspace(player_x, player_y);
    int exit_x, exit_y;
    gettingwinpoint(exit_x, exit_y);

    // checking if kaveh or arad are playing XD 
    bool isArad = cheat_name_checker(player_name, "Arad");
    bool isKaveh = cheat_name_checker(player_name, "kaveh");
    
    int lives = max_hearts;
    int score = 0;
    int turnCounter = 0;
    
    // time-based movement tracking
    clock_t last_move_ghost = clock();
    double timeIntervalSeconds = ghost_time_per_move;

    // spawning ghosts
    vector<int> ghost_x;
    vector<int> ghost_y;
    ghost_x.reserve(ghost_count);
    ghost_y.reserve(ghost_count);
    for (int i=0;i<ghost_count;++i) {
        int gx, gy;
        gettingrandspace(gx, gy);
        ghost_x.push_back(gx);
        ghost_y.push_back(gy);
    }

    bool gameOver = false; // to know if game is over or not
    while (!gameOver) {

        getting_map(player_x, player_y, ghost_x, ghost_y);
        cout << "\nPlayer: " << player_name << "   Lives: " << lives << "   Score: " << score << "\n";
        if (isArad) cout << "[CHEAT MODE] You can pass through walls!\n";
        if (isKaveh) cout << "[UNLIMITED HEARTS] Your hearts won't decrease!\n";
        cout << "[MAZE-CORE] Move with W A S D  |  exit = O \n";

        char cmd = 0;
        bool cmdinput = false;
        
        // for time based ghosts. making them to walk even while player is not moving as i had problem when player is watching door which is saying "ah" ghosts are just watching him untill game grow a tree :)
        if (!ghost_movement_model) {
            while (true) {
                if (_kbhit()) { // as kaveh alr used _getch() so we are be able to use _kbhit? :)
                    // https://stackoverflow.com/questions/62399203/function-of-kbhit
                    cmd = _getch();
                    cmdinput = true;
                    break;
                }
                
                // check if its time to move ghosts
                clock_t currentTime = clock();
                double elapsedSeconds = ((double)(currentTime - last_move_ghost)) / CLOCKS_PER_SEC;
                if (elapsedSeconds >= timeIntervalSeconds) {
                    // making ghosts to move there ass :>
                    for (size_t i=0;i<ghost_x.size();++i) {
                        if (ghost_x[i] < player_x) ghost_x[i]++;
                        else if (ghost_x[i] > player_x) ghost_x[i]--;

                        if (ghost_y[i] < player_y) ghost_y[i]++;
                        else if (ghost_y[i] > player_y) ghost_y[i]--;
                    }
                    last_move_ghost = currentTime; // ln 306-313  / 317-322  debugged by gpt5 as its 5PM atm xd
                    
                    // checking if ghosts finally coutched player
                    bool caught = false;
                    for (size_t i=0; i<ghost_x.size(); ++i) {
                        if (ghost_x[i] == player_x && ghost_y[i] == player_y) {
                            if (!isKaveh) lives--; // kaveh has unlimited hearts xD
                            score -= 5;
                            if (score < 0) score = 0;
                            getting1stspace(player_x, player_y);
                            // debug -> making ghosts respawn in random place afting killing player as it had problem in previus version
                            ghost_x.clear();
                            ghost_y.clear();
                            for (int j=0; j<ghost_count; ++j) {
                                int gx, gy;
                                gettingrandspace(gx, gy);
                                ghost_x.push_back(gx);
                                ghost_y.push_back(gy);
                            }
                            cout << "\nA ghost caught you! Lives left: " << lives << "   Press any key...";
                            _getch();
                            
                            if (lives <= 0) {
                                score = 0;
                                append2history(player_name, score);
                                clssystem();
                                cout << "GAME OVER! You lost all lives.\n";
                                cout << "Final Score: " << score << "\n";
                                cout << "Press any key to return to menu...";
                                _getch();
                                return;
                            }
                            caught = true;
                            break;
                        }
                    }
                    
                    if (!caught) {
                        break; // break to redraw and continue main loop
                    } else {
                        continue; // continue to restart main gmae after respawn
                    }
                }
            }
        } else {
            // only in movement based mode: just wait for input normally (its was for both models so i had few problems)
            cmd = _getch(); // thx kaveh :>
            cmdinput = true;
        }

        // only process input if bot received a command
        if (!cmdinput) {
            continue; // re-draw map and continue game
        }

        // changing to lowchars (if user have caplock on)  
        if (cmd >= 'A' && cmd <= 'Z')
            cmd = char(cmd - 'A' + 'a'); //idea is by ai. i was using a function to change all charackters to small but its trash asf

        // well, who wants to quit from such a good game be like this? :>
        if (cmd == 'o') {
            // im sure they clicked in 'o' by mistake
            cout << "\nAre you sure you want to exit? :( (y/n): ";
            char confirm = _getch();
            cout << confirm << "\n";
            if (confirm == 'y' || confirm == 'Y') {
                // they really wanted to exit? 😢
                append2history(player_name, score);
                return;
            } else {
                continue;
            }
        }

        // movement of player depending on command
        int nx = player_x, ny = player_y;
        if (cmd == 'w') nx = player_x - 1;
        else if (cmd == 's') nx = player_x + 1;
        else if (cmd == 'a') ny = player_y - 1;
        else if (cmd == 'd') ny = player_y + 1;
        else {
            continue;
        }

        if (moveable(nx, ny, isArad)) {
            // checking if next move is valid or not + he won or not
            if (MAP[nx][ny] == 'O') {
                if (smart_scoring) {
                    // smart scoring which is not best rn but ill probably update if user finished maz faster by time -> more score
                    
                    int time_bonus = max(0, 1000 - turnCounter);
                    int lives_bonus = lives * 50;
                    score += 20 + time_bonus / 10 + lives_bonus;
                } else {
                    score += 20;
                }
                append2history(player_name, score);
                clssystem();
                cout << "CONGRATULATIONS!! " << player_name << " ! You Reached The Gate Of Game.\n";
                cout << "Final Score: " << score << "\n";
                cout << "Press any key to return to menu...";
                _getch();
                return;
            } else {
                // normal movement
                player_x = nx; player_y = ny;
                if (smart_scoring) {
                    // score += 1; comment for now cuz it over give scors
                }
            }
        } else {
            // doing smt if they riched wall (optional if you want to edit code)
        }


        turnCounter++;

            // checking if ghosts found player imidientlly
        for (size_t i=0; i<ghost_x.size(); ++i) {
            if (ghost_x[i] == player_x && ghost_y[i] == player_y) {
                // if they caught player, restarting game
                if (!isKaveh) lives--; // kaveh has unlimited hearts
                score -= 5;
                if (score < 0) score = 0; // not letting player having - score :>
                getting1stspace(player_x, player_y);
                // Respawn ghosts randomly
                ghost_x.clear();
                ghost_y.clear();
                for (int j=0; j<ghost_count; ++j) {
                    int gx, gy;
                    gettingrandspace(gx, gy);
                    ghost_x.push_back(gx);
                    ghost_y.push_back(gy);
                }
                cout << "\nYou've been caught by a ghost! Lives left: " << lives << "   Press any key...";
                _getch();
                break;
            }
        }

        // if he lose all his hearts -> Game Over
        if (lives <= 0) {
            score = 0;
            append2history(player_name, score);
            clssystem();
            cout << "GAME OVER! You lost all lives.\n";
            cout << "Final Score: " << score << "\n";
            cout << "Press any key to return to menu...";
            _getch();
            return;
        }

        bool movement_of_ghosts = false;
        
        if (ghost_movement_model) {
            // movement based; ghosts move every x player moves
            if (turnCounter % ghost_movement_speed_v1 == 0) {
                movement_of_ghosts = true;
            }
        } else {
            // time based; ghosts move every x seconds
            clock_t currentTime = clock();
            double elapsedSeconds = ((double)(currentTime - last_move_ghost)) / CLOCKS_PER_SEC;
            if (elapsedSeconds >= timeIntervalSeconds) {
                movement_of_ghosts = true;
                last_move_ghost = currentTime;
            }
        }
        
        if (movement_of_ghosts) {
            for (size_t i=0;i<ghost_x.size();++i) {
                if (ghost_x[i] < player_x) ghost_x[i]++;
                else if (ghost_x[i] > player_x) ghost_x[i]--;

                if (ghost_y[i] < player_y) ghost_y[i]++;
                else if (ghost_y[i] > player_y) ghost_y[i]--;
            }
        }

        // checking if ghosts were smart or not :)
        for (size_t i=0; i<ghost_x.size(); ++i) {
            if (ghost_x[i] == player_x && ghost_y[i] == player_y) {
                if (!isKaveh) lives--; // kaveh has unlimited hearts
                score -= 5;
                if (score < 0) score = 0;
                getting1stspace(player_x, player_y);
                // respawn ghosts randomly
                ghost_x.clear();
                ghost_y.clear();
                for (int j=0; j<ghost_count; ++j) {
                    int gx, gy;
                    gettingrandspace(gx, gy);
                    ghost_x.push_back(gx);
                    ghost_y.push_back(gy);
                }
                cout << "\nA ghost caught you after moving! Lives left: " << lives << "   Press any key...";
                _getch();
                break;
            }
        }

        if (lives <= 0) {
            score = 0;
            append2history(player_name, score);
            clssystem();
            cout << "GAME OVER! You lost all lives.\n";
            cout << "Final Score: " << score << "\n";
            cout << "Press any key to return to menu...";
            _getch();
            return;
        }

        // ill probably update it and give custom score depending on time but im lazy for now :) maybe next version
        // edit: done
    }
}

void displaySettings() {
    while (true) {
        clssystem();
        cout << "┌──────────────────────────────────┐\n";
        cout << "│            GAME SETTINGS         │\n";
        cout << "├──────────────────────────────────┤\n";
        cout << "│  Current Settings:               │\n";
        cout << "│  * Number of Ghosts: " << ghost_count << "           │\n";
        cout << "│  * Ghost Speed: " << ghost_movement_speed_v1 << " (lower=faster)    │\n";
        cout << "│  * Number of Hearts: " << max_hearts << "          │\n";
        cout << "│  * Smart Scoring: ";
        if (smart_scoring){ 
            cout << "ON ";
        }else {
            cout << "OFF";}
        
        cout << "              │" << endl;
        cout << "│  * Ghost Mode: " << (ghost_movement_model ? "Movement" : "Time   ") << "          │\n";
        if (!ghost_movement_model) {
            cout << "│  * Time Interval: " << ghost_time_per_move << " sec            │\n";
        }
        cout << "├──────────────────────────────────┤\n";
        cout << "│  1)  Change Number of Ghosts     │\n";
        cout << "│  2)  Change Ghost Speed           │\n";
        cout << "│  3)  Change Number of Hearts      │\n";
        cout << "│  4)  Toggle Smart Scoring         │\n";
        cout << "│  5)  Change Ghost Movement Mode   │\n";
        if (!ghost_movement_model) {
            cout << "│  6)  Change Time Interval        │\n"; // shwing only if ghost movement is false -> time based 
        }
        cout << "│  " << (ghost_movement_model ? "6" : "7") << ")  Help / Information          │\n";
        cout << "│  " << (ghost_movement_model ? "7" : "8") << ")  Back to Main Menu           │\n";
        cout << "└──────────────────────────────────┘\n";
        cout << "\nSelect an option (1-" << (ghost_movement_model ? "7" : "8") << "): ";

        string line;
        getline(cin, line);
        if (line.empty()) continue;
        char choice = line[0];
        if (choice == '1') {
            cout << "\nGhosts (1-10): ";
            int n;
            cin >> n;
            if (n >= 1 && n <= 10) {
                ghost_count = n;
                cout << "ghosts = " << ghost_count << endl;
            } else {
                cout << "bad input\n";
            }
            cin.ignore(9999, '\n');
            cout << "any key...\n";
            _getch();
        } else if (choice == '2') {
            cout << "\nGhost Speed (1-20): ";
            int n;
            cin >> n;
            if (n >= 1 && n <= 20) {
                ghost_movement_speed_v1 = n;
                cout << "ghost speed = " << ghost_movement_speed_v1 << endl;
            } else {
                cout << "bad input\n";
            }
            cin.ignore(9999, '\n');
            cout << "any key...\n";
            _getch();
        } else if (choice == '3') {
            cout << "\nHearts (1-10): ";
            int n;
            cin >> n;
            if (n >= 1 && n <= 10) {
                max_hearts = n;
                cout << "hearts = " << max_hearts << endl;
            } else {
                cout << "bad input\n";
            }
            cin.ignore(9999, '\n');
            cout << "any key...\n";
            _getch();
        } else if (choice == '4') {
            smart_scoring = !smart_scoring;
            if (smart_scoring) {
                cout << "Smart scoring: ON" << endl;
            } else {
                cout << "Smart scoring: OFF" << endl;
            }
            cout << "any key...\n";
            _getch();
        } else if (choice == '5') {
            ghost_movement_model = !ghost_movement_model; // changing it if its alr true it will be false and if flase it will be true
            cout << "Ghost mode: ";
            if (ghost_movement_model) { // true -> movement mode and false -> time mode
                cout << "movement";
            } else {
                cout << "time";
            }
            cout << endl;
            cout << "any key...\n";
            _getch();
        } else if (choice == '6' && !ghost_movement_model) {
            cout << "\nTime interval (1-10): "; // if i had more time i would make it to have flout too so user could enter 0.5 sec etc
            int n;
            cin >> n;
            if (n >= 1 && n <= 10) {
                ghost_time_per_move = n;
                cout << "interval = " << ghost_time_per_move << endl;
            } else {
                cout << "bad input\n";
            }
            cin.ignore(9999, '\n');
            cout << "any key...\n";
            _getch();

        } else if ((choice == '6' && ghost_movement_model) || (choice == '7' && !ghost_movement_model)) {
            clssystem();
            cout << "┌────────────────────────────────────────────┐\n";
            cout << "│           📖 SETTINGS HELP 📖             │\n";
            cout << "├────────────────────────────────────────────┤\n";
            cout << "│  Number of Ghosts:                         │\n";
            cout << "│  * Controls how many ghosts spawn in game  │\n";
            cout << "│  * Range: 1-10                             │\n";
            cout << "│  * More ghosts = harder game               │\n";
            cout << "│                                            │\n";
            cout << "│  Ghost Speed:                              │\n";
            cout << "│  * How often ghosts move (every N moves)   │\n";
            cout << "│  * Range: 1-20                             │\n";
            cout << "│  * Lower number = faster ghosts            │\n";
            cout << "│  * Example: 5 = ghosts move every 5 moves  │\n";
            cout << "│                                            │\n";
            cout << "│  Number of Hearts:                         │\n";
            cout << "│  * Starting lives/hearts for player        │\n";
            cout << "│  * Range: 1-10                             │\n";
            cout << "│  * More hearts = easier game               │\n";
            cout << "│                                            │\n";
            cout << "│  Smart Scoring:                            │\n";
            cout << "│  * Advanced scoring system                 │\n";
            cout << "│  * Rewards efficient gameplay              │\n";
            cout << "│  * Bonus points for speed and skill        │\n";
            cout << "│                                            │\n";
            cout << "│  Ghost Movement Mode:                      │\n";
            cout << "│  * Time: Ghosts move every X seconds       │\n";
            cout << "└────────────────────────────────────────────┘\n";
            cout << "\nPress any key to return...";
            _getch();
        } else if ((choice == '7' && ghost_movement_model) || (choice == '8' && !ghost_movement_model)) {
            return;
        } else {
            cout << "\nInvalid choice! Press any key...";
            _getch();
        }
    }
}

// main menu
int displayMenu() {
    while (true) {
        clssystem();

        cout << "┌──────────────────────────────────┐\n";
        cout << "│         ★ MAZE RUNNER ★         │\n";
        cout << "├──────────────────────────────────┤\n";
        cout << "│  1)  Start New Game              │\n";
        cout << "│  2)  History                     │\n";
        cout << "│  3)  Settings                    │\n"; // tried my best to make it easy to use. everything in setting :)
        cout << "│  4)  Exit                        │\n";
        cout << "└──────────────────────────────────┘\n";
        cout << "\nSelect an option (1-4): ";

        char choice;
        cin >> choice;
        cin.ignore(9999, '\n');
        if (choice >= '1' && choice <= '4') {
            return choice - '0';
        }
        cout << "\nWrong! Press any key...";
        _getch();
    }
}


// starting game by getting player name
void startGame() {
    clssystem();
    string name;
    while (true) {
        cout << "Enter player name (no spaces, max 9 characters): ";
        cin >> name;
        // https://stackoverflow.com/questions/33861470/what-cin-ignore-does-exactly :>
        cin.ignore(9999, '\n'); // like a normal terminal command: while its processing, you can paste the next command, and it will do it after the current process finishes.

        if (name.empty()) {
            name = "Player";
            break;
        }
        
        if (name.length() >= 10) {
            cout << "Username must be less than 10 characters! Try again.\n\n";
            continue;
        }
        
        break;
    }

    // aking for the way user want to start game
    clssystem();
    cout << "┌──────────────────────────────────┐\n";
    cout << "│    Select Ghost Movement Mode     │\n";
    cout << "├──────────────────────────────────┤\n";
    cout << "│  1)  Movement-Based               │\n";
    string speed_str = padLeft(to_string(ghost_movement_speed_v1), 2);
    cout << "│      (Ghosts move every " << speed_str << " moves)  │\n";
    cout << "│                                  │\n";
    cout << "│  2)  Time-Based                  │\n";
    string interval_str = padLeft(to_string(ghost_time_per_move), 2);
    cout << "│      (Ghosts move every " << interval_str << " seconds) │\n";
    cout << "└──────────────────────────────────┘\n";
    cout << "\nSelect mode (1-2): ";
    
    string mode_line;
    char ch;
    cin >> ch;
    if (ch == '2') ghost_movement_model = false;
    else ghost_movement_model = true;
    cin.ignore(9999, '\n');

    // random by time. thx kaveh :>
    srand((unsigned int) time(0));

    // finally runnig game :>
    game(name);
}


int main() {
    while (true) {
        int choice = displayMenu();
        if (choice == 1) {
            startGame();
        } else if (choice == 2) {
            display_history();
        } else if (choice == 3) {
            displaySettings();
        } else if (choice == 4) {
            clssystem();
            cout << "Goodbye :> ";
            break;
        }
    }
    return 0;
}
