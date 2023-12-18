// Longest commons subsequence

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

const int LIM = 100000;

int LCS(char *s, char *t, char *u) {
    int m = strlen(s);
    int n = strlen(t);
    int p = strlen(u);
    int dp[m+1][n+1][p+1];
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < p; ++k) {
                if(i==0 || j==0 || k==0) {
                    dp[i+1][j+1][k+1]=0;
                }
                else if(s[i]==t[j]&&s[i]==u[k]) {
                    dp[i+1][j+1][k+1]=dp[i][j][k]+1;
                }
                else {
                    dp[i+1][j+1][k+1]=MAX(MAX(dp[i][j+1][k+1],dp[i+1][j][k+1]),dp[i+1][j+1][k]);
                }
            }
        }
    }
    return dp[m][n][p];
}

int main() {
    char *s = malloc(LIM*sizeof(char));
    char *t = malloc(LIM*sizeof(char));
    char *u = malloc(LIM*sizeof(char));
    fgets(s,LIM,stdin);
    fgets(t,LIM,stdin);
    fgets(u,LIM,stdin);
    printf("%d\n",LCS(s,t,u));
    free(s);
    free(t);
    free(u);
    return 0;
}
