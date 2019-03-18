//
//  Graph.h
//  DataStructures
//
//  Created by Jarman, Caroline on 3/8/19.
//  Copyright © 2019 ctec. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <set>
#include <queue>
#include <assert.h>

using namespace std;
template <class Type>
class Graph
{
private:
    static const int MAXIMUM = 50;
    bool adjacencyMatrix [MAXIMUM][MAXIMUM];
    int weightCostMatrix [MAXIMUM][MAXIMUM];
    Type graphData[MAXIMUM];
    int vertexCount;
    void depthFirstTraversal(Graph<Type> & graph, int vertex, bool markedVertices[]);
public:
    Graph() //graph operations
    
    void addVertex(const Type& value); //Type& like a setter, have reference to IT
    
    //Connect vertices
    void addEdge(int source, int target);
    void addEdgeUndirected(int source, int target);
    void addEdgeCost(int source, int target, int cost);
    //Disconnect vertices
    void removeEdge(int source, int target);
    void removeEdgeUndirected(int source, int target);
    void removeEdgeCost(int source, int target);
    
    //Accessors
    Type& operator [] (int vertex);
    Type operator [] (int vertex) const;
    int size() const;
    
    //Check Connections
    bool hasUndirectedConnection(int source, int target) const;
    bool areConnected(int source, int target) const;
    std:: set<int> neighbors(int vertex) const;
    
    //Traversals
    void depthFirstTraversal(Graph<Type> & graph, int vertex);
    void breadthFirstTraversal(Graph<Type> & graph, int vertex);
    int costTraversal(Graph<Type> & graph, int vertex);
    
};

template <class Type>
const int Graph<Type> :: MAXIMUM;

template <class Type>
Graph<Type> :: Graph()
{
    this->vertexCount = 0;
}

template <class Type>
int Graph<Type> :: size() const
{
    return vertexCount;
}

//left hand side operator
template <class Type>
Type& Graph<Type> :: operator[] (int vertex)
{
    assert(vertex < vertexCount);
    return graphData[vertex];
}

//right hand side operator
template <class Type>
Type Graph<Type> :: operator[] (int vertex) const
{
    assert(vertex < vertexCount);
    return graphData[vertex];
}

template <class Type>
void Graph<Type> :: addVertex(const Type& value)
{
    assert( vertexCount < MAXIMUM);
    int newVertexNumber = vertexCount;
    vertexCount++;
    
    for(int otherVertexNumber  = 0; otherVertexNumber < vertexCount; otherVertexNumber++)
    {
        adjacencyMatrix[otherVertexNumber][newVertexNumber] = false;
          adjacencyMatrix[newVertexNumber][otherVertexNumber] = false;
    }
    graphData[newVertexNumber] = value;
}


//ADD EDGES
template <class Type>
void Graph<Type> :: addEdge(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = true;
}

template <class Type>
void Graph<Type> :: addEdgeCost(int source, int target, int cost)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = cost;
    adjacencyMatrix[target][source] = cost;
}

template <class Type>
void Graph<Type> :: addEdgeUndirected(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = true;
    adjacencyMatrix[target][source] = true;
}

//REMOVE EDGES
template <class Type>
void Graph<Type> :: removeEdge(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = false;
}

template <class Type>
void Graph<Type> :: removeEdgeUndirected(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = false;
    adjacencyMatrix[target][source] = false;
}

template <class Type>
void Graph<Type> :: removeEdgeCost(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = 0;
    adjacencyMatrix[target][source] = 0;
}

//CONNECTION CHECKS
template <class Type>
bool Graph<Type> :: hasUndirectedConnection(int source, int target) const
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    bool isAnEdge = false;
    isAnEdge = adjacencyMatrix[source][target] || adjacencyMatrix[target][source];
    return isAnEdge;
}
template <class Type>
bool Graph<Type> :: areConnected(int source, int target) const
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    bool isAnEdge = false;
    isAnEdge = adjacencyMatrix[source][target] ;
    return isAnEdge;
}

