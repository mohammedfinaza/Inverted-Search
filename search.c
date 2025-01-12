#include "head.h"

int search_database(char searchword[],hash *table)
{
    int index=find_index(searchword[0]);

    int flag=0;
    main_node *temp1=table[index].link;
    subnode *temp2;

    while(temp1!=NULL)
    {
        if(strcmp(searchword,temp1 -> word) == 0)
        {

            printf("\n%s is present in %d files.\n",searchword,temp1 -> filecount);
            temp2=temp1 -> sub_link;

            while(temp2 !=NULL)
            {
                printf("In file %s %d times\n",temp2 -> filename,temp2 -> wordcount);
                temp2=temp2 -> sublink;

            }
            return SUCCESS;
        }

        temp1 =temp1 -> mainlink;
    }

    printf("INFO: Word is not found in the database.\n");
    return FAILURE;


}