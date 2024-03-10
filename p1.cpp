#include <bits/stdc++.h>
using namespace std;
class Set
{
    set<int> mySet;

public:
    Set(vector<int> arr)
    {
        mySet.insert(arr.begin(), arr.end());
    }
    set<int> getSet()
    {
        return mySet;
    }
    void display()
    {
        for (auto it : mySet)
        {
            cout << it << "  ";
        }
    }
    string isMember(int x)
    {
        auto answer = mySet.find(x);
        return (answer == mySet.end()) ? "False" : "True";
    }
    // set<set<int>> powerSet()
    // {
    //     set<set<int>> powerSets;
    //     set<int> currentSet;
    //     for (int i = 0; i < mySet.size(); i++)
    //     {
    //     }
    // }
    bool isSubset(set<int> other)
    {
        set<int> unionSet;
        set_union(mySet.begin(), mySet.end(), other.begin(), other.end(), inserter(unionSet, unionSet.begin()));
        if (unionSet == other)
            return true;
        return false;
    }
    set<int> setUnion(set<int> other)
    {
        set<int> unionSet;
        set_union(mySet.begin(), mySet.end(), other.begin(), other.end(), inserter(unionSet, unionSet.begin()));
        return unionSet;
    }
    set<int> setIntersection(set<int> other)
    {
        set<int> resultSet;
        set_intersection(mySet.begin(), mySet.end(), other.begin(), other.end(), inserter(resultSet, resultSet.begin()));
        return resultSet;
    }
    // set<int> complement(set<int> comp)
    // {
    //     set<int> compSet;
    //     set<int> univSet;
    //     int size;
    //     cout << "Enter the size of the universal set" << endl;
    //     cin >> size;
    //     cout << "Enter the universal set" << endl;
    //     for (int i = 0; i < size; i++)
    //     {
    //         int num;
    //         cin >> num;
    //         univSet.insert(num);
    //     }
    //     set_difference(univSet.begin(), univSet.end(), mySet.begin(), mySet.end(), inserter(compSet, compSet.begin()));
    //     return compSet;
    // }
    set<int> difference(set<int> other)
    {
        set<int> diff;
        set_difference(mySet.begin(), mySet.end(), other.begin(), other.end(), inserter(diff, diff.begin()));
        return diff;
    }
    set<int> SymmetricDifference(set<int> other)
    {
        set<int> diff;
        set_symmetric_difference(mySet.begin(), mySet.end(), other.begin(), other.end(), inserter(diff, diff.begin()));
        return diff;
    }
    set<set<int>> cartesianProduct(set<int> other)
    {
        set<set<int>> prod;
        set<int> current;
        for (auto a : mySet)
        {
            for (auto b : other)
            {
                current.insert({a, b});
                prod.insert(current);
            }
        }
        return prod;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 2, 3, 2, 3, 2, 3};
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Set newSet(arr);
    Set set1(arr1);
    // set<int> set2 = newSet.setIntersection(set1.getSet());
    set<set<int>> set2 = set1.cartesianProduct(newSet.getSet());
    for (auto it : set2)
        {
            for(auto a:it) cout << a<<' ';
            cout << endl;
        }

    return 0;
}