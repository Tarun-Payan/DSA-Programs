#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int main()
{
	char ch[] = "This is my first C program that \ninteract with another file";
	char string[50];
	FILE *fp;
	
	Reading a file
	fp = fopen("textfile.txt", "r");
	if(fp == NULL){
		printf("Cannot open file.\n");
		
	}
	fscanf(fp, "%s", ch);
	printf("The value of textfile.txt :\n%s", ch);
	fclose(fp);
	
	
	//Writing a file
	//fp = fopen("newtxt.txt", "a");
	//printf("Enter some value to store in permanate memory :");
	//gets(string);
	//strcat(string, "\n");
	//fprintf(fp, "%s", string);
	//fclose(fp);
}