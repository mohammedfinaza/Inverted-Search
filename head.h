#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE 1


typedef struct subnode
{
    int wordcount;
    char filename[30];
    struct subnode *sublink;

}subnode;

typedef struct main_node
{
    int filecount;
    char word[20];
    subnode *sub_link; 
    struct main_node *mainlink;  

}main_node;

typedef struct hash_table
{
    int key;
    main_node *link;
}hash;


typedef struct filename
{
    char fname[30];
    struct filename *link;
}filename;

/*Global variables*/
extern filename *head;
extern int updateflag;
extern int createflag;

/*Function to validate the command line argument*/
int read_validate(int argc,char *argv[]);

/*Function to print the single linked list*/
int print_list(filename *head);

/*Function to create database*/
int create_database();

/*Function to insert last to the single linked list*/
int insert_last(char str[]);

/*Function to find the index of the word*/
int find_index(char word);

/*Function to check whether the filename is present in single linked list or not*/
int check_duplicate(char str[]);

/*Function to delete a node in single linked list*/
int delete_element(char data[]);

/*Function to create subnode*/
subnode * create_subnode();

/*Function to create Main node*/
main_node * create_main_node();

/*Function to create hash table*/
hash * create_hash_table(hash *table);

/*Function to display database*/
int display_database(hash *table);

/*Function to search database*/
int search_database(char wordsearch[],hash *table);

/*Function to save database*/
int save_database(hash *table,char savefilename[]);

/*function to update database*/
int update_database(hash *table);


#endif
