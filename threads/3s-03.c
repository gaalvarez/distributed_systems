#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THREADS 8
#define VECTOR_SIZE 100000000

pthread_t tid[MAX_THREADS]; 
pthread_mutex_t mutex; 
int *array;
int length = VECTOR_SIZE;
int count = 0;
int double_count = 0;
int t = MAX_THREADS;
int max_threads = 0;

void *count3s_thread(void *arg) {
	int i;
	int length_per_thread = length/max_threads;
	// Cast -> http://stackoverflow.com/questions/1640423/error-cast-from-void-to-int-loses-precision
	//int id = *((int*)(&arg));
	int id = (int)arg;
	int start = id * length_per_thread;
	printf("\tThread [%d] starts [%d] length [%d]\n",id, start, length_per_thread);
	pthread_mutex_lock(&mutex);
	for (i = start; i < start + length_per_thread; i++) {
		if (array[i] == 3) {
			count++;
		}
	}
	pthread_mutex_unlock(&mutex);
}


void initialize_vector() {
	int i = 0;
	array = (int*) malloc(sizeof(int) * VECTOR_SIZE);
	if (array == NULL) {
		printf("Allocation memory failed!\n");
		exit(-1);
	}
	for (; i < VECTOR_SIZE; i++) {
		array[i] = rand() % 20;
		if (array[i] == 3)
			double_count++;
	}
}

int main(int argc, char* argv[]) {
	int i = 0;
	int err;
	clock_t t1, t2, tt1, tt2;

	if (argc == 2) {
		max_threads = atoi(argv[1]);
		if (max_threads > MAX_THREADS)
			max_threads = MAX_THREADS;
	} else {
		max_threads = MAX_THREADS;
	}
	printf("[3s-03] Using %d threads\n",max_threads);
	// random seed
	// http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
	srand(time(NULL));
	printf("*** 3s-03 ***\n");
	printf("Initializing vector... ");
	fflush(stdout);
	initialize_vector();
	printf("Vector initialized!\n");
	fflush(stdout);
	t1 = clock();
	pthread_mutex_init(&mutex,NULL);
	while (i < max_threads) {
		err = pthread_create(&tid[i], NULL, &count3s_thread, (void*)i);
		if (err != 0) 
			printf("[3s-03] Can't create a thread: [%d]\n", i);
		else
			printf("[3s-03] Thread created!\n");
		i++;
	}
	// https://computing.llnl.gov/tutorials/pthreads/#Joining
	i = 0;
	for (; i < max_threads; i++) {
		tt1 = clock();
		void *status;
		int rc;
		rc = pthread_join(tid[i], &status);
		if (rc) {
			printf("ERROR; retrun code from pthread_join() is %d\n", rc);
			exit(-1);
		}  else {
			printf("Thread [%d] exited with status [%ld]\n", i, (long)status);
		}
		tt2 = clock();
		printf("[3s-01] Elapsed time %f\n", (((float)tt2 - (float)tt1) / 1000000.0F ) * 1000);
		printf(" for thread: [%d]\n", i);
	}
	t2 = clock();
	printf("[3s-03] Count by threads %d\n", count);
	printf("[3s-03] Double check %d\n", double_count);
	pthread_mutex_destroy(&mutex);
	//printf("[[3s-03] Elapsed time %ld ms\n", ((double)t2 - t1) / CLOCKS_PER_SEC * 1000);
	printf("[[3s-03] Elapsed full time %f\n", (((float)t2 - (float)t1) / 1000000.0F ) * 1000);
	pthread_exit(NULL);
	return 0;
}

