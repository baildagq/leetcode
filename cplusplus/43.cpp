#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <iterator>
#include "./utils.h"


class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> n1, n2;
        vector<int> resnum(len1+len2, 0);
        for (auto& c : num1) {
            n1.push_back(c - '0');
        }
        for (auto& c : num2) {
            n2.push_back(c - '0');
        }
        for (int i = 0;i < len1;i ++) {
            for (int j = 0; j < len2; j ++) {
                resnum[i+j] += n1[i]*n2[j];
            }
        }
        int carrybit = 0;
        for (int i = 0;i < resnum.size();i ++) {
            resnum[i] += carrybit;
            carrybit = resnum[i] / 10;
            resnum[i] %= 10;
        }
        while (carrybit != 0) {
            resnum.push_back(carrybit % 10);
            carrybit /= 10;
        }
        while (resnum.back() == 0 && resnum.size() > 1) {
            resnum.pop_back();
        }
        stringstream ss;
        string res;
        reverse_copy(resnum.begin(), resnum.end(), ostream_iterator<int>(ss, ""));
        res = ss.str();
        return res;
    }
};


int main(int argc, const char** argv) {
    string num1 = "0";
    string num2 = "0";
    cout << num1 << endl << num2 << endl << Solution().multiply(num1, num2) << endl;
    return 0;
}
