#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
#include "child.h"

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child


typedef string infotype_parent;

typedef struct elmLomba *adr_lomba;

struct elmLomba{
    infotype_parent info;
    adr_lomba next;
    ListAnggota child;
};

struct ListLomba{
    adr_lomba first;
};

/// create list dan alokasi
void createListLomba(ListLomba &L);
adr_lomba alokasiLomba(infotype_parent X);

///find
adr_lomba findElmLomba(ListLomba L, infotype_parent X);
adr_anggota findElmAnggota2(adr_lomba P, infotype_child X);

///insert
void insertLastLomba(ListLomba &L, adr_lomba P);

///delete
void deleteFirstLombaLomba(ListLomba &L, adr_lomba &P);
void deleteLastLomba(ListLomba &L, adr_lomba &P);
void deleteAfterLomba(adr_lomba Prec, adr_lomba &P);
void deleteParent(ListLomba &L, adr_lomba Q, adr_lomba &P);
void deleteLomba(ListLomba &L, infotype_parent data, adr_lomba &P);
void DeleteAllAnggota(ListLomba L, ListAnggota &O, infotype_child X);

///conection
void connect(adr_lomba &P, infotype_child Y);

///show
void showLomba(ListLomba L);
void showAllData2(ListLomba L, ListAnggota Q);
void showAnggotaTertentu(ListLomba L, ListAnggota O);
void showLombaTertentu(ListLomba L);

///max and min
int hitungAnggota(ListLomba L, adr_lomba P);
void lombaTerbanyak(ListLomba L);
int hitungLomba(ListLomba L, adr_anggota P);
void minimalAnggota(ListLomba LP, ListAnggota LC);

///menu
void menu_utama (ListLomba &L , ListAnggota &Q);
void menu_insertLomba(ListLomba &L);
void menu_insertAnggota(ListAnggota &O);
void menu_connection(ListLomba L, ListAnggota O);
void menu_deleteAnggota(ListLomba &L, ListAnggota &O);
void menu_deleteLomba(ListLomba &L);

void cls();
#endif // PARENT_H_INCLUDED
