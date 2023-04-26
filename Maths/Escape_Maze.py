"""
Can you exit the maze ?
Maze problem: Starting from top left corner, find a way to the bottom right corner.
All directions are allowed Up, Down, Right, Left.
"""

class Solution:
    def existPath(self,maze)->bool:
        N = len(maze)
        M = len(maze[0])
        row = [-1,0,0,1]
        col = [0,-1,1,0]
        
        def dfs(maze,x,y)->bool:
            if x < 0 or x >= N or y < 0 or y >= M or maze[x][y]!=1:
                return False
            if x==N-1 and y==M-1:
                return True
            elif maze[x][y]==1:
                maze[x][y]='$' # block after visit
                for k in range(4):
                    if dfs(maze,x+row[k],y+col[k]):
                        return True
                maze[x][y] = 1 # backtrack and unmark the cell as visited
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
