class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        if not heightMap or not heightMap[0]:
            return 0
        
        row, col = len(heightMap), len(heightMap[0])
        if row < 3 or col < 3:
            return 0
        
        heap = list()
        for r in range(row):
            for c in range(col):
                if r in [0, row - 1] or c in [0, col - 1]:
                    heappush(heap, (heightMap[r][c], r, c))
                    heightMap[r][c] = -1
        
        res, level = 0, 0
        while heap:
            cur_h, x, y = heappop(heap)
            level = max(level, cur_h)
            
            for r, c in [((x + 1), y), (x - 1, y), (x, y + 1), (x, y - 1)]:
                if 0 <= r < row and 0 <= c < col and heightMap[r][c] != -1:
                    heappush(heap, (heightMap[r][c], r, c))
                
                    res += max(0, level - heightMap[r][c])
                    heightMap[r][c] = -1
        return res
