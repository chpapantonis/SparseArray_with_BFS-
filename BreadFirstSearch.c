
/***********************************************************

	BREADTH FIRST SEARCH
	Developer:Christos Papantonis
	A.M : 2012 515

***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "SparseBfs.h"
//#define size 30

struct graphEdge{
	int i, j; 
	int activated;
	struct graphEdge* left;
	struct graphEdge* right;
};

struct graphVertex{
	int value;
	int visited;
	struct graphVertex* parent;
	struct graphVertex* left;
	struct graphVertex* right;
};

struct circleEdge{
	int i , j;
	struct circleEdge *left;
	struct circleEdge *right;
};

//Global variables
struct graphVertex *header_V = NULL;// list headers
struct graphEdge *header_E = NULL;
//int T_v = 1;//keeps track of the number of verices in the list 
			// value = 1 to count the header in the first place


/*******************Bfs Functions*************************/
void SpanningTree(struct Array*SparseArray);
int VerticesNumber(struct Array* SparseArray);
void vertexSetVisited(struct graphVertex *header_V,struct graphVertex *aux, struct Array*SparseArray);
int vertexExists (struct graphVertex *header_V, struct graphVertex *existAux, struct Array*SparseArray);
struct graphVertex *returnVertex(int number);
void putGraphVerticesOnList (struct graphVertex *header_V,struct graphVertex *aux, struct Array*SparseArray);
void putGraphEdgesOnList(struct graphEdge *header_E,struct graphEdge *aux, struct Array*SparseArray);
void findNeightbors (struct graphVertex *aux, struct Array* SparseArray);
struct  graphVertex* findNextVertex();
void PrintVerices();
void PrintEdges();
/***************************CircleFunctions*************************/
void findCircle();
struct graphEdge* chooseNonRelativeDeactivatedEdge();
struct circleEdge* pathToRoot(struct graphVertex*Vertex,struct circleEdge *header);
struct graphEdge* chooseNonRelativeDeactivatedEdge();
struct circleEdge* putCircleVerticesOnList(struct circleEdge *inputEdge,struct circleEdge *header);
int parentOrnot(struct graphEdge*temp);
struct circleEdge* mergeLists(struct circleEdge* headerClimbToRootA, struct circleEdge* headerClimbToRootB ,struct circleEdge* mergeHeader);
struct circleEdge *CopyEdge(struct circleEdge* in);




void main (){
	printf("************************************************************\n");
	printf("BREADTH FIRST SEARCH  TO GRAPH FROM SPARSE ARRAY\n");
	printf("************************************************************\n");
	fflush (stdin);
	char choice = 0;
	struct Array* SparseArray = sparseConstructor(); 
	header_V = (struct graphVertex*)malloc (sizeof(struct graphVertex));
	header_E = (struct graphEdge*)malloc (sizeof(struct graphEdge));

	while(choice !='q'){
		printf("HELLO!! What do you want to do??\n");
		printf("Press e(edit graph) , s(Spanning tree BFS ) , f(find Circle on BFS) or Quit (q)\n");
		scanf("%c",&choice);
		getchar();
		struct graphVertex* temp =(struct graphVertex*)malloc (sizeof(struct graphVertex));
		
		switch (choice){
			case 'e':
				menuSparse(SparseArray);
				break;
			case 's':
				printf("Give the vertex you want to be the root\n");
				scanf("%d",&temp ->value);
				getchar();
				///header initiallizaton from root values
				header_V ->value = temp->value;
				header_V ->parent = header_V;
				header_E ->i = temp->value;
				header_E->j = temp ->value;
				header_E -> activated = 1;
				SpanningTree(SparseArray);
				PrintVerices();
				PrintEdges();
				break;
			case 'f':
				findCircle();
				break;
			case 'q' :
				printf("GOODBYE HF\n");
				break;	
			default :
				printf("Wrong Selection\n");	

		}
	choice = 0;	
	}
}

// # of vertices in Sparse
int VerticesNumber(struct Array* SparseArray){
	int i ,count;
	count = 0;
	for (i = 0; i < 30; i++ ){
		if (SparseArray->HeaderRows[i]->right !=NULL){
			count += 1;
		}
	}
	printf("The number of Vertices in the Sparse Array is  %d \n",count);
	return count;
}

