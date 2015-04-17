/***********************************************************************************
 * SparseArray .c
 *
 *  Created on:  2/ 2014
 *      Developer: Christos Papantonis
         A.M : 2012 515
 

********************************************************************************** */

 
#include<stdio.h>
#include<stdlib.h>
#include "SparseBfs.h"
#define size 30

void menuSparse(struct Array* SparseArray )
{
	printf("***********************************************\n");
	printf("EDIT SPARSE ARRAY WITH DOUBLE LINKED LISTS\n");
	printf("************************************************\n");
	 fflush(stdin);
	//Array of Structs creation

	char c = 0;
	//printf("%d\n",SparseArray->HeaderCols[29]->j);
	while (c != 'q') {
		printf("Press  i(insert),p(print),d(delete), a(autoInsert) , q(quit editing):\n");
		scanf("%c", &c);
		getchar();
		switch (c) {
		case 'i':
			insert(SparseArray);
			break;
		case 'p':
			print(SparseArray);
			break;
		case 'd':
			delete(SparseArray);
			break;
		case 'q':
			printf("\n ta lemene\n");
			break;
		case 'a' :
			//insertion of AUTOGRAPH Reisi
			 { struct edge *temp3;
			  temp3 =(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv3=(struct edge*)malloc(sizeof(struct edge));
			  temp3->i=25;
			  temp3->j=17;
			  temp3->weight=1;
			  temp_inv3->i=temp3->j;
			  temp_inv3->j=temp3->i;
			  temp_inv3->weight=temp3->weight;
			  insertCol(temp3,SparseArray);
			  insertRow(temp3,SparseArray);
			  insertCol(temp_inv3,SparseArray);
			  insertRow(temp_inv3,SparseArray);
			  
			  struct  edge *temp4=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv4=(struct edge*)malloc(sizeof(struct edge));
			  temp4->i=13;
			  temp4->j=25;
			  temp4->weight=1;
			  temp_inv4->i=temp4->j;
			  temp_inv4->j=temp4->i;
			  temp_inv4->weight=temp4->weight;
			  insertCol(temp4,SparseArray);
			  insertRow(temp4,SparseArray);
			  insertCol(temp_inv4,SparseArray);
			  insertRow(temp_inv4,SparseArray);
			  
			  struct  edge *temp5=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv5=(struct edge*)malloc(sizeof(struct edge));
			  temp5->i=13;
			  temp5->j=20;
			  temp5->weight=1;
			  temp_inv5->i=temp5->j;
			  temp_inv5->j=temp5->i;
			  temp_inv5->weight=temp5->weight;
			  insertCol(temp5,SparseArray);
			  insertRow(temp5,SparseArray);
			  insertCol(temp_inv5,SparseArray);
			  insertRow(temp_inv5,SparseArray);
			  
			  struct  edge *temp6=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv6=(struct edge*)malloc(sizeof(struct edge));
			  temp6->i=20;
			  temp6->j=17;
			  temp6->weight=1;
			  temp_inv6->i=temp6->j;
			  temp_inv6->j=temp6->i;
			  temp_inv6->weight=temp6->weight;
			  insertCol(temp6,SparseArray);
			  insertRow(temp6,SparseArray);
			  insertCol(temp_inv6,SparseArray);
			  insertRow(temp_inv6,SparseArray);
			  
			  struct  edge *temp7=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv7=(struct edge*)malloc(sizeof(struct edge));
			  temp7->i=20;
			  temp7->j=21;
			  temp7->weight=1;
			  temp_inv7->i=temp7->j;
			  temp_inv7->j=temp7->i;
			  temp_inv7->weight=temp7->weight;
			  insertCol(temp7,SparseArray);
			  insertRow(temp7,SparseArray);
			  insertCol(temp_inv7,SparseArray);
			  insertRow(temp_inv7,SparseArray);
			  
			  struct  edge *temp8=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv8=(struct edge*)malloc(sizeof(struct edge));
			  temp8->i=21;
			  temp8->j=17;
			  temp8->weight=1;
			  temp_inv8->i=temp8->j;
			  temp_inv8->j=temp8->i;
			  temp_inv8->weight=temp8->weight;
			  insertCol(temp8,SparseArray);
			  insertRow(temp8,SparseArray);
			  insertCol(temp_inv8,SparseArray);
			  insertRow(temp_inv8,SparseArray);
			  
			  struct  edge *temp9=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv9=(struct edge*)malloc(sizeof(struct edge));
			  temp9->i=25;
			  temp9->j=21;
			  temp9->weight=1;
			  temp_inv9->i=temp9->j;
			  temp_inv9->j=temp9->i;
			  temp_inv9->weight=temp9->weight;
			  insertCol(temp9,SparseArray);
			  insertRow(temp9,SparseArray);
			  insertCol(temp_inv9,SparseArray);
			  insertRow(temp_inv9,SparseArray);
			  
			  struct  edge *temp11=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv11=(struct edge*)malloc(sizeof(struct edge));
			  temp11->i=13;
			  temp11->j=30;
			  temp11->weight=1;
			  temp_inv11->i=temp11->j;
			  temp_inv11->j=temp11->i;
			  temp_inv11->weight=temp11->weight;
			  insertCol(temp11,SparseArray);
			  insertRow(temp11,SparseArray);
			  insertCol(temp_inv11,SparseArray);
			  insertRow(temp_inv11,SparseArray);
			  
			  struct  edge *temp22=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv22=(struct edge*)malloc(sizeof(struct edge));
			  temp22->i=30;
			  temp22->j=22;
			  temp22->weight=1;
			  temp_inv22->i=temp22->j;
			  temp_inv22->j=temp22->i;
			  temp_inv22->weight=temp22->weight;
			  insertCol(temp22,SparseArray);
			  insertRow(temp22,SparseArray);
			  insertCol(temp_inv22,SparseArray);
			  insertRow(temp_inv22,SparseArray);
			  
			  struct  edge *temp33=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv33=(struct edge*)malloc(sizeof(struct edge));
			  temp33->i=22;
			  temp33->j=5;
			  temp33->weight=1;
			  temp_inv33->i=temp33->j;
			  temp_inv33->j=temp33->i;
			  temp_inv33->weight=temp33->weight;
			  insertCol(temp33,SparseArray);
			  insertRow(temp33,SparseArray);
			  insertCol(temp_inv33,SparseArray);
			  insertRow(temp_inv33,SparseArray);
			  
			   struct  edge *temp44=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv44=(struct edge*)malloc(sizeof(struct edge));
			  temp44->i=5;
			  temp44->j=19;
			  temp44->weight=1;
			  temp_inv44->i=temp44->j;
			  temp_inv44->j=temp44->i;
			  temp_inv44->weight=temp44->weight;
			  insertCol(temp44,SparseArray);
			  insertRow(temp44,SparseArray);
			  insertCol(temp_inv44,SparseArray);
			  insertRow(temp_inv44,SparseArray);
			  
			   struct  edge *temp55=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv55=(struct edge*)malloc(sizeof(struct edge));
			  temp55->i=19;
			  temp55->j=14;
			  temp55->weight=1;
			  temp_inv55->i=temp55->j;
			  temp_inv55->j=temp55->i;
			  temp_inv55->weight=temp55->weight;
			  insertCol(temp55,SparseArray);
			  insertRow(temp55,SparseArray);
			  insertCol(temp_inv55,SparseArray);
			  insertRow(temp_inv55,SparseArray);
			  
			   struct  edge *temp66=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv66=(struct edge*)malloc(sizeof(struct edge));
			  temp66->i=19;
			  temp66->j=2;
			  temp66->weight=1;
			  temp_inv66->i=temp66->j;
			  temp_inv66->j=temp66->i;
			  temp_inv66->weight=temp66->weight;
			  insertCol(temp66,SparseArray);
			  insertRow(temp66,SparseArray);
			  insertCol(temp_inv66,SparseArray);
			  insertRow(temp_inv66,SparseArray);
			  
			   struct  edge *temp77=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv77=(struct edge*)malloc(sizeof(struct edge));
			  temp77->i=14;
			  temp77->j=4;
			  temp77->weight=1;
			  temp_inv77->i=temp77->j;
			  temp_inv77->j=temp77->i;
			  temp_inv77->weight=temp77->weight;
			  insertCol(temp77,SparseArray);
			  insertRow(temp77,SparseArray);
			  insertCol(temp_inv77,SparseArray);
			  insertRow(temp_inv77,SparseArray);
			  
			   struct  edge *temp88=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv88=(struct edge*)malloc(sizeof(struct edge));
			  temp88->i=2;
			  temp88->j=1;
			  temp88->weight=1;
			  temp_inv88->i=temp88->j;
			  temp_inv88->j=temp88->i;
			  temp_inv88->weight=temp88->weight;
			  insertCol(temp88,SparseArray);
			  insertRow(temp88,SparseArray);
			  insertCol(temp_inv88,SparseArray);
			  insertRow(temp_inv88,SparseArray);

			  struct  edge *temp994=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv994=(struct edge*)malloc(sizeof(struct edge));
			  temp994->i=1;
			  temp994->j=4;
			  temp994->weight=1;
			  temp_inv994->i=temp994->j;
			  temp_inv994->j=temp994->i;
			  temp_inv994->weight=temp994->weight;
			  insertCol(temp994,SparseArray);
			  insertRow(temp994,SparseArray);
			  insertCol(temp_inv994,SparseArray);
			  insertRow(temp_inv994,SparseArray);
			  
			   struct  edge *temp99=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv99=(struct edge*)malloc(sizeof(struct edge));
			  temp99->i=2;
			  temp99->j=4;
			  temp99->weight=1;
			  temp_inv99->i=temp99->j;
			  temp_inv99->j=temp99->i;
			  temp_inv99->weight=temp99->weight;
			  insertCol(temp99,SparseArray);
			  insertRow(temp99,SparseArray);
			  insertCol(temp_inv99,SparseArray);
			  insertRow(temp_inv99,SparseArray);
			  
			   struct  edge *temp111=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv111=(struct edge*)malloc(sizeof(struct edge));
			  temp111->i=4;
			  temp111->j=7;
			  temp111->weight=1;
			  temp_inv111->i=temp111->j;
			  temp_inv111->j=temp111->i;
			  temp_inv111->weight=temp111->weight;
			  insertCol(temp111,SparseArray);
			  insertRow(temp111,SparseArray);
			  insertCol(temp_inv111,SparseArray);
			  insertRow(temp_inv111,SparseArray);
			  
			   struct  edge *temp222=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv222=(struct edge*)malloc(sizeof(struct edge));
			  temp222->i=7;
			  temp222->j=17;
			  temp222->weight=1;
			  temp_inv222->i=temp222->j;
			  temp_inv222->j=temp222->i;
			  temp_inv222->weight=temp222->weight;
			  insertCol(temp222,SparseArray);
			  insertRow(temp222,SparseArray);
			  insertCol(temp_inv222,SparseArray);
			  insertRow(temp_inv222,SparseArray);
			  
			     struct  edge *temp333=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv333=(struct edge*)malloc(sizeof(struct edge));
			  temp333->i=1;
			  temp333->j=18;
			  temp333->weight=1;
			  temp_inv333->i=temp333->j;
			  temp_inv333->j=temp333->i;
			  temp_inv333->weight=temp333->weight;
			  insertCol(temp333,SparseArray);
			  insertRow(temp333,SparseArray);
			  insertCol(temp_inv333,SparseArray);
			  insertRow(temp_inv333,SparseArray);

			  struct  edge *temp3337=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv3337=(struct edge*)malloc(sizeof(struct edge));
			  temp3337->i=7;
			  temp3337->j=18;
			  temp3337->weight=1;
			  temp_inv3337->i=temp3337->j;
			  temp_inv3337->j=temp3337->i;
			  temp_inv3337->weight=temp3337->weight;
			  insertCol(temp3337,SparseArray);
			  insertRow(temp3337,SparseArray);
			  insertCol(temp_inv3337,SparseArray);
			  insertRow(temp_inv3337,SparseArray);
			  
			     struct  edge *temp444=(struct edge*)malloc(sizeof(struct edge)); 
			  struct  edge *temp_inv444=(struct edge*)malloc(sizeof(struct edge));
			  temp444->i=21;
			  temp444->j=18;
			  temp444->weight=1;
			  temp_inv444->i=temp444->j;
			  temp_inv444->j=temp444->i;
			  temp_inv444->weight=temp444->weight;
			  insertCol(temp444,SparseArray);
			  insertRow(temp444,SparseArray);
			  insertCol(temp_inv444,SparseArray);
			  insertRow(temp_inv444,SparseArray);}
			  break;	
		default:
			printf("\n wrong input\n");
		}
	}
	//return 0;
}

//Array of structs instantiantion
struct Array* sparseConstructor(){
	int i;
	SparseArray = malloc(sizeof(struct Array));
	SparseArray->HeaderRows = malloc(30*sizeof(struct edge*));
	SparseArray->HeaderCols = malloc(30*sizeof(struct edge*));
	
	
	for ( i = 0; i <=size; i++) {
		p t_h = (p)malloc(sizeof(struct edge*));
		t_h ->i = i+1;
		t_h->j = 0;
		t_h->right = NULL;
		SparseArray->HeaderRows[i] = t_h;
		

		p t_v =  (p)malloc(sizeof(struct edge*));
		t_v->j = i+1;
		t_v ->i = 0;
		t_v ->down = NULL;
		SparseArray -> HeaderCols[i] = t_v;
	}
	return SparseArray;
}

//finds the node inside sparse
int findNode(p aux , struct Array*SparseArray){
	int high = 0;
	p current =  SparseArray -> HeaderRows[(aux->i) - 1];
	if(current ->right != NULL){
		while(current->right->j <= aux->j && current ->right != NULL){
			current = current ->right;	//1a auksanw giati to prwto stoixio ine sto Array of struct=>den ine auto pou 8elw
			if(current->j == aux ->j){
				char ch,y,n;

				//do{
					printf("edge Exists !!!!\n");
					printf("Do you want to change its' weight?? Press y(yes) or n(no) \n");
					scanf("%ch",&ch);
					getchar();
				//}while(ch == y && ch ==n);		
				if(ch=='y'){
					printf("Give me the new weight for edge %d ,%d  \n",aux->i , aux->j);
					scanf("%d",&aux->weight);
					getchar();
					changeValueOfNode(aux,SparseArray);
				}
				else{
					printf("Nothing Happened.edge did not updated. . .\n");
					}
				high =1;	

			}
			if(current->right ==NULL){
				printf("last edge need to stop \n");
				break;
			}
		}
	}	
	return high;	
}
//int existVertex(aux struct Array*SparseArray){



//changes teh weight of a node/edge
void changeValueOfNode(p changeNode , struct Array*SparseArray)
{
	p current = SparseArray-> HeaderRows[(changeNode->i) - 1];
	if (current->right != NULL)
	{
		while (current ->right->j <= changeNode-> j && current ->right !=NULL)
		{
			current = current->right;
			if (current ->j == changeNode->j){
				current->weight = changeNode->weight;
				break;
			}
		}
	}	
} 

void insert(struct Array* SparseArray ) {	
	 struct edge *temp , *temp_inv;
	temp = (struct edge*) malloc(sizeof(struct edge));
	temp_inv = (p)malloc(sizeof(struct edge));//auxiliary edge for inverting i and j
	do{
		printf("Give i number from 1 to %d \n",size); //zita seira
		scanf("%d",&temp->i);
		getchar();
		temp_inv->j = temp->i;
	}while(temp->i >size);	

	do{
		printf("Give column number from 1 to %d",size); //zita stili
		scanf("%d",&temp->j);
		getchar();
		temp_inv ->i = temp->j;
	}while(temp->j >size);
	
	if (!findNode(temp,SparseArray))
	{
		printf("Give me key "); //zita weight
		scanf("%d",&temp -> weight);
		getchar();
		temp_inv->weight = temp->weight;
		//Function calling for setting all the ptrs of the edge
		insertRow(temp ,SparseArray);
		insertCol(temp,SparseArray);
		if(temp->i != temp ->j){//prevent double copies of same i and column
			//Functions for setting the ptr to the inverted i -j
			insertRow(temp_inv,SparseArray);
			insertCol(temp_inv,SparseArray);
		}
	}

}

void insertRow(p aux, struct Array* SparseArray ) {
	if (SparseArray->HeaderRows[(aux->i)-1]-> right == NULL){
		printf("im the first edge in the i\n");
		SparseArray->HeaderRows[(aux->i)-1] -> right = aux;
		aux->left = SparseArray->HeaderRows[(aux->i)-1];
		
		
	}	//Make i Header the auxiliary edge
	else {
		p current;
		current = SparseArray-> HeaderRows[(aux->i)-1];  //temp header gia traverse tin grammi
		while (current->right->j < aux->j && current->right !=NULL) {
			printf("right traverse\n");
			current = current->right;
			if(current -> right == NULL){
				printf("last edge need to stop \n");
				break;}
		}	
		if (current->right == NULL){
				printf("last edge in the i\n");
				aux->right = current->right;
				aux->left = current;
				current->right = aux;
		}	
		else {
				printf("the edge is between others \n");
				aux->left = current;//kollaei ton aristero tou edge me ton current
				aux->right = current->right; //kollaei ton deksi pointer tou current sto deksi tou edge
				current->right->left = aux; // kollaei tn aristero tou epomenou tou current me  ton edge
				current->right = aux; // kollaei ton proigoumeno me ton edge
			} 
	}
}

void insertCol(p aux ,struct Array* SparseArray)
{
	if (SparseArray->HeaderCols[(aux->j)-1] -> down == NULL){

		printf("im the first edge in the Column\n");
		SparseArray->HeaderCols[(aux->j)-1] -> down = aux;
		aux->up = SparseArray->HeaderCols[(aux->j)-1];
	}	//Make i Header the auxiliary edge
	else {
		p current;
		current = SparseArray-> HeaderCols [(aux->j)-1];  //temp header gia traverse tin grammi
		while (current->down->i < aux->i && current->down !=NULL) {
			printf("right traverse\n");
			current = current->down;
			if(current -> down == NULL){
				printf("last edge need to stop \n");
				break;}
		}	
		if (current->down == NULL){
				printf("last edge in the i\n");
				aux->down = current->down;
				aux->up = current;
				current->down = aux;
		}	
		else {
				printf("the edge is between others \n");
				aux->up = current;//kollaei ton aristero tou edge me ton current
				aux->down = current->down; //kollaei ton deksi pointer tou current sto deksi tou edge
				current->down->up = aux; // kollaei tn aristero tou epomenou tou current me  ton edge
				current->down = aux;} // kollaei ton proigoumeno me ton edge
	}
}
	

void delete(struct Array* SparseArray){
		p temp ,temp_inv ;
		temp = (p) malloc(sizeof(struct edge));
		temp_inv = (p)malloc(sizeof(struct edge)); //instantiation of aux edge for reverse.
		do{
			printf("Give i number from 1 to %d \n",size); //zita seira
			scanf("%d", &temp->i);
			getchar();
			temp_inv->j = temp->i;
			if (temp->i > size) {
			printf("Size of Array Exceeded , Give i below %d \n",size);}
		}while(temp-> i >size);
	
		do{
		printf("Give column number from 1 to %d\n",size); //zita stili
		scanf("%d", &temp->j);
		getchar();
		temp_inv ->i = temp->j;
		if (temp->i > size) {
			printf("Size of Array Exceeded , Give j below %d \n",size);}
		}while(temp->j >size);
		if (!findNode(temp,SparseArray)){
			DeleteRow(temp , SparseArray ); //kalesma sunartisewn gia orizodio kai katheto ksulwma twn ptr
			DeleteCol(temp, SparseArray);
			//
			DeleteRow(temp_inv ,SparseArray); //kalesma sunartisewn gia orizodio kai katheto ksulwma twn ptr of inverted nodes
			DeleteCol(temp_inv,SparseArray);
			printf("edge Deleted . . . \n");
			free(temp);
		}
		else{
			printf("there is no edge with these coordinates \n");
		}
}


void DeleteRow(p aux ,struct Array* SparseArray){
	if(SparseArray->HeaderRows[(aux->i)-1] ->right == NULL){
			printf("nothing to delete on this i \n");}
	else{
		p current;		
		current = SparseArray->HeaderRows[(aux ->i)-1];
		while(current ->right->j <= aux->j && current->right != NULL){ //traverse till find exactness or stopped by Arrays' bounds
				current = current->right;
			printf("right traverse\n");
			if(current ->right == NULL){
				printf("last edge reached \n");
				break;}
		}
		
		if (current->right == NULL && current ->j == aux->j ){
			current ->left->right = NULL;
			printf("the deleted edge was last in line\n");
		}	
		else if(current->j == aux->j){
			printf("the deleted edge was between others\n");
			current->left->right = current ->right;
			current->right->left = current->left; }
	}
}

void DeleteCol(p aux , struct Array* SparseArray){
	if(SparseArray->HeaderRows[(aux->j)-1]->down ==NULL){
			printf("nothing to delete on this j \n");}
	else{
		p current;		
		current = SparseArray->HeaderRows[(aux ->j)-1];
		while(current ->down->i <= aux->i && current->down != NULL){ //traverse till find exactness or stopped by Arrays' bounds
			current = current->down;
			printf("down traverse\n");
			if(current ->down == NULL){
				printf("last edge reached \n");
				break;}
		}
		
		if (current->down == NULL && current ->i == aux->i ){
			printf("the deleted note was last in column\n");
			current ->up->down= NULL;
		}	
		else if(current->j == aux->j){
			current->up->down = aux ->down;
			current->down->left = aux ->up; }
	}
}


void print(struct Array* SparseArray)
{
	printf("-------------------------------------------------------------------------\n");
	printf("Printed Sparse Array \n");
	printf("--------------------------------------------------------------------------\n");
	int i, k;
	printf("  ");
	for(k = 1; k<= size; k++ ){
		printf("%2d ",k);
	}
	printf("\n");
	for(i=0;i <size;i++)
	{
		p aux = SparseArray->HeaderRows[i];
		printf("%2d",SparseArray->HeaderRows[i]->i);
		while( aux -> right != NULL)
		{	
			int m;
			for(m=1; m< ( aux ->right->j - aux->j); m++)
			{
				printf(" * ");
			}
			printf("%2d ",aux->right ->weight);
			aux = aux->right;
		}
		int m;
		for(m=0; m < size - aux->j;m++)
		{
			printf(" * ");
		}
		printf("\n");
	}
	printf("\n");
	printf("--------------------------------------------------------------------------\n");
	printf("* = NULL\n");
}