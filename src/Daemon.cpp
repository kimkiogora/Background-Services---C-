#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<pthread.h>

/*****************************
 Include the dependencies
*****************************/
#include "Logger.h"
#include "Config.h"
#include "Daemon.h"
/****************************/

#define DAEMON_WAIT 1
#define BUFFER_SIZE 80
#define IN_RUNNING_STATE 1

using namespace std;

void sleep(int seconds);

/**
 * Wait a limited time.
*/
void sleep( int nbr_seconds ) {
	clock_t goal;
	goal = ( nbr_seconds * CLOCKS_PER_SEC ) + clock();
	while( goal > clock() )
	{
		; /* loop */
	}
}

/**
 * Entry point for thread.
*/
void *Start(void *threadid) {
	Daemon *d = new Daemon;
	d->setDebugOn(1);
	
	while(IN_RUNNING_STATE) {
		//Check & resend failed ACKs
		//fetch & process payments
		d->fetchAndProcessRequests();
		sleep(DAEMON_WAIT);		
	}	
	pthread_exit(NULL);
}

/**
 * Entry point for application
*/
int main() {
	pthread_t threads[1];
	int rc;
	for(int i=0;i<1;i++) {
		rc = pthread_create(&threads[i],NULL,Start,(void *)i);
		if( rc ) {
			cout<<"Unable to start master thread"<<endl;
			exit(-1);
		}
	}
	pthread_exit(NULL);
}
