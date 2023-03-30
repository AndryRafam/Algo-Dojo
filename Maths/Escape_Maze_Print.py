"""
Can you exit the maze ?
Maze problem: Starting from top left corner, find a way to the bottom right corner.
All directions are allowed Up, Down, Right, Left.
Print the solution if there is one, otherwise, print NO PATH.
"""

def path(maze)->bool:
    N = len(maze)
    M = len(maze[0])
    sol = [[0 for j in range(M)] for i in range(N)]
    if dfs(maze,0,0,sol):
        printPath(sol)
        return True
    print("NO PATH")
    return False

def printPath(maze):
    for i in range(len(maze)):
        for j in range(len(maze[0])):
            print(maze[i][j], end=" ")
        print("\n")

def dfs(maze,x,y,sol)->bool:
    N = len(maze)
    M = len(maze[0])
    dx = [-1,0,0,1]
    dy = [0,-1,1,0]
    if x < 0 or x >= N or y < 0 or y >= M or maze[x][y]!=1:
        return False
    if x==N-1 and y==M-1:
        sol[x][y]=1
        return True
    elif maze[x][y]==1:
        maze[x][y]='$'
        for k in range(4):
            if dfs(maze,x+dx[k],y+dy[k],sol):
                sol[x][y]=1
                return True
    return False

if __name__=="__main__":
    maze = [[1, 0, 0, 0, 0],
            [1, 0, 1, 1, 1],
            [1, 1, 1, 0, 1],
            [0, 0, 0, 1, 1],
            [1, 1, 0, 1, 0],
            [0, 0, 0, 1, 1]]
    path(maze);
