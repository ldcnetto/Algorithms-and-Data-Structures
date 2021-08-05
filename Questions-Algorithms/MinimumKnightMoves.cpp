#include <bits/stdc++.h>
using namespace std;

struct tabuleiro {
    string pos;
    int dest;
};

int bfs(tabuleiro posInicial, tabuleiro posFinal) {
    int sentidoHor[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int sentidoVer[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int posX, posY;
    bool visitado[8][8]{false};
    string temp = "12";

    queue<tabuleiro> q;
    q.push(posInicial);

    while(!q.empty()) {
        tabuleiro curr = q.front();
        q.pop();

        if (curr.pos[0] == posFinal.pos[0] && curr.pos[1] == posFinal.pos[1]) {
            return curr.dest;
        }

        posX = (int)(curr.pos[0] - 'a');
        posY = (int)(curr.pos[1] - '1');

        if (!visitado[posX][posY]) {   
            visitado[posX][posY] = true;
            for (int i = 0; i < 8; i++) {
                if ((posX + sentidoHor[i] >= 0) && (posY + sentidoVer[i] >= 0) && (posX + sentidoHor[i] < 8) && (posY + sentidoVer[i] < 8)) {
                    temp[0] = (curr.pos[0] + sentidoHor[i]);
                    temp[1] = (curr.pos[1] + sentidoVer[i]);
                    q.push((tabuleiro){.pos = temp, .dest = curr.dest + 1});
                }
            }
        }
    }
    return -1;
};

int main() {   
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    string posInicial, posFinal;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> posInicial >> posFinal;
        cout << bfs((tabuleiro){.pos = posInicial, .dest = 0}, (tabuleiro){.pos = posFinal, .dest = 0}) << "\n";
    }
    return 0;
}