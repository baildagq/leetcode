#include "./utils.h"



/*
 * // method-1: 枚举, tle
class Solution {
private:
    int res = 0;
    vector<int> item;
public:
    void solve(const string& s, const string& t, int si, int ti){
        if (ti == (int)t.length()) {
            res += 1;
            return;
        }
        for (int i = si; i < (int)s.length(); i++) {
            if (s[i] == t[ti]) {
                item.push_back(i);
                solve(s, t, i+1, ti+1);
                item.pop_back();
            }
        }
    }
    int numDistinct(string s, string t) {
        solve(s, t, 0, 0);
        return res;
    }
};
*/

#define uint_32 unsigned int

class Solution {
    int res = 0;
public:
    int numDistinct(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        vector<vector<uint_32>> dp(tlen+1, vector<uint_32>(slen+1, 0));
        for (int i = 0;i < slen+1; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1;i < tlen+1; i++) {
            for (int j = 1; j < slen+1; j++) {
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[tlen][slen]; 
    }
};


int main(int argc, const char** argv)
{
    // string s1 = "adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc";
    // string s2 = "bcddceeeebecbc";
    string s1 = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
    string s2 = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
    printf("res: %d\n", Solution().numDistinct(s1, s2));
    return 0;
}
