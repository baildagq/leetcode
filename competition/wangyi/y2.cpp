#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define MAX 1000005
using namespace std;

vector<int> fds; // if fd is busy, fds = 1 else 0
vector<string> names;
map<int, int> subIndex;
// map<string, int> name2fd;
// map<int, string> fd2name;

int main(int argc, const char** argv)
{
    int N;
    cin >> N;
    for (int _i = 0; _i < N; _i ++) {
        int T;
        cin >> T;
        fds = vector<int>(MAX, -1);
        string operName;
        string fileName;
        int maxIndex = 0;
        for (int i = 0;i < T; i++) {
            cin >> operName;
            if (operName == "open") {
                cin >> fileName;
                names.push_back(fileName);
                // find the first fd with -1
                int fd;
                if (subIndex.size() != 0) {
                    fd = (*subIndex.begin()).first;
                    subIndex.erase(subIndex.begin());
                } else {
                    while (fds[maxIndex] != -1) {
                        maxIndex ++;
                    }
                    fd = maxIndex;
                    maxIndex ++;
                }
                fds[fd] = names.size() - 1;
                cout << fd << endl;
            }
            if (operName == "close") {
                int fd;
                cin >> fd;                
                fds[fd] = -1;
                if (fd < maxIndex) {
                    subIndex.insert(make_pair(fd, 0));
                }
            }
            if (operName == "dup") {
                int _fd;
                cin >> _fd;
                // find the first fd with -1
                int fd;
                if (subIndex.size() != 0) {
                    fd = (*subIndex.begin()).first;
                    subIndex.erase(subIndex.begin());
                } else {
                    while (fds[maxIndex] != -1) {
                        maxIndex ++;
                    }
                    fd = maxIndex;
                    maxIndex ++;
                }
                fds[fd] = fds[_fd];
                cout << fd << endl;
            }
            if (operName == "dup2") {
                int fd1, fd2;
                cin >> fd1 >> fd2;
                fds[fd2] =fds[fd1];
                if (subIndex.find(fd2) != subIndex.end()) {
                    subIndex.erase(subIndex.find(fd2));
                }
            }
            if (operName == "query") {
                int fd;
                cin >> fd;
                cout << names[fds[fd]] << endl;
            }
        }
    }
    return 0;
}
