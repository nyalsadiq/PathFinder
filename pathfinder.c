#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Maze {

    int (*array)[5];

};


struct Maze * getMaze(FILE * fd){

    char P3[3];
	int  width, height, maxi, i,j;
    struct Maze * Maze1;
    struct pixels * pixel;
	int r,g,b;
 


    Maze1 = (struct Maze*)malloc(sizeof(struct Maze));
    Maze1->array = malloc(sizeof(int[6][6]));
    
   
 
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

struct Maze * DFS(struct Maze * maze){
    int startx, starty;
    int i,j;
    


}

int main (int argc, char ** argv){
	FILE * fin;
	struct Maze * Maze2;
    int i,j;

   fin = fopen(argv[1], "r");
   Maze2 = getMaze(fin);
   
   for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            printf(" %d ", Maze2->array[j][i]);
        }
        printf("\n");
    }

  

    exit(0);
}



	/*fscanf(fd," %s",&P3);
    

	if (P3[0] != 'P' || P3[1] != '3'){
		
		printf("Invalid Image Format\n");
		exit(1);
		
	}
   
   

    fscanf(fd, " %d %d",&width, &height);	
    
	fscanf(fd, " %d", &maxi);
    

     printf("%s\n%d %d\n%d\n", P3, width, height, maxi);*/