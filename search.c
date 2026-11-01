#include "main.h"
int search_DB(File_name *f_head, hash_table *hashtable)
{
    char s_word[100];
    int index;
    printf("enter the search word:\n");

    //which word is search
    scanf("%s",s_word);
    
    //find index of using hash table 1 st letter
        if('A' <= s_word[0] &&  s_word[0] <= 'Z')
        {
            index=s_word[0]-'A';
        }
        else if('a' <=s_word[0] && s_word[0]<='z')
        {
           index=s_word[0]-'a';
        }
        else if('0'<=s_word[0] && s_word[0]<='9')
        {
            index=26;
        }
        else
        {
            index=27;
        }
     
   //find index in hashtable main node is threre or not     
  if(hashtable[index].hashlink != NULL)
  {

    Mainnode *m_temp=hashtable[index].hashlink;//hashtable link address in an head
    while(m_temp != NULL)//traverse the main node
    {
        if(strcmp(m_temp->word,s_word)==0)//main node only check word
        {
            //print the index and word ans filecount
        printf("index:%d,Word:%s,filecount:%d",index,m_temp->word,m_temp->filecount);

        Sub_node *s_temp=m_temp->sublink;

        while(s_temp != NULL)
        {
            //all sub node are display it 
             printf("File: %s,Count:%d\n",s_temp->filename,s_temp->wordcount);
            s_temp=s_temp->sublink;
        }
        return SUCCESS;

    }
     m_temp=m_temp->mainlink;//all main node check it
  }
}
//suppose link is there in NULL hash table word is not there
  printf("ERROR:word not found\n");
  return FAILURE;
}
