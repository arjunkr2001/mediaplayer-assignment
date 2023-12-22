#include "track.h"
#include <string.h>
void setId(struct Track* t,int id){
    t->id = id;
}
void setName(struct Track* t,const char *name){
    strncpy(t->name,name,sizeof(name));
}
void setDur(struct Track* t,int dur){
    t->dur=dur;
}
int getId(struct Track* t){
    return t->id;
}
const char* getName(struct Track* t){
    return t->name;
}
int getDur(struct Track* t){
    return t->dur;
}