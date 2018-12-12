#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *sendMessage(void *params){

	//char *argv = (char *)params;
	
	FILE *fp = fopen("C:\\Users\\sheel\\OneDrive\\Documents\\Visual Studio 2013\\Projects\\Chats\\chats.txt", "w");
	
	char *message = (char *)malloc(sizeof(char)* 255);
	
	while (1){
		int flag = 0;
		fflush(stdin);
		gets(message);
		if (message[0] >= '0' && message[0] <= '9'){
			flag = -1;
			int number = atoi(message);
			fwrite(&flag, sizeof(int), 1, fp);
			fwrite(&number, sizeof(int), 1, fp);
		}
		else{
			flag = strlen(message);
			fwrite(&flag, sizeof(int), 1, fp);
			fwrite(message, flag, 1, fp);
		}
		fflush(fp);
	}
	
	fclose(fp);
	
	return NULL;
}

void *getAck(void *params){
	//char *argv = (char *)params;

	FILE *afp = fopen("C:\\Users\\sheel\\OneDrive\\Documents\\Visual Studio 2013\\Projects\\Chats\\ack.txt", "r");

	int messageID;

	while (fread(&messageID, sizeof(int), 1, afp) != 0){
		printf("\n\nMessage %d is read by receiver.\n\n", messageID);
	}

	fclose(afp);

	return NULL;
}

int main(int argc, char *argv[]){

	pthread_t thread[2];

	pthread_create(&thread[0], NULL, sendMessage, argv[1]);
	pthread_create(&thread[1], NULL, getAck, argv[2]);
	
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);

	system("pause");
	return 0;
}