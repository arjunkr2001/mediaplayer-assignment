#include <stdio.h>
#include "player.h"
void createPlaylist(struct Playlist* pl){
    pl->totalTracks = 3;
    pl->curTrackIdx = 0;
    setId(&pl->t[0],1);
    setName(&pl->t[0],"Track1");
    setDur(&pl->t[0],10);

    setId(&pl->t[1],2);
    setName(&pl->t[1],"Track2");
    setDur(&pl->t[1],30);

    setId(&pl->t[2],3);
    setName(&pl->t[2],"Track3");
    setDur(&pl->t[2],60);
}
void play(struct Playlist* pl){
    printf("Now playing: %s\n",getName(&pl->t[pl->curTrackIdx]));
}
void pausee(struct Playlist* pl){
    printf("%s Paused!\n",getName(&pl->t[pl->curTrackIdx]));
}
void next(struct Playlist* pl, int shuf){
    pl->curTrackIdx = (pl->curTrackIdx+1)%pl->totalTracks;
    printf("Current Song: %s\n",getName(&pl->t[pl->curTrackIdx]));
    //play(pl);
}
void prev(struct Playlist* pl, int shuf){
    if(pl->curTrackIdx==0) pl->curTrackIdx=pl->totalTracks;
    pl->curTrackIdx = (pl->curTrackIdx-1)%pl->totalTracks;
    printf("Current Song: %s\n",getName(&pl->t[pl->curTrackIdx]));
}

void showCurrentSong(struct Playlist* pl){
    printf("Current Song: %s\n",getName(&pl->t[pl->curTrackIdx]));
}