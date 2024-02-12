#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


typedef struct {
	int intValue;
} DataBlock;


int main() {
	int id;
	DataBlock *memory, *ptr;
	key_t key;
	int i;
	
	if ((key = ftok(".", 'R')) == -1) {
		perror("ftok");
		exit(1);
	}
	
	if ((id = shmget(key, 5 * sizeof(DataBlock), IPC_CREAT | 0666)) == -1) {
		perror("shmget");
		exit(1);
	}
	
	if ((memory = (DataBlock *)shmat(id, NULL, 0)) == (DataBlock *) -1) {
		perror("shmat");
		exit(1);
	}
	
	for (i = 0, ptr = memory; i < 5; ++i, ++ptr) {
		ptr->intValue = 0;
	}
	
	for (i = 0; i < 5; ++i) {
		pid_t pid = fork();
		if (pid == -1) {
			perror("fork");
			exit(1);
		} else if (pid == 0) {
			srand(getpid());
			memory[i].intValue = rand()%100;
		
			exit(0);
		} 
	}
	
	for (i = 0; i < 5; ++i) {
		wait(NULL);
	}
	
	int sum = 0;
	
	for (i = 0, ptr = memory; i < 5; ++i, ++ptr) {
		sum += ptr->intValue;
		printf("VAL: %d\n", ptr->intValue);
	}
	
	printf("SUM: %d\n", sum);
	
	if(shmdt(memory) == -1) {
		perror("smdt");
		exit(1);
	}
	
	if (shmctl(id, IPC_RMID, NULL) == -1) {
		perror("shmctl");
		exit(1);
	}
	
	return 0;
}


