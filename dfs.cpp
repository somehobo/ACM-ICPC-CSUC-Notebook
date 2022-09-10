#include <vector>

using namespace std;

/* 
Input: DFS
    VI parents array (by reference),
    VII Adjacency list

Output:
    Parents array would contain the parents of any given node.
    If a node has no parents it will have -1 as a parent.
*/


typedef int I;
typedef vector<I> VI;
typedef vector<VI> VVI; //vector of vector of doubles

typedef vector<I> VI; //vector of ints

typedef vector<char> VC; //vecotr of chars



void dfsVisit(int currentNode, VI &parents, VC &colors, const VVI AdjList) {
    colors[currentNode] = 'G';
    for (int i = 0; i < AdjList[currentNode].size(); i++){
        int currentNeighbor = AdjList[currentNode][i];
        if (colors[currentNeighbor] == 'W'){
            parents[currentNeighbor] = currentNode;
            colors[currentNeighbor] = 'G';
            dfsVisit(currentNeighbor, parents, colors, AdjList);
        }
    }
    colors[currentNode] = 'B';
}


void dfs(VI &parents, const VVI AdjList) {


    int totalNodes = AdjList.size();
    
    VC colors = VC(totalNodes, 'W');
    parents.resize(totalNodes, -1);

    for (int currentNode = 0; currentNode < totalNodes; currentNode++){
        if (colors[currentNode] == 'W')
            dfsVisit(currentNode, parents, colors, AdjList);
    }
}