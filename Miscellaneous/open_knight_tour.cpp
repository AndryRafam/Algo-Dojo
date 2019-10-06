/* Andry Rafam Andrianjafy - September 2018. For educational purpose only
Open knight tour problem using Backtracking algorithm.
In fact, backtracking is not the best way to solve the knight tour problem. */

#include <bits/stdc++.h>
#define B 8 // Board of 8*8 size
using namespace std;

// Check if the next square is available.
bool Safe_place (int x, int y, int Sol[B][B]) {
	return (x >= 0 && x < B && y >= 0 && y < B && Sol[x][y] == -1);
}

// Function which prints the solution.
void Solution_print (int Sol[B][B]) {
	for (int x = 0; x < B; x++) {
		for (int y = 0; y < B; y++)
			cout << setw(5) << Sol[x][y];
		cout << endl << endl;
	}
}

// Function which find a path on the board.
bool find_path (int x, int y, int move_next, int Sol[B][B], int Move_x[B], int Move_y[B]) {
	int k, next_x, next_y;
	if (move_next == B*B)
		return true;

	for (k = 0; k < 8; k++) {
		next_x = x + Move_x[k];
		next_y = y + Move_y[k];
		if (Safe_place (next_x, next_y, Sol)) {
			Sol[next_x][next_y] = move_next;
			if (find_path(next_x, next_y, move_next+1, Sol, Move_x, Move_y) == true)
				return true;
		
			else
				Sol[next_x][next_y] = -1;
		}	
	}
	return false;
}

bool KT() {
	int Sol[B][B];
	
	for (int x = 0; x < B; x++)
		for (int y = 0; y < B; y++)
			Sol[x][y] = -1;
	
	int Move_x[8] = {1,1,2,2,-1,-1,-2,-2};
	int Move_y[8] = {2,-2,1,-1,2,-2,1,-1};
	
	
	cout << endl;
	cout <<"The Knight position is initialized at >>  " <<" Line = " << 4 <<" and Column = " << 4 <<" marked by 0." << endl;

	Sol[3][3] = 0; 

	if (find_path(3,3,1,Sol,Move_x,Move_y) == false)
	{
		cout << endl;
		cout <<"NO SOLUTION\n\n";
		return false;
	}
	else {
		cout << endl;
		Solution_print(Sol);
		cout << endl;
	}	
	return true;
}

// Main program
int main() {
	KT();
	return 0;
}
	

