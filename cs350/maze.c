#include <stdio.h>
#include <stdlib.h>
int findEntrance(char** a, int row, int col);
main()
{
  
  int i,j,row,col;
  char **array = malloc(row*sizeof(char*));
  FILE *fptr;
  char c;
  char file_name[20];
  
  printf("Type the number of Rows for maze: ");
  scanf("%d",&row);
  //printf("%d THIS IS TEH ROW U JUST TYPED\n", row);

  printf("type in the number of cols for maze: ");
  scanf("%d" , &col);
  //  printf("%d THIS IS THE COLUMS U JUST TYPED\n", col);


  for (i = 0; i < row; i++) {
    array[i] = malloc(sizeof(char));
  }

  printf("Type in the name of the file containing the Field: ");
  scanf("%s",file_name);
  fptr=fopen(file_name,"r");
  for (i=0; i<row; i++)
    for (j=0; j<col; j++){
      c=fgetc(fptr); 
      while ( !((c == '1')||(c =='0')) ) c=fgetc(fptr);
      array[i][j]=c;
    }
  fclose(fptr);
  //dont forget this makes the array correclty it just makes it look pretty!
  for (i=0; i<row; i++)
    for (j=0; j<col; j++)  {
      if (j == 0) printf("\n");                
      printf("%c  ",array[i][j]);
    }
  printf("\n");
  //  if(array[0][0] = '0')
  //printf("!!!!!!!!made it, should have printed the maze from file. \n");

  //here i will begin writing the code to solve the maze. 
  findEntrance(array,row,col);



}    

int findEntrance(char** a, int row, int col)
{
    printf("this isjust making sure im accessing the array correctly: %c \n", a[0][0]);
  int i;
  for(i=0; i<col; i++)
    {
      if (a[0][i] =='0')//checks first row for entrence
	{
	  printf("found an entrance at 1,%d \n" ,i+1);
	  return a[0][i];
	}
      else if (a[row-1][i] == '0')//checks last row for entrance
	{
	  printf("found an entrance at %d,%d \n" ,row,i+1);
	  return a[row-1][i];
	}
      printf("passed the first for loop \n");
    }

  for(i=0; i<row; i++)
    {
      if(a[i][0] == '0')
	{
	//checks first col for entrance

	  printf("found entrance at %d,0\n" , i+1);//the plus one takes makes teh rows correct to a human cuz we dont start at 0 and C does
	  return a[i+1][0]; 
	}

      else if (a[i][col] == '0')//checks last col for entrance
	{
	 
	  printf("found an entrance at %d,%d\n", col+1,i);
	  return a[i][col+1];
	}
      printf("passed the second for loop \n");
    }
  printf("yes the function ran..I think \n");
}
