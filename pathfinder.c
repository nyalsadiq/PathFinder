#include <stdio.h>
#include <stdlib.h>
#include <string.h>




struct Maze {

    int (*array)[5];

};

struct Graph {

    int (*adjMatrix)[5];
    int numberOfNodes;

};

struct node {

    int x;
    int y;

};

//int checkCardinality(int x, int y, struct Maze * maze);
int checkNode(int x, int y, struct Maze * maze);
int checkAdj(int i, int j, struct node * nodes);
struct Graph * getGraph(struct Maze * maze);





struct Maze * getMaze(FILE * fd){

    char P3[3];
	int  width, height, maxi, i,j;
    struct Maze * Maze1;
   
    
	int r,g,b;
 



    Maze1 = (struct Maze*)malloc(sizeof(struct Maze));
    Maze1->array = malloc(sizeof(int[6][6]));


    fscanf(fd," %s",&P3);
    

	if (P3[0] != 'P' || P3[1] != '3'){
		
		printf("Invalid Image Format\n");
		exit(1);
		
	}
   
   

    fscanf(fd, " %d %d",&width, &height);	
    
	fscanf(fd, " %d", &maxi);
    

    printf("%s\n%d %d\n%d\n", P3, width, height, maxi);
    
   
 
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            fscanf(fd, " %d", &r);
            fscanf(fd, " %d", &g);
            fscanf(fd, " %d", &b);
              
         //  printf(" %d %d %d  ", pixel->r,pixel->g,pixel->b);
            if(r == 255){
                 Maze1->array[j][i] = 0;
                 
               
            } else if(r == 0){
                 Maze1->array[j][i] = 1;
                 
            } else {
                Maze1->array[j][i] = 6;
            }
        }
    

    }
   
    return Maze1;

}


struct Graph * getGraph(struct Maze * maze){

    struct Graph * graph;
    struct node * nodes;
    int i, j, k;
    int countNode;
   int flag;
   

    countNode = 0;
    nodes = (struct node*)malloc(20 * sizeof(struct node));

  

    for(i = 0; i < 6;i++){
        for(j = 0; j < 6;j++){
            if (checkNode(j,i,maze) == 1){
            
                    nodes[countNode].x = j;
                    nodes[countNode].y = i;
                    countNode++;
                
            }
        }

    }

  
        
    
    graph->numberOfNodes = countNode;
    graph->adjMatrix = malloc(sizeof(int[countNode][countNode]));
    

    for(i = 0; i < countNode; i++){
        for(j = i; j < countNode; j++){
             if (checkAdj(i,j,nodes) == 1){
                 graph->adjMatrix[i][j] = 1;
                 graph->adjMatrix[j][i] = 1;
             }  else if (checkAdj(i,j,nodes) == 0){
                 graph->adjMatrix[i][j] = 0;
                 graph->adjMatrix[j][i] = 0;
             }
        }
    }
        
        
    for(i = 0; i < countNode; i++){
        printf("Node %d: x = %d y = %d\n", i, nodes[i].x, nodes[i].y);
    }
    

    

    return graph;
     
}

int checkAdj(int i, int j, struct node * nodes){
    int Adj = 0;
    int ix, iy, jx, jy; 

    ix = nodes[i].x;
    iy = nodes[i].y;
    jx = nodes[j].x;
    jy = nodes[j].y;

   if (ix == jx){
        if ( (iy + 1) == jy){
            Adj = 1;
        } else if ( (iy - 1) == jy){
            Adj = 1;
        }
   } else if (iy == jy){
        if ( (ix + 1) == jx){
            Adj = 1;
        } else if ( (ix - 1) == jx){
            Adj = 1;
        }       
   }

   
    
    return Adj;
}

int checkNode(int x, int y, struct Maze * maze){
   
    if (maze->array[x][y] == 0){
        return 1;
    } else{
        return 0;
    }

}

/*int checkCardinality(int x, int y, struct Maze * maze){
    int count;
    count = 0;
    if (maze->array[x+1][y] == 0){
        count++;
    } 
    if (maze->array[x-1][y] == 0){
        count++;
    }
    if (maze->array[x][y+1] == 0){
        count++;
    }
    if (maze->array[x][y-1] == 0){
        count++;
    }

       return count;        
}*/



int main (int argc, char ** argv){
	FILE * fin;
	struct Maze * Maze2;
    int i,j;
    struct Graph * graph;

   fin = fopen(argv[1], "r");
   Maze2 = getMaze(fin);
   
   for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            printf(" %d ", Maze2->array[j][i]);
        }
        printf("\n");
    }
    printf("\n");

    graph = getGraph(Maze2);

    printf("  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11\n");
    for(i = 0; i < graph->numberOfNodes; i++){
         printf("%d,", i);
        for(j = 0; j < graph->numberOfNodes; j++){
           
            printf(" %d,", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }

  

    exit(0);
}