///update the parent  to visited...
void vertexSetVisited(struct graphVertex *header_V,struct graphVertex *visitedAux, struct Array*SparseArray){
	struct graphVertex* visitedCurrent ;
	visitedCurrent = header_V;
	if(visitedCurrent ->right !=NULL)
	{
		while (visitedCurrent->right !=NULL )
		{
			
			if (visitedCurrent->value == visitedAux->value){
				printf("the vertex %d is visited \n",visitedAux->value);
				visitedAux->visited = 1;
				break;
			}
			else{
				visitedCurrent = visitedCurrent ->right;	
			}
		}

		if (visitedCurrent ->value == visitedAux ->value){
			printf("the vertex %d is visited \n",visitedAux->value);
			visitedAux->visited = 1;
		}	
	}
}

int vertexExists (struct graphVertex *header_V, struct graphVertex *existAux, struct Array*SparseArray){
	int exists = 0;
	struct graphVertex* existCurrent;
	existCurrent = header_V;
	while(existCurrent ->right != NULL ){
		if (existCurrent->value == existAux ->value)
		{
			//printf("%d ", existCurrent->value);
			//printf("Vertex exists \n");
			exists =1;
			break;
		}
		else{
			existCurrent = existCurrent->right;
		}
	}		
	if (existCurrent ->value == existAux ->value ){
		exists = 1;
	}	
	return exists;
}

struct graphVertex *returnVertex(int number){
	struct graphVertex* returnV = NULL;
	struct graphVertex* existCurrent = header_V;
	while(existCurrent ->right != NULL ){
		if (existCurrent->value == number)
		{
			returnV = existCurrent ;
			break;
		}
		else{
			existCurrent = existCurrent->right;
		}
	}		
	if (existCurrent ->value == number ){
		returnV = existCurrent;
	}	
	return returnV;
}


void putGraphVerticesOnList (struct graphVertex *header_V,struct graphVertex *vertexAux, struct Array*SparseArray)
{ //puts vertex on the list 

	struct graphVertex* vertexCurrent = header_V;
		while(vertexCurrent ->right !=NULL){
			//printf("%d\n",current->value);
			//putGraphVerticesOnList(header_V,vertexAux,SparseArray);
			vertexCurrent = vertexCurrent ->right;	
		}

		vertexAux->right =  vertexCurrent ->right;
		vertexCurrent ->right =  vertexAux;
		vertexAux ->left = vertexCurrent;
			
	//T_v = T_v +1;
}



void putGraphEdgesOnList(struct graphEdge *header_E,struct graphEdge *edgeAux, struct Array*SparseArray){
	struct graphEdge* edgeCurrent  = header_E;
	
		while (edgeCurrent ->right !=NULL){
			edgeCurrent = edgeCurrent ->right;
		}
		edgeAux->right =  edgeCurrent ->right;
		edgeCurrent ->right =  edgeAux;
		edgeAux->left = edgeCurrent;
}

void findNeightbors (struct graphVertex *VisitingNow, struct Array* SparseArray){
	struct edge* current = SparseArray->HeaderRows[(VisitingNow->value)-1];
	struct graphVertex* checkExists;
	while(current -> right != NULL)
	{
		current = current->right;
		checkExists ->value = current->j;
		if(!vertexExists(header_V,checkExists ,SparseArray))
		{
			struct graphVertex *neightbor = (struct graphVertex*)malloc(sizeof(struct graphVertex)) ;
			struct graphEdge *nearEdge = (struct graphEdge*)malloc(sizeof(struct graphEdge));
			neightbor->value =  current ->j;
			neightbor->parent = VisitingNow;
			nearEdge ->i = current -> i;
			nearEdge ->j = current ->j;
			nearEdge ->activated = 1;
			printf("%d im the neigtbor of %d\n", neightbor->value,VisitingNow->value);
			putGraphVerticesOnList(header_V,neightbor , SparseArray);	//putGraphVerticesOnList(header_V,current , SparseArray);
			putGraphEdgesOnList(header_E,nearEdge ,SparseArray);
		}
		else
		{
			struct graphEdge *nearEdge = (struct graphEdge*)malloc(sizeof(struct graphEdge));
			nearEdge ->i = current -> i;
			nearEdge ->j = current ->j;
			nearEdge ->activated = 0;
			putGraphEdgesOnList(header_E,nearEdge ,SparseArray);
		}	
		
	}
	vertexSetVisited(header_V , VisitingNow, SparseArray);
	//PrintVerices();
}

struct  graphVertex* findNextVertex()
{
	struct graphVertex *findCurrent;
	findCurrent = header_V;
	if (findCurrent->right == NULL && findCurrent->visited ==0){
		return findCurrent;
	} 
	else{
		while (findCurrent->right != NULL){
			findCurrent = findCurrent ->right;
			if (findCurrent->visited == 0){
				return findCurrent;
			}
		}
	}
}

