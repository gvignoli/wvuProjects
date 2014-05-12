// Guy Vignoli
// Text Justification based on user inputted word per line values
#include <stdio.h>
#include <stdlib.h>

struct listNode {  /* self-referential structure */
  char data;
  
  struct listNode *nextPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void insert(LISTNODEPTR *, char[]);
char delete(LISTNODEPTR *, char);
//int isEmpty(LISTNODEPTR);
//void printList(LISTNODEPTR);


main()
{
 
  LISTNODEPTR startPtr = NULL;
  int charLine;
  int count;
  char item,c;
  char usrIn[20];
  char word[25]="test";//basically saying that the longest word i can handle in 25 chars long
  FILE *in_file;
  FILE *out_file; 

  printf("Enter name of file to be justified:  ");
  gets(usrIn);
  in_file  = fopen(usrIn, "r"); // read only 
  out_file = fopen("justified", "w"); // write only 
  fprintf(out_file,"this is a test of writing to a file \n");

  // test for files not existing. 
  if (in_file == NULL) 
    {   
      printf("Error! Could not open file\n"); 
      exit(-1);
    }
 
  printf("Enter number of characters per line:  ");
  scanf("\n%d", &charLine);
  printf("this is the number of char per line: %d \n",charLine);//verifying the charLine value
  //  printf("enter a word test word to be put into the list: \n");
  //gets(word);
  word[0] = 'h';
  word[1] = 'i';//trying to insert the word hi into the list....
  char *wordPtr;
  wordPtr = word;
  printf("LLLOOKKKK %c \n",*wordPtr);
  //*Ptr = word[0];
  //printf("LLOOOKKK %c \n",*Ptr);
  do
   {
      c = fgetc(in_file);
      printf("%c", c);//prints to screen
      fprintf(out_file, "%c",c);//prints to file called justified in working directory

      // void insert(LISTNODEPTR *, char);
      //uncomment to get number of chars per line.
      /* count++;
	 if(c=='\n')
	{
	printf("*******************this is the number of char per line: %d \n",count);//verifying the charLine val
	count = 0;
	}
      */
   }while(c != EOF);

  while(EOF != (c = fgetc(filePtr))) 
    {

      if ((c == ' ') || (c == '\n'))
	{
	  if (i == 0)
	    {
	      continue;
	    }

	  tempStr[i] = '\0';
	  i = 0;

	  //here do your linklist node creation and insertion operation
	   insert(&startPtr,word);
	   printList(startPtr);
 
	  continue;
	}

      tempStr[i] = c;
      i++;
    }

  fclose(in_file);
  return 0;
}




/* Insert a new value into the list in sorted order */
void insert(LISTNODEPTR *sPtr,  char word[25])//trying to store entire word in char[]
{
  LISTNODEPTR newPtr, previousPtr, currentPtr;

  //newPtr = malloc(sizeof(LISTNODE));//originally in example, writing mine below
  newPtr = malloc(sizeof(word));
  int i;
  for ( i =0; i<strlen(word)-1; i++)
  printf("checking to see what is being put into list %c \n",word[i]);
  //  printf("checking to see what is being put into list %c \n",wordPtr);
  if (newPtr != NULL) {    /* is space available */
    newPtr->data = word[0];
    newPtr->nextPtr = NULL;

    previousPtr = NULL;
    currentPtr = *sPtr;

    while (currentPtr != NULL) {
      previousPtr = currentPtr;          /* walk to ...   */
      currentPtr = currentPtr->nextPtr;  /* ... next node */
    }

    if (previousPtr == NULL) {
      newPtr->nextPtr = *sPtr;
      *sPtr = newPtr;
    }
    else {
      previousPtr->nextPtr = newPtr;
      newPtr->nextPtr = currentPtr;
    }
  }
  else
    printf("No memory available.\n");
}

/*should not need this function
// Delete a list element 
char delete(LISTNODEPTR *sPtr, char value)
{
  LISTNODEPTR previousPtr, currentPtr, tempPtr;

  if (value == (*sPtr)->data) {
    tempPtr = *sPtr;
    *sPtr = (*sPtr)->nextPtr;  /* de-thread the node 
    free(tempPtr);             /* free the de-threaded node 
    return value;
  }
  else {
    previousPtr = *sPtr;
    currentPtr = (*sPtr)->nextPtr;

    while (currentPtr != NULL && currentPtr->data != value) {
      previousPtr = currentPtr;          /* walk to ...   
      currentPtr = currentPtr->nextPtr;  /* ... next node 
    }

    if (currentPtr != NULL) {
      tempPtr = currentPtr;
      previousPtr->nextPtr = currentPtr->nextPtr;
      free(tempPtr);
      return value;
    }                                                        
  }

  return '\0';
}
*/


/* Shouldnt need  function

// Return 1 if the list is empty, 0 otherwise 
int isEmpty(LISTNODEPTR sPtr)
{
  return sPtr == NULL;
}
*/


// Print the list 
void printList(LISTNODEPTR currentPtr)
{
  if (currentPtr == NULL)
    printf("List is empty.\n\n");
  else {
    printf("The list is:\n");

    while (currentPtr != NULL) {
       printf("%c --> ", currentPtr->data);//commented out, do not need '-->' in my proj
      currentPtr = currentPtr->nextPtr;
    }

    printf("NULL\n\n");
  }
}
