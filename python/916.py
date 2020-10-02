class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        bmap = {}
        for word in B:
            m = {}
            for c in word:
                if m.get(c) == None:
                    m[c] = 1
                else:
                    m[c] += 1
            for c in m:
                if bmap.get(c) == None:
                    bmap[c] = m[c]
                else:
                    bmap[c] = max(bmap[c], m[c])
        res = []

        # print(bmap)

        for word in A:
            # countA = [0] * 26
            # for c in word:
            #     countA[]
            amap = {}
            for c in word:
                if amap.get(c) == None:
                    amap[c] = 1
                else:
                    amap[c] += 1
            flag = True
            for c in bmap:
                if amap.get(c, 0) < bmap[c]:
                    flag = False
                    break
            if flag:
                res.append(word)
        return res


print(Solution().xxx(root))