template <class Type>
std::set<int> Graph<Type> :: neighbors(int vertex) const
{
    //Asking-> do IIIIIII have a connection
    assert(vertex < vertexCount);
    std::set<int> vertexNeighbors;
    
    for(int index = 0; index < vertexCount; index++)
    {
        if (adjacencyMatrix[vertex][index]) //the whole grid part
        {
            vertexNeighbors.insert(index);
        }
    } //returns a set -->goes through an ad matrix and adds each TRUE index to a set
    //who are neighbors, have a visited them? grab them, grab neighbors who have not be visited yet
    return vertexNeighobors;
}

//TRAVERSALS
//Depth First - Recursive -> builds on top of itself -> no extra pieces
template <class Type>
void Graph<Type> :: depthFirstTraversal(Graph<Type> & currentGraph, int vertex)
{
    bool visitedVertices[MAXIMUM];
    assert (vertex < currentGraph.size());
    std::fill_n(visitedVertices, currentGraph.size(), false); //fill n gives it default values bc c++ doesn't
    depthFirstTraversal(currentGraph, vertex, visitedVerticies);
}

template <class Type>
void Graph<Type> :: depthFirstTraversal(Graph<Type> & currentGraph, int index, book * visited)
{
    std::set<int> connections = currentGraph.neighbors(vertex);
    std::set<int>::iterator setIterator;
    
    visited[vertex] = true;
    coud << currentGraph[vertex] << ", " << endl;
    
    for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
    {
        if(!visited[*setIterator])
        {
            depthFirstTraversal(currentGraph, *setIterator, visited)
        }
    }
}

//Breadth First - Iterative, NOT Recursive (has extra pieces, but less space
template <class Type>
void Graph<Type> :: breadthFirstTraversal(Graph<Type> & currentGraph, int vertex)
{
    assert (vertex < currentGraph.size());
    bool visited[MAXIMUM];
    std::set<int> connections;
    std::set<int>::iterator setIterator;
    std::queue<int> vertexQueue;
    
    std::fill_n(visited, currentGraph.size(), false);
    visited[vertex] = true;
    cout << currentGraph[vertex] << endl;
    vertexQueue.push(vertex); //adds a value to the queue
    while(!vertexQueue.empty()) //must loop through at least one
    {
        connections = currentGraph.neighbors(vertexQueue.front());
        vertexQueue.pop(); //removes from queue
        
        for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
        {
            if(!visited[*setIterator])
            {
                visited[*setIterator] = true;
                cout << currentGraph[*setIterator] << endl;
                vertexQueue.push(*setIterator); //how to end the thing -> adds to queue so while loop stops
                
                //0 -> ada lovelace
                //1 -> grace hopper, ada lovelace, Katherine Johnson, Ria Galanos ->Grabbed neighbors neighbors ->2nd level connections
                                                                                    //friend of a friend
            }
        }
    }
}

//cost
template <class Type>
int Graph<Type> :: costTraversal(Graph<Type> & currentGraph, int start)
{
    assert(start >= 0 && start < vertexCount);
    int cost = 0;
    bool visited[MAXIMUM];
    std::set<int> connections;
    std::set<int>::iterator setIterator;
    std::queue<int> vertexQueue;
    
    std::fill_n(visited, currentGraph.size(), false);
    visited[start] = true;
    
    vertexQueue.push(start);
    while(!vertexQueue.empty())
    {
        int currentIndex = vertexQueue.front();
        connections = currentGraph.neighbors(currentIndex);
        vertexQueue.pop();
        
        for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
        {
            if(!visited[*setIterator])
            {
                cost += weightCostMatrix[currentIndex][*setIterator];
                visited[*setIterator] = true;
                vertexQueue.push(*setIterator);
            }
        }
    }
    return cost;
}

#endif /* Graph_h */
