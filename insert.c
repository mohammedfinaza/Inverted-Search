
#include "head.h"


hash * create_hash_table(hash *table)
{
    int i;

    for(int i=0;i<28;i++)
    {
        table[i].key=i;
        table[i].link=NULL;   
    }
}

int check_duplicate(char str[])
{
    filename *temp=head;
    while(temp!=NULL)
    {
        if(strcmp(temp ->fname,str)==0)
        {
            printf("INFO: %s is repeated ,the file won't be added to the list.\n",str);
            return FAILURE;
        }
        temp =temp -> link;
    }
    return SUCCESS;
}



int insert_last(char str[])
{
    if(check_duplicate(str)!=SUCCESS)
        return FAILURE;

    filename *temp=head,*new=malloc(sizeof(filename));

    if(new==NULL)
    {
        return FAILURE;
    }

    new -> link=NULL;
    strcpy(new ->fname,str);  

    if(head==NULL)
    {
        head=new;
        return SUCCESS;
          
    } 
    
    while(temp -> link !=NULL)
    {
        if(strcmp(temp -> fname,str)==0)
        {
            return FAILURE;
        }
        temp =temp -> link;
    } 

    temp -> link=new;

    return SUCCESS;
     
}

int print_list(filename *head)
{
    printf("\n");

    filename *temp=head;

    while(temp!=NULL)
    {
        printf("%s -> ",temp -> fname);
        temp=temp->link;
    }
    printf("NULL\n");
    return SUCCESS;
}

int find_index(char word)
{
    int index;

    if(word>='a' && word<='z')
    {
        index=word-97;
    }
    else if(word>='A' && word<='Z')
    {
        index=word-65;
    }
    else if(word>='0' && word<='9')
    {
        index=26;
    }
    else
    {
        index=27;
    }

    return index;
}

subnode * create_subnode()
{
    subnode * new=malloc(sizeof(subnode));

    new -> wordcount=0;
    new -> sublink=NULL;

    return new;
}

main_node * create_main_node()
{
    main_node *new=malloc(sizeof(main_node));

    new -> filecount=0;
    
    new -> mainlink=NULL;

    new->sub_link=create_subnode();

    return new;

}

int delete_element(char data[])
 {
    if (head == NULL) 
    {
        return FAILURE;
    }

    filename *temp = head, *temp1 = NULL;

    if (strcmp(head->fname, data) == 0)
    {
        head = temp->link;
        free(temp);
        return SUCCESS;
    }

    while (temp->link != NULL)
    {
        if (strcmp(temp->link->fname, data) == 0) 
        {
            temp1 = temp->link->link;
            free(temp->link);
            temp->link = temp1;
            return SUCCESS;
        }
        temp = temp->link;
    }
    return FAILURE;
}


