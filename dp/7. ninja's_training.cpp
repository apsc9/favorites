// the idea is to use dp here as greedy wont give us the most optimal answer
// example consider this : 
// 10 50 1
// 5 100 11   : greedy gives us 61, but optimal soln gives us 110
// find the recurrence relation first by taking into account the prev day choice as an additional 
// parameter here, then just convert it to dp as overlapping subproblems can be seen

// Bottom Up approach : memoization :
// TC = O(n*4 *3) ; There are N*4 states and for every state, we are running a for loop iterating three times
// SC = O(n)   +  O(n*4) , recursion stack space(O(N)) and a 2D array (again O(N*4))
//    recursion   array

int func(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    int mx ;
    if (day == 0){
        mx = 0 ;
        for (int i = 0 ; i < 3 ; i++){
            if (i != last){
                mx = max(mx, points[0][i]);
            }
        }
        return mx;
    }

    if (dp[day][last] != -1){
        return dp[day][last];
    }

    mx = 0 ;
    for (int i = 0 ; i < 3 ; i++){
        if (i != last){
            int point = points[day][i] + func(day-1, i, points, dp);
            mx = max(mx, point);
        }
    }
    return dp[day][last] = mx ;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n, vector<int>(4, -1));
    return func(n-1, 3, points, dp);
}


// Bottom Up Approach : Tabulation 
// TC = O(n*4*3) , 
// SC = O(n*4) , there is no recursion stack space over here , only external array

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // dp[i][j] represents the maximum points at day i, considering the last activity as j
    vector<vector<int>>dp(n, vector<int>(4,0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0],max(points[0][1], points[0][2]));

    for (int day = 1 ; day < n ; day++){
        for (int last = 0 ; last < 4 ; last++){
            dp[day][last] = 0 ;

            for (int i = 0 ; i < 3 ; i++){
                if (i != last){
                    int point = points[day][i] + dp[day-1][i];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n-1][3];
}

// Space optimized approach: we can optimize the space as we only need previous days array 
// in order to compute the result for the current day 
// TC = O(n*4*3)
// SC = O(4) == O(1)

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>prev(4,0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0],max(points[0][1], points[0][2]));

    for (int day = 1 ; day < n ; day++){
        vector<int>temp(4,0);
        for (int last = 0 ; last < 4 ; last++){
            temp[last] = 0 ;

            for (int i = 0 ; i < 3 ; i++){
                if (i != last){
                    temp[last] = max(temp[last], points[day][i]+ prev[i]);
                }
            }
        }
        prev = temp ;
    }
    return prev[3];
}

// TC = O(N*4*3)
// SC = O(4)