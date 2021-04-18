#include "child.h"

void createListAnggota(ListAnggota &L){
    first(L) = NULL;
}

adr_anggota alokasiAnggota(infotype_child X){
    adr_anggota P = new elmAnggota;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertLastAnggota(ListAnggota &L, adr_anggota P){
    if(first(L) == NULL){
        first(L) = P;
    } else{
        adr_anggota Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
        prev(P) = Q;
    }
}

void deleteFirstLombaAnggota(ListAnggota &L, adr_anggota &P){
    P = first(L);
    if(next(first(L)) == NULL){
        first(L) = NULL;
    } else{
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}

void deleteLastAnggota(ListAnggota &L, adr_anggota &P){
    if(next(first(L)) == NULL){
        P = first(L);
        next(P) = NULL;
    } else {
        adr_anggota Q = first(L);
        while(next(next(Q)) != NULL){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
        prev(P) = NULL;
    }
}

void deleteAfterAnggota(adr_anggota Prec, adr_anggota &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(Prec)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}

void deleteAnggota(ListAnggota &L, infotype_child data, adr_anggota &P){
    adr_anggota F = findElmAnggota(L, data);
    if(first(L) != NULL){
        if (F != NULL){
            if (F == first(L)){
                deleteFirstLombaAnggota(L, P);
            } else if (next(F) == NULL){
                deleteLastAnggota(L, P);
            } else{
                adr_anggota Prec = first(L);
                while (next(Prec) != F){
                    Prec = next(Prec);
                }
                deleteAfterAnggota(Prec, P);
            }
            cout<<"Peserta telah dihapus! \n";
        }
    } else {
        cout<<"belum ada data"<<endl;
    }
}

void showAnggota(ListAnggota L) {
    adr_anggota P = first(L);
    while(P != NULL) {
        cout << info(P) << ", ";
        P = next(P);
    }
    cout << endl;
}
