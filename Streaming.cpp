#include "Streaming.h"

void create_MLL(mll &L){
    first(L) = NULL;
    last(L) = NULL;
}
adr_parent alokasiParent(string genre, int total){
    parent temp;
    adr_parent p = new elm_parent;

    temp.genre = genre;
    temp.total = total;
    infoParent(p) = temp;
    nextParent(p) = NULL;
    nextChild(p) = NULL;

    return p;
}
adr_children alokasiChildren(string namaFilm, int rating, string sutradara){
    children temp;
    adr_children p = new elm_children;

    temp.namaFilm = namaFilm;
    temp.rating = rating;
    temp.sutradara = sutradara;
    infoChild(p) = temp;
    nextChild(p) = NULL;

    return p;
}
void insertParent(mll &L, adr_parent p){
    //insertLast
    if (first(L) == NULL){
        first(L) = p;
        last(L) = p;
        nextParent(p) = p;
    }
    else{
        nextParent(last(L)) = p;
        nextParent(p) = first(L);
        last(L) = p;
    }
}
void deleteParent(mll &L, adr_parent &p){
    adr_parent jalan;
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
    }
    else if (first(L) == last(L)){
        p = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }
    else{
        p = last(L);
        jalan = first(L);
        while (nextParent(jalan) != last(L)){
            jalan = nextParent(jalan);
        }
        nextParent(jalan) = first(L);
        nextParent(p) = NULL;
        last(L) = jalan;
    }
}
void showParent(mll L){
    adr_parent p;
    if (first(L) == NULL){
        cout << "List kosong" << endl;
    }
    else{
        p = first(L);
        while (nextParent(p) != first(L)){
            cout << "genre: " << infoParent(p).genre << endl;
            cout << "Jumlah Film: " << infoParent(p).total << endl;
            cout << endl;
            p = nextParent(p);
        }
        cout << "genre: " << infoParent(p).genre << endl;
        cout << "Jumlah Film: " << infoParent(p).total << endl;
        cout << endl;
    }
}
adr_parent findParent(mll L, string namaGenre){
    adr_parent p = first(L);
    while (nextParent(p) != first(L)){
        if (infoParent(p).genre == namaGenre){
            return p;
        }
        p = nextParent(p);
    }
    if (infoParent(p).genre == namaGenre){
        return p;
    }
    else{
        cout << "Tidak ditemukan" << endl;
        return NULL;
    }
}
void insertLastChild(mll &L, adr_parent p, adr_children q){
    adr_children point;
    point = nextChild(p);
    if(point==NULL){
//        point=q;
            nextChild(p) = q;
    }else{
        while(nextChild(point)!=NULL){
            point = nextChild(point);
        }
        nextChild(point) = q;
    }
}
void insertChildOfParent(mll &L, adr_parent p, adr_children q){
    adr_parent point;
    bool ada;
    ada = false;
    point = first(L);
    if(first(L)==NULL){
        cout << "List kosong";
    }else{
        while(point!=nextParent(point)){
                if(point==p){
                    insertLastChild(L, point, q);
                    ada = true;
                    break;
                }
                point = nextParent(point);
        }
        if(ada==false){
            cout << "Tidak ada parent di dalam list";
        }
    }
}

void deleteChildOfParent(mll &L, adr_parent p, adr_children &q){
    if(nextChild(p)==NULL){
        cout << "Tidak ada data";
    }else{
        adr_children jalan;
        jalan = nextChild(p);
        while(nextChild(jalan)!=NULL){
            jalan = nextChild(jalan);
        }
        q = nextChild(jalan);
        nextChild(jalan) = NULL;
    }
}

void showChildOfParentX(mll &L, adr_parent p){
    adr_children point;
    point = nextChild(p);
    if(point==NULL){
        cout << "Tidak ada child";
    }else{
        while(point!=NULL){
            cout << infoChild(point).namaFilm << " " << infoChild(point).rating << " " << infoChild(point).sutradara << endl;
            point = nextChild(point);
        }
    }
}
adr_children findChildOfParentX(mll &L, adr_parent p, string namaFilm){
    adr_children chil;
    chil = nextChild(first(L));
    if(first(L)==NULL){
        cout << "List kosong";
    }else{
//        while(point!=nextParent(point)){
        chil = nextChild(p);
        while(chil!=NULL){
            if(infoChild(chil).namaFilm==namaFilm){
                return chil;
            }
            chil = nextChild(chil);
        }
    }
    return NULL;
}

void create_MLLChildren(mllChild &L){
    first(L) = NULL;
    last(L) = NULL;
}
//void insertChild(mllChild &L, adr_children p){
//    if(first(L) == NULL){
//        first(L) = p;
//    }
//    else{
//
//    }
//}