///return a value when all vertices in list are visited(their neighbors have been found)
int allVerticesVisited(){
	int allvisit = 0;
	struct graphVertex *current = NULL;
	if(header_V !=NULL){
		current  = header_V ;
		while(current ->right != NULL){
			current = current ->right ; 
			if (current->right == NULL && current->visited ==1){
				allvisit = 1;
			}		
		}
	}
	return allvisit;	
}

//main of spanning tree
void SpanningTree(struct Array*SparseArray){
	
	int V = VerticesNumber(SparseArray);// # of vertices in the initial graph
	struct graphVertex*temp;
	while (!allVerticesVisited()){							//repeat until  #of vertices in list  matches the # of vertices in graph
		temp = findNextVertex(); //drains the next unvisited vertex from the list
		printf("finding neightbors of %d \n" ,temp->value); 
		findNeightbors(temp , SparseArray);//finds all neigbors of the vertex
	}
	printf("***********************************\n");
	printf("Spanning Tree Has been made...\n");
	printf("Press 'p' to print it \n");
}

/***********************PRINTING SESSION**********************************/

void PrintVerices(){
	struct graphVertex* current;
	current = header_V; 
	printf("**********LIST OF VERTICES**********:\n");
	while(current->right !=NULL){
		printf("vertex: %2d  [ parent = %2d , visited = %d ]\n",current ->value , current-> parent->value, current->visited);
		current = current->right;	
	}
	printf("vertex: %2d  [ parent = %2d , visited = %d ]\n",current ->value , current-> parent->value, current->visited);
	printf("\n");
}


void PrintEdges(){
	struct graphEdge *current ;
	current = header_E;
	printf("************ACTIVATED EDGES**************: \n");
	while(current ->right != NULL){
		if(current ->activated ==1){
		printf("(%2d,%2d) \n", current->i , current ->j);}
		current = current->right;	
	}
	if(current ->activated ==1){
	printf("(%2d,%2d)  " , current->i , current ->j);}

	printf("\n");
	printf("************DEACTIVATED EDGES**************\n");
	current = header_E;
	while(current ->right != NULL){
		if(current ->activated ==0){
		printf("(%2d,%2d) \n", current->i , current ->j);}
		current = current->right;	
	}
	if(current ->activated ==0){
	printf("(%2d,%2d)  " , current->i , current ->j);}
	printf("\n");
}


void printCircleList(struct circleEdge *header){
	if (header == NULL) {
		printf("List is empty\n");
		return;
	}
	printf(" (%d , %d) \n", header->i , header-> j);
	printCircleList(header->right); //recursive	
}

/*******************************************************************************/

//finding circles main
void findCircle(){
	struct circleEdge *headerClimbToRootA = NULL;
	struct circleEdge *headerClimbToRootB= NULL;
	struct circleEdge *mergeHeader = NULL;
	if (header_V == NULL){
		printf("Press 's'  first to build Spanning tree\n");
		return;
	}
	struct graphVertex *VertexA = (struct graphVertex*)malloc(sizeof(struct graphVertex)); 
	struct graphVertex *VertexB = (struct graphVertex*)malloc(sizeof(struct graphVertex));
	struct graphEdge *temp = (struct graphEdge*)malloc(sizeof(struct graphEdge));

	temp =chooseNonRelativeDeactivatedEdge();
	VertexA ->value = temp ->i;
	VertexB ->value = temp ->j;

	headerClimbToRootA =  pathToRoot(VertexA,headerClimbToRootA);
	printf("********LIST  FROM ROOT TO VERTEX A*********\n");
	printCircleList(headerClimbToRootA);


	headerClimbToRootB = pathToRoot(VertexB,headerClimbToRootB);
	printf("********LIST  FROM ROOT TO VERTEX B*********\n");
	printCircleList(headerClimbToRootB);

	 struct circleEdge *lastEdgeInCommon =  (struct circleEdge*)malloc(sizeof(struct circleEdge));
	 lastEdgeInCommon ->i = temp->i;
	 lastEdgeInCommon ->j = temp->j;
	 mergeHeader =  mergeLists(headerClimbToRootA,headerClimbToRootB ,mergeHeader);
	 mergeHeader =  putCircleVerticesOnList(lastEdgeInCommon, mergeHeader);
	 printf("***********THE CIRCLE IS**************\n");
	 printCircleList(mergeHeader);  	

}


