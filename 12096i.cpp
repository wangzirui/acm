#include <bits/stdc++.h>
using namespace std;

map<set<int>, int> mem;
vector<set<int>> rmem;

int check(set<int> s) {
  if (mem.find(s) != mem.end())
    return mem[s];
  rmem.push_back(s);
  return mem[s] = mem.size();
}

int main() {
  int cs;
  cin >> cs;
  while (cs--) {
    int q;
    cin >> q;
    stack<int> s;
    while (q--) {
      string c;
      cin >> c;
      if (c == "PUSH")
	s.push(check(set<int>()));
      else if (c == "DUP")
	s.push(s.top());
      else if (c == "UNION") {
	set<int> a = rmem[s.top()];
	s.pop();
	set<int> b = rmem[s.top()];
	s.pop();
	for (int i : a)
	  b.insert(i);
	s.push(check(b));
      } else if (c == "INTERSECT") {
	set<int> a = rmem[s.top()];
	s.pop();
	set<int> b = rmem[s.top()], c;
	s.pop();
	for (int i : a)
	  if (b.find(i) != b.end())
	    c.insert(i);
	s.push(check(c));
      } else {
	int a = s.top();
	s.pop();
	set<int> b = rmem[s.top()];
	s.pop();
	b.insert(a);
	s.push(check(b));
      }
      cout << rmem[s.top()].size() << "\n";
    }
    cout << "***\n";
  }
}
