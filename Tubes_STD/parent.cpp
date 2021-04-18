#include "parent.h"

string lowercase(string str) {
    (transform(str.begin(), str.end(), str.begin(), ::tolower));
    return str;
}
void createListLomba(ListLomba &L){
    first(L) = NULL;
}

adr_lomba alokasiLomba(infotype_parent X){
    adr_lomba P = new elmLomba;
    info(P) = X;
    next(P) = NULL;
    createListAnggota(child(P));
    return P;
}

adr_lomba findElmLomba(ListLomba L, infotype_parent X){
    adr_lomba P = first(L);
    if(P != NULL){
        do {
            if (lowercase(info(P)) == lowercase(X)){
                return P;
            }
            P = next(P);
        } while (P != first(L));
     }
    return NULL;
}

adr_anggota findElmAnggota(ListAnggota L, infotype_child X){
    adr_anggota P = first(L);
    if(P != NULL){
        do {
            if (lowercase(info(P)) == lowercase(X)){
                return P;
            }
            P = next(P);
        } while (P != NULL);
    }
    return NULL;
}

adr_anggota findElmAnggota2(adr_lomba P, infotype_child X) {
    adr_anggota Q = first(child(P));

    while(Q != NULL) {
        if(lowercase(info(Q)) == lowercase(X)) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void insertLastLomba(ListLomba &L, adr_lomba P){
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = first(L);
    } else {
        adr_lomba Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
    }
}

void deleteFirstLomba(ListLomba &L, adr_lomba &P){
    if(next(first(L)) == first(L)) {
        P = first(L);
        next(P) = NULL;
        first(L) = NULL;
    } else {
        P = first(L);
        adr_lomba Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        first(L) = next(P);
        next(Q) = first(L);
        next(P) = NULL;
    }
}

void deleteLastLomba(ListLomba &L, adr_lomba &P){
    if (next(first(L)) == first(L)){
        P = first(L);
        first(L) = NULL;
    } else{
        adr_lomba Q = first(L);
        while(next(next(Q)) != first(L)){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = first(L);
        next(P) = NULL;
    }
}

void deleteAfterLomba(adr_lomba Prec, adr_lomba &P){
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}

void deleteParent(ListLomba &L, adr_lomba Q, adr_lomba &P) {
    if(first(L) == NULL) {
        cout << "data perlombaan kosong" << endl;
    } else if(next(first(L)) == first(L)) {
        deleteFirstLomba(L, P);
    } else {
        if(Q == first(L)) {
            deleteFirstLomba(L, P);
        } else if(next(Q) == first(L)) {
            deleteLastLomba(L, P);
        } else {
            adr_lomba Prec = first(L);
            while(next(Prec) != Q) {
                Prec = next(Prec);
            }
            deleteAfterLomba(Prec, P);
        }
    }
}

void deleteLomba(ListLomba &L, infotype_parent data, adr_lomba &P){
    adr_lomba F = findElmLomba(L, data);
    if(first(L) != NULL){
        if (F != NULL){
            deleteParent(L, F, P);
            cout<<"Perlombaan telah dihapus! \n";
        }

    } else {
        cout<<"belum ada data"<<endl;
    }
}

void showLomba(ListLomba L){
    if(first(L) == NULL){
        cout<<"parent kosong";
    } else{
        adr_lomba P = first(L);
        do{
            cout<<info(P)<<", ";
            P = next(P);
        } while (P != first(L));
        cout << endl;
    }
}

void connect(adr_lomba &P, infotype_child Y) {
    insertLastAnggota(child(P), alokasiAnggota(Y));
}

void DeleteAllAnggota(ListLomba L, ListAnggota &O, infotype_child X){
    adr_anggota Pout;
    adr_lomba P = first(L);
    if(first(L) != NULL){
        do{
            adr_anggota Q = findElmAnggota(child(P), X);
            if(Q != NULL){
                deleteAnggota(child(P), X, Pout);
            }
            P = next(P);
        } while(P != first(L));

    } else {
        cout<<"Belum ada data \n";
    }
}

void showAllData2(ListLomba L, ListAnggota Q){
    system("cls");
    adr_anggota q_first = first(Q);
    if ( (first(L) != NULL) && (first(Q) != NULL) ){
        while(q_first != NULL) {
            cout << info(q_first) << " : ";
            adr_lomba p_first = first(L);
            do {
                adr_anggota cari = findElmAnggota(child(p_first), info(q_first));
                if(cari != NULL) {
                    cout << info(p_first) << ", ";
                }
                p_first = next(p_first);
            } while(p_first != first(L));
            cout << "\n";
            q_first = next(q_first);
        }
    } else{
        cout<<"Tidak ada data \n";
    }
}

void showAnggotaTertentu(ListLomba L, ListAnggota O) {
    system("cls");
    adr_lomba p_first = first(L);
    adr_anggota Q;
    infotype_child nama;
    showAnggota(O);
    cout<<"Masukkan nama peserta : ";
    cin.ignore();
    getline(cin,nama);
    Q = findElmAnggota(O, nama);
    if(Q != NULL){
        cout << info(Q) << " : ";
        do {
            adr_anggota cari = findElmAnggota(child(p_first), info(Q));
            if(cari != NULL) {
                cout << info(p_first) << ", ";
            }
            p_first = next(p_first);
            } while(p_first != first(L));
    } else{
        cout<<"Peserta tersebut tidak ada! \n";
    }
    cout << "\n";
}

void showLombaTertentu(ListLomba L){
    system("cls");
    adr_lomba p_first = first(L);
    adr_lomba P;
    infotype_parent lomba;
    showLomba(L);
    cout<<"Masukkan nama perlombaan : ";
    cin.ignore();
    getline(cin,lomba);
    P = findElmLomba(L, lomba);
    if(P != NULL){
        cout << info(P) <<" : ";
        do {
            if ( P != NULL){
                adr_anggota q_first = first(child(P));
                while(q_first != NULL){
                    cout<<info(q_first)<<", ";
                    q_first = next(q_first);
                }
            }
        } while (p_first != first(L));
    } else{
        cout<<"perlombaan tersebut tidak ada! \n";
    }
    cout << " \n";
}

int hitungAnggota(ListLomba L, adr_lomba P){
    int i = 0;
    if (first(child(P)) != NULL){
        adr_anggota Q = first(child(P));
        while ( Q != NULL){
            i = i +1;
            Q = next(Q);
        }
    }
    return i;
}

void lombaTerbanyak(ListLomba L){
    int temp = 0;
    int temp2 = 0;
    adr_lomba Q;
    adr_lomba P = first(L);
    if (first(L) != NULL){
        do{
            temp = hitungAnggota(L, P);
            if ( temp > temp2){
                temp2 = temp;
                Q = P;
            }
            P = next(P);
        } while ( P != first(L));
    }

    cout<<"lomba yang paling banyak diikuti adalah : "<< info(Q)<<endl;
    cout<<"jumlah peserta yang mengikuti lomba tersebut sebanyak : "<<temp2<<endl;
}

int hitungLomba(ListLomba L, adr_anggota P) {
    adr_lomba Q = first(L);
    int i = 0;
    if (Q != NULL) {
        do {
            adr_anggota cari = findElmAnggota2(Q, info(P));
            if(cari != NULL) {
                i++;
            }
            Q = next(Q);
        } while(Q != first(L));
    }
    return i;
}

void minimalAnggota(ListLomba LP, ListAnggota LC) {
    adr_anggota P = first(LC);
    int jum = hitungLomba(LP, P);
    int MIN = jum;
    adr_anggota pMIN = P;
    while(P != NULL) {
        jum = hitungLomba(LP, P);
        if(jum < MIN) {
            MIN = jum;
            pMIN = P;
        }
        P = next(P);
    }

    cout<<"Peserta yang paling sedikit mengikuti lomba adalah : " <<info(pMIN) << endl;
    cout<<"Total perlombaan yang diikuti sebanyak : "<<MIN<<endl;
}

///menu
void cls(){
    system("cls");
}

void menu_utama (ListLomba &L , ListAnggota &O){
    int pil;
    do {
        cout << "------PROGRAM KEJUARAAN DAN LOMBA------ \n";
        cout << "1.Tambah perlombaan \n";
        cout << "2.Tambah peserta \n";
        cout << "3.Tambah koneksi antara peserta dengan perlombaan \n";
        cout << "4.Hapus peserta \n";
        cout << "5.Hapus perlombaan \n";
        cout << "6.Tampilkan seluruh peserta dan kejuaraan yang diikutinya \n";
        cout << "7.Tampilkan peserta yang mengikuti perlombaan tertentu \n";
        cout << "8.Tampilkan  kejuaraan yang diikuti oleh seseorang \n";
        cout << "9.Tampilkan perlombaan yang paling banyak diminati, dan orang yang mengikuti perlombaan paling sedikit \n";
        cout << "0.Keluar \n";
        cout << "Pilihan : ";
        cin >> pil;
        switch(pil) {
            case 0 : break;
            case 1 : menu_insertLomba(L);
                     break;
            case 2 : menu_insertAnggota(O);
                     break;
            case 3 : menu_connection(L,O);
                     break;
            case 4 : menu_deleteAnggota(L, O);
                     break;
            case 5 : menu_deleteLomba(L);
                     break;
            case 6 : showAllData2(L, O);
                     break;
            case 7 : showLombaTertentu(L);
                     break;
            case 8 : showAnggotaTertentu(L, O);
                     break;
            case 9 : system("cls");
                     lombaTerbanyak(L);
                     minimalAnggota(L, O);
                     break;
            default : cout << "tidak ada pilihan tersebut \n";
                     break;
        }
        system("pause");
        system("CLS");
    }while ( (pil != 0) );
}

 void menu_insertLomba(ListLomba &L){
    system ("cls");
    infotype_parent nama;
    string coba;
    do{
        do {
            cout << "ketik tidak untuk selesai \n";
            cout << "Nama perlombaan : ";
            cin.ignore();
            getline(cin,nama);
        }while (nama == "");
       if (nama != "tidak"){
            adr_lomba cari = findElmLomba(L, nama);
            if (cari == NULL){
                adr_lomba P;
                P = alokasiLomba(nama);
                insertLastLomba(L,P);
                cout << "Perlombaan berhasil ditambahkan! \n ";
                system("pause");
                do{
                    cout << "Tambahkan perlombaan lagi? (y/t) ? ";
                    cin >> coba;
                }while ( (coba != "y") && (coba != "t" ) );
            }else{
                cout<<"perlombaan tersebut telah terdaftar! \n";
            }
        }else {
            cout << "input telah selesai \n";
            coba = "t";
        }
    }while (coba != "t");
}

 void menu_insertAnggota(ListAnggota &O){
    system ("cls");
    infotype_child nama;
    string coba;
    do{
        do {
            cout << "ketik tidak untuk selesai \n";
            cout << "Nama peserta : ";
            cin.ignore();
            getline(cin,nama);
        }while (nama == "");
       if (nama != "tidak"){
            adr_anggota cari = findElmAnggota(O, nama);
            if (cari == NULL){
                adr_anggota P;
                P = alokasiAnggota(nama);
                insertLastAnggota(O,P);
                cout << "Peserta berhasil ditambahkan! \n ";
                system("pause");
                do{
                    cout << "Tambahkan Peserta lagi? (y/t) ? ";
                    cin >> coba;
                }while ( (coba != "y") && (coba != "t" ) );
            } else {
                cout<<"Peserta tersebut telah terdaftar! \n";
            }
        }else {
            cout << "input telah selesai \n";
            coba = "t";
        }
    }while (coba != "t");
}

void menu_connection(ListLomba L, ListAnggota O){
    infotype_parent lomba;
    infotype_child anggota;
    adr_lomba P;
    adr_anggota Q;
    string coba;
    string pil;
    cls();
    if  ( (first(L) == NULL) || (first(O) == NULL) ){
        cout << "Tidak ada data \n";
    }else {
        cout<<"Perlombaan : ";
        showLomba(L);
        cout<<"Peserta: ";
        showAnggota(O);
        cout<<"1. Hubungkan peserta dengan perlombaan tertentu \n";
        cout<<"2. Hubungkan perlombaan dengan peserta tertentu \n";
        cout<<"pilihan : ";
        cin>>pil;
        if (pil == "1"){
             do{
                do {
                    cout << "ketik tidak untuk selesai \n";
                    cout << "Masukkan nama peserta : ";
                    cin.ignore();
                    getline(cin,anggota);
                }while (anggota == "");
               if (anggota != "tidak"){
                    Q = findElmAnggota(O, anggota);
                    if(Q != NULL){
                        cout<<"hubungkan ke perlombaan : ";
                        getline(cin,lomba);
                        P = findElmLomba(L, lomba);
                        if(P != NULL){
                            connect(P, info(Q));
                            cout<<"Peserta berhasil dihubungkan! \n";
                            system("pause");
                         } else{
                            cout<<"perlombaan tersebut tidak ada \n";
                        }
                    } else{
                        cout<<"Peserta tersebut tidak ada \n";
                    }
                    do{
                        cout << "Tambahkan Peserta lagi? (y/t) ? ";
                        cin >> coba;
                    }while ( (coba != "y") && (coba != "t" ) );
                }else {
                    cout << "input telah selesai \n";
                    coba = "t";
                }
            }while (coba != "t");
        } else if (pil == "2"){
            do{
                do {
                    cout << "ketik tidak untuk selesai \n";
                    cout << "Masukkan nama lomba : ";
                    cin.ignore();
                    getline(cin,lomba);
                }while (lomba == "");
               if (lomba != "tidak"){
                    P = findElmLomba(L, lomba);
                    if(P != NULL){
                        cout<<"hubungkan ke peserta : ";
                        getline(cin,anggota);
                        Q = findElmAnggota(O, anggota);
                        if(Q != NULL){
                            connect(P, anggota);
                            cout<<"Perlombaan berhasil dihubungkan! \n";
                            system("pause");
                         } else{
                            cout<<"peserta tersebut tidak ada \n";
                        }
                    } else{
                        cout<<"Perlombaan tersebut tidak ada \n";
                    }
                    do{
                        cout << "Tambahkan Peserta lagi? (y/t) ? ";
                        cin >> coba;
                    }while ( (coba != "y") && (coba != "t" ) );
                }else {
                    cout << "input telah selesai \n";
                    coba = "t";
                }
            }while (coba != "t");

        }
    }
}

void menu_deleteAnggota(ListLomba &L, ListAnggota &O){
    infotype_child anggota;
    adr_anggota Pout;
    bool error = false;
    if (first(O) != NULL){
        do {
            error = false;
            cls();
            showAnggota(O);
            cout << "ketik tidak untuk keluar \n";
            cout << "Masukkan nama peserta : ";
            cin.ignore();
            getline(cin,anggota);
            if (anggota != "tidak"){
                DeleteAllAnggota(L, O, anggota);
                deleteAnggota(O, anggota, Pout);
            } else {
                error = true;
            }
        }while (error == true) ;
    }else{
        cls();
        cout << "Tidak ada peserta! \n";
    }
}

void menu_deleteLomba(ListLomba &L){
    infotype_parent lomba;
    adr_lomba Pout;
    bool error = false;
    if (first(L) != NULL){
        do {
            error = false;
            cls();
            showLomba(L);
            cout << "ketik tidak untuk keluar \n";
            cout << "Masukkan nama perlombaan : ";
            cin.ignore();
            getline(cin,lomba);
            if (lomba != "tidak"){
                deleteLomba(L, lomba, Pout);
            } else {
                error = true;
            }
        }while (error == true) ;
    }else{
        cls();
        cout << "tidak ada perlombaan! \n";
    }
}
