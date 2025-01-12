/*Documentation
Name : Mohammed Finaz A
Date : 26/12/24
DES  :Inverted Search

*/

#include "head.h"

filename *head = NULL;
int updateflag=0;
int createflag=0;

int main(int argc,char *argv[])
{

   hash table[28];
   int choice;
   char ch,searchword[20],savefilename[20];

   if(read_validate(argc,argv)==SUCCESS)//validating the commandline arguments
   {
      create_hash_table(table);

   }
   else
   {
      return 0;
   }


   print_list(head);//printing the single linked list

   do
   {
      printf("\n");
      printf("Enter the choice among the below operation\n");
      printf("1. Create Database\n");
      printf("2. Display Database\n");
      printf("3. Update Database\n");
      printf("4. Search\n");
      printf("5. Save Database\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)//switch case to do the operation.
      {
         case 1:
               create_database(table);
               break;
         case 2:
               display_database(table);
               break;
         case 3:
               update_database(table);
               break;
         case 4:
               printf("Enter the word to search : ");
               scanf("%s",searchword); 
               search_database(searchword,table);
               break;
         case 5:   
               printf("Enter the filename to save database: ");
               scanf("%s",savefilename);
               save_database(table,savefilename);       
               break;   
         default:
               printf("\nInvalid choice. Please try again.\n");
      }


      printf("\nEnter y/Y to continue and n/N to discontinue :");
      scanf(" %c",&ch);

   }while(ch!='N' && ch!='n');
   


}