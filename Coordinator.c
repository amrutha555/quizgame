#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"prototype.h"

extern coordinator *c_root ;
question_ans question_extraction_from_file(char * , question_ans);
question_ans *q_root ;

void Coordinator()
{

	int ch ;
	char user_id[BUFFER_SIZE];
	
	design();
	printf("Welcome to Coordinator \n");
	design();
	
	while(1)
	{
		printf("1) Update his/her details\n");
		printf("2) Add New Quiz\n");
		printf("3) Update Quiz\n");
		printf("4) Delete Quiz\n");
		printf("5) Exit\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("enter user-id \n");
				scanf("%s",user_id);
				if(update_coordinator(user_id , c_root) == NULL)
				{
					printf("user-id is not found please enter correct user id %s\n",user_id);
				}
				else 
					printf("updated succesfully\n");
				break;
			case 2: 
				add_new_quiz();
		}
	}
}


void add_new_quiz()
{
	char *quize_file = "quize_question_round1.txt";
	question_ans q_data[10] ;
	char buffer[100] ;
	FILE *fptr = NULL ;
	int counter = 0 , index  = 0;
	
	fptr = fopen(quize_file,"r");
	if(fptr == NULL)
	{
		printf("%s file is not found plsease check the file\n",quize_file);
	}
	else
	{
		while(!feof(fptr))
		{
		
			if(!(fgets(buffer,QUESTION_BUFFER_SIZE,fptr)))
			{
				//printf("string reading is fail\n");
				break ;
			}
			else 
			{
				counter++;
				if(counter == 8)
				{
					printf("quesition is :%s\n",q_data[index].question);
					
					index++ ;
					counter = 0;
				}
				q_data[index] = question_extraction_from_file(buffer , q_data[index]);
			}
		}
	}
		
}

question_ans  question_extraction_from_file(char *str , question_ans q_a_data)
{
	int i = 0  , str_num = 0;
	
	static int ans_index = 0 ;
	//printf("buffer is :%s\n",str);
	
	
	while( *str != '\0' && *str != '\n')
	{
		str_num = str[0] - 48 ; 
		if(str_num > 0  && str_num <=10)
		{
			q_a_data.q_num = str_num;
			str++;
			 
			//printf("question number is :%d \n",q_a_data.q_num);
			
			strcpy(q_a_data.question , str+1);
			//printf("question is %s \n",q_a_data.question);
			break;
		}
		else if(str[0] >= 'A' && str[0] <= 'D')
		{
			str_num = atoi(str+2);
			if(str_num > 0)
			{
				if(ans_index == 4)
				{
					ans_index = 0;
				}
				q_a_data.ans_intiger[ans_index] =  str_num ;
				
				//printf("num : %d\n",q_a_data.ans_intiger[ans_index++]);	
			}
			else
			{
				if(ans_index == 4)
				{
					ans_index = 0;
				}
				
				strcpy(q_a_data.ans_string[ans_index] , str+2);
				
				//printf("string : %s\n",q_a_data.ans_string[ans_index++]);
			}
			break;
		}
		else
		{
			str_num = atoi(str+4) ;
			if(str_num > 0 )
			{
				q_a_data.ans_int = str_num ;
				//printf("ans in int : %d\n",q_a_data.ans_int);
				break;
			}
			else 
			{
				strcpy(q_a_data.ans_str ,str+4 );
				//printf("ans in str : %s\n",q_a_data.ans_str);
				break;
			}
		}
		
		str++;
	}
	
	return q_a_data ;
	
}
