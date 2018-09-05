//
//  GraphTest.cpp
//  #10_Graph
//
//  Created by HOWON KIM on 3/10/16.
//  Copyright © 2016 HOWON KIM. All rights reserved.
//

#include <iostream>
#include "Graph.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    // Graph Error(0); // Graph : Can not make graph with less than 1 vertex

    Graph test(4);
    test.printGraph();
    
    /* Error List */
    test.addDirectedEdge(5,3); // addDirectedEdge : 5 is higher than total number of verticies
    test.addDirectedEdge(3,6); // addDirectedEdge : 6 is higher than total number of verticies
    
    test.addDirectedEdge(1, 4);
    test.addDirectedEdge(1, 4); // addDirectedEdge : 4 is already exist in the list
    test.addDirectedEdge(1, 3);
    test.addDirectedEdge(0, 3); // addDirectedEdge : Number smaller than 1 can not be input to the list
    test.addDirectedEdge(3, 0); // addDirectedEdge : Number smaller than 1 can not be input to the list


    test.printGraph();
    /*
     1: 3,4
     2:
     3:
     4:
     */
    
    Graph test1(8);
    test1.addUndirectedEdge(0, 5); // addDirectedEdge : Number smaller than 1 can not be input to the list

    test1.addUndirectedEdge(1, 9); // addUndirectedEdge : 9 is higher than total number of verticies
    test1.addUndirectedEdge(10, 1); // addUndirectedEdge : 10 is higher than total number of verticies

    test1.addUndirectedEdge(1, 5);
    test1.addUndirectedEdge(5, 1); // addUndirectedEdge : 1 is already exist in the list
    test1.addUndirectedEdge(1, 5); // addUndirectedEdge : 5 is already exist in the list

    test1.addUndirectedEdge(1, 7);
    test1.addUndirectedEdge(1, 8);
    test1.addUndirectedEdge(2, 5);
    
    test1.printGraph();
    /*
     1: 5,7,8
     2: 5
     3:
     4:
     5: 1,2
     6: 
     7: 1
     8: 1
     */
    Graph test2(7);
    
    test2.addUndirectedEdge(1, 2);
    test2.addUndirectedEdge(1, 6);
    test2.addUndirectedEdge(2, 3);
    test2.addUndirectedEdge(2, 6);
    test2.addUndirectedEdge(2, 7);
    test2.addUndirectedEdge(3, 7);
    test2.addUndirectedEdge(3, 5);
    test2.addUndirectedEdge(3, 4);
    test2.addUndirectedEdge(4, 5);
    test2.addUndirectedEdge(5, 6);
    test2.addUndirectedEdge(5, 7);
    test2.addUndirectedEdge(6, 7);




    test2.printGraph();
    cout << "Edges : " << test2.getNumEdges() << endl; // 12
    cout << "Vertices : " << test2.getNumVertices() << endl; // 7

    
    test2.BFS(1);
    test2.printBFS();
    /* Class Example 
     v    c    p    d
     1    B    0    0
     2    B    1    1
     3    B    2    2
     4    B    3    3
     5    B    6    2
     6    B    1    1
     7    B    2    2
     */
    
    Graph test3(3);
    
    test3.addDirectedEdge(1, 1); // Self Looping
    test3.addDirectedEdge(1, 1); // addDirectedEdge : 1 is already exist in the list

    test3.addDirectedEdge(1, 2);
    test3.addDirectedEdge(2, 1); // addDirectedEdge : 2 is already connected with 1


    test3.printGraph();
    /*
     ********** Print Graph **********
     1: 1,2
     2:
     3:
     */
    return 0;
}

/* OUTPUT
 ********** Print Graph **********
 1:
 2:
 3:
 4:
 addDirectedEdge : 5 is higher than total number of verticies
 addDirectedEdge : 6 is higher than total number of verticies
 linear_search(listitem item) : List is empty
 linear_search(listitem item) : List is empty
 addDirectedEdge : 4 is already exist in the list
 linear_search(listitem item) : List is empty
 addDirectedEdge : Number smaller than 1 can not be input to the list
 addDirectedEdge : Number smaller than 1 can not be input to the list
 ********** Print Graph **********
 1: 3,4
 2:
 3:
 4:
 addUndirectedEdge : Number smaller than 1 can not be input to the list
 addUndirectedEdge : 9 is higher than total number of verticies
 addUndirectedEdge : 10 is higher than total number of verticies
 addUndirectedEdge : 1 is already exist in the list
 addUndirectedEdge : 5 is already exist in the list
 ********** Print Graph **********
 1: 5,7,8
 2: 5
 3:
 4:
 5: 1,2
 6:
 7: 1
 8: 1
 ********** Print Graph **********
 1: 2,6
 2: 1,3,6,7
 3: 2,4,5,7
 4: 3,5
 5: 3,4,6,7
 6: 1,2,5,7
 7: 2,3,5,6
 Edges : 12
 Vertices : 7
 ********** Print BFS **********
 v    c    p    d
 1    B    0    0
 2    B    1    1
 3    B    2    2
 4    B    3    3
 5    B    6    2
 6    B    1    1
 7    B    2    2
 linear_search(listitem item) : List is empty
 addDirectedEdge : 1 is already connected with 1
 linear_search(listitem item) : List is empty
 addDirectedEdge : 2 is already connected with 1
 ********** Print Graph **********
 1: 1,2
 2: 
 3: 
 Program ended with exit code: 0
*/