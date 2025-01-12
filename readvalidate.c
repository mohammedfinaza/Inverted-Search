#include "head.h"

int read_validate(int argc,char *argv[])
{
    int flag=0,count=0;

    if(argc>1)//checking whether file names are given or not
    {
        int len,i,j;

        for(i=1;i<argc;i++)
        {
            flag=0;
           
            FILE *fptr;

            if(strstr(argv[i],".txt"))//checking whether in .txt format or not
            {
                flag=1;
            }
            else
            {
                printf("INFO: %s is not in .txt format\n",argv[i]);
            }
                

            if(flag==1)
            {
                fptr=fopen(argv[i],"r");

                if(fptr!=NULL)//checking whether the file exist in the directory or not.
                {
                    fseek(fptr,0,SEEK_END);
                    if(ftell(fptr)!=0)//checking whether file is empty or not.
                    {
                        fclose(fptr);
                        if(insert_last(argv[i])==SUCCESS)
                            count++;

                    }
                    else
                    {
                        printf("\nINFO :%s is empty\n",argv[i]);
                    }
                    
                   
                }
                else
                {
                    printf("\nINFO: %s doesn't exist in the directory\n",argv[i]);
                }

            }    
   
        } 
    }
    else
    {
      printf("INFO : Insufficient arguments\n");
      printf("Please pass the arguments like ./a.out <txt file>\n");  
      return FAILURE;
    }

    if(count==0)
    {
        printf("INFO: Pass atleast one .txt file\n");
        return FAILURE;
    }

    return SUCCESS;

    
}