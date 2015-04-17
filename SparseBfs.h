/************************************
*SPARSE HEADER INCLUDED IN BFS
*
************************************/

#ifndef SparseBfs 
#define SparseBfs

typedef struct edge *p;
struct edge {
	int i, j;
	int weight;
	p right, left;//columns pointer
	p up, down;//rows pointers
} ;
struct Array{
	 struct edge** HeaderRows;
	 struct edge** HeaderCols;
};

struct Array* SparseArray;

///functions Declaration
void insert(struct Array* SparseArray);
int findNode(p aux , struct Array*SparseArray);
void insertRow(p aux,struct Array* SparseArray);
void insertCol(p aux,struct Array* SparseArray);
void changeValueOfNode(p aux , struct Array*SparseArray);
void delete(struct Array* SparseArray);
void DeleteCol(p aux , struct Array* SparseArray);
void DeleteRow(p aux ,struct Array* SparseArray);
void print(struct Array* SparseArray);
void menuSparse(struct Array* SparseArray);
struct Array* sparseConstructor();

#endif