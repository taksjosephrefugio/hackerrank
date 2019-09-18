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

void UPDATE_STRUCT(NAME_VALUE_PAIR* struct_placeholder, int size_of_struct) {
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

int main()
{	
	printf("======= USER INPUT SECTION =========\n");
	int account_count = 0;
	scanf("%d", &account_count);

	// Populate key-value data from user input
	NAME_VALUE_PAIR phonebook[account_count];
	UPDATE_STRUCT(phonebook, account_count);

	// Flushing input buffer	
	flush_input_buffer();
	
	printf("======== TESTING SECTION ===========\n");
	// Prompting user to enter string to test
	char querry[MAX_STR_LIM];
	printf("Enter string to test:\t");
	scanf("%s", querry);

	// Printing to console for verification check
	printf("%s\t%ld\n", phonebook[0].name, strlen(phonebook[0].name));
	printf("%s\t%ld\n", phonebook[1].name, strlen(phonebook[1].name));
	printf("%s\t%ld\n", querry, strlen(querry));
	printf("%d\n", strcmp(querry, phonebook[0].name));

	//FIXME: Detect empty line input to querry. Might have to do it in hackerrank.

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



