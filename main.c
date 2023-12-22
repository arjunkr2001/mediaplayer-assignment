#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "player.h"

struct Playlist pl;
char song[100]="";
int c=0;
int eth=0,etm=0,ets=0;
int repON=0;
char *repStr = "OFF";
int sp = 2;
int skp = 0;
int shuf = 0;

void *displayClock(void *arg){
	while(1){
		system("clear");
        if(c==0){ 
            showCurrentSong(&pl);
            ets=0; 
            //play(&pl);  
            c=1; 
        }
        if(c==10) break;
        if(c==1){
            play(&pl);
            //c=0;
        }
        else if(c==2){
            pausee(&pl);
            ets--;
        }
        else if(c==3){
            next(&pl,shuf);
            c=0;
            ets=0;
            etm=0;
            eth=0;
        }
        else if(c==4){
            prev(&pl,shuf);
            c=0;
            ets=0;
            etm=0;
            eth=0;
        }
        else if(c==9){
            repON = repON?0:1;
            repStr=repON?"ON":"OFF";
            c=0;
        }
        else if(c==5){
            sp=1;
        }
        else if(c==6){
            sp=2;
        }
        else if(c==7){
            sp=3;
        }
        printf("%02d:%02d:%02d \n\nMenu:\n\t1.Play\n\t2.Pause\n\t3.Next\n\t4.Prev\n\t5. 0.5x\n\t6. 1x\n\t7. 2x\n\t8.Shuffle\n\t9.Repeat:%s\n\t10.Exit\nEnter: > ",eth,etm,ets,repStr);
        if(sp==2) ets++;
        else if(sp==1) {
            if(!skp){
                ets++;
                skp=1;
            }
            else skp=0;
        }
        else if(sp==3){
            ets+=2;
        }
        if(ets>=60){
            ets=0;
            etm++;
        }
        if(etm>=60){
            etm=0;
            eth++;
        }
		fflush(stdout);
		sleep(1);
	}
	return NULL;
}

void *readInput(void *arg){
	while(1){
		system("clear");
        if(c==10) break;
        scanf("%d",&c);
		fflush(stdout);
	}
	return NULL;
}

int main(){
    
    createPlaylist(&pl);

	pthread_t clkt,inpt;
	pthread_create(&clkt,NULL,displayClock,NULL);
	pthread_create(&inpt,NULL,readInput,NULL);
	pthread_join(clkt,NULL);
	pthread_join(inpt,NULL);
	return 0;
}