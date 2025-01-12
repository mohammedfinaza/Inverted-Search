#include "head.h"

int update_database(hash *table) 
{
    if(createflag==1)//checking whether database already created or not
    {
        printf("\nINFO: Updation after creation of database not possible\n");
        return FAILURE;
    }

    if(updateflag==1)//checking whether database already created or not
    {
        printf("\nINFO: The database cannot be updated again\n");
        return FAILURE;
    }

    char datafilename[20];
    FILE *fptr;

    printf("Enter the filename: ");
    scanf("%s", datafilename);

    
    if (strstr(datafilename, ".txt") == NULL)//checking whether file is in .txt or not
    {
        printf("INFO: Enter the file in .txt format\n");
        return FAILURE;
    }

    fptr = fopen(datafilename, "r");
    if (fptr == NULL) 
    {
        printf("INFO: The inputed file doesn't exist in the directory\n");
        return FAILURE;
    }

    char start, end;
    fscanf(fptr, "%c", &start);
    fseek(fptr, -2, SEEK_END);
    fscanf(fptr, "%c", &end);

    if (start != '#' || end != '#')//checking whether the file is the database or not
     {
        printf("INFO: The inputed file doesn't have the database\n");
        fclose(fptr);
        return FAILURE;
    }
    rewind(fptr);

    int index, filecount, wordcount;
    char word[20], filename[20];
    main_node *temp1, *prev1;
    subnode *temp2;

    while (fscanf(fptr, "#%d;%[^;];%d;", &index, word, &filecount) != EOF) //updating the saved database onto the table
    {
        if (table[index].link == NULL)
         {
            temp1 = create_main_node();
            table[index].link = temp1;
            temp1 -> filecount = filecount;
            strcpy(temp1 -> word, word);

            temp2 = temp1 -> sub_link;
            fscanf(fptr, "%[^;];%d;", filename, &wordcount);
            temp2 -> wordcount=wordcount;
            strcpy(temp2 -> filename, filename);
            if(check_duplicate(filename)==FAILURE)
            {
                delete_element(filename);
            }

            for (int i = 0; i < filecount - 1; i++)
             {
                fscanf(fptr, "%[^;];%d;", filename, &wordcount);
                temp2 -> sublink = create_subnode();
                temp2 = temp2 -> sublink;
                temp2 -> wordcount=wordcount;
                strcpy(temp2 -> filename, filename);
                if(check_duplicate(filename)==FAILURE)
                {
                    delete_element(filename);
                }
                
            }
        }
        else
        {
            temp1 = table[index].link;
            while (temp1 -> mainlink != NULL) 
            {
                temp1 = temp1 -> mainlink;
            }

            temp1 -> mainlink = create_main_node();
            temp1 = temp1 -> mainlink;
            temp1 -> filecount = filecount;
            strcpy(temp1 -> word, word);

            temp2 = temp1 -> sub_link;
            fscanf(fptr, "%[^;];%d;", filename, &wordcount);
            temp2 -> wordcount=wordcount;
            strcpy(temp2 -> filename, filename);
            if(check_duplicate(filename)==FAILURE)
            {
                delete_element(filename);
            }

            for (int i = 0; i < filecount - 1; i++)
             {
                fscanf(fptr, "%[^;];%d;", filename, &wordcount);
                temp2 -> sublink = create_subnode();
                temp2 = temp2 -> sublink;
                temp2 -> wordcount=wordcount;
                strcpy(temp2 -> filename, filename);
                if(check_duplicate(filename)==FAILURE)
                {
                    delete_element(filename);
                }
            }
        }
        fscanf(fptr,"#\n");

    }

    fclose(fptr);
    printf("\nINFO: Database Updated Successfully\n");
    updateflag=1;
    return SUCCESS;
}

