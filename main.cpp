#include "Streaming.h"

int main(){
    mll L; adr_parent parent; adr_children child;
    mllChild R;
    create_MLL(L);

    parent = alokasiParent("Action", 0);
    insertParent(L, parent);
    parent = alokasiParent("Horor", 0);
    insertParent(L, parent);
    parent = alokasiParent("Comedy", 0);
    insertParent(L, parent);
    parent = findParent(L, "baugs");

    parent = first(L);
    child = alokasiChildren("FnF_6", 9, "John");
    insertChildOfParent(L, parent, child);
    child = alokasiChildren("FnF_5", 8, "John Deo");
    insertChildOfParent(L, parent, child);

    adr_children p = findChildOfParentX(L, parent, "FnF_5");
    cout << infoChild(p).namaFilm << endl;

    showChildOfParentX(L, parent);

    parent = nextParent(parent);
    child = alokasiChildren("Insidius", 9, "Joe mama");
    insertChildOfParent(L, parent, child);
    child = alokasiChildren("Insidiuss", 9, "Joe mama");
    insertChildOfParent(L, parent, child);
    child = alokasiChildren("Insidiusss", 9, "Joe mama");
    insertChildOfParent(L, parent, child);

    showChildOfParentX(L, parent);

    cout << "===============Sesi Relasi==============" << endl;

    create_MLLChildren(R);
    insertChild(R, alokasiChildren("Kocaks", 8, "meja"));
    insertChild(R, alokasiChildren("kocak", 9, "Kursi"));
    insertChild(R, alokasiChildren("memnkocak", 10, "Kursis"));

    parent = nextParent(parent);
    cout << "insert" << endl;
    makeRelationOfParentX(L, R, parent);
    showChildOfParentX(L, parent);
    cout << "delete" << endl;
    deleteRelationChildAndParent(L, R, parent);
    showChildOfParentX(L, parent);

    return 0;
}
