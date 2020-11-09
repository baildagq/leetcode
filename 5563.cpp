#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int n = inventory.size();
        if (n == 0) return 0;
        sort(inventory.begin(), inventory.end());
        vector<int> nums(n, 1);
        int res = 0;
        int base = 1;
        for (int i = 0;i < 9; i++) {
            base *= 10;
        }
        base += 7;
        int last = n - 1;
        while(orders > 0 && last >= 0) {
            // merge last items;
            while(last > 0 && inventory[last] == inventory[last - 1]) {
                nums[last - 1] += nums[last];
                last -= 1;
            }


            // int diff = 0;
            // if (last > 0) {
            //     diff = (inventory[last] - inventory[last - 1]) * nums[last];
            // } else {
            //     diff = inventory[last] * nums[last];
            // }
            // diff = min(orders, diff);


            int item = min(orders, nums[last]);
            res += inventory[last] * item;
            res %= base;
            inventory[last] -= 1;
            orders -= item;
        }
        return res;
    }
};

int main() {
    vector<int> inventory{2, 8, 4, 10, 6};
    int orders = 20;
    int res = Solution().maxProfit(inventory, orders);
    cout << "res: " << res << endl;
	return 0;
}
