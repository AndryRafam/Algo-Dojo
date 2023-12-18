/*Levenshtein Distance*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

#define LIM 100000

int levenshteinDistance(char s[LIM], char t[LIM]) {
    int m = strlen(s);
    int n = strlen(t);
    int dp[m+1][n+1];
    int cost;
    for(int i = 0; i <= m; ++i) {
        dp[i][0]=i;
    }
    for(int j = 0; j <= n; ++j) {
        dp[0][j]=j;
    }
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            cost = (*(s+i-1)==*(t+j-1)) ? 0:1;
            dp[i][j] = MIN(MIN(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+cost);
        }
    }
    return dp[m][n];
}

int main() {
    char s[LIM];
    char t[LIM];
    fgets(s,LIM,stdin);
    fgets(t,LIM,stdin);
    printf("%d\n",levenshteinDistance(s,t));
    return 0;
}
