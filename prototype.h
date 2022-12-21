#include<stdio.h>
#define BUFFER_SIZE 20
#define PSWD_SIZE 8
#define QUESTION_BUFFER_SIZE 200
typedef struct coordinator
{
        char name[BUFFER_SIZE];
        char userid[BUFFER_SIZE];
        char pswd[PSWD_SIZE];
        struct coordinator *next;
}coordinator;

typedef struct question_ans
{
	int q_num ;
	char question[QUESTION_BUFFER_SIZE];
	char ans_string[4][BUFFER_SIZE];
	int ans_intiger[4] ;
	char ans_str[BUFFER_SIZE];
	int ans_int ;
	struct question_ans *next ;
	
}question_ans ;

void design();
void admin();
void Coordinator() ;
void Contestant();


coordinator *new_coordinator();
coordinator *update_coordinator(char *,coordinator *);

coordinator *delete_coordinator(char *,coordinator *);
void display_coordinator();

void delete_contestant();
void view_contestant();

void add_new_quiz(); 
