#include "Streaming.h"

int main(){
    // kotak 1
    mll L;
    create_MLL(L);
    adr_parent par;
    par = alokasiParent("Action");
    insertParent(L, par);
    adr_children chil;
    chil = alokasiChildren("Spider-Man: No Way Home", 8.0, "Jon Watts" );
    insertLastChild(L, par, chil);
    chil = alokasiChildren("Venom: Let There Be Carnage", 5.0, "Andy Serkis" );
    insertLastChild(L, par,chil);
    chil = alokasiChildren("Shang-Chi and the Legend of the Ten Rings", 7.5, "Destin Daniel Cretton" );
    insertLastChild(L, par, chil);
    chil = alokasiChildren("Eternals", 6.8, "Kevin Feige" );
    insertLastChild(L, par, chil);

    chil = alokasiChildren("Avengers: Endgame", 8.8, "Jon Watts" );
    insertLastChild(L, par, chil);
    // kotak 2
    par = alokasiParent("Animasi");
    insertParent(L, par);
    chil = alokasiChildren("Encanto", 7.3, "Byron Howard" );
    insertLastChild(L, par, chil);
    chil = alokasiChildren("Frozen 2", 7.5, "Jennifer Lee" );
    insertLastChild(L, par, chil);
    chil = alokasiChildren("Raya and the Last Dragon", 7.3, "Carlos Lopez Estrada" );
    insertLastChild(L, par, chil);

    // kotak 3
    par = alokasiParent("Musikal/Drama");
    insertParent(L, par);
    chil = alokasiChildren("The Greatest Showman", 8.0, "Michael Gracey" );
    insertLastChild(L, par, chil);
    chil = alokasiChildren("Bohemian Rhapsody", 7.9, "Bryan Singer and Dexter Fletcher" );
    insertLastChild(L, par, chil);
    showAll(L);
    cout << endl;
    averageRatingOfAllGenre(L);

    // study case deleteRelation
    mllChild c;
    create_MLLChildren(c);
    deleteRelationChildAndParent(L, c, par);
    makeRelationOfParentX(L, c, first(L));
    cout << "\n===================DeleteRelationChildAndParent====================\n" << endl;
    showAll(L);
    averageRatingOfAllGenre(L);
    cout << endl;
    adr_children cari;
    cari = findChildOfParentX(L, first(L), "Spider-Man: No Way Home");
    cout << infoChild(cari).namaFilm;

    adr_children anu = findChildOfParentX(L, first(L), "Spider-Man: No Way Home");
    return 0;
}
