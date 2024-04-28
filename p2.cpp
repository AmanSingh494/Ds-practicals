#include <bits/stdc++.h>
using namespace std;
class Relation
{
private:
    vector<vector<int>> matrix;

public:
    Relation(const vector<vector<int>> &matrix) : matrix(matrix) {}

    bool isReflexive()
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][i] != 1)
            {
                return false;
            }
        }
        return true;
    }

    bool isSymmetric()
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] != matrix[j][i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isAntiSymmetric()
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isTransitive()
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 1)
                {
                    for (int k = 0; k < matrix.size(); k++)
                    {
                        if (matrix[j][k] == 1 && matrix[i][k] != 1)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    void checkRelation()
    {
        if (isReflexive() && isSymmetric() && isTransitive())
        {
            cout << "The relation is an equivalence relation.\n";
        }
        else if (isReflexive() && isAntiSymmetric() && isTransitive())
        {
            cout << "The relation is a partial order relation.\n";
        }
        else
        {
            cout << "The relation is neither an equivalence relation nor a partial order relation.\n";
        }
    }
};
int main()
{
    vector<vector<int>> matrix = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    Relation relation(matrix);
    relation.checkRelation();
    return 0;
}