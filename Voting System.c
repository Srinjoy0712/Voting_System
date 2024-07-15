#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
void display();
void add_voter();
void admin_panel();
void cast_vote();
int search(char ad[]);
void winner();
int verify();

typedef struct voter_information
{
    char aadhar[10];
    char namev[20];
    char DOB[15];
    bool vc;
    struct voter_information *next;
} node;

    int vote1=0;
   int vote2=0;
   int vote3=0;
   int vote4=0;

node * start=NULL;

int opt,pass;


node*get_voter(){
     node * new=(node*)malloc(sizeof(node));
     
        printf("Enter Aadhar of  voter");
        scanf("%s",new->aadhar);
        printf("Enter name of  voter");
        scanf("%s",new->namev);
        printf("Enter date of birth in DD-MM-YYYY format");
        scanf("%s",new->DOB);
     new->vc=false;
     new->next=NULL;
     return new;
}




int main(){
   
    	while(1){

    
    printf("\n\n\n");
    printf("\t            ****** WELCOME TO THE ONLINE VOTING PORTAL ******        \n");
   
    printf("        \t\t *****************MAIN MENU*************************\n");
    printf("\t           ***************************************************        \n");
    printf("        \t\t *****1.CAST VOTE       ***** \n");
    printf("        \t\t *****2.ADMIN PANEL     ***** \n");
     printf("       \t\t *****3.ELECTION RESULTS***** \n");
      printf("      \t\t *****4.EXIT            *****\n");
    scanf("%d",&opt);
      switch(opt)
      {
          case 1:cast_vote();
                 break;
          case 2:admin_panel();
                 break;
          case 3: winner();
                 break;
          default:exit(0);
      }
   
   
    }
    

    return 0;
}
    
void admin_panel(){
    int ch;
    printf("\n\n\n\n");
     printf("\t\t\t\t\tEnter Your Password To Unlock The Admin Panel\n\n");
     scanf("%d",&pass);
     if(pass==1234){
         printf("        \t\t **********ADMIN PANEL*********    \n\n\n");
           printf("        \t\t *****1.UPDATE VOTER LIST       *****    \n\n\n");
           printf("        \t\t *****2.display voter list       *****    \n\n\n");
           printf("        \t\t *****3.MAIN MENU       *****    \n\n\n");
           scanf("%d",&opt);
           switch(opt)
           {
               case 1:add_voter();
                      break;
                
                case 2:display();
                       break;
                default: ;      
                      
           }
     }
     else{
           printf("\tINVALID PASSWORD\n\n");
           
     }
}    
    
void add_voter(){
     node *new=get_voter();
     node *temp=NULL;
     temp=start;
     if(start==NULL)
     {
         start=new;
         printf("voter added successfully\n");
     }
     else{
     while(temp->next!=NULL)
     temp=temp->next;
     
     temp->next=new;
      printf("voter added successfully\n");
     }
     
}    




void display(){
    node* temp=NULL;
    temp=start;
    while(temp!=NULL)
{
    printf("VOTER DETAILS ARE\n");
        printf("Name=%s\n",temp->namev);
        printf("AADHAR=%s\n",temp->aadhar);
        printf("DOB=%s\n",temp->DOB);
        temp=temp->next;
}
    
}
void cast_vote()
{  char ad[10];
   int cc=0;

   printf("VOTE CAN BE CASTED ONLY ONCE AND IF YOU ARE PRE-REGISTERED IN VOTER LIST\n");
   printf("ENTER YOUR AADHAR TO VERIFY \n");
   scanf("%s",ad);
   
   if( search(ad))
   {   
       printf("VOTER FOUND");
       if(verify(ad)){
       printf("\nLIST OF CANDIDATES ARE:\n");
       printf("**********************\n");
       printf("1.Narendra Modi\n2.Rahul Gandhi\n3.Basavaraj Bommai\n4.Arvind kejriwal\n");
       scanf("%d",&cc);
       if(cc==1)
       vote1++;
       else if(cc==2)
       vote2++;
       else if(cc==3)
       vote3++;
       else if(cc==4)
       vote4++;
       printf("You have successfully casted your vote");
       }
       else
       printf("\nVOTE HAS ALREADY BEEN CASTED \n");
   }
   else{
       printf("\nVOTER NOT FOUND");
       printf("\nPLEASE REGISTER YOUR NAME IN VOTER LIST FIRST");
       
   }
   
  
}

int search(char ad[]){
    node *temp=start;
    printf("\nSEARCHING IN THE VOTER LIST.....\n");
    while(temp!=NULL){
        if(!strcmp(temp->aadhar,ad))
        return 1;
    }
    return 0;
    
}
int verify(char ad[]){
    node* temp=start;
  while(temp!=NULL){
      if(!strcmp(temp->aadhar,ad))
      {
          if(temp->vc==false){
              temp->vc=true;
          return 1;
          }
          return 0;
      }
      temp=temp->next;
  }
}


void winner()
{

if(vote1>vote2 && vote1>vote3 && vote1>vote4)
printf("Winner is Narendra Modi with %d votes",vote1);
else if(vote2>vote1&&vote2>vote3 && vote2>vote4)
printf("Winner is Rahul Gandhi with %d votes",vote2);
else if(vote3>vote1&&vote3>vote2 && vote3>vote4)
printf("Winner is Basavaraj Bommai with %d votes",vote3);
else if(vote4>vote1&&vote4>vote3 && vote4>vote1)
printf("Winner is Arvind Kejriwal with %d votes",vote4);
else
printf("\nNO WINNER THERE IS A TIE");
}
