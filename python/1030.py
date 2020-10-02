class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        array = [[1]*C for i in range(R)]
        stack = [[r0, c0]]
        array[r0][c0] = 0
        res = []
        diffx = [-1, 1, 0, 0]
        diffy = [0, 0, 1, -1]
        while len(stack) != 0:
            res += stack
            newStack = []
            for p in stack:
                for i in range(4):
                    x = p[0] + diffx[i]
                    y = p[1] + diffy[i]
                    if 0 <= x and x < R and 0 <= y and y < C and array[x][y] == 1:
                        newStack.append([x, y])
                        array[x][y] = 0
            stack = newStack
        return res

print(Solution().allCellsDistOrder(root))
