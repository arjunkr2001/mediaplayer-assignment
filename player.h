#ifndef PLAYER_H
#define PLAYER_H
#include "track.h"
struct Playlist{
    struct Track t[50];
    int curTrackIdx;
    int totalTracks;
};
void createPlaylist(struct Playlist* pl);
void play(struct Playlist* pl);
void pausee(struct Playlist* pl);
void next(struct Playlist* pl, int shuf);
void prev(struct Playlist* pl, int shuf);

void showCurrentSong(struct Playlist* pl);
#endif
