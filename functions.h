#include <stdio.h> 
#include <stdlib.h> 
#include<string.h> 
#include "typedefs.h" 
typedef struct Node Node;
typedef struct list list;
struct Node 
{ 
   u16 ID; 
   u8 age;
   u8 name[256];
   u8 gender;
   Node* next;
   Node* prev;   
}; 
struct list 
{ 
  Node* start;
  Node* end;
};
list L;
Node N;
u8 slots[5]={0};
Node* start= NULL;
Node* end= NULL;



Node* create_node(void)
{
	return (Node*)malloc(sizeof(Node));	
}
void Append(list* L, u16 new_Node_ID, u8 new_Node_name[256] ,u8 new_Node_gender, u8 new_Node_age) 
{ 
      Node* N = create_node();
	  N->ID = new_Node_ID;
	  N->age = new_Node_age; 
	  strcpy( N->name, new_Node_name);
	  N->gender = new_Node_gender; 
     if(L->start==NULL)
	 {
		  L->start=L->end=N ;
		  N->next = N->prev=NULL;
	 }		 
	 else
	 {
		 L->end->next=N;
		 N->prev = L->end; 
		 N->next = NULL;
		 L->end = N; 
	 }	 	
}
Node* search(list L,u16 N_ID) 
{ 
    Node* cuurent = L.start; 
    while ((cuurent) &&(cuurent->ID != N_ID))
    { 
        cuurent = cuurent->next;	
		if((cuurent==L.end)&&(cuurent->ID != N_ID))   
	   {
		    cuurent = NULL;
			break;
	   }	   
    }
    return cuurent;
}
u8 replace(list* L ,u16 old_ID, u16 new_Node_ID, u8 new_Node_name[256] ,u8 new_Node_gender, u8 new_Node_age)
{
	u8 R_state=0;
	Node* temp = search(*L ,old_ID); 
	Node* N =create_node(); 
	if(temp==NULL)
	{
		 printf("incorrect ID \n");  
	}
	else 
	{   
        if((L->start==L->end))
	    {
		     L->start=L->end=N;
			 N->next=N->prev=NULL;
	    }
		else if(L->end == temp)
		{
			 temp->prev->next=N; 
		     N->prev = temp->prev;
			 N->next =NULL;
			 L->end = N ;
			 
		}
		else if(L->start ==temp)
	    {
			 temp->next->prev=N;
		     N->next = temp->next;
			 N->prev =NULL;
			 L->start = N ;
	    } 
        else 
	    {
			 temp->prev->next=N;
			 temp->next->prev=N;
             N->next = temp->next;			 
		     N->prev = temp->prev;
	    }		
	 N->ID = new_Node_ID;
     N->age = new_Node_age; 
	 strcpy( N->name, new_Node_name );
	 N->gender = new_Node_gender;	 
     R_state= 1;	
	}
	 free(temp);
	 return R_state;
}
void printList(Node* N) 
{ 
  u16 i=1;
while (N!= NULL) 
{ 
	printf("patient %d ID : %d \n",i,N->ID);
    printf("patient %d age : %d \n",i,N->age);
	printf("patient %d name : %s \n",i,N->name);
	//printf("patient name :  \n");
	//puts(N->name);
	printf("patient %d gender : %c \n",i,N->gender);
    printf("..................................\n");	
	N = N->next; 
    i++;	
} 
if(L.start== NULL)
{
  	printf("empty list \n"); 
}	
}
void printNode(Node* N)
{
	//printing information
    printf("..................................\n");			
    printf("patient ID : %d \n",N->ID);
    printf("patient age : %d \n",N->age);
    //printf("patient name :  \n");	
	//puts(N->name);
	printf("patient name : %s \n",N->name);
	printf("patient gender : %c \n",N->gender);
    printf("..................................\n");		
}