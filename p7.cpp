#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool isCompleteGraph(const vector<set<int>>& adjacencyList) {
    int size = adjacencyList.size();
    for (const auto& neighbors : adjacencyList) {
        if (neighbors.size() != size - 1) {
            return false;
        }
    }
    return true;
}
void representGraph(vector<set<int>> arr){
    for(int i = 0;i<arr.size();i++){
        cout << i << ' ' << ':' << ' '<<'[';
        for(auto it:arr[i]){
            cout <<  it <<' ';
        }
        cout << ']' << endl;
    }
}
int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<set<int>> adjacencyList(numVertices);

    cout << "Enter the edges:\n";
    for (int i = 0; i < numEdges; ++i) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        adjacencyList[vertex1].insert(vertex2);
        adjacencyList[vertex2].insert(vertex1);
    }

    if (isCompleteGraph(adjacencyList)) {
        cout << "The graph is complete\n";
    } else {
        cout << "The graph is not complete\n";
    }
    representGraph(adjacencyList);
    return 0;
}