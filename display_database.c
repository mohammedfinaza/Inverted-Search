
#include "head.h"

int display_database(hash *table)
{
    int i;
    main_node *temp1;
    subnode *temp2;

    printf("\n%-10s %-20s %-16s %-20s %-10s\n", "INDEX", "WORD", "FILE COUNT", "FILE NAME", "WORD COUNT");

    for (i = 0; i < 28; i++)//displaying the database
    {
        if (table[i].link != NULL)
        {
            temp1 = table[i].link;

            while (temp1 != NULL)
            {
                temp2 = temp1 -> sub_link;
                int flag = 0;
                while (temp2 != NULL)
                {
                    if (flag == 0)
                    {
                        
                        printf("%-10d %-20s %-16d %-20s %-10d\n",i, temp1 -> word, temp1 -> filecount, temp2 -> filename, temp2 -> wordcount);
                        flag = 1;
                    }
                    else
                    {
                        
                        printf("%-10s %-20s %-16s %-20s %-10d\n", "", "", "", temp2 -> filename, temp2 -> wordcount);
                    }
                    temp2 = temp2->sublink;
                }
                temp1 = temp1->mainlink;
            }
        }
    }

    printf("\n");

    return SUCCESS;
}
