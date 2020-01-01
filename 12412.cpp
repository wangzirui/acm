#include <bits/stdc++.h>
using namespace std;

struct stu {
    string sid, cid, name;
    int s[4], added;
    
    stu(string sid1, string cid1, string name1, int a1, int b1, int c1, int d1, int added1) {
        sid = sid1;
        cid = cid1;
        name = name1;
        s[0] = a1;
        s[1] = b1;
        s[2] = c1;
        s[3] = d1;
        added = added1;
    }
    
    bool operator<(const stu b) const {
        return added < b.added;
    }
    
//    bool operator==(stu b) {
//        return sid == b.sid;
//    }
    
    stu& operator=(const stu b) {
        sid = b.sid;
        cid = b.cid;
        name = b.name;
        s[0] = b.s[0];
        s[1] = b.s[1];
        s[2] = b.s[2];
        s[3] = b.s[3];
        added = b.added;
        return *this;
    }
};

const double ep = pow(10, -5);
int ind;

int main() {
    set<stu> d;
    while (true) {
        cout << "Welcome to Student Performance Management System (SPMS).\n"
            << "\n"
            << "1 - Add\n"
            << "2 - Remove\n"
            << "3 - Query\n"
            << "4 - Show ranking\n"
            << "5 - Show Statistics\n"
            << "0 - Exit\n"
            << "\n";
        int cmd;
        cin >> cmd;
        if (cmd == 0)
            break;
        else if (cmd == 1) {
            while (true) {
                cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish.\n";
                string sid;
                cin >> sid;
                if (sid == "0")
                    break;
                string cid, name;
                int a, b, c, dd;
                cin >> cid >> name >> a >> b >> c >> dd;
                bool flag = false;
                for (stu i : d)
                    if (i.sid == sid) {
                        cout << "Duplicated SID.\n";
                        flag = true;
                    }
                if (flag)
                    continue;
                stu t(sid, cid, name, a, b, c, dd, ind++);
                d.insert(t);
            }
        } else if (cmd == 2) {
            while (true) {
                cout << "Please enter SID or name. Enter 0 to finish.\n";
                string s;
                cin >> s;
                if (s == "0")
                    break;
                int count = 0;
                set<stu> t;
                for (stu i : d)
                    if (i.sid == s || i.name == s)
                        count++;
                    else t.insert(i);
                d = t;
                cout << count << " student(s) removed.\n";
            }
        } else if (cmd == 3) {
            while (true) {
                cout << "Please enter SID or name. Enter 0 to finish.\n";
                string s;
                cin >> s;
                if (s == "0")
                    break;
                vector<int> v;
                for (stu i : d)
                    v.push_back(i.s[0] + i.s[1] + i.s[2] + i.s[3]);
                sort(v.begin(), v.end());
                for (stu i : d)
                    if (i.sid == s || i.name == s) {
                        int t = i.s[0] + i.s[1] + i.s[2] + i.s[3];
                        cout << distance(upper_bound(v.begin(), v.end(), t), v.end()) + 1 << " "
                            << i.sid << " " << i.cid << " " << i.name << " "
                            << i.s[0] << " " << i.s[1] << " " << i.s[2] << " " << i.s[3] << " "
                            << t << " " << fixed << setprecision(2) << t / 4.0 + ep << "\n";
                    }
            }
        } else if (cmd == 4) {
            cout << "Showing the ranklist hurts students' self-esteem. Don't do that.\n";
        } else if (cmd == 5) {
            cout << "Please enter class ID, 0 for the whole statistics.\n";
            string cid;
            cin >> cid;
            vector<int> total(4), pass(4), fail(4), sub(5);
            for (stu i : d)
                if (cid == "0" || i.cid == cid) {
                    int ps = 0;
                    for (int j = 0; j < 4; j++) {
                        total[j] += i.s[j];
                        if (i.s[j] >= 60) {
                            pass[j]++;
                            ps++;
                        } else fail[j]++;
                    }
                    sub[ps]++;
                }
            string sname[] = {"Chinese", "Mathematics", "English", "Programming"};
            for (int i = 0; i < 4; i++)
                cout << sname[i] << "\n"
                    << "Average Score: " << fixed << setprecision(2)
                    << (double)total[i] / (pass[i] + fail[i]) + ep << "\n"
                    << "Number of passed students: " << pass[i] << "\n"
                    << "Number of failed students: " << fail[i] << "\n"
                    << "\n";
            for (int i = 3; i >= 1; i--)
                sub[i] += sub[i + 1];
            cout << "Overall:\n"
                << "Number of students who passed all subjects: " << sub[4] << "\n"
                << "Number of students who passed 3 or more subjects: " << sub[3] << "\n"
                << "Number of students who passed 2 or more subjects: " << sub[2] << "\n"
                << "Number of students who passed 1 or more subjects: " << sub[1] << "\n"
                << "Number of students who failed all subjects: " << sub[0] << "\n"
                << "\n";
        }
    }
}

