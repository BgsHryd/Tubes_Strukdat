#include "Streaming.h"

void create_MLL(mll &L){
    first(L) = NULL;
    last(L) = NULL;
}
adr_parent alokasiParent(string genre){
    parent temp;
    adr_parent p = new elm_parent;

    temp.genre = genre;
    temp.total = 0;
    infoParent(p) = temp;
    nextParent(p) = NULL;
    nextChild(p) = NULL;

    return p;
}
adr_children alokasiChildren(string namaFilm, float rating, string sutradara){
    children temp;
    adr_children p = new elm_children;

    temp.namaFilm = namaFilm;
    temp.rating = rating;
    temp.sutradara = sutradara;
    infoChild(p) = temp;
    nextChild(p) = NULL;
    prevChild(p) = NULL;

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
void insertLastChild(mll &L, adr_parent &p, adr_children q){
    adr_children point;
    point = nextChild(p);
    if(point==NULL){
        nextChild(p) = q;
        infoParent(p).total++;
    }else{
        while(nextChild(point)!=NULL){
            point = nextChild(point);
        }
        nextChild(point) = q;
        prevChild(q) = point;
        infoParent(p).total++;
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
        prevChild(q)=NULL;
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
void insertChild(mllChild &L, adr_children p){
    if(first(L) == NULL){
        first(L) = p;
        last(L) = p;
    }
    else{
        nextChild(last(L)) = p;
        prevChild(p) = last(L);
        last(L) = p;
    }
}
void deleteChild(mllChild &L, adr_children &p){
    if (first(L) == NULL && last(L) == NULL){
        cout << "List Kosong" << endl;
    }
    else if (first(L) == last(L)){
        p = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }
    else{
        p = last(L);
        last(L) = prevChild(p);
        prevChild(p) = NULL;
        nextChild(prevChild(p)) = NULL;
    }
}
void makeRelationOfParentX(mll &L, mllChild rel_child, adr_parent &p){
    int n = 0;
    adr_children chil;
    chil = first(rel_child);
    while (chil != NULL){
        n++;
        chil = nextChild(chil);
    }
    if (nextChild(p) == NULL){
        nextChild(p) = first(rel_child);
        infoParent(p).total += n;
    }
    else{
        adr_children jalan;
        jalan = nextChild(p);
        while(nextChild(jalan) != NULL){
            jalan = nextChild(jalan);
        }
        nextChild(jalan) = first(rel_child);
        prevChild(first(rel_child)) = jalan;
        infoParent(p).total += n;
    }
}
void deleteRelationChildAndParent(mll &p, mllChild &c, adr_parent par){
    if(nextChild(par)==NULL){
        cout << "tidak ada child" << endl;
    }else{
        create_MLLChildren(c);
        adr_children chil;
        chil = nextChild(par);
        while (chil != NULL){
            insertChild(c, chil);
            chil = nextChild(chil);
        }
        nextChild(par) = NULL;
        infoParent(par).total = 0;
    }
}
void showAll(mll L){
    if(first(L)==NULL){
        cout << "List kosong" << endl;
    }else{
        adr_parent p;
        adr_children q;
        p = first(L);
        while(nextParent(p)!=first(L)){
            cout << infoParent(p).genre << " | " << infoParent(p).total << endl;
            q = nextChild(p);
            while(q!=NULL){
                cout << infoChild(q).namaFilm << " " << infoChild(q).rating << " " << infoChild(q).sutradara << endl;
                q = nextChild(q);
            }
            cout << endl;
            p = nextParent(p);
        }
        cout << infoParent(p).genre << " | " << infoParent(p).total << endl;
        q = nextChild(p);
        while(q!=NULL){
            cout << infoChild(q).namaFilm << " " << infoChild(q).rating << " " << infoChild(q).sutradara << endl;
            q = nextChild(q);
        }
        cout << endl;
        p = nextParent(p);
    }
}
void averageRatingOfAllGenre(mll L){
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
    }
    else{
        adr_parent jalan; adr_children chil;
        float total;
        jalan = first(L);
        while(nextParent(jalan) != first(L)){
            chil = nextChild(jalan);
            total = 0;
            while(chil != NULL){
                total = total + infoChild(chil).rating;
                chil = nextChild(chil);
            }
            cout << "Genre: " << infoParent(jalan).genre << "  Rating: " << total/infoParent(jalan).total << endl;
            jalan = nextParent(jalan);
        }
        total = 0;
        chil = nextChild(jalan);
        while(chil != NULL){
            total += infoChild(chil).rating;
            chil = nextChild(chil);
        }
        cout << "Genre: " << infoParent(jalan).genre << "  Rating: " << total/infoParent(jalan).total << endl;
    }
}
