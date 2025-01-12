#include "head.h"

int save_database(hash *table,char savefilename[])
{

    if(strstr(savefilename,".txt")==NULL)//checking file is .txt format or not
    {
        printf("INFO: Pass the filename in .txt format.");
        return FAILURE;
    }

    FILE *fptr;
    fptr=fopen(savefilename,"w");

    main_node *temp1;
    subnode *temp2;


    for (int i = 0; i < 28; i++)//writing the database onto a file 
    {
        if (table[i].link != NULL)
        {
            temp1 = table[i].link;

            while (temp1 != NULL)
            {
                temp2 = temp1 -> sub_link;
                int flag = 0;
                fprintf(fptr,"#%d;%s;%d;",i, temp1 -> word, temp1 -> filecount);
                while (temp2 != NULL)
                {      
                    fprintf(fptr,"%s;%d;", temp2 -> filename, temp2 -> wordcount);
                    
                    temp2 = temp2->sublink;
                }
                fprintf(fptr,"#\n");
                temp1 = temp1->mainlink;
            }
        }
    }

    fclose(fptr);

    printf("INFO : Database Saved Successfully\n");

    return SUCCESS;


}