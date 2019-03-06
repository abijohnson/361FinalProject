/**
  * Maksim Stoyanov
  * Brad Christensen
  * Jon Gillespie
  * Abby Johnson
  *
  * CS361
  * Instructor: Dr. Flesch
  * Date: 03/04/19
  * Lab: Final Project
  * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <list>
#include <array>

using namespace std;

// A class that represents an undirected graph
class Graph
{
    int V;      //number of verticies
    list<int> *adj;    // Pointer to a list of adjacency verticies
    vector<char> vertices;
public:
    // Constructor and destructor
    Graph(int V)
    {
        this->V = V; adj = new list<int>[V];
        vertices.reserve(V);

        char let = 'A';
        for(int i = 0; i < V; i++)
            vertices.push_back(let++);
    }

    ~Graph()
    {
        delete [] adj;
    }

    // function to add an edge to graph
    void addEdge(int v, int w);

    // Prints greedy coloring of the vertices
    void greedyColoring();
};

/**
 * @brief Graph::greedyColoring
 * @cite https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/
 */
void Graph::greedyColoring()
{
    vector<int> result(V);

    //initial coloring of the starting Vertex
    result[0] = 0;

    //initialize the rest of the vertices
    for(int i = 1; i < V; i++)
        result[i] = -1; // None == -1

    // Vector storing the available colors. When colored[i] == true
    // the color at colored[i] is already assigned to one of its
    // adjacent verticies
    vector<bool> colored(V);
    for(int i = 0; i < V; i++)
        colored[i] = false;

    //color the rest of the vertices
    for(int u = 1; u < V; u++)
    {
        // parse the adjacent vertices and flag
        // their colors as false
        list<int>::iterator it;
        for(it = adj[u].begin(); it != adj[u].end(); ++it)
            if(result[*it] != -1)
                colored[result[*it]] = true;

        int cr; // finding the first avail color
        for(cr = 0; cr < V; cr++)
            if(colored[cr] == false)
                break;
    }


}

/**
 * @brief Graph::addEdge an undirected graph
 * @param v src
 * @param w dest
 */
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int main()
{
    enum gralphabet { A = 0, B = 1,
                      C = 2, D = 3,
                      E = 4, F = 5,
                      G = 6 };
    Graph g1(7);
    g1.addEdge(A, B); g1.addEdge(A, C);
    g1.addEdge(A, E); g1.addEdge(D, E);
    g1.addEdge(D, G); g1.addEdge(F, E);
    g1.addEdge(G, E); g1.addEdge(F, C);
    g1.addEdge(F, B); g1.addEdge(C, B); g1.addEdge(C, E);

    g1.greedyColoring();
}
