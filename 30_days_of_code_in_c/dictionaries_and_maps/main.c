#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_STR_LIM 512
static int account_count = 0;

typedef struct NAME_VALUE_PAIR 
{
	char name[MAX_STR_LIM];
	int number;
} NAME_VALUE_PAIR;

typedef struct NODE 
{
	char member[MAX_STR_LIM];
	struct NODE* next;
} NODE;

void flush_input_buffer() 
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }
}

void UPDATE_STRUCT(NAME_VALUE_PAIR* struct_placeholder, int size_of_struct) 
{
	for (int i = 0; i < size_of_struct; i++) {
		// Get user name
		char tempstring[MAX_STR_LIM];
		scanf("%s", tempstring);
		strcpy(struct_placeholder[i].name, tempstring);

		// Get user number
		scanf("%d", &struct_placeholder[i].number);
	}
	printf("\n\n");
}

char* GET_STRING() 
{
	static char temp[MAX_STR_LIM];
	printf("Enter string to test:\t");
	gets(temp);
	return temp;
}

bool MATCH_CHECK(NAME_VALUE_PAIR* phonebook, char querry[], NAME_VALUE_PAIR* match_result)
{
	// Printing to console for verification check
	bool found_result = false;
	for (int i = 0; i < account_count; i++) {
		if (!strcmp(querry, phonebook[i].name))
		{
			found_result = true;
			strcpy(match_result->name, phonebook[i].name);
			match_result->number = phonebook[i].number;
			break;
		}
	}
	return found_result;
}

int main()
{	
	printf("========== USER INPUT SECTION ===============\n");
	scanf("%d", &account_count);

	// Populate key-value data from user input
	NAME_VALUE_PAIR phonebook[account_count];
	UPDATE_STRUCT(phonebook, account_count);

	// Flushing input buffer	
	flush_input_buffer();

	// Prompting user to enter string to test
	printf("============ TESTING SECTION ================\n");
	char querry[MAX_STR_LIM];
	strcpy(querry, GET_STRING());

	// // Initiating first node of the linked list
	NODE* head = NULL;
	head = (NODE*)malloc(sizeof(NODE));

	// FIXME: Make sure linked list is functioning properly
	while(strcmp(querry, "\0"))
	{
		head->next = head;
		strcpy(head->member, querry);

		NAME_VALUE_PAIR match_result;
		bool found = MATCH_CHECK(phonebook, querry, &match_result);
		if (found)
		{
			printf("%s=%d\n", match_result.name, match_result.number);
		}
		else if (!found)
		{
			printf("Not found\n");
		}

		strcpy(querry, GET_STRING());
	}

	printf("%s\n", head->member);
	head = head->next;
	printf("%s\n", head->member);
	head = head->next;
	printf("%s\n", head->member);

	return 0;
}



