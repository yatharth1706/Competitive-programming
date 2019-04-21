#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#include<unistd.h>
#define N 5
#define THINKING 2 
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum+4)%N
#define RIGHT (phnum+1)%N

int state[N];
int phil[N]={0,1,2,3,4};

sem_t mutex;
sem_t s[N];


void check(int phnum){
	if(state[phnum]== HUNGRY && state[LEFT]!=EATING && state[RIGHT]!=EATING){
		state[phnum]=EATING;
		sleep(2);
		printf("Philosopher %d takes %d and %d fork\n",phnum+1,LEFT+1,phnum+1 );
		
		printf("Philospher %d is eating now...\n", phnum+1);
		
		
		sem_post(&s[phnum]);
		
	}	
}

void take_chopstick(int phnum){
	sem_wait(&mutex);
	
	state[phnum]= HUNGRY;
	printf("Philosopher %d is HUNGRY\n",phnum+1);
	check(phnum);
	
	sem_post(&mutex);
	
	sem_wait(&s[phnum]);
	
	sleep(1);
	
}

void put_chopstick(int phnum){
	sem_wait(&mutex);
	state[phnum]=THINKING;
	
	printf("Philosopher %d putting fork %d and %d\n",phnum+1,LEFT+1,phnum+1);
	
	check(LEFT);
	check(RIGHT);
	
	sem_post(&mutex);
}

void* philosopher(void* num){
	while(true){
		int i=*(int*)num;
		sleep(1);
		take_chopstick(i);
		sleep(0);
		put_chopstick(i);
	}
}

int main(){
	int i;
	pthread_t thread_id[N];
	
	sem_init(&mutex,0,1);
	
	for(i=0;i<N;i++){
		sem_init(&s[i],0,0);
	}
	
	for(i=0;i<N;i++){
		pthread_create(&thread_id[i],NULL, philosopher,&phil[i]);
		printf("Philosopher %d is thinking\n",i+1);
	}
	
	for(i=0;i<N;i++){
		pthread_join(thread_id[i],NULL);
	}
	
	
	
	return 0;
}
