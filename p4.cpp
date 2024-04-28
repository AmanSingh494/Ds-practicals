#include <bits/stdc++.h>
using namespace std;
void findSolutions(int n, int C)
{
    vector<int> combination(n, 0);
    while (true)
    {
        int sum = 0;
        for (int num : combination)
        {
            sum += num;
        }
        if (sum == C)
        {
            for (int num : combination)
            {
                cout << num << ' ';
            }
            cout << '\n';
        }

        // Generate next combination
        for (int i = 0; i < n; ++i)
        {
            if (combination[i] < C)
            {
                ++combination[i];
                break;
            }
            else
            {
                combination[i] = 0;
            }
        }

        // Check if we've gone through all combinations
        if (combination == vector<int>(n, 0))
        {
            break;
        }
    }
}

int main()
{
    int n = 3;
    int C = 4;
    findSolutions(n, C);
    return 0;
}