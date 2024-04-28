#include <bits/stdc++.h>
using namespace std;

void permutationsWithoutRepition(vector<int> x)
{

    do
    {
        for (int num : x)
        {
            cout << num << ' ';
        }
        cout << endl;
    } while (next_permutation(x.begin(), x.end()));
}
void generatePermutations(vector<int> &digits, int n, vector<int> &result)
{
    if (n == result.size())
    {
        for (int num : result)
        {
            cout << num << ' ';
        }
        cout << '\n';
    }
    else
    {
        for (int num : digits)
        {
            result.push_back(num);
            generatePermutations(digits, n, result);
            result.pop_back();
        }
    }
}
int main()
{
    vector<int> digits = {1, 2, 3, 4};
    vector<int> result;
    permutationsWithoutRepition(digits);
    generatePermutations(digits, digits.size(), result);
    return 0;
}