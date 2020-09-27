#include "./utils.h"

class Solution {
    vector<int> numStack;
    vector<char> operStack;

public:
    int cal(int n1, int n2, char oper)
    {
        return (oper == '+') ? n1 + n2 : n1 - n2;
    }

    void trycal()
    {
        while (operStack.size() != 0 && operStack.back() != '(') {
            int n2 = numStack.back();
            numStack.pop_back();
            int n1 = numStack.back();
            numStack.pop_back();
            char oper = operStack.back();
            operStack.pop_back();
            numStack.push_back(cal(n1, n2, oper));
        }
    }

    int calculate(string s)
    {
        // method-0: 状态
        int base = -1;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            char c = s[i];
            if (c == ' ' || c == '(' || c == ')' || c == '+' || c == '-') {
                if (base != -1) {
                    numStack.push_back(base);
                    trycal();
                    base = -1;
                }
                if (c == ')') {
                    // pop 出tryCal完成后暴露的(
                    operStack.pop_back();
                    trycal();
                }
                if (c == '(' || c == '+' || c == '-') {
                    operStack.push_back(c);
                }
            } else {
                base = (base == -1) ? c - '0' : c - '0' + base * 10;
                if (i == size - 1) {
                    numStack.push_back(base);
                    trycal();
                }
            }
            // printf("%c ", c);
            // printf("mid:\n");
            // printVector(numStack);
            // printVector(operStack);
        }
        trycal();
        return numStack[0];
    }
};

int main(int argc, const char** argv)
{
    string s = "(29+(72 - 36) -(42) + (7+2+(1-2)-4))";
    printf("res: %d\n", Solution().calculate(s));
    return 0;
}
