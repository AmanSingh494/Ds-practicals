#include <bits/stdc++.h>
using namespace std;
void complete(vector<vector<int>> arr, int size)
{
    // checking if the graph is a complete graph
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j && arr[i][j] != 0)
            {
                cout << "The given graph is not a complete graph" << endl;
                return;
            }
            else if (i != j && arr[i][j] != 1)
            {
                cout << "The given graph is not a complete graph" << endl;
                return;
            }
        }
        cout << "The given graph is a complete graph" << endl;
        return;
    }
}
int main()
{
    int vertices = 0, numOfRelations = 0;
    vector<vector<char>> relations;
    cout << "Enter the number of vertices" << endl;
    cin >> vertices;
    cout << "Enter the number of edges" << endl;
    cin >> numOfRelations;
    cout << "Enter all the edges like this\na a\na b\na c" << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < numOfRelations; i++)
    {
        vector<char> pair={};
        for (int j = 0; j < 2; j++)
        {
            char element;
            cin >> element;
            pair.push_back(element);
        }
        relations.push_back(pair);
        swap(pair[0],pair[1]);
        relations.push_back(pair);
    }
    vector<vector<int>> relationMatrix;
    for (int i = 0; i < vertices; i++)
    {
        vector<char> temp;
        vector<int> arr;
        char ch = 'a';
        for (int j = 0; j < vertices; j++)
        {
            temp.push_back(ch + i);
            temp.push_back(ch + j);
            if ((find(relations.begin(), relations.end(), temp)) != relations.end())
            {
                arr.push_back(1);
            }
            else
            {
                arr.push_back(0);
            }
            temp.clear();
        }
        relationMatrix.push_back(arr);
        arr.clear();
    }
    for (auto it : relationMatrix)
    {
        for (auto x : it)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
    complete(relationMatrix, relationMatrix.size());
    return 0;
}