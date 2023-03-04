#include <bits/stdc++.h>
using namespace std;

#ifdef __APPLE__
    #define CLEAR_COMMAND "clear"
#else
    #define CLEAR_COMMAND "cls"
#endif

const char boom = '#';
const char nothing = 'O';

void sleep(int seconds) {
    this_thread::sleep_for(chrono:: seconds((seconds)));
}
void print(char** a, int n) {
    cout << "\t\t\t\tYOUR MAP\n\n";
    for (int i = 0; i < n ; i++) {
        cout << "\t\t\t\t";
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\t\t  ==================================\n\n";
}

int main() {
    bool start = true;
    while (start == true) {
        system(CLEAR_COMMAND);
        int n;
        cout <<  "\t\t***** WELLCOME TO MY MINESWEEPER GAME *****\n\n";
        cout << "\t\t\t\tCHOOSE YOUR MAP \n";
        cout << "\t\t\t      ==================\n";
        cout << "\t\t\t\t[1] - MAP 3x3 \n";
        cout << "\t\t\t\t[2] - MAP 4x4\n";
        cout << "\t\t\t\t[3] - MAP 5x5\n";
        cout << "\t\t\t      ==================\n\n";
        cout << "..::Enter your selection: ";
        cin >> n;
        while (n != 1 && n != 2 && n != 3) {
            cout << '\n';
            cout << "ERROR!! PLEASE TRY AGAIN: ";
            cin >> n;
        }
        n+=2;
        char** a = new char* [n];
        char** b = new char* [n];
        for (int i = 0; i < n; i++) {
            a[i] = new char [n];
            b[i] = new char [n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                b[i][j] = nothing;
            }
        }
        srand(time(NULL));
        int x_rand,y_rand;
        for (int i = 0; i < n-1; i++) {
            x_rand = rand() % n;
            y_rand = rand() % n;
            while (b[x_rand][y_rand] == boom) {
                x_rand = rand() % n;
                y_rand = rand() % n;
            }
            b[x_rand][y_rand] = boom;
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                a[i][j] = '*';
            }
        }
        system(CLEAR_COMMAND);
        print(a,n);
        bool gameOver = false, passGame = false;
        int count = 0;
        while (gameOver == false && passGame == false){
            int x,y;
            cout << "Please enter x,y: ";
            cin >> x >> y;
            while (x < 0 || y < 0 || x >n-1 || y > n-1) {
                cout << '\n';
                cout << "Error!! Please enter x,y: ";
                cin >> x >> y;
            }
            count ++;
            a[x][y] = b[x][y];
            system(CLEAR_COMMAND);
            if (a[x][y] == boom) {
                print(b,n);
                cout << "GAME OVER!!!!!! \n";
                cout << "--------------------------------\n";
                char check;
                cout << "..:PLAY AGAIN? Y - YES ; N - NO\n";
                cin >> check;
                tolower(check);
                while (check != 'y' && check != 'n') {
                        cout << "ERROR!! PLEASE TRY AGAIN:\n";
                        cout << "PALY AGAIN? Y - YES ; N - NO\n";
                        cin >> check;
                        tolower(check);
                }
                if ( check == 'y') {
                    gameOver = true;
                }
                else {
                    gameOver = true;
                    start = false;
                    return 0;
                }
            }
            else {
                print(a,n);
                if (count < n*n - n){
                    a[x][y] = b[x][y];
                    continue;
                }
                else {
                    system(CLEAR_COMMAND);     
                    cout << "\t\t***** WINNER WINNER, CHICKEN DINER *****\n\n";
                    cout << "..:PLAY AGAIN? Y - YES ; N - NO\n";
                    char check;
                    cin >> check;
                    tolower(check);
                    while (check != 'y' && check != 'n') {
                            cout << "ERROR!! PLEASE TRY AGAIN:\n";
                            cout << "..:PLAY AGAIN? Y - YES ; N - NO\n";
                            cin >> check;
                            tolower(check);
                    }
                    if ( check == 'y') {
                        passGame = true;
                    }
                    else {
                        passGame = true;
                        start = false;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
    
