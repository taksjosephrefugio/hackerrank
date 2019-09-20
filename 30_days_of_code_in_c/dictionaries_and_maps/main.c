#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_STR_LIM 512

typedef struct NAME_VALUE_PAIR {
char name[MAX_STR_LIM];
int number;
} NAME_VALUE_PAIR;

void flush_input_buffer() {
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
	scanf("%s", temp);
	return temp;
}



void PRINT_ALL_GIVE(NAME_VALUE_PAIR* phonebook, char querry[], int account_count)
{
	// // Printing to console for verification check
	for (int i = 0; i < account_count; i++) { printf("%s\t%ld\n", phonebook[i].name, strlen(phonebook[i].name)); }
	printf("%s\t%ld\n", querry, strlen(querry));
	printf("%d\n", strcmp(querry, phonebook[0].name));
}

int main()
{	
printf("========== USER INPUT SECTION ===============\n");
int account_count = 0;
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
PRINT_ALL_GIVE(phonebook, querry, account_count);

// while(true) {
// 	printf("Enter string to test:\t");
// 	fgets(querry, MAX_STR_LIM, stdin);
// 	bool match_found = false;

// 	for (int i = 0; i < account_count; i++) {
// 		int compare_result = strcmp(phonebook[i].name, querry);

// 		if (compare_result == 0) {
// 			printf("%s=%d\n", phonebook[i].name, phonebook[i].number);
// 			match_found = true;
// 			break;
// 		}
// 	}	
// }
return 0;
}



