#include <bits/stdc++.h>
using namespace std;

#ifdef __APPLE__
    #define CLEAR_COMMAND "clear"
#else
    #define CLEAR_COMMAND "cls"
#endif

const char boom = '#';
const char nothing = 'O';

void print(char** a, int m , int n) {
    cout << "\t\t\t\tHERE IS YOUR MAP:\n\n";
    for (int i = 0; i < m ; i++) {
        cout << "\t\t\t\t";
        for (int j = 0; j < n; j++) {
            if (a[i][j] == boom) {
                cout << "\033[31m" << a[i][j] << "\033[0m" << " ";
            }
            else
                cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "==================================\n\n";
}

int count_index(char** a,int m, int n ,int i, int j) {
    int count = 0;
    for (int k = i-1; k <= i+1; k++) {
        for (int l = j-1; l <= j+1; l++) {
            if (k >=0 && l >= 0 && k < m && k < n){
                if (a[k][l] == boom) count++;
                else {
                    continue;
                }
            }
            else continue;
        }
    }
    return count;
}

void render_map_with_booms (char** b, int m, int n ) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char count_ch = (count_index(b,m,n,i,j)) + 48;
            if (b[i][j] != boom) b[i][j] = count_ch;
        }
    }
}

int main() {
    bool start = true;
    while (start == true) {
        system(CLEAR_COMMAND);
        int m,n;
        cout <<  "\t\t     ***** WELLCOME TO MY MINESWEEPER GAME *****\n\n";
        cout << "\t\t\t\tLET'S CUSTOM YOUR MAP ! \n";
        cout << "\t\t\t      ==========================\n\n";
        cout << "..::Enter your Map [m x n]: ";
        cin >> m >> n;
        while (m <= 1 || n <= 1) {
            cout << '\n';
            cout << "ERROR!! [m > 1 and n > 1] PLEASE TRY AGAIN: ";
            cin >> m >> n;
        }
        while (m > 40 || n > 40) {
            cout << '\n';
            cout << "ERROR!! THAT MAP IS TOO LARGE! PLEASE TRY AGAIN: ";
            cin >> m >> n;
        }
        
        int num_booms;
        cout << "..::Enter the number of bombs you want [ < " << m*n << " ] : ";
        cin >> num_booms;
        while (num_booms >= m*n) {
            cout << '\n';
            cout << "ERROR!! [ bombs < " << m*n << " ] PLEASE ENTER  TRY AGAIN: ";
            cin >> num_booms;
        }

        while (num_booms <= 0) {
            cout << '\n';
            cout << "ERROR!! [ bombs > 0 ] PLEASE ENTER  TRY AGAIN: ";
            cin >> num_booms;
        }

        char** a = new char* [m];
        char** b = new char* [m];
        for (int i = 0; i < m; i++) {
            a[i] = new char [n];
            b[i] = new char [n];
        }
        
        srand(time(NULL));
        int x_rand,y_rand;
        for (int i = 0; i < num_booms; i++) {
            x_rand = rand() % m;
            y_rand = rand() % n;
            while (b[x_rand][y_rand] == boom) {
                x_rand = rand() % m;
                y_rand = rand() % n;
            }
            b[x_rand][y_rand] = boom;
        }

        render_map_with_booms(b,m,n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                a[i][j] = '*';
            }
        }
        system(CLEAR_COMMAND);
        print(a,m,n);
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
                print(b,m,n);
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
                    delete [] a;
                    delete [] b;
                }
                else {
                    gameOver = true;
                    start = false;
                    delete [] a;
                    delete [] b;
                    return 0;
                }
            }
            else {
                print(a,m,n);
                if (count < m*n - num_booms){
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
                        delete [] a;
                        delete [] b;
                    }
                    else {
                        passGame = true;
                        start = false;
                        delete [] a;
                        delete [] b;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
    
