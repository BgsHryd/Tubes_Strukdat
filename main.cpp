#include "Streaming.h"

int main(){
    // kotak 1
    mll L;
    create_MLL(L);
    adr_parent par;
    par = alokasiParent("Action", 0);
    insertParent(L, par);
    adr_children chil;
    chil = alokasiChildren("Spider-Man: No Way Home", 8.0, "Jon Watts" );
    insertLastChild(L, par, chil);
    mllChild C;
    create_MLLChildren(C);
    chil = alokasiChildren("Venom: Let There Be Carnage", 5.0, "Andy Serkis" );
    insertChild(C, chil);
    chil = alokasiChildren("Shang-Chi and the Legend of the Ten Rings", 7.5, "Destin Daniel Cretton" );
    insertChild(C, chil);
    chil = alokasiChildren("Eternals", 6.8, "Kevin Feige" );
    insertChild(C, chil);
    makeRelationOfParentX(L, C, par);
    chil = alokasiChildren("Avengers: Endgame", 8.8, "Jon Watts" );
    insertLastChild(L, par, chil);
    // kotak 2
    par = alokasiParent("Animasi", 0);
    insertParent(L, par);
    // kotak 3
    par = alokasiParent("Musikal/Drama", 0);
    insertParent(L, par);
    chil = alokasiChildren("The Greatest Showman", 8.0, "Jon Watts" );
    insertLastChild(L, par, chil);
    chil = alokasiChildren("Bohemian Rhapsody", 7.9, "Bryan Singer and Dexter Fletcher" );
    insertLastChild(L, par, chil);
    showAll(L);
    cout << endl;
    averageRatingOfAllGenre(L);
    return 0;
}
