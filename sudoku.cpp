#include <bits/stdc++.h>

using namespace std;

#define mask vector<vector<bool>>

const bool findAll = false;

void show(vector<vector<int>> &board) {
    cout << "\n";
    cout << "\n";
    for (vector<int>&v:board) {
        for (int&i:v) cout << i << " ";
        cout << "\n";
    }
    cout << endl;
}


int solve(int level, int ind, vector<vector<int>> &b, mask &e, mask &lM, mask &cM, mask &sM) {
    int size = level * level;
    if (ind >= size * size) {
        show(b);
        return (!findAll);
    }
  

    if (e[ind/size][ind%size]) {
        return solve(level, ind+1, b, e, lM, cM, sM);
    }

    for (int i = 1; i <= size; i++) {
        if (lM[ind%size][i-1] || cM[ind/size][i-1] || sM[(ind/size) / level * level + (ind%size) / level][i-1]) continue;
        lM[ind%size][i-1] = true;
        cM[ind/size][i-1] = true;
        sM[(ind/size) / level * level + (ind%size) / level][i-1] = true;
        b[ind/size][ind%size] = i;

        if (solve(level, ind+1, b, e, lM, cM, sM)) return 1;

        lM[ind%size][i-1] = false;
        cM[ind/size][i-1] = false;
        sM[(ind/size) / level * level + (ind%size) / level][i-1] = false;
        b[ind/size][ind%size] = 0;
    }
    return 0;
}

int generate(int level, vector<vector<int>> &b, mask &e, mask &lM, mask &cM, mask &sM) {
    int size = level * level;

    for (int ind = 0; ind < size*size; ind++) {
        int num = b[ind/size][ind%size];

        if (!num) continue;
        if (lM[ind%size][num-1] || cM[ind/size][num-1] || sM[(ind/size) / level * level + (ind%size) / level][num-1]) return -1;

        e[ind/size][ind%size] = true;
        lM[ind%size][num-1] = true;
        cM[ind/size][num-1] = true;
        sM[(ind/size) / level * level + (ind%size) / level][num-1] = true;
    }

    return 0;
}

int readFromFile(string fileName, int level, vector<vector<int>> &b, mask &e, mask &lM, mask &cM, mask &sM) {
    int size = level * level;
    fstream file(fileName);

    int num;
    for (int ind = 0; ind < size*size; ind++) {
        file >> num;

        if (!num) continue;
        if (lM[ind%size][num-1] || cM[ind/size][num-1] || sM[(ind/size) / level * level + (ind%size) / level][num-1]) return -1;

        b[ind/size][ind%size] = num;
        e[ind/size][ind%size] = true;
        lM[ind%size][num-1] = true;
        cM[ind/size][num-1] = true;
        sM[(ind/size) / level * level + (ind%size) / level][num-1] = true;
    }

    return 0;
}

int generateRandom(int level, vector<vector<int>> &b, mask &e, mask &lM, mask &cM, mask &sM) {
    int size = level * level;

    for (int i = 0; i < 200; i++) {
        int ind = random() % (size*size);

        int num = random() % size + 1;
        if (lM[ind%size][num-1] || cM[ind/size][num-1] || sM[(ind/size) / level * level + (ind%size) / level][num-1]) continue;


        b[ind/size][ind%size] = num;
        e[ind/size][ind%size] = true;
        lM[ind%size][num-1] = true;
        cM[ind/size][num-1] = true;
        sM[(ind/size) / level * level + (ind%size) / level][num-1] = true;
    }

    return 0;
}


 
int main() {
    const int level = 3;
    const int size = level*level;

    vector<vector<int>> board(size, vector<int> (size));
    mask editableMask(size, vector<bool> (size));

    mask lineMask (size, vector<bool> (size));
    mask coluMask (size, vector<bool> (size));
    mask squaMask (size, vector<bool> (size));


    cout << "Generate or read? (G/file_name) " << endl;
    string ans;
    cin >> ans;

    if (ans == "G")
        generateRandom(level, board, editableMask, lineMask, coluMask, squaMask);
    else
        readFromFile(ans, level, board, editableMask, lineMask, coluMask, squaMask);

    cout << "Board before solving: \n" << endl;
    show(board);

    cout << "Press enter to solve... ";
    cin.ignore();
    string _; getline(cin, _);
    cout << "\nSolving..."<<endl;

    solve(level, 0, board, editableMask, lineMask, coluMask, squaMask);

    return 0;
}



