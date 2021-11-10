// Wasim Adetunji

#include <stdio.h>
#include <pthread.h>
int c = 35;
int i = 37;

void* thread_hi_nosem(void* p){
	
    for (int i=0; i<50; i++) {
    printf(".");
    }
    printf(" hi there\n");
    pthread_exit(NULL);			    
}

void* thread_wasim_nosem(void* p){
    
 for (int c=0; c<50; c++) {
    printf("x");
    }
    printf(" Wasim \n");
    pthread_exit(NULL);	
}


int main(void){
  pthread_t t_id1;					
  pthread_create(&t_id1, NULL, thread_hi_nosem, NULL);	
  pthread_t t_id2;	
   pthread_create(&t_id2, NULL, thread_wasim_nosem, NULL);
   pthread_join(t_id1, NULL);
   pthread_join(t_id2, NULL);
}
