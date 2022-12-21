#include<stdio.h>
#include<string.h>
#include"prototype.h"

void design()
{
	for(int i = 0 ; i <30 ; i++)
		printf("*");
	
	printf("\n");
}

int main()
{
	int ch , admin_pswd_flag = 0;
	char pswd[10];
	char *admin_pswd = "Quiz123";
	design();
	printf("WELCOME TO Quiz Game\n");
	design();
	while(1)
	{
		printf("1) Admin\n");
		printf("2) Coordinator\n");
		printf("3) Contestant\n");
		
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: 
				printf("please enter Password \n");
				
				while(1)
				{
					scanf("%s",pswd);
					
					if(strcmp(admin_pswd ,pswd ) == 0)
					{
						admin();
						break;
					}
					else 
					{
						admin_pswd_flag++;
						printf("please enter correct Password \n");
					}
					
					if(admin_pswd_flag == 3)
					{
						printf("Too many attempts please try again\n");
						break;
					}
				}
					
				break ;
			case 2:
				Coordinator() ;
				break ;
			case 3: 
				Contestant();
				break ;
				
				
		}
		
	}	
	
}
