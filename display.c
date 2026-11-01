#include "main.h"
int display_DB(File_name *f_head, hash_table *hashtable)
{
  //save the file in backup.txt
    int index=0;
//hash table in 27 
while(index <= 27 )
{
//hashtable link is null so no data
  if(hashtable[index].hashlink != NULL)
  {
     //hashlink is initial for mainnode
    Mainnode *m_temp=hashtable[index].hashlink;
     //file write in the backup.txt
    while(m_temp != NULL)
    {
        printf("index:%d,Word:%s,filecount:%d\n",index,m_temp->word,m_temp->filecount);
        //subnode main temp sublink
        Sub_node *s_temp=m_temp->sublink;
        while(s_temp != NULL)
        {
           //print write subnode
            printf("File: %s,Count:%d\n",s_temp->filename,s_temp->wordcount);
            s_temp=s_temp->sublink;
        }
     
        m_temp=m_temp->mainlink;
    }
  }
  index++;//index increment
}
}
