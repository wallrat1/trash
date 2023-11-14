#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <cstdlib>
#include <random>
#include <fstream>
using namespace std;
bool isMany(size_t a, size_t b) {
    return static_cast<int>(a) + 1 < static_cast<int>(b);
}
bool isSm(size_t a) {
    return static_cast<int>(a) - 1 >= 0;
}
void Output(vector<vector<char>>& mask, size_t& m, size_t& n) {
    system("cls");
    for (size_t i = 0; i != m; ++i) {
        for (size_t j = 0; j != n; ++j) {
            if (j != n - 1) {
                cout << mask[i][j] << " ";
            }
            else {
                cout << mask[i][j] << "\n";
            }
        }
    }
    cout << endl;

}
void Proverka(vector<vector<char>>& pole, size_t x, size_t y, size_t m, size_t n) {
    if (isMany(x, m) && isMany(y, n)) {
        if (pole[x + 1][y + 1] != '*') {
            pole[x + 1][y + 1] += 1;
        }
    }
    if (isSm(x) && isSm(y)) {
        if (pole[x - 1][y - 1] != '*') {
            pole[x - 1][y - 1] += 1;
        }
    }
    if (isMany(x, m)) {
        if (pole[x + 1][y] != '*') {
            pole[x + 1][y] += 1;
        }
    }
    if (isMany(y, n)) {
        if (pole[x][y + 1] != '*') {
            pole[x][y + 1] += 1;
        }
    }
    if (isSm(x)) {
        if (pole[x - 1][y] != '*') {
            pole[x - 1][y] += 1;
        }
    }
    if (isSm(y)) {
        if (pole[x][y - 1] != '*') {
            pole[x][y - 1] += 1;
        }
    }
    if (isMany(x, m) && isSm(y)) {
        if (pole[x + 1][y - 1] != '*') {
            pole[x + 1][y - 1] += 1;
        }
    }
    if (isSm(x) && isMany(y, n)) {
        if (pole[x - 1][y + 1] != '*') {
            pole[x - 1][y + 1] += 1;
        }
    }

}
void Choise(vector<vector<char>>& mask, char WASD, size_t& x, size_t& y, size_t m, size_t n, char& cash) {
    switch (WASD)
    {
    case('w'):
        if (isSm(x)) {
            mask[x][y] = cash;
            x--;
            cash = mask[x][y];
            mask[x][y] = 'X';
        }
        break;
    case('s'):
        if (isMany(x, m)) {
            mask[x][y] = cash;
            x++;
            cash = mask[x][y];
            mask[x][y] = 'X';
        }
        break;
    case('d'):
        if (isMany(y, n)) {
            mask[x][y] = cash;
            y++;
            cash = mask[x][y];
            mask[x][y] = 'X';
        }
        break;
    case('a'):
        if (isSm(y)) {
            mask[x][y] = cash;
            y--;
            cash = mask[x][y];
            mask[x][y] = 'X';
        }
        break;

    default:
        break;
    }

}
bool SortKey(vector<string>& a, vector<string>& b) {
    return stoi(a[1]) > stoi(b[1]);
}
void Open(vector<vector<char>>& mask, vector<vector<char>>& pole, size_t x, size_t y, size_t m, size_t n) {
    if (x < 0 || x >= m || y < 0 || y >= n) {
        return;
    }
    if (mask[x][y] != '#') {
        return;
    }
    mask[x][y] = pole[x][y];
    if (mask[x][y] != '0') {
        return;
    }
    Open(mask, pole, x + 1, y, m, n);
    Open(mask, pole, x - 1, y, m, n);
    Open(mask, pole, x, y + 1, m, n);
    Open(mask, pole, x, y - 1, m, n);
    Open(mask, pole, x + 1, y + 1, m, n);
    Open(mask, pole, x - 1, y - 1, m, n);
    Open(mask, pole, x + 1, y - 1, m, n);
    Open(mask, pole, x - 1, y + 1, m, n);
}
bool tasks(int mincount, int c) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> ran(0, 100);
    int num1 = ran(gen); int num2 = ran(gen); int rez;
    if (mincount < c / 2) {
        cout << num1 << " + " << num2 << " =  ";
        cin >> rez;
        return rez == (num1 + num2);
    }
    else {
        cout << num1 << " * " << num2 << " =  ";
        cin >> rez;
        return rez == (num1 * num2);
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    string name;
    cout << "Введите имя: ";
    getline(cin, name);
    size_t m, n;
    int c;
    size_t x, y;
    size_t k;
    cout << "Выберите уровень мложности(1-3 опционально)" << endl;
    cin >> k;
    m = k * 6;
    n = k * 8;
    c = (n * m) / 8;
    cout << c << " " << m << " " << n << endl;
    vector<vector<char>> pole(m, vector<char>(n));
    vector<vector<char>> mask(m, vector<char>(n));
    cout << "1";
    for (size_t i = 0; i != m; ++i) {
        for (size_t j = 0; j != n; ++j) {
            pole[i][j] = '0';
            mask[i][j] = '#';
        }
    }
    cout << "2";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> strok(0, m - 1);
    uniform_int_distribution<int> stolb(0, n - 1);
    for (size_t i = 0; i < c; ++i) {
        do {
            x = strok(gen); y = stolb(gen);
        } while (pole[x][y] == '*');
        pole[x][y] = '*';
        Proverka(pole, x, y, m, n);
    }
    cout << "3";
    bool end = false;
    int mincount = 0;
    int flags = 0;
    char move;
    char cash = mask[0][0];
    char point = '0';
    Output(mask, m, n);
    while (!end) {
        cout << "f - поставить флаг, с - открыть клетку" << "(у вас осталось " << c - flags << " флагов)" << endl;
        do {
            cin >> move;
        } while (move != 'f' && move != 'c');
        if (move == 'f') {
            if (flags == c) {
                cout << "Флаги кончились" << endl; continue;
            }
        }
        cout << "Выберите клетку WASD" << endl;
        x = 0; y = 0; cash = mask[0][0]; mask[0][0] = 'X';
        Output(mask, m, n);
        while (true) {
            point = _getch();
            if (point == 13) { break; }
            Choise(mask, point, x, y, m, n, cash);
            Output(mask, m, n);
        }
        mask[x][y] = cash;
        if (move == 'c') {
            if (pole[x][y] == '*') { cout << "Вы проиграли" << endl; break; }
            Open(mask, pole, x, y, m, n);
            Output(mask, m, n);
        }
        if (move == 'f') {
            if (mask[x][y] == '+') {
                flags--;
                if (pole[x][y] == '*') { mincount--; }
                mask[x][y] == '#';
            }
            else if (mask[x][y] == '#') {
                flags++;
                if (!tasks(mincount, c)) { cout << "Вы взорвались(" << endl; break; }
                mask[x][y] = '+';
                if (pole[x][y] == '*') { mincount++; }
                if (mincount == c) { cout << "ПОБЕДА!" << endl; break; }
            }
            else {
                cout << "Нельзя ставить флаг на открытую клетку" << endl;
            }
            Output(mask, m, n);
        }

    }
    ifstream fileif("score_list.txt");
    vector<vector<string>> score(5, vector<string>(2));
    string line = "";
    int f = 1;
    for (int i = 0; i < 5; i++) {
        getline(fileif, line);
        score[i][0] = line.substr(0, line.find(' ')); score[i][1] = line.substr(line.find(' ') + 1);
        if (stoi(score[i][1]) > mincount && score[i][0] == name) {
            score[i][1] = to_string(mincount);
            f = 0;
        }
    }
    if (f == 1 && stoi(score[4][1]) < mincount) {
        score[4][1] = to_string(mincount);
        score[4][0] = name;
    }
    sort(score.begin(), score.end(), SortKey);
    fileif.close();
    ofstream fileof("score_list.txt");
    cout << "Score List: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << score[i][0] << " " << score[i][1] << endl;
        if (i != 4) { fileof << score[i][0] << " " << score[i][1] << "\n"; }
        else { fileof << score[i][0] << " " << score[i][1]; }
    }
    fileof.close();
}