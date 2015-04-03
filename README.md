# SparseArray_with_BFS-
Sparse Array is a  2D array holding values w/o preallocating memory for the whole array.Its implementation is based on linked lists. One initial list for the column and one for the rows. Afterwards when an elements needs to be inserted, pointers will be created from the corresponding  row and column elements pointing to the inserted element. 

Sparse Array then used as a graph representation. Each node is represented by rows and columns (e.g element 3,3 in the 3rd node) and each edge represented as a neightbor to this element(e.g 3,4 is an edge going from node 3 to 4).In our case the graph is bidirectional so the array is symmentrical (3,4 and 4,3 edges are inserted). 

Breadth Fisrt Seacrh is a algorithm for traversing or searching a graph. It is based on queueing and dequeueing elements which we are going to be visited and has been visited accordingly.Our graph is weighted by introducing values on the corresponding elements in the sparsearray.  
