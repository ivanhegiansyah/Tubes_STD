#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

typedef string infotype_child;
typedef struct elmAnggota *adr_anggota;

struct elmAnggota{
    infotype_child info;
    adr_anggota next, prev;
};

struct ListAnggota{
    adr_anggota first;
};

/// create list dan alokasi
void createListAnggota(ListAnggota &L);
adr_anggota alokasiAnggota(infotype_child X);

///find
adr_anggota findElmAnggota(ListAnggota L, infotype_child X);

///show
void showAnggota(ListAnggota L);

///insert
void insertFirstAnggota(ListAnggota &L, adr_anggota P);
void insertLastAnggota(ListAnggota &L, adr_anggota P);
void insertAfterAnggota(adr_anggota &Prec, adr_anggota P);

///delete
void deleteFirstLombaAnggota(ListAnggota &L, adr_anggota &P);
void deleteLastAnggota(ListAnggota &L, adr_anggota &P);
void deleteAfterAnggota(adr_anggota Prec, adr_anggota &P);
void deleteAnggota(ListAnggota &L, infotype_child data, adr_anggota &P);

///menu
 void menu_insertAnggota(ListAnggota &O);


#endif // CHILD_H_INCLUDED
