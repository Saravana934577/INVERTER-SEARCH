#include "main.h"

int update_DB(File_name *f_head, hash_table *hashtable)
{
    //file name backup.txt
    char filename1[50]="backup.txt";
    //.txt filename invalid
   if(strstr(filename1,".txt") == NULL)
   {
     printf("invalid file name\n");
     return 0;
   }
   //open the filename
    FILE *fptr=fopen("backup.txt","r");

    //file is inside not there 
    if(fptr == NULL)
    {
        printf("error the open file\n");
        return 0;
    }
    
int index,filecount;

char word[100];//word is there
char fname[100];
int w_count;

//index,word and filecount is only 3 data
while( fscanf(fptr," #%d;%[^;];%d;",&index,word,&filecount) == 3)
{
    //create the main node
    Mainnode *new_main=malloc(sizeof(Mainnode));
    strcpy(new_main->word,word);//store the word in mainnode
    new_main->filecount=filecount;//store the filecount
    new_main->mainlink=NULL;
    new_main->sublink=NULL;

//file count is again and again 
for(int i=0;i<filecount;i++)
{
    //take the input filename and wordcount
      fscanf(fptr,"%[^;];%d;",fname,&w_count); 
      
      //data is collect file create new file 
      File_name *new_file = malloc(sizeof(File_name));

      //new file is stored linked list
strcpy(new_file->filename, fname);
new_file->filelink = NULL;

//head is empty so create file
if(f_head == NULL)
{
    f_head = new_file;
}

//file is create after linked it
else
{
    File_name *temp = f_head;

    while(temp->filelink != NULL)
    {
        temp = temp->filelink;//traverse file
    }

    //update with new filw
    temp->filelink = new_file;
}

      //create sub node 
    Sub_node *new_sub=malloc(sizeof(Sub_node));
    strcpy(new_sub->filename,fname);
    new_sub->wordcount=w_count;
    new_sub->sublink=NULL;

    //last sub link is an update it
    if(new_main->sublink == NULL)
    {
       new_main->sublink=new_sub;
    }

    //sublink is not null
    else
    {
        //not null head sublink
        Sub_node *last =new_main->sublink;
        while(last->sublink !=NULL)
        {
            last=last->sublink;//traverse the sub link
        }
      last->sublink=new_sub;//final sublink newnode

    }
      
}
//take the # in last line
fscanf(fptr,"#");
//hash table link is update 
if(hashtable[index].hashlink == NULL)
{
hashtable[index].hashlink=new_main;
}
//main node data is updated
else
{

    Mainnode *temp =hashtable[index].hashlink;
    while(temp->mainlink !=NULL)
    {
        temp=temp->mainlink;//traverse only main node
    }
    temp->mainlink=new_main;//main link is updated in last oneindex

}

}

fclose(fptr);//close the file
printf("update is done\n");
return SUCCESS;
}