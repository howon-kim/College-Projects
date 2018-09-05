//
//  Graph.cpp
//  #10_Graph
//
//  Created by HOWON KIM on 3/10/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include "Graph.h"
#include "Queue.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

/*---------------------------------------------------------------------
 Constructor
 --------------------------------------------------------------------*/

Graph::Graph(int n)
{
    if(n<=0)
    {
        cout << "Graph : Can not make graph with less than 1 vertex" << endl;
        exit(111); // prevent destructor error
    }
    else
    {
        vertices = n;
        edges = 0;
        
        adj.push_back(List<int>());
        color.push_back(NULL);
        distance.push_back(NULL);
        parent.push_back(NULL);
        
        
        
        
        for (int i =1; i<=n; i++)
        {
            adj.push_back(List<int>());
            color.push_back('W');
            distance.push_back(-1);
            parent.push_back(0);
        }
    }
}


/*---------------------------------------------------------------------
 Destructor
 --------------------------------------------------------------------*/

Graph::~Graph()
{
    for(int i = 0; i<=vertices; i++)
    {
        color.pop_back();
        distance.pop_back();
        parent.pop_back();
        
        for(int j = 1; j <= adj[i].get_size(); j++)
            adj[vertices-i].remove_last();
        
        adj.pop_back();
    }
    
    vertices = NULL;
    edges = NULL;
}



/*---------------------------------------------------------------------
 Access Function
 --------------------------------------------------------------------*/

int Graph::getNumEdges(){return edges;}
int Graph::getNumVertices(){return vertices;}




/*---------------------------------------------------------------------
 Print the Graph
 --------------------------------------------------------------------*/

void Graph::printGraph()
{
    cout << "********** Print Graph **********" << endl;
    for(int i=1; i<=getNumVertices(); i++)
    {
        cout << i << ": ";
        adj[i].print();
        cout << endl;
    }
    
}



/*---------------------------------------------------------------------
 inserts vertex v into the adjacency list of vertex u
 (i.e. inserts v into the list at index u)
 --------------------------------------------------------------------*/

void Graph::addDirectedEdge(int u, int v)
{
    if(u <= 0 || v <=0)
    {
        cout << "addDirectedEdge : Number smaller than 1 can not be input to the list" << endl;
        return ;
    }
    else if(v>getNumVertices())
    {
        cout << "addDirectedEdge : " << v << " is higher than total number of verticies" << endl;
        return;
    }
    else if(u>getNumVertices())
    {
        cout << "addDirectedEdge : " << u << " is higher than total number of verticies" << endl;
        return;
    }
    else
    {
        if(adj[v].linear_search(u) != -1)
        {
            cout << "addDirectedEdge : " << u << " is already connected with " << v  << endl;
            return;
        }
        else if(adj[u].is_empty())
        {
            adj[u].insert_first(v);
            edges++;
        }
        else if(adj[u].linear_search(v) != -1)
        {
            cout << "addDirectedEdge : " << v << " is already exist in the list" << endl;
            return;
        }
        else
        {
            adj[u].insert_last(v);
            adj[u].sorting();
            edges++;
        }
        
    }
    
}



/*---------------------------------------------------------------------
 inserts vertex v into the adjacency list of vertex u
 (i.e. inserts v into the list at index u)
 also inserts u into the adjacency list of v
 --------------------------------------------------------------------*/

void Graph::addUndirectedEdge(int u, int v)
{
    if(u <= 0 || v <=0)
    {
        cout << "addUndirectedEdge : Number smaller than 1 can not be input to the list" << endl;
        return ;
    }
    else if(v>getNumVertices())
    {
        cout << "addUndirectedEdge : " << v << " is higher than total number of verticies" << endl;
        return;
    }
    else if(u>getNumVertices())
    {
        cout << "addUndirectedEdge : " << u << " is higher than total number of verticies" << endl;
        return;
    }
    else if(adj[u].is_empty())
    {
        adj[u].insert_first(v);
        
        if(adj[v].is_empty())
            adj[v].insert_first(u);
        else
        {
            adj[v].insert_last(u);
            adj[v].sorting();
        }
        
        edges++;
    }
    else if(adj[v].is_empty())
    {
        adj[v].insert_first(u);
        
        if(adj[u].is_empty())
            adj[u].insert_first(v);
        else
        {
            adj[u].insert_last(v);
            adj[u].sorting();
        }
        edges++;
    }
    else
    {
        if(adj[u].linear_search(v) != -1)
        {
            cout << "addUndirectedEdge : " << v << " is already exist in the list" << endl;
            return;
        }
        else if(adj[v].linear_search(u) != -1)
        {
            cout << "addUndirectedEdge : " << u << " is already exist in the list" << endl;
            return;
        }
        else
        {
            adj[u].insert_last(v);
            adj[v].insert_last(u);
            
            adj[u].sorting();
            adj[v].sorting();
            
            edges++;
        }
    }
}



/*---------------------------------------------------------------------
 print out each vertex, along with its color, distance and parent
 --------------------------------------------------------------------*/

void Graph::printBFS()
{
    cout << "********** Print BFS **********" << endl;

    cout << left << setw(5) << "v" << setw(5) << "c" << setw(5) << "p" << setw(5) << "d" << endl;
    
    for(int i =1; i<=vertices; i++)
    {
        cout << left << setw(5) << i << setw(5) << color[i] << setw(5) << parent[i] << setw(5) << distance[i] << endl;
    }
}



/*---------------------------------------------------------------------
 performs BFS on the graph according to the pseudocode given in class
 --------------------------------------------------------------------*/

void Graph::BFS(int source)
{
    if(source<=0 || source>=vertices)
    {
        cout << "BFS : There is error for number of source" << endl;
        return;
    }
    else
    {
        Queue list;
        int x =0;
        int y =0;
        
        color[source] = 'G';
        distance[source] = 0;
        
        list.enqueue(source);
        
        while(!list.is_empty())
        {
            x = list.get_front();
            list.dequeue();
            
            for(int i = 1; i <= adj[x].get_size(); i++)
            {
                adj[x].scrollToIndex(i);
                y = adj[x].get_current();
                
                if(color[y] == 'W')
                {
                    color[y] = 'G';
                    distance[y] = distance[x] +1 ;
                    parent[y] = x;
                    list.enqueue(y);
                }
            }
            
            color[x] = 'B';
            
        }
    }
}


