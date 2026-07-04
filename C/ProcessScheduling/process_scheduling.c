
//Alphan Algül 2584639
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <pthread.h>

//process data structure
typedef struct {
    int pid;/* Process ID: 1 to 10    */
    int burst_time;/* Execution time: 5 to 25 ms */
    int priority;/* 1 to 10 (larger = higher priority) */
    int arrival_time; /* Arrival time: 0 to 20 ms */
} Process;

//initializing an array of n processes
void initProcesses(Process queue[], int n) {
    for (int i = 0; i <n; i++) {
        queue[i].pid = i+1;
        queue[i].burst_time = rand()%21 + 5;
        queue[i].priority = rand()%10 + 1;
        queue[i].arrival_time = rand()%21;
    }
}

//printing the process array
void printArray(Process queue[],int n) {
    for (int i = 0; i < n; i++) {
        printf("\nProcess ID: %d",queue[i].pid);
        printf("\nProcess Burst Time: %d",queue[i].burst_time);
        printf("\nProcess Arrival Time: %d",queue[i].arrival_time);
        printf("\nProcess Priority: %d\n",queue[i].priority);
    }
}

//sorting the process array based on arrival time or priority
void sortProcesses(Process queue[], int n, int mode) {
    for (int i = 1; i < n; i++) {
        Process sort = queue[i];
        int j = i - 1;

        if (mode == 1) {//sorting based on arrival time
            while (j >= 0 && queue[j].arrival_time > sort.arrival_time) {
                queue[j + 1] = queue[j];
                j--;
            }
        }
        else if (mode == 2) {//sorting based on priority if priorities are equal the one with the lower arrival time will be first
            while (j >= 0) {
                if (queue[j].priority < sort.priority) {
                    queue[j + 1] = queue[j];
                    j--;
                }
                else if (queue[j].priority == sort.priority &&
                         queue[j].arrival_time > sort.arrival_time) {
                    queue[j + 1] = queue[j];
                    j--;
                         }
                else {
                    break;
                }
            }
        }

        queue[j + 1] = sort;
    }
}

//executing processes with either Shortest Process Next or Preemptive
void executeProcesses(Process queue[], int n, int algorithm) {
    int remaining_time[10];
    int completion_time[10];
    int completed_processes[10];
    int count = 0;
    int time = 0;

    // initialize remaining times
    for (int i = 0; i < n; i++) {
        remaining_time[i] = queue[i].burst_time;
    }

    //Shortest Process Next
    if (algorithm == 1) {

        //While there are processes to complete
        while (count < n) {
            int selected_process = -1;
            int process_completed;

            for (int i = 0; i < n; i++) {
                process_completed = 0;

                // skip already completed processes
                for (int j = 0; j < count; j++) {
                    if (queue[i].pid == completed_processes[j]) {
                        process_completed = 1;
                        break;
                    }
                }

                // If the process arrived and isnt completed start it
                if (queue[i].arrival_time <= time && process_completed == 0) {
                    if (selected_process == -1) {//if it is the first process arrived start right away
                        selected_process = i;
                    }
                    //else start the processes based on shortest burst time
                    else if (queue[i].burst_time < queue[selected_process].burst_time) {
                        selected_process = i;
                    }
                }
            }

            // if no processes continue
            if (selected_process == -1) {
                time++;
                continue;
            }

            //non preemptive so run process until completed
            while (remaining_time[selected_process] > 0) {
                printf("\nTime %d: Process %d is running\n", time, queue[selected_process].pid);
                remaining_time[selected_process]--;
                time++;
            }

            //Store the completed process and its completion time
            completion_time[selected_process] = time;
            completed_processes[count] = queue[selected_process].pid;
            count++;
        }
    }


    //Preemptive
    else if (algorithm == 2) {

        //While there are processes to complete
        while (count < n) {
            int selected_process = -1;
            int process_completed;

            for (int i = 0; i < n; i++) {
                process_completed = 0;

                // skip already completed processes
                for (int j = 0; j < count; j++) {
                    if (queue[i].pid == completed_processes[j]) {
                        process_completed = 1;
                        break;
                    }
                }

                // If the process arrived and isnt completed start it
                if (queue[i].arrival_time <= time && process_completed == 0) {
                    if (selected_process == -1) {//if it is the first process arrived start right away
                        selected_process = i;
                    }
                    //else start the processes based on priority
                    else if (queue[i].priority > queue[selected_process].priority) {
                        selected_process = i;
                    }
                }
            }

            // if no processes continue
            if (selected_process == -1) {
                time++;
                continue;
            }

            // run for 1ms, if higher priority process arrives switch to it
            printf("\nTime %d: Process %d is running\n", time, queue[selected_process].pid);
            remaining_time[selected_process]--;
            time++;

            // if the process is completed store the completed process and its completion time
            if (remaining_time[selected_process] == 0) {
                completion_time[selected_process] = time;
                completed_processes[count] = queue[selected_process].pid;
                count++;
            }
        }
    }

    printf("\nTurnaround and Waiting Times:\n");
    for (int i = 0; i < n; i++) {
        int turnaround = completion_time[i] - queue[i].arrival_time;
        int waiting = turnaround - queue[i].burst_time;

        printf("Process %d, Turnaround Time: %d, Waiting Time: %d\n",
               queue[i].pid, turnaround, waiting);
    }
}

