#include "main.h"
int save_DB(File_name *f_head, hash_table *hashtable)
{
    int index=0;
    //save the file in backup.txt
FILE *fp=fopen("backup.txt","w");

//hash table in 27 
while(index <= 27 )
{
  //hashtable link is null so no data
  if(hashtable[index].hashlink != NULL)
  {
    //hashlink is initial for mainnode
    Mainnode *m_temp=hashtable[index].hashlink;
    while(m_temp != NULL)
    {
        //file write in the backup.txt
        
        fprintf(fp,"#%d;%s;%d;",index,m_temp->word,m_temp->filecount);
        //subnode main temp sublink
        Sub_node *s_temp=m_temp->sublink;

        while(s_temp != NULL)
        {
          //file write subnode
            fprintf(fp,"%s;%d;",s_temp->filename,s_temp->wordcount);
            s_temp=s_temp->sublink;//oprate sub link
        }
        //lastly # in skip save it
        fprintf(fp,"#\n");
        m_temp=m_temp->mainlink;
    }
  }
  index++;//index increment
}
}
