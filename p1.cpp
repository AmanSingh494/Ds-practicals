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
    set<set<int>> powerSet()
    {
        vector<int> S(mySet.begin(), mySet.end());
        int total = pow(2, S.size());
        set<set<int>> powerSets;
        for (int i = 0; i < total; i++)
        {
            set<int> subset;
            for (int j = 0; j < S.size(); j++)
            {
                if ((i & (1 << j)) != 0)
                    subset.insert(S[j]);
            }
            powerSets.insert(subset);
        }
        return powerSets;
    }
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
    set<int> complement()
    {
        set<int> compSet;
        set<int> univSet;
        int size;
        cout << "Enter the size of the universal set" << endl;
        cin >> size;
        cout << "Enter the universal set" << endl;
        for (int i = 0; i < size; i++)
        {
            int num;
            cin >> num;
            univSet.emplace(num);
        }
        set_difference(univSet.begin(), univSet.end(), mySet.begin(), mySet.end(), inserter(compSet, compSet.begin()));
        return compSet;
    }
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
    set<list<int>> cartesianProduct(set<int> other)
    {
        set<list<int>> prod;
        list<int> current;
        for (auto a : mySet)
        {
            for (auto b : other)
            {
                // current = {a,b};
                // for(auto it :current) cout << it << ' ';
                // cout << endl;
                prod.insert({a, b});
                // current.clear();
            }
        }
        return prod;
    }
};
void display(set<int> x)
{
    for (auto it : x)
    {
        cout << it << "  ";
    }
}
Set createSet()
{
    int size;
    vector<int> arr;
    cout << "Enter the size of the set" << endl;
    cin >> size;
    cout << "Enter the set" << endl;
    for (int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    Set newSet(arr);
    return newSet;
}
int menu()
{
    int option;
    cout << "Enter the number of the function you want to perform" << endl;
    cout << "1. Check whether an element belongs to the set or not and return value as true/false \n 2. List all the elements of the power set. \n 3. Check if the set is a subset. \n 4.Union of two sets. \n 5.Intersection of two sets. \n 6. Complement of a set. \n 7. Set difference of two sets. \n 8. Symmetric difference of two sets. \n 9. Cartesian product of two sets" << endl;
    cin >> option;
    return option;
}
void perform(int n, Set x)
{

    if (n == 1)
    {
        int num = 0;
        cout << "Enter the number for which you want check if it is the member" << endl;
        cin >> num;
        cout << x.isMember(num) << endl;
    }
    else if (n == 2)
    {
        // Code for case 2
    }
    else if (n == 3)
    {
        Set other = createSet();
        cout << x.isSubset(other.getSet()) << endl;
    }
    else if (n == 4)
    {
        Set other = createSet();
        set<int> newSet = x.setUnion(other.getSet());
        cout << "The union set is: ";
        display(newSet);
    }
    else if (n == 5)
    {
        Set other = createSet();
        set<int> newSet = x.setIntersection(other.getSet());
        cout << "The intersection set is: ";
        display(newSet);
    }
    else if (n == 6)
    {
        set<int> newSet = x.complement();
        cout << "The complement set is: ";
        display(newSet);
    }
    else if (n == 7)
    {
        Set other = createSet();
        set<int> newSet = x.difference(other.getSet());
        cout << "The difference set is: ";
        display(newSet);
    }
    else if (n == 8)
    {
        Set other = createSet();
        set<int> newSet = x.SymmetricDifference(other.getSet());
        cout << "The symmetric difference set is: ";
        display(newSet);
    }
    else if (n == 9)
    {
        Set other = createSet();
        set<list<int>> newSet = x.cartesianProduct(other.getSet());
        cout << "The cartesian product set is: ";
        // display(newSet);
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
}
int main()
{
    Set set1 = createSet();
    int choice = menu();
    perform(choice, set1);
    // vector<int> arr = {1, 2, 3,5};
    // vector<int> arr1 = {5,7,8,9,10};
    // Set newSet(arr);
    // Set set1(arr1);
    // set<int> set2 = newSet.complement();
    // // set<list<int>> set2 = set1.cartesianProduct(newSet.getSet());
    // for (auto it : set2)
    //     {
    //         cout << it<<' ';
    //     }

    return 0;
}