"""
Can you exit the maze ?
Maze problem: Starting from top left corner, find a way to the bottom right corner.
All directions is allowed Up, Down, Right, Left.
"""

class Solution:
    def existPath(self,maze)->bool:
        N = len(maze)
        M = len(maze[0])
        row = [-1,0,0,1]
        col = [0,-1,1,0]
        
        def dfs(maze,start_x,start_y)->bool:
            if start_x < 0 or start_x >= N or start_y < 0 or start_y >= M or maze[start_x][start_y]!=1:
                return False
            if start_x==N-1 and start_y==M-1:
                return True
            elif maze[start_x][start_y]==1:
                maze[start_x][start_y]=0
                for k in range(4):
                    if dfs(maze,start_x+row[k],start_y+col[k]):
                        return True
            return False
        
        if dfs(maze,0,0)==False:
            return False
        return True

if __name__=="__main__":
    maze = [[1, 0, 0, 1, 1, 1],
            [1, 1, 0, 1, 0, 1],
            [0, 1, 1, 1, 0, 1],
            [0, 0, 1, 0, 1, 1],
            [0, 0, 1, 0, 1, 0],
            [0, 0, 1, 0, 1, 1]]

    s = Solution()
    print(s.existPath(maze))
