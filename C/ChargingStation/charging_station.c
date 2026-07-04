//Alphan Algül 2584639

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

//Structures for vehicle and station
struct Station;

struct Vehicle {
    int id;
    char type;
    int charge_time;
    struct Station *station;
};

struct Station {
    struct Vehicle queue[5];

    int vehicle_number;
    int slots;
    int total_vehicle;
    int finished_vehicle;

    int busy;
    int has_vehicle;
    struct Vehicle vehicle;

    sem_t semaphore;
    pthread_mutex_t mutex;
};


void print_queue(struct Station *station)
{
    printf("\nQueue:");

    for (int i = 0; i < station->slots; i++)
    {
        if (i < station->vehicle_number){
            printf(" %c%d",station->queue[i].type,station->queue[i].id);
        }
        else{
            printf(" Empty");
        }
    }
}


void insert_vehicle(struct Station *station, struct Vehicle vehicle)
{

    //insert all in the back if normal stop
    station->queue[station->vehicle_number] = vehicle;
    station->vehicle_number++;

    //if emergency shift left until correct place
    int index;
    if (vehicle.type == 'E') {
        index = station->vehicle_number - 1;

        while (index > 0 && station->queue[index - 1].type == 'N') {
            station->queue[index] = station->queue[index - 1];
            station->queue[index - 1] = vehicle;
            index--;
        }
    }
}


void *vehicle_thread(void *arg)
{
    struct Vehicle *vehicle = arg;
    struct Station *station = vehicle->station;

    sleep(rand() % 10 + 1);//generating random vehicle arrivals
    pthread_mutex_lock(&station->mutex);

    printf("\n%c%d arrived with charging time %d\n",vehicle->type,vehicle->id,vehicle->charge_time);

    int signal_check = 1;

    //if station free, charge, if not but queue has free slot insert to queue, if both full leave
    if (station->busy==0) {
        station->busy = 1;
        station->has_vehicle = 1;
        station->vehicle = *vehicle;
        printf("\n%c%d starts charging\n",vehicle->type,vehicle->id);
    }

    else if (station->vehicle_number < station->slots) {
        insert_vehicle(station, *vehicle);
        printf("\n%c%d waits in the queue\n",vehicle->type,vehicle->id);
        print_queue(station);
    }

    else {
        station->finished_vehicle++;
        printf("\n%c%d leaves because queue is full\n",vehicle->type,vehicle->id);

        if (station->finished_vehicle == station->total_vehicle) {
            signal_check = 1;
        }
        else {
            signal_check = 0;
        }
    }

    if (signal_check == 1) {//wake up station
        sem_post(&station->semaphore);
    }

    pthread_mutex_unlock(&station->mutex);
    return NULL;
}


void *station_thread(void *arg)
{
    struct Station *station = arg;

    //while there are uncharged vehicles
    for (int i = 0; station->finished_vehicle < station->total_vehicle; ) {

        //wait until wake up
        sem_wait(&station->semaphore);
        pthread_mutex_lock(&station->mutex);

        struct Vehicle vehicle;
        int vehicle_check = 0;

        //if station has vehicle, charge it else wait for signal
        if (station->has_vehicle == 1) {
            vehicle = station->vehicle;
            station->has_vehicle = 0;
            vehicle_check = 1;
        }

        else if (station->vehicle_number > 0) {
            vehicle = station->queue[0];
            vehicle_check = 1;

            int j = 0;
            while (j < station->vehicle_number - 1) {
                station->queue[j] = station->queue[j + 1];
                j++;
            }
            station->vehicle_number--;
        }

        if (vehicle_check== 0) {
            pthread_mutex_unlock(&station->mutex);
            continue;
        }

        printf("\nCharging station: Busy\n");
        print_queue(station);

        pthread_mutex_unlock(&station->mutex);
        sleep(vehicle.charge_time);//wait for charge time

        pthread_mutex_lock(&station->mutex);

        printf("\nVehicle %c%d finished charging.\n", vehicle.type, vehicle.id);

        station->finished_vehicle++;

        if (station->vehicle_number == 0 && station->has_vehicle == 0) {
            station->busy = 0;
        }

        pthread_mutex_unlock(&station->mutex);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    //thread for station
    pthread_t stationThread;
    struct Station station;

    station.vehicle_number = 0;
    station.finished_vehicle = 0;
    station.busy = 0;
    station.has_vehicle = 0;
    station.slots = rand() % 5 + 1;
    station.total_vehicle = rand() % 9 + 2;

    printf("Number of waiting slots: %d\n", station.slots);
    printf("Number of vehicles: %d\n", station.total_vehicle);

    sem_init(&station.semaphore, 0, 0);
    pthread_mutex_init(&station.mutex, NULL);
    pthread_create(&stationThread, NULL, station_thread, &station);



    //thread for each vehicle
    pthread_t vehicleThreads[10];
    struct Vehicle vehicles[10];
    for (int i = 0; i < station.total_vehicle; i++) {
        vehicles[i].id = i + 1;

        if (rand() % 2 == 0) {
            vehicles[i].type = 'N';
        } else {
            vehicles[i].type = 'E';
        }

        vehicles[i].charge_time = rand() % 200 + 1;
        vehicles[i].station = &station;

        pthread_create(&vehicleThreads[i], NULL, vehicle_thread, &vehicles[i]);
    }

    for (int i = 0; i < station.total_vehicle; i++) {
        pthread_join(vehicleThreads[i], NULL);
    }

    pthread_join(stationThread, NULL);

}