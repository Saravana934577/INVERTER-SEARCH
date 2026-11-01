/*DOCUMENTATION:
  NAME: SARAVANAN.K
  REG_NO: 25031_072
  START_DATE:29-05-2026
  END_DATE: 06-05-2026
  DESC: Inverted search is a technique used to map words to the locations where they appear, 
  typically in files or documents.Instead of storing data file-by-file, it stores each word 
  along with the list of files containing that word. This structure is called an inverted 
  index, making searching faster and efficient.It is commonly used in search engines to 
  quickly find documents matching a given keyword.
*/

#include "main.h"

int main(int argc,char *argv[])
{
    
    hash_table hash_t[28];//take an array hashtable
    File_name *f_head=NULL;//one by one linked list
    int choice;
    int flag_c=0;//create flag
    int flag_u=0;//update flag


    if(argc <= 1)
    {
        printf("INFO : plese pass the file name\n");
        return 0;
    }
    //initialise in hashtable link is null
    for(int i=0;i<28;i++)
    {
        hash_t[i].hashlink=NULL;
    }


//it's argument conunt is greater than 1    
if(argc > 1)
{
for(int i=1;i<argc;i++)
{
    //check the extention file is present or not 
if(strstr(argv[i],".txt") == NULL)
{

    printf("error the text file\n");
    return FAILURE;
}

//open the file pointers
 FILE *fptr=fopen(argv[i],"r");

 //check the file pointers
 if(fptr == NULL)
 {
    printf("file does not exit\n");
    return FAILURE;
 }
 
 //create file one by in linked list
File_name *new=malloc(sizeof(File_name));

 if(new==NULL)
 {
    printf("memory alocation is failed\n");
     return FAILURE;
 }

strcpy(new->filename,argv[i]);
new->filelink=NULL;
//it is empty include it empty
if(f_head == NULL)
{
f_head=new;
continue;
}

//create the linked list an one by one file
File_name *temp=f_head;
while(temp->filelink != NULL)
{
    temp=temp->filelink;
}
temp->filelink=new;

}
}

while(1)
{
     
printf("1.Create\n2.Search\n3.Update\n4.Display\n5.Save\n6.Exit\n");
printf("enter the choice:\n");
scanf("%d",&choice);
switch(choice)
{
    case 1:
    {
        //create after create is not possible
        
        if(flag_c==0)
        {
            create_DB(f_head, hash_t);
            flag_c=1;
            break;
        }
        if(flag_c==1)
        {
            printf("Error:two times create is not possible\n");
            break;
        }
    }
    case 2:
    {
         if(flag_c == 0)
        {
            printf("\ncreate is not so search is not possible\n");
            break;
        }
       //call the search function
        search_DB(f_head,hash_t);
        break;
    }
    case 3:
    {
        //update after update is not posssible
        if(flag_c==1)
        {
            printf("Error:create after update is not possible\n");
            break;
        }
        if(flag_u==0)
        {
            update_DB(f_head, hash_t);
            flag_u=1;
            break;
        }
        if(flag_u==1)
        {
            printf("Error:two times update is not possible\n");
            break;
        }
    }
    case 4:
    {
        //call the display the function
        display_DB(f_head,hash_t);
        break;
    }
    case 5:
    {
        //store into the one file
        save_DB(f_head, hash_t);   
        break;
    }
    case 6:
    {
        
        return 0;
        break;
    }
    default:
    {
        printf("ERROR:your choice is wrong\n");
        return 0;
        
    }
    
}
}
}