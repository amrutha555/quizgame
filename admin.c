#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"prototype.h"
coordinator *c_root = NULL ;

void admin()
{
	int ch , exit_flag_1 = 0 , exit_flag_2 = 0 , exit_flag_3 = 0;
	design();
	printf("Wellcome to Admin \n");
	char user_id[BUFFER_SIZE];
	
	
	while(1)
	{
		design(); 
		printf("1) Manage Coordinator details\n");
		printf("2) Manage Contestant details\n");
		printf("3) Logout and exit\n");
		design();
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: 
				while(1)
				{
					design();
					printf("1) New Coordinator \n");
					printf("2) Update Coordinator \n");
					printf("3) Delete Coordinator \n");
					printf("4) Display Coordinator list\n");
					printf("5) Back to previous menu\n");
					design();
					scanf("%d",&ch);
					
					switch(ch)
					{
						case 1:
							c_root = new_coordinator(c_root);
							break;
						case 2:
							printf("enter user-id \n");
							scanf("%s",user_id);
							if(update_coordinator(user_id , c_root) == NULL)
							{
								printf("user-id is not found please enter correct user id %s\n",user_id);
							}
							else 
								printf("updated succesfully\n");
							
							break;
						case 3:
							printf("enter user-id \n");
							scanf("%s",user_id);
							c_root = delete_coordinator(user_id , c_root);
							break;
						case 4:
							display_coordinator(c_root);
						case 5:
							exit_flag_1 =1;
							
					}
					
					if(exit_flag_1 == 1)
						break;
				}	
				break ;
				
			case 2:
				while(1)
				{
					design();
					printf("1) Delete Contestant\n");
					printf("2) View contestant\n");
					printf("3) Back\n");
					design();
					scanf("%d",&ch);
					
					switch(ch)
					{
						case 1:
							delete_contestant();
							break ;
						case 2: view_contestant();
							break;
						case 3:
							exit_flag_2 = 1;	
					}
					
					if(exit_flag_2 == 1)
						break;
				}
				break ;
				
			case 3:
				exit_flag_3 = 1;
				break ;
				
			
		}
		
		if(exit_flag_3 == 1)
			break;
	}
}

coordinator *new_coordinator(coordinator *source)
{
	if(source == NULL)
	{
		source  = (coordinator *)malloc(sizeof(coordinator));
		printf("enter the user name \n");
		scanf("%s",source->name);
		printf("enter the user-id\n");
		scanf("%s",source->userid);
		printf("enter the password\n");
		scanf("%s",source->pswd);
		source->next = NULL;
	}
	else 
	{
		coordinator *p = source ;	
		coordinator *temp = (coordinator *) malloc(sizeof(coordinator));
		
		 while(p->next != NULL)
		 {
		 	p = p->next ;
				 	
		 }
		 
		printf("enter the user name \n");
		scanf("%s",temp->name);
		printf("enter the user-id\n");
		scanf("%s",temp->userid);
		printf("enter the password\n");
		scanf("%s",temp->pswd);
		
		p->next = temp ;
		temp->next = NULL ;
		 
	}

	return source;	
}	

coordinator *update_coordinator(char *str , coordinator *source)
{

	int flag = 0;
	char ch ;
	printf("%s\n",str);
	coordinator *p = source ;	
	
	while(p!= NULL)
	{
		if(strcmp(p->userid , str) == 0)
		{
			flag =1 ;
			
			printf("user-id is %s\n",p->userid);
			printf("name is %s\n",p->name);
			printf("pswd is %s\n",p->pswd);
			
			printf("enter y to update\n");
			scanf(" %c",&ch);
			if(ch == 'y' || ch == 'Y')
			{
				printf("enter the user name \n");
				scanf("%s",p->name);
				printf("enter the user id \n");
				scanf("%s",p->userid);
				printf("enter the password\n");
				scanf("%s",p->pswd);
			}
		}
		
		p = p->next ;
	}

if(flag == 0)
	return NULL ;
else 
	return source ;
		
}

void display_coordinator(coordinator *source)
{
	while(source != NULL)
	{
		printf("user-name is %s\n",source->name);
		printf("user-id is %s\n",source->userid);
		
		source = source->next ;
	}

}

int* len_of_list_coordinator(coordinator  *source ,int *index)
{
	int count =0 ;
	
	if(source ==  NULL)
	{
		printf("list is empty\n") ;
		return NULL ;
	}
	
	
	coordinator   *p = source ;
	
	while(p!=NULL)
	{
		count ++;	
		p = p->next ;
	}
	
	*index = count ;
	
	return index ;	
}


int *lookup_coordinator(coordinator *source, char *str , int *index )
{
	
	
	 int count = 1 , check_flag = 0;
	 
	 if(source ==  NULL)
	 {
		printf("list is empty\n") ;
		return NULL ;
	  }
	
	coordinator *p = source ;
	
	int i = 0 , j =0;
	
	while(p!=NULL)
	{
		if(strcmp(p->userid ,str) == 0 )
		{
			
			printf("user-id is %s\n",p->userid);
			printf("name is %s\n",p->name);
			check_flag = 1;
			break;
		}
		else 
		{
			count++ ;
				
		}
		p = p->next ;
	}
	
	if(check_flag == 1)
	{
		*index = count ;
	}
	else
		*index = -1;
	
	return index ;
}


coordinator *delete_coordinator(char *str , coordinator *source)
{
	
	printf("delete_coordinator \n");
	
	int position = 0   , len = 0 , link =1;
	
	char ch ;
	
	if(source ==  NULL)
	{
		printf("list is empty\n") ;
		return NULL ;
	 }
	 
	 
	coordinator *p = source ;
	coordinator *temp = source  ;
	
	position = *lookup_coordinator(p,str,&position) ; 
	len = *len_of_list_coordinator(p,&len);
	

	printf("please enter y to delete \n");
	scanf(" %c",&ch);
	
	if((ch == 'y' || ch == 'Y')&&position >0)
	{
		if(position == 1)
		{
			source = temp->next ;
			temp->next = NULL ;
		}
		else if(position < len)
		{
				 
			while(link < position-1)
			{
				temp = temp->next;
				link++ ;
					
			}
			
			coordinator* del = temp->next;
			del->next = del->next ;
			temp->next = del->next ;		
			
		}
		else if(position == len)
		{
			link = 1 ;
			
			
			while(link < position-1)
			{
				temp = temp->next; 
				link++;
			}
			
			temp->next = NULL;
			
		
		}
	}
	else 
	printf("user-id is  not deleted\n");	
	return source;
}

void delete_contestant()
{
	printf("delete_contestant \n");	
}

void view_contestant()
{
	printf("view_contestant \n");
}
