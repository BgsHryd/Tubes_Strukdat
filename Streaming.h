#ifndef STREAMING_H_INCLUDED
#define STREAMING_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last

#define infoParent(P) P->infoParent
#define nextParent(P) P->nextParent

#define infoChild(P) P->infoChild
#define nextChild(P) P->nextChild
#define prevChild(P) P->prevChild

typedef struct elm_parent *adr_parent;
typedef struct elm_children *adr_children;
struct parent{
    string genre;
    int total;
};
struct children{
    string namaFilm;
    float rating;
    string sutradara;
};
struct elm_parent{
    parent infoParent;
    adr_parent nextParent;
    adr_children nextChild;
};
struct elm_children {
    children infoChild;
    adr_children nextChild;
    adr_children prevChild;
};
struct mll{
    adr_parent first;
    adr_parent last;
};

struct mllChild{
    adr_children first;
    adr_children last;
};

void create_MLL(mll &L);
adr_parent alokasiParent(string genre, int total);
adr_children alokasiChildren(string namaFilm, float rating, string sutradara);
void insertParent(mll &L, adr_parent p);
void deleteParent(mll &L, adr_parent &p);
void showParent(mll L);
adr_parent findParent(mll L, string namaGenre);
void insertLastChild(mll &L, adr_parent &p, adr_children q);
void deleteChildOfParent(mll &L, adr_parent p, adr_children &q);
void showChildOfParentX(mll &L, adr_parent p);
adr_children findChildOfParentX(mll &L, adr_parent p, string namFilm);

void create_MLLChildren(mllChild &L);
void insertChild(mllChild &L, adr_children p);
void deleteChild(mllChild &L, adr_children &p);
void makeRelationOfParentX(mll &L, mllChild rel_child, adr_parent &p);
void deleteRelationChildAndParent(mll &p, mllChild &c, adr_parent par);

void showAll(mll L);
void averageRatingOfAllGenre(mll L);
#endif // STREAMING_H_INCLUDED
