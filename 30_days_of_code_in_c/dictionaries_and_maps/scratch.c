#include<stdio.h>
#include<stdbool.h>
#define CHAR_LIM 512


int main()
{
	while(true) {
		char s[80];
		fgets(s, sizeof s, stdin);
		if(s[0] == '\n') {
	    	puts("line is empty");
		}
		else {
			printf("%s\n", s);
		}
	}
	return 0;
}