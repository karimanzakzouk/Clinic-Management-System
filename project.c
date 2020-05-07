#include <stdio.h> 
#include <stdlib.h>
#include<string.h>  
#include "typedefs.h" 
#include "functions.h" 

Node* create_node(void);
Node* search(list L,u16 N_ID); 
void Append(list* L, u16 new_Node_ID, u8 new_Node_name[256] , u8 new_Node_gender, u8 new_Node_age);
u8 replace(list* L ,u16 old_ID, u16 new_Node_ID, u8 new_Node_name[256] ,  u8 new_Node_gender, u8 new_Node_age); 
void printList(Node* N);
void printNode(Node* N);

void main(void) 
{ 
   u8 name[256]= {'\0'};
   u8 gender;
   u8 mode,i,x,flag=0, case_2=0;
   u8 age, slot_num, j; 
   u16 ID , old_ID;
   printf("for admin mode enter 1\n");
   printf("for user mode enter 2\n");
   printf("enter your choice is :\n");	
   scanf("%d",&mode);
   u16 password;
  u8 admin_order, state_R ;	
 do{  
   switch(mode)
   {   
    // admin mode
	    case 1 :
        {  
			printf("enter your password: ");
            scanf("%d",&password);
          while( (flag!=1)&&(i!=2) )
		  {

			switch(password)
			{
			   case 1234 :
			    {  
			        printf("Correct Password \n"); 
			        flag=1;
			        break;
                }
               default :
			    {
			        printf("Incorrect Password \n");
				    for(i=0;i<=1;i++)
                    {
                       printf("try again : ");
                       scanf("%d",&password);
					   if(password==1234)
					   {   break;}  						  
                    }
				   break;
			    }
   	        }
	      }

       if(flag==1)
       {    //admin can add 1 , edit 2 , reserve 3 , cancel 4
	             
		  do{	               	
		        printf("enter your order .......\n");
              	printf("to add patient enter 1 \n");
              	printf("to edit patient enter 2\n");
              	printf("to reserve a slot enter 3\n");
              	printf("to cancel a slot enter 4\n");	
                printf("enter your choice is :\n");				
                scanf("%d",&admin_order);				 
				 
				switch(admin_order)
		       	{
			        case 1 :     //add 
			       { 	//scanning data

					    printf("enter patient ID\n");
				        scanf( "%d" , &ID );
                        Node* temp_N = search(L ,ID); 
						if(temp_N ==NULL)
						{

  					        printf("enter patient age\n");     			 
				            scanf( "%d" , &age );
					        printf("enter patient new gender for F/M \n");     
				            scanf("%s",&gender);						
		                    printf("enter patient name\n");
						    //scanf( "%s" ,&name);							
							gets(name);
                            gets(name);								
                            Append(&L,ID,name,gender,age); 	
	                        printf("patient added thank you.......\n");
							printf("list ...............................................\n");
                            printList(L.start);
						}
                        else
						{
                            printf("ID already exist \n");   
						}						
						
					 break;
					
				   }
			        case 2 :   //edit
			       {  	 //scanning data 			   				
					    printf("enter patient old ID\n");
				        scanf( "%d" , &old_ID );
                        Node* temp_N = search(L ,old_ID); 
						if(temp_N==NULL)
                        {
		                    printf("ID not exist\n");
                        }
                        else
						{							
					        printf("enter patient new ID\n");
				            scanf( "%d" , &ID );					
					        printf("enter patient new age\n");     			 
				            scanf( "%d" , &age );
					        printf("enter patient new gender for F/M \n");     
				            scanf( "%s" ,&gender );							
 					        printf("enter patient new name\n");
							//scanf( "%s" ,&name);
							gets(name);
							gets(name);	
					        state_R = replace(&L, old_ID, ID, name, gender, age);
							if(state_R==1)
                            {
		                        printf("patient replaced thank you\n");
							    printf("list ...............................................\n");
							    printList(L.start); 
                            }
						}

					 break; 
				   }
			        case 3 :
			       {   //reserve
					    
						 printf("enter patient ID \n");
						 scanf( "%d" ,&ID );	
						 Node* temp_N = search(L ,ID); 
						if(temp_N==NULL)
                        {
		                    printf(" ID not exist\n");
                        }
						else 
						{
					     printf("enter desired slot \n");
						 scanf( "%d" ,&slot_num );
						 for(j=0;j<=4;j++)
						 {
                            if(j==(slot_num-1))						 
						    {
							    slots[j] = ID;
						    }							 
						 }	 
						 printf("empty slots........\n");
						 for(j=0;j<=4;j++)
						 {
							 if(slots[j]==0)
							 {
								 printf("slot %d is empty\n",j+1);
							}
						 }
						}
				        break;
				   }
			        case 4 :
			        {   // cancel 
					     printf("enter patient ID \n");
						 scanf( "%d" ,&ID );	
						 Node* temp_N = search(L ,ID); 
						if(temp_N==NULL)
                        {
		                    printf(" ID not exist\n");
                        }
						else 
						{
						 for(j=0;j<=4;j++)
						 {
						   if(slots[j]== ID)						 
						    {
							    slots[j] = 0;
								break;
						    } 
						 }
						 printf("empty slots........\n");
						 for(j=0;j<=4;j++)
						 {
							 if(slots[j]==0)
							 {
								 printf("slot %d is empty  \n",j+1);
							}
						 }						 
						}						 
					   break;
				    }	
                    default :
			           {
			            printf("Invalid order \n");					
					    break;
				       } 
			    }
				
	        printf("if you want to switch to  user mode enter 2  if not enter 1 \n");
            scanf("%d",&mode);
		 
		}while(mode==1);
	   }
	   break;
	  }
	  
// user mode 
	   case 2 :
       {   // user can  view patient information 1 , view slots 2

	        u8 U_order;
	        do{
				printf("enter your order .......\n");
  	            printf("to view patient information enter 1 \n");
   	            printf("to view slots enter 2\n");
	            scanf("%d",&U_order);
	            switch(U_order)
             	{
		            case 1: //view patient information
		            {		   
					    printf("enter patient ID\n");
                        scanf( "%d" , &ID );
		               	Node* N = search(L ,ID);
					  if(N!=NULL)
					  {
			           //printing information
                         printNode(N);
					  }
					  else 
					  {
						 printf("invalid ....\n");
					  }
			           break;
		            }
		            case 2:  // view slots
		            {
						printf("today reservations........\n");
						 for(j=0;j<=4;j++)
						 {
							 if(slots[j]!=0)
							 {
								 printf("slot %d  reserved by patient with ID :%d \n",j+1,ID);
							 } 
							 else
							 {
								 printf("slot %d is empty  \n",j+1); 
							 }
						 }	
		              	break;
		            }
                    default :
                    {
		                printf("Invalid order \n");					
		                break;
		            }
		          
	            }
		      printf("if you want to switch to  admin mode enter 1  if not enter 2 \n");
              scanf("%d",&mode);
              flag=0;			  
	        }while(mode==2);
  
	     break;
       }   
// wrong  	   
       default:
       {
		    printf("invalid mode\n"); 
            break;
       } 
       
}

if((i==2)&&(flag==0))
{
    printf("incorrect password for three times , No more tries... \n ");
	break;
				
}

}while( (mode==1) || (mode==2) );
 

    /*if((mode!=1)&&(mode!=2))
    {      
		printf("invalid mode\n");        
    } 	*/
	
}
 
