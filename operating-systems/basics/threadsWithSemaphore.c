// Wasim Adetunji

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;

int t = 0;

void* thread_adder_wsem(void* _arg){
	
    for (int i= 0; i<20; i++) {
	  
      printf("adding %d time\n", i);
      sem_wait(&mutex);
      int x= t;
      x = x + 1;
      t =x;
      sem_post(&mutex);
    }
	
    pthread_exit(&t); 	    
}

void* thread_subtracter_wsem(void* _arg){
    for (int i =0; i< 20; i++) {
	    printf("subtracting %d time\n", i);
      sem_wait(&mutex);
      int x =t;
      x =x - 1;
      t =x;
      sem_post(&mutex);
    }
    
    pthread_exit(&t); 	
}


int main(void){
  pthread_t t_id1, t_id2, t_id3, t_id4;		
  int* finalVal;
  int errNo = sem_init(&mutex, 0, 1);
  
				// note to self:
				// pay careful attention to initialization value

  if(errNo){printf("Error code {%d} encountered.", errNo);};
  
  pthread_create(&t_id1, NULL, thread_adder_wsem, NULL);						
 
  pthread_create(&t_id3, NULL, thread_subtracter_wsem, NULL);
  
  pthread_create(&t_id2, NULL, thread_adder_wsem, NULL);	
  
  pthread_create(&t_id4, NULL, thread_subtracter_wsem, NULL);
  pthread_join(t_id1, NULL);
  printf("adder1 finished\n");
  pthread_join(t_id2, NULL);
  printf("adder2 finished\n");
  pthread_join(t_id3, NULL);
  printf("Subtractor1 finished\n");

  pthread_join(t_id4, (void**)&finalVal);
  printf("Subtractor2 finished\n");
  printf("Value received by parent process from last subracter thread: %d\n", *finalVal);

  sem_destroy(&mutex);
}
 
