#include <bits/stdc++.h>
using namespace std;

char d[11][10];

int between(int x, int y, int a, int b) {
    int r = 0;
    if (x == a) {
        for (int i = min(y, b) + 1; i < max(y, b); i++)
            if (d[x][i])
                r++;
    } else if (y == b) {
        for (int i = min(x, a) + 1; i < max(x, a); i++)
            if (d[i][y])
                r++;
    } else r = -1;
    return r;
}

bool mated(int xx, int yy) {
    int o[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        int x = xx + o[i][0];
        int y = yy + o[i][1];
        if (x < 1 || x > 3 || y < 4 || y > 6)
            continue;
        bool attacked = false;
        for (int j = 1; j <= 10; j++)
            for (int k = 1; k <= 9; k++)
                if (d[j][k] == 'G') {
                    if (k == y && between(x, y, j, k) == 0)
                        attacked = true;
                } else if (d[j][k] == 'R') {
                    //cout << j << " " << k << "\n";
                    if ((x == j || y == k) && !(x == j && y == k) && between(x, y, j, k) == 0)
                        attacked = true;
                } else if (d[j][k] == 'C') {
                    if ((x == j || y == k) && !(x == j && y == k) && between(x, y, j, k) == 1)
                        attacked = true;
                } else if (d[j][k] == 'H') {
                    if ((x == j - 2 && abs(k - y) == 1 && d[j - 1][k] == 0) ||
                        (x == j + 2 && abs(k - y) == 1 && d[j + 1][k] == 0) ||
                        (y == k - 2 && abs(x - j) == 1 && d[j][k - 1] == 0) ||
                        (y == k + 2 && abs(x - j) == 1 && d[j][k + 1] == 0))
                        attacked = true;
                }
        //cout << x << " " << y << " " << attacked << "\n";
        if (!attacked)
            return false;
    }
    return true;
}

int main() {
    int n, x, y;
    while (cin >> n >> x >> y && n) {
        for (int i = 1; i <= 10; i++)
            for (int j = 1; j <= 9; j++)
                d[i][j] = 0;
        while (n--) {
            char p;
            int a, b;
            cin >> p >> a >> b;
            d[a][b] = p;
        }
        if (mated(x, y))
            cout << "YES\n";
        else cout << "NO\n";
    }
}

