#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<int> inDegree(numVertices, 0), outDegree(numVertices, 0);

    cout << "Enter the edges in their respective direction starting with the first edge as 0. For ex :- \n0 1\n3 2\n5 1" << endl;
    for (int i = 0; i < numEdges; ++i)
    {
        int from, to;
        cin >> from >> to;
        ++outDegree[from];
        ++inDegree[to];
    }

    for (int i = 0; i < numVertices; ++i)
    {
        cout << "Vertex " << i << ": in-degree = " << inDegree[i] << ", out-degree = " << outDegree[i] << "\n";
    }

    return 0;
}