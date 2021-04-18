#include "parent.h"

int main()
{
    ListLomba L;
    ListAnggota O;
    createListLomba(L);
    createListAnggota(O);
    menu_utama(L, O);

    return 0;
}
