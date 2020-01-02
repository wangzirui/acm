#include <bits/stdc++.h>
using namespace std;

const int o[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
char d[9][9];
bool white;

bool range(int x, int y) {
  return 1 <= x && x <= 8 && 1 <= y && y <= 8;
}

bool sandwich(int x, int y, int i) {
  int c = 0;
  do {
    x += o[i][0];
    y += o[i][1];
    c++;
  } while (range(x, y) && d[x][y] == (white ? 'B' : 'W'));
  return c > 1 && range(x, y) && d[x][y] == (white ? 'W' : 'B');
}

vector<pair<int, int>> list_moves() {
  vector<pair<int, int>> r;
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++)
      if (d[i][j] == '-') {
	bool flag = false;
	for (int k = 0; k < 8; k++) {
	  //cout << i << " " << j << " " << k << " " << sandwich(i, j, k) << "\n";
	  if (sandwich(i, j, k))
	    flag = true;
	}
	if (flag)
	  r.push_back(make_pair(i, j));
      }
  return r;
}

void move(int x, int y) {
  d[x][y] = (white ? 'W' : 'B');
  for (int i = 0; i < 8; i++)
    if (sandwich(x, y, i))
      for (int xx = x + o[i][0], yy = y + o[i][1];
	   range(xx, yy) && d[xx][yy] == (white ? 'B' : 'W');
	   xx += o[i][0], yy += o[i][1])
	d[xx][yy] = (white ? 'W' : 'B');
}

pair<int, int> count() {
  pair<int, int> r;
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++)
      if (d[i][j] == 'W')
	r.second++;
      else if (d[i][j] == 'B')
	r.first++;
  return r;
}

int main() {
  int cs;
  cin >> cs;
  for (int cc = 1; cc <= cs; cc++) {
    if (cc > 1)
      cout << "\n";
    for (int i = 1; i <= 8; i++)
      for (int j = 1; j <= 8; j++)
	cin >> d[i][j];
    char c;
    cin >> c;
    white = c == 'W';
    while (cin >> c)
      if (c == 'P') {
	for (int i = 1; i <= 8; i++) {
	  for (int j = 1; j <= 8; j++)
	    cout << d[i][j];
	  cout << "\n";
	}
      } else if (c == 'Q') {
	for (int i = 1; i <= 8; i++) {
	  for (int j = 1; j <= 8; j++)
	    cout << d[i][j];
	  cout << "\n";
	}
	break;
      } else if (c == 'L') {
	vector<pair<int, int>> v = list_moves();
	if (v.empty())
	  cout << "No legal move.\n";
	else {
	  for (int i = 0; i < v.size(); i++)
	    cout << (i ? " " : "") << "(" << v[i].first << "," << v[i].second << ")";
	  cout << "\n";
	}
      } else if (c == 'M') {
	char a, b;
	cin >> a >> b;
	int aa = a - '0';
	int bb = b - '0';
	vector<pair<int, int>> v = list_moves();
	if (find(v.begin(), v.end(), make_pair(aa, bb)) == v.end())
	  white = !white;
	move(aa, bb);
	pair<int, int> total = count();
	cout << "Black - " << setw(2) << total.first << " White - " << setw(2) << total.second << "\n";
	white = !white;
      }
  }
}
