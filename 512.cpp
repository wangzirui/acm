#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    for (int cc = 1; cin >> r >> c && r; cc++) {
        pair<int, int> d[51][51];
        for (int i = 0; i <= 50; i++)
            for (int j = 0; j <= 50; j++)
                d[i][j] = make_pair(i, j);
        int cmd;
        cin >> cmd;
        while (cmd--) {
            string s;
            cin >> s;
            if (s == "EX") {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                swap(d[x1][y1], d[x2][y2]);
            } else {
                int n;
                cin >> n;
                set<int> ss;
                for (int i = 0; i < n; i++) {
                    int t;
                    cin >> t;
                    ss.insert(t);
                }
                vector<int> o = {0};
                for (int i = 1; i <= 50; i++)
                    if (ss.find(i) != ss.end()) {
                        if (s[0] == 'I') {
                            o.push_back(0);
                            o.push_back(i);
                        }
                    } else o.push_back(i);
                pair<int, int> t[51][51];
                if (s[1] == 'R') {
                    for (int i = 1; i < min(51, (int)o.size()); i++)
                        for (int j = 1; j <= 50; j++)
                            t[i][j] = d[o[i]][j];
                } else for (int i = 1; i <= 50; i++)
                    for (int j = 1; j < min(51, (int)o.size()); j++)
                        t[i][j] = d[i][o[j]];
                for (int i = 1; i <= 50; i++)
                    for (int j = 1; j <= 50; j++)
                        d[i][j] = t[i][j];
            }
        }
        map<int, map<int, pair<int, int>>> m;
        for (int i = 1; i <= 50; i++)
            for (int j = 1; j <= 50; j++)
                m[d[i][j].first][d[i][j].second] = make_pair(i, j);
        if (cc > 1)
            cout << "\n";
        cout << "Spreadsheet #" << cc << "\n";
        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;
            cout << "Cell data in (" << x << "," << y << ") ";
            if (m[x][y] == make_pair(0, 0))
                cout << "GONE\n";
            else cout << "moved to (" << m[x][y].first << "," << m[x][y].second << ")\n";
        }
    }
}
