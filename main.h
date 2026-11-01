#ifndef DATABASE_H
#define DATABASE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0;
#define FAILURE -1;
typedef struct sub_node
{
    char filename[100];
    int wordcount;
    struct sub_node *sublink;

}Sub_node;

typedef struct main_node
{
    char word[100];
    int filecount;
    struct main_node *mainlink;
    Sub_node *sublink;

}Mainnode;

typedef struct hashtable
{
    int index;
    Mainnode *hashlink;

}hash_table;

typedef struct file_name 
{
   char filename[100];
    struct file_name *filelink;

}File_name;

int create_DB(File_name *f_head, hash_table *hashtable);
int search_DB(File_name *f_head, hash_table *hashtable);
int display_DB(File_name *f_head, hash_table *hashtable);
int save_DB(File_name *f_head, hash_table *hashtable);
int update_DB(File_name *f_head, hash_table *hashtable);

#endif