void *thread1_function(void *pArg){
	Process *q_thread = (Process*)pArg;
	sortProcesses(q_thread,10,2);
	pthread_exit(0);
}

void *thread2_function(void  *pArg){
	Process *q_thread = (Process*)pArg;
	executeProcesses(q_thread,10,2);
	pthread_exit(0);
}

int main(void) {
    srand(time(NULL));
    Process q[10];
    initProcesses(q,10);

    //Sorting by arrival time
    printf("\n------------------------------------------------------------------------------------");
    sortProcesses(q,10,1);
    printArray(q,10);

    //SOrting by priority and if priorities are equal by who arrived first
    printf("\n------------------------------------------------------------------------------------");
    sortProcesses(q,10,2);
    printArray(q,10);
   
    //Shortest Process Next
    printf("\n------------------------------------------------------------------------------------");
    executeProcesses(q,10,1);

    //Preemptive by priority
    printf("\n------------------------------------------------------------------------------------");
    executeProcesses(q,10,2);

    printf("\n------------------------------------------------------------------------------------");
    printf("\n------------------------------------------------------------------------------------");

    //allocating process array with mmap
    Process  *process_queue = mmap(NULL, 10 * sizeof(Process), PROT_READ | PROT_WRITE , MAP_SHARED | MAP_ANONYMOUS, 0 ,0 );
    initProcesses(process_queue,10);
    printArray(process_queue,10);
    printf("\n------------------------------------------------------------------------------------");

   pid_t p = fork();//creating child process with fork

   if(p == 0){//child process
	 printf("\n------------------------------------------------------------------------------------");
	 sortProcesses(process_queue, 10, 1);
	 printArray(process_queue,10);
	 printf("\nChild completed.\n");
	 printf("\n------------------------------------------------------------------------------------\n");
	 return 0;
   }
   else{//parent process
	wait(NULL); //parent waits until child finishes executing
	printf("\nParent reads:\n");
	printf("\n------------------------------------------------------------------------------------");
	printArray(process_queue,10);
	printf("\n------------------------------------------------------------------------------------");
	executeProcesses(process_queue,10,1);
	printf("\n------------------------------------------------------------------------------------");
	executeProcesses(process_queue,10,2);
        printf("\n------------------------------------------------------------------------------------");

  }

  Process q_thread[10];
  initProcesses(q_thread,10);
  printf("\n------------------------------------------------------------------------------------");
  printf("\nThread 1 and Thread 2:\n");

  pthread_t thread1,thread2;
  pthread_create(&thread1,NULL,thread1_function,q_thread);
   
  pthread_join(thread1,NULL);//waiting for thread1 to finish

  pthread_create(&thread2,NULL,thread2_function,q_thread);

  pthread_join(thread2,NULL);//waiting for thread2 to finish

  return 0;
}


