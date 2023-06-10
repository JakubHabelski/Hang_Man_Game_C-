
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>

#ifdef _WIN32
#include <cstdlib>
#else
#include <unistd.h>
#endif

using namespace std;

void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::cout << "\033[2J\033[1;1H";
    std::cout.flush();
#endif
}

string pass[] = {
    "hangman game",
    "word puzzle",
    "computer science",
    "game development",
    "guessing game",
    "fun activity",
    "logic puzzle",
    "vocabulary word",
    "challenge accepted",
    "brain teaser",
    "team effort",
    "strategy game",
    "mind game",
    "trivia question",
    "learning experience",
    "problem solving",
    "entertainment industry",
    "wordplay game",
    "creative thinking",
    "mind-boggling",
    "knowledge base",
    "critical thinking",
    "brainstorming session",
    "word formation",
    "educational game",
    "brain exercise",
    "thinking outside the box",
    "word association",
    "word guessing",
    "language skills",
    "intellectual challenge"
};

string random_pass(string pass[]) {
    int index = rand() % 30-1;
    return pass[index];
}

void draw_pass(string pass, bool is_guessed[]) {
    for (int i = 0; i < pass.size(); i++) {
        if (pass[i] == ' ') {
           cout << " ";
        }
        else if (is_guessed[i] == false && pass[i] != ' ') {
            cout << "_";
        }
        else {
            cout << pass[i];
        }
    }
    cout << endl;
}

void hide_password(string pass, bool is_guessed[]) {
    for (int i = 0; i < pass.size(); i++) {
        is_guessed[i] = false;
    }
}

void create_board(char board[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = ' ';
        }
    }
}

void draw_board(char board[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}
void check_error(char key, string pass, bool is_guessed[], bool& is_changed, int& errors) {
    cin >> key;
    for (int i = 0; i < pass.size(); i++) {
        if (key == pass[i]) {
            is_guessed[i] = true;
            is_changed = true;
        }
    }
    if (is_changed == false) {
        errors++;
    }
}
void draw_hang_man(int errors, char board[][10]) {
    switch (errors) {
    case 1: board[9][1] = '|'; break;
    case 2: board[8][1] = '|'; break;
    case 3: board[7][1] = '|'; break;
    case 4: board[6][1] = '|'; break;
    case 5: board[5][1] = '|'; break;
    case 6: board[4][1] = '|'; break;
    case 7: board[3][1] = '|'; break;
    case 8: board[2][1] = '|'; break;
    case 9: board[1][2] = '_'; break;
    case 10: board[1][3] = '_'; break;
    case 11: board[1][4] = '_'; break;
    case 12: board[1][5] = '_'; break;
    case 13: board[1][6] = '_'; break;
    case 14: board[2][6] = '|'; break;
    case 15: board[3][6] = 'O'; break;
    case 16: board[4][6] = '|'; break;
    case 17: board[4][5] = '\\'; break;
    case 18: board[4][7] = '/'; break;
    case 19: board[4][6] = '|'; break;
    case 20: board[5][6] = '|'; break;
    case 21: board[6][7] = '\\'; break;
    case 22: board[6][5] = '/'; break;
    }  
   }
void game_over(int errors, char board[][10]) {
    if (errors > 22) {
        clearScreen();
        draw_board(board);
        std::cout << "GAME OVER";
    }
}




int main() {
    char board[10][10];
    //string pass[] = { "", ""};
    srand(time(0));
    bool is_guessed[20];
    char key=' ';
    bool is_changed=false;
    int errors = 0;
    
    create_board(board);
    string temp_pass = random_pass(pass);
    hide_password(temp_pass, is_guessed);
    
    
    while (errors < 23) {   
        is_changed = false; 
        clearScreen();        
        draw_pass(temp_pass, is_guessed);
        draw_hang_man(errors, board); 
        draw_board(board);
        check_error(key, temp_pass, is_guessed, is_changed, errors);           
        game_over(errors, board);   
                
    }
    return 0;
}