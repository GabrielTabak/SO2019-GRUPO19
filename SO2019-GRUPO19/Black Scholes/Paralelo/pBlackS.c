#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

double max(double a){

    if(a>0)
	return a;
    else
	return 0;

}


void * thread1(void * S){

double * k = (double *)S;
int i;double t, *trials;

trials = malloc(sizeof(double)*(k[5])/4);


for(i=0;i<(k[5])/4;i++){
    t = k[0]*pow(M_E,(k[2] - k[3]*k[3]/2)*k[4] + k[3]*sqrt(k[4])*rand()/(double)RAND_MAX);
    trials[i] = pow(M_E,(-k[2])*k[4])*max(t-k[1]);
}

    pthread_exit(trials);


}




int main(){

FILE *f;
f = fopen("entrada_blackscholes.txt", "r");
srand(time(NULL));
double * S;

pthread_t t1,t2,t3,t4;

long long int i;
double * trials1, * trials2,* trials3,* trials4, media=0, variancia = 0, stddev, intervalo, minimo, maximo;


S = malloc(sizeof(double)*6);

fscanf(f,"%lf", &S[0]);
fscanf(f,"%lf", &S[1]);
fscanf(f,"%lf", &S[2]);
fscanf(f,"%lf", &S[3]);
fscanf(f,"%lf", &S[4]);
fscanf(f,"%lf", &S[5]);


pthread_create(&t1,NULL,thread1,(void *)S);
pthread_create(&t2,NULL,thread1,(void *)S);
pthread_create(&t3,NULL,thread1,(void *)S);
pthread_create(&t4,NULL,thread1,(void *)S);


void * recebe;


pthread_join(t1,&recebe);
trials1 = (double *)recebe;
pthread_join(t2,&recebe);
trials2 = (double *)recebe;
pthread_join(t3,&recebe);
trials3 = (double *)recebe;
pthread_join(t4,&recebe);
trials4 = (double *)recebe;

fclose(f);

for(i = 0 ; i < S[5]/4; i++){
	media =  media + trials1[i] + trials2[i] + trials3[i] + trials4[i];

}

media = media/S[5];
for(i = 0 ; i < S[5]/4; i++){
    variancia = variancia + ((trials1[i]-media)*(trials1[i]-media)) + ((trials2[i]-media)*(trials2[i]-media)) + ((trials3[i]-media)*(trials3[i]-media)) + ((trials4[i]-media)*(trials4[i]-media));
}

variancia = variancia/S[5];
stddev = sqrt(variancia);

intervalo = (1.96*stddev)/(sqrt(S[5]));
minimo = media - intervalo;
maximo = media + intervalo;


	printf("S        %0.lf\n",S[0]);
	printf("E        %0.lf\n",S[1]);
	printf("r        %0.lf\n",S[2]);
	printf("sigma    %0.lf\n",S[3]);
	printf("T        %0.lf\n",S[4]);
	printf("M        %lf\n",S[5]);
	
	printf("Intervalo: (%lf,%lf)\n", minimo,maximo);


free(trials1);free(trials2);free(trials3);free(trials4);
free(S);


return 0;

}
