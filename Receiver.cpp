#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

	FILE *fp = fopen("C:\\Users\\sheel\\OneDrive\\Documents\\Visual Studio 2013\\Projects\\Chats\\chats.txt", "r");

	FILE *afp = fopen("C:\\Users\\sheel\\OneDrive\\Documents\\Visual Studio 2013\\Projects\\Chats\\ack.txt", "w");

	char *message = (char *)malloc(sizeof(char)* 255);
	int flag, number, count = 0;

	while (1){
		while (fread(&flag, sizeof(int), 1, fp) != 0){
			if (flag == -1){
				fread(&number, sizeof(int), 1, fp);
				printf("Number: %d\n", number);
				count += 1;
				fwrite(&count, sizeof(int), 1, afp);
				fflush(afp);
			}
			else{
				fread(message, flag, 1, fp);
				message[flag] = '\0';
				printf("Text: ");
				puts(message);
				count += 1;
				fwrite(&count, sizeof(int), 1, afp);
				fflush(afp);
			}
		}
	}

	fclose(afp);

	fclose(fp);

	system("pause");
	return 0;
}