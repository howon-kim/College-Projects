//
//  Graph.h
//  #10_Graph
//
//  Created by HOWON KIM on 3/10/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <iostream>
#include <cstdlib>
#include "List.h"
#include <vector>
using namespace std;

class Graph {
    
public:
    
    /**Constructors and destructors*/
    
    Graph(int n); //initializes an empty graph to have n vertices
    
    ~Graph();
    
    /*** Access functions ***/
    
    int getNumEdges();
    int getNumVertices();
    
    /*** Manipulation procedures ***/
    
    void addDirectedEdge(int u, int v);
    //inserts vertex v into the adjacency list of vertex u (i.e. inserts v into the list at index u)
    
    void addUndirectedEdge(int u, int v);
    //inserts vertex v into the adjacency list of vertex u (i.e. inserts v into the list at index u)
    //also inserts u into the adjacency list of v
    /*** Other operations ***/
    
    
    
    void printGraph();
    //prints as the adjacency list representation of the graph
    //see example below
    
    void printBFS();
    //print out each vertex, along with its color, distance and parent
    //see example below
    
    void BFS(int source);
    //performs BFS on the graph according to the pseudocode given in class
    
private:
    int vertices, edges; //number of edges and vertices
    vector<List<int> > adj; // we will use a vector here for our array
    //This vector is the heart of the graph as it stores the adjacency lists of the graph
    //See explanation of color, distance and parent vectors below
    vector<char> color; 
    vector<int> distance;
    vector<int> parent;
    
};
#endif /* Graph_h */
