#ifndef TRACK_H
#define TRACK_H
struct Track{
    int id;
    char name[100];
    int dur;
};
void setId(struct Track* t,int id);
void setName(struct Track* t,const char *name);
void setDur(struct Track* t,int dur);
int getId(struct Track* t);
const char* getName(struct Track* t);
int getDur(struct Track* t);
#endif