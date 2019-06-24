#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<gmp.h>
#include<time.h>
#include <pthread.h>

mpf_t dentro;
pthread_mutex_t mux = PTHREAD_MUTEX_INITIALIZER;


void * thread1(void * d){

mpf_t dentro1;
mpf_init(dentro1);
mpf_set_ui(dentro1,0);
long long int i, limite = 100000000/4;
double X, Y;


for(i=0;i<limite;i++){

    X = ((double)rand()/(double)RAND_MAX);;
    Y = ((double)rand()/(double)RAND_MAX);;
    if( X*X + Y*Y <= 1){
	mpf_add_ui(dentro1,dentro1,1);
    }

}

	pthread_mutex_lock(&mux);
	mpf_add(dentro,dentro,dentro1);
	pthread_mutex_unlock(&mux);

//printf("\n%lld\n",i);
mpf_clear(dentro1);
    pthread_exit(NULL);

}

int main(){

pthread_t t1, t2, t3, t4;

long long int limite = 100000000;
mpf_set_default_prec(100000);
mpf_t total;
mpf_init(dentro);
mpf_set_ui(dentro,0);
mpf_init(total);
mpf_set_ui(total,limite);


srand(time(NULL));


pthread_create(&t1,NULL,thread1,NULL);
pthread_create(&t2,NULL,thread1,NULL);
pthread_create(&t3,NULL,thread1,NULL);
pthread_create(&t4,NULL,thread1,NULL);



pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
pthread_join(t4,NULL);

mpf_mul_ui(dentro,dentro,4);
mpf_div(dentro,dentro,total);

printf("\n pi = ");
mpf_out_str(stdout,10,0,dentro);
printf("\n\n");


mpf_clear(total); mpf_clear(dentro);

return 0;

}

