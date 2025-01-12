#include "head.h"


int create_database(hash *table) 
{
    if(createflag==1)//checking whether the database is created before or not.
    {
        printf("\nINFO: Database already created\n");
        return FAILURE;
    }

    FILE *fp;
    filename *temp = head;
    char word[50];
    int index;
    main_node *temp1, *prev1;

    while (temp != NULL)
     {
        fp = fopen(temp->fname, "r");
        

        while (fscanf(fp, "%s", word) != EOF)
         {
            index = find_index(word[0]);//finding the index of the word
            

            if (table[index].link == NULL)//creating the main and sub nodes
            {
                temp1 = create_main_node();
                table[index].link = temp1;
                temp1 -> filecount++;
                strcpy(temp1 -> word, word);
                strcpy(temp1 -> sub_link -> filename, temp -> fname);
                temp1 -> sub_link -> wordcount++;
            } 
            else 
            {
                int flag = 0;
                temp1 = table[index].link;

                while (temp1 != NULL)
                 {
                    if (strcmp(word, temp1 -> word) == 0) 
                    {
                        subnode *temp2 = temp1 -> sub_link, *prev2 = NULL;

                        while (temp2 != NULL)
                         {
                            if (strcmp(temp2 -> filename, temp -> fname) == 0) 
                            {
                                flag = 1;
                                temp2 -> wordcount++;
                                break;
                            }
                            prev2 = temp2;
                            temp2 = temp2 -> sublink;
                        }

                        if (flag == 0) 
                        {
                            if (prev2 != NULL) 
                            {
                                prev2 -> sublink = create_subnode();
                                temp2 = prev2 -> sublink;
                                temp1 -> filecount++;
                            } 
                            else
                            {
                                temp1 -> sub_link = create_subnode();
                                temp2 = temp1 -> sub_link;
                                temp1 -> filecount++;
                            }
                            temp2 -> wordcount++;
                            strcpy(temp2 -> filename, temp -> fname);
                            flag = 1;
                        }
                        break;
                    }
                    prev1 = temp1;
                    temp1 = temp1 -> mainlink;
                }

                if (flag == 0) 
                {
                    prev1 -> mainlink = create_main_node();
                    temp1 = prev1 -> mainlink;
                    temp1 -> filecount++;
                    strcpy(temp1 -> word, word);
                    strcpy(temp1 -> sub_link -> filename, temp -> fname);
                    temp1 -> sub_link -> wordcount++;
                }
            }
        }
        fclose(fp);
        temp = temp -> link;
    }

    printf("INFO : Database creation Successful\n");

    createflag=1;

    return SUCCESS;
}

