#ifndef STREAMING_H_INCLUDED
#define STREAMING_H_INCLUDED
#define first(L) L.first
#define last(L) L.last
typedef struct elm_parent *adr_parent;
typedef struct elm_children *adr_children;
struct parent{
    string genre;
    int total;
};
struct elm_parent{
    parent info;
    adr_parent next;
    adr_children nextChild;
};
struct elm_children {
    string namaFilm;
    int rating;
    string sutradara;
    adr_children Next;
};
struct mll {
    adr_parent first;
    adr_parent last;
};




#endif // STREAMING_H_INCLUDED
