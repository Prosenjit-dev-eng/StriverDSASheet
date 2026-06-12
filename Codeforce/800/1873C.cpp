#include<bits/stdc++.h>
using namespace std;
const int score[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,1,1,1,1,1,1,1,1,1}
};
int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        char a[10][10]; // 10x10 grid to store the target for each test case
        for (int i = 0; i < 10; i++) // Loop through each row of the grid
        {
            string s;
            cin >> s; // Read each row as a string
            for (int j = 0; j < 10; j++) // Loop through each column of the grid
            {
                a[i][j] = s[j]; // Store each character in the grid
            }
        }

        int total_score = 0; // Variable to accumulate the total score for the current test case
        for (int i = 0; i < 10; i++) // Loop through each row of the grid
        {
            for (int j = 0; j < 10; j++) // Loop through each column of the grid
            {
                if (a[i][j] == 'X') // Check if there is an arrow at this position
                {
                    total_score += score[i][j]; // Add the score for this position to the total score
                }
            }
        }
        cout << total_score << endl;
    }
    return 0;
}