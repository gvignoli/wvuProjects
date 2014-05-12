// Guy Vignoli
// Text Justification based on user inputted word per line numbers

/* 
##### BUGS #####
There are two main issues with this program

1. The first letter of the first paragraph is not in line with other
   this is because of the way i formatted the printing.

2. For some reason, the last word in each paragraph will sometimes be cut off, or treated as a separate line. 
   again, not sure why.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode { char Item[15]; struct ListNode *nextPtr;  };
struct ListNode *MyList = 0; // This is the list, initially as empty
typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void Insert(char *word); // Add a new word to the list 
void printList(int pad);//printign list with padding being passed to it
void RemoveList(void);//removes enttire list
main()
{
 
  LISTNODEPTR startPtr = NULL;
  int charLine; //the number of chars desired by user
  char item,c;
  char usrIn[20];//longest file name will be 20 chars
  char tmpStr[30];//basically saying that the longest word i can handle in 25 chars long
  char *wordPtr;
  int i=0;
  int bytes;
  char *buffer;//buffer to hold the contents of file
  int count= 0;
  FILE *in_file; //the user specified file to be justified
  int index=0;
  int buffLen;
  int j=0;
  // int lineCount = 0; 
  int charCount = 0; //the actual number of chars on each line
  int pad=0; //padding to be added, this is in number of white spaces i should add

  //getting name of file to justify
  printf("Enter name of file to be justified:  ");
  gets(usrIn);
  in_file  = fopen(usrIn, "r"); // read only 

  // test for files not existing. 
  if (in_file == NULL) 
    {   
      printf("Error! Could not open file\n"); 
      exit(-1);
    }
 
  //gets user desired number of chars per line
  printf("Enter number of characters per line:  ");
  scanf("\n%d", &charLine);
 
  //defining buffer and putting all text from file into buffer
  fseek(in_file, 0L, SEEK_END);
  bytes = ftell(in_file);
  fseek(in_file, 0L, SEEK_SET);
  buffer = (char*) calloc(bytes,sizeof(char));

  if(buffer == NULL)
    return 1;
  fread(buffer, sizeof(char), bytes, in_file);
  fclose(in_file); //immediately closing file

  buffLen = strlen(buffer);//getting buffer length to use later for iterations
  //printf("%d",buffLen);

 while( index <= buffLen) //doing all of this until end of buffer
    {
      tmpStr[j]=buffer[i]; //basically, this lets my tmpStr be only one word, while still looping over the entire buffer.
 
      if (( tmpStr[j] == ' ')|| (tmpStr[j] == '\n')  )//this means i have found the end of a sentence or the end of a word
	{
	  if (tmpStr[j] == '\n') //reached the end of a line and will now begin padding and printing
	    {
	      pad = charLine - charCount; //charLine is the number the user entered for number of chars per line & charCount is the current chars per line before padding
	      charCount = 0; //sets the number of chars to zero so it can begin countign the chars for the next line 
	      // printf("%d",index);	     

	      printList(pad); //passing the value of pad to correctly pad the line
	      RemoveList(); //removes all nodes and frees space. This gets ran every line
	      printf("\n"); //using carriage return to keep origianl paragraph structure

	    }
	  tmpStr[j] = '\0'; //this is denoting that tmpStr[j] is now the end of my string or word
	  Insert(tmpStr); //inserting the word into my list
	  j = -1;//not the best way to handle this, but immediatly after this get incremented and it has to start at zero sfter being incremented
	 
	}

      charCount++;
      i++;
      j++;
      index++;
    
    } 

  printf("\n"); // just a return for cosmetics
  return 0;
}



void printList(pad) // Print out the words of the list thus far
{ struct ListNode *p;
  int stopPad = 0;
  for ( p= MyList ; p != 0 ; p = p ->nextPtr )
    { 
      if(p ->nextPtr == 0)//this finds the word next to the end of the list and adds the remaining padding right before the last word
	{
	  while(stopPad<pad)
	    {
	      printf(" ");
	      stopPad++;
	    }
	}
      stopPad++;//the following will add an extra space between every word, as long as the padding has not been exceeded
      if(stopPad<pad)
	printf("%s  ",p->Item );
      else{printf("%s ",p->Item );}
    }
	  
}


void Insert(char *word) // Add a new word to the list MyList
{ struct ListNode *item,*last;
  item = (struct ListNode *) malloc(sizeof(struct ListNode));
  if ( item==0 ) { printf ("Malloc Failed \n");  return ; }
  strcpy(item->Item,word); // Copy Word into new Item
  item->nextPtr = 0; // Set that next Item is nothing

  if ( MyList == 0 ) // If List is Empty, make this the first item
    { MyList = item; return ; }

  for( last = MyList ; last->nextPtr != 0 ; last = last->nextPtr ) 
    { } // Find the Last Item in the list. Last Item's Next is 0

  last ->nextPtr = item; // Append New Item to Last Item
}

void RemoveList(void) // Release the memory allocated to the list
{ struct ListNode *p,*next;
  if ( MyList== 0) { return; } // If no List return
  for(p = MyList ; p !=0 ; p = next )
    {
      next = p->nextPtr; // Save the next item position
      free ( p ); // release the item at p.
    }
  MyList=0; // Make sure that list point to 0 (Empty list)
}
