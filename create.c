#include "main.h"
int create_DB(File_name *f_head, hash_table *hashtable)
{
    //int index;
    File_name *f_temp = f_head;
while(f_temp != NULL)
{
    //file pointer using the txt file
    FILE *fptr=fopen(f_temp->filename,"r");

    //check the file inside data is presen or not
    if(fptr==NULL)
    {
        printf("Error: unable to open file %s",f_temp->filename);
        f_temp=f_temp->filelink;//move to another file
        continue;
        
    }


    char word[100];
    int index;
    //one by one file taking 
    while( fscanf(fptr,"%s",word) != EOF)//take the word using fscanf
    {
        //first letter is decide hash table index
        if('A' <= word[0] &&  word[0] <= 'Z')
        {
            index=word[0]-'A';
        }
        else if('a' <=word[0] && word[0]<='z')
        {
           index=word[0]-'a';
        }
        //all digits are index 26 only
        else if('0'<=word[0] && word[0]<='9')
        {
            index=26;
        }

        //other sybol take 27
        else
        {
            index=27;
        }
        //hashtable link is an head
        Mainnode *m_temp=hashtable[index].hashlink;
        Mainnode *prev= NULL;

        //create a main link
        while(m_temp != NULL)
        {
            //check this word is already there or not
            if(strcmp(m_temp->word,word)==0)
            {
                break;
            }

            prev=m_temp;
            m_temp=m_temp->mainlink;
        }
        //case 1: word not found ->create main node
        if(m_temp == NULL)
        {
            //create the mainnode 
            Mainnode *new_main=malloc(sizeof(Mainnode));
            strcpy(new_main->word,word);//word is create 
            new_main->filecount=1;//intial filecount
            new_main->mainlink=NULL;//main node is connect with new main node

            //create the subnode 
            Sub_node *new_sub =malloc(sizeof(Sub_node));
            strcpy(new_sub->filename,f_temp->filename);//filename is include subnode
            new_sub->wordcount =1;//one word is how many times come
            new_sub->sublink=NULL;//it is connect with new sub link

            //connect the main node and subnode
            new_main->sublink=new_sub;

            //insert the hashtable
            if(hashtable[index].hashlink == NULL)
            {
                hashtable[index].hashlink=new_main;

            }
            //update only main link in prev main link
            else
            {
                prev->mainlink=new_main;
            }

        }
        //case 2: word found ->update sub node
        else
        {
            //traverse the subnode same word but othe file
            Sub_node *s_temp=m_temp->sublink;
            Sub_node *s_prev=NULL;


            while(s_temp != NULL)
            {
                //check the same file and same wodrd check it
                if(strcmp(s_temp->filename,f_temp->filename)==0)
                {
                 break;
                }

                s_prev=s_temp;
                s_temp=s_temp->sublink;
            }
            //only f2.txt love love 2 times
            if(s_temp !=NULL)
            {
                s_temp->wordcount++;//increase only word count
            }
            //create new file for subnode
            else
            {
                Sub_node *new_sub=malloc(sizeof(Sub_node));
                strcpy(new_sub->filename,f_temp->filename);//new file name is stored it
                new_sub->wordcount=1;//intial word count is 1 only
                new_sub->sublink=NULL;

                //subnode also linked list
                if(s_prev == NULL)//this is 1 st sub linked list 
                {
                   m_temp->sublink = new_sub;//update the previous file link main node
                }
             //also sub link is there 
                else
                {
                   s_prev->sublink=new_sub; //update with prev linked list subnode 
                }

                m_temp->filecount++;//new file same word increse the file count also


            }

        }

    }
    fclose(fptr);//close the file after get data
    f_temp = f_temp->filelink;//moving one by one file L.L
}
return SUCCESS;

}