struct circleEdge* pathToRoot(struct graphVertex*Vertex,struct circleEdge *auxheader){ // wiill find the vertex from the spanning tree list and traverse to Root

	struct graphVertex *aux = returnVertex(Vertex->value);
	while(aux->parent !=aux){
		struct  circleEdge* circleTemp = (struct circleEdge*)malloc(sizeof(struct circleEdge));
		circleTemp -> j = aux ->value;
		circleTemp -> i = aux ->parent->value;
		
		auxheader = putCircleVerticesOnList(circleTemp , auxheader);
		aux  = aux ->parent;
	}
	struct  circleEdge* circleTemp = (struct circleEdge*)malloc(sizeof(struct circleEdge));
		circleTemp -> i = aux ->parent->value;
		circleTemp ->j = aux ->value;
		putCircleVerticesOnList(circleTemp , auxheader);
	return auxheader;	
}


//********* merging lists of Vertex A and B 
struct circleEdge* mergeLists(struct circleEdge* headerClimbToRootA, struct circleEdge* headerClimbToRootB ,struct circleEdge* mergeHeader){
	
	struct circleEdge *tempA = headerClimbToRootA;
	struct circleEdge *tempB = headerClimbToRootB;
	struct circleEdge *tempCopy;
	
	while(tempA ->right->i == tempB->right->i ){
		tempA = tempA ->right;
		tempB = tempB ->right;
	}
	
	if(tempA == tempB){
		printf("Seperate paths begin\n");
	}	
	if(tempA != NULL){
		while (tempA->right!= NULL){
			tempCopy = CopyEdge(tempA);
			mergeHeader = putCircleVerticesOnList(tempCopy,mergeHeader);
			tempA = tempA ->right;
		}
		tempCopy = CopyEdge(tempA);
		mergeHeader =  putCircleVerticesOnList(tempCopy,mergeHeader);
	}
	if(tempB != NULL){
		while (tempB->right->right != NULL){
			tempCopy = CopyEdge(tempB);
			mergeHeader = putCircleVerticesOnList(tempCopy,mergeHeader);
			tempB = tempB ->right;
		}
		tempCopy = CopyEdge(tempB);
		mergeHeader = putCircleVerticesOnList(tempCopy,mergeHeader);
	}
	return mergeHeader;
}

// inserts edges to list//
struct circleEdge* putCircleVerticesOnList(struct circleEdge* inputEdge, struct circleEdge* header){
	struct circleEdge* auxy = header;
	if (auxy  != NULL ){
		inputEdge->right = header; 
		header ->left =  inputEdge;
		auxy =  inputEdge;
	} 
	else {
		auxy = inputEdge; 
	}
	return auxy;
}

///checks if the  edge is parent-child combination
int parentOrnot(struct graphEdge* aux){
	int relative =0;
	struct graphVertex *compareA = returnVertex(aux->i);
	struct graphVertex *compareB = returnVertex(aux->j);
		
	if (vertexExists(header_V,compareA,SparseArray) && vertexExists(header_V,compareB,SparseArray)){
		if (compareA->value == compareB ->parent->value || compareB->value == compareA->parent->value){
			relative = 1;
			//printf("These Verices  are relatives\n");
		}
	}
	return relative;
}

/// Prints the list of the available deactivated edges that can for a circle
struct graphEdge* chooseNonRelativeDeactivatedEdge(){
	struct graphEdge *current = header_E;
	struct graphEdge *aux  = (struct graphEdge*)malloc(sizeof(struct graphEdge));// giati malloc???

	printf("************DEACTIVATED EDGES THAT CAN  FORM A CIRCLE**************\n");
	while(current ->right != NULL){
		if(current ->activated == 0 && !parentOrnot(current)){
		printf("(%2d,%2d) \n", current->i , current ->j);
		}
		current = current->right;	
	}
	if(current ->activated ==0 && parentOrnot(current)){
	printf("(%2d,%2d) \n " , current->i , current ->j);}

	printf("Choose one of the Deactivated Edges from above to form a circle \n");
	scanf("%d %d",&aux->i , &aux->j);
	getchar();
	return aux; 

}

//creates copies of structs so the initials' struct pointers stay intact
struct circleEdge *CopyEdge(struct circleEdge* in){
	struct  circleEdge* out = (struct circleEdge*)malloc(sizeof(struct circleEdge));
	out ->i = in ->i;
	out->j = in->j;
} 
