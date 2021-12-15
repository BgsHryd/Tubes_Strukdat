#ifndef STREAMING_H_INCLUDED
#define STREAMING_H_INCLUDED

#define first(L) L.first
#define last(L) L.last

#define infoParent(P) P -> infoParent
#define nextParent(P) P -> NextParent

#define infoChild(P) P -> infoChild
#define nextChild(P) P-> NextChild

typedef struct elm_parent *adr_parent;
typedef struct elm_children *adr_children;
struct parent{
    string genre;
    int total;
};
struct children{
    string namFilm;
    int rating;
    string sutradara;
};
struct elm_parent{
    parent infoParent;
    adr_parent nextParent;
    adr_children nextChild;
};
struct elm_children {
    children infoChildr;
    adr_children NextChild;
};
struct mll {
    adr_parent first;
    adr_parent last;
};




#endif // STREAMING_H_INCLUDED
