#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
struct player
{
    char nama[30];
    int nilai;
};
vector<player> V;
int maksimal = 5;

void tampil()
{
    for (int i = 0; i < V.size(); i++)
    {
        cout << i + 1 << "." << V[i].nama << " - " << V[i].nilai << endl;
    }
}

void tambah_belakang(char nama[30], int nilai)
{

    player *databaru;
    databaru = new player;
    strcpy(databaru->nama, nama);
    databaru->nilai = nilai;
    V.push_back(*databaru);
}

void hapus_belakang()
{
    V.pop_back();
}

int main()
{
    string nmplayer[10] = {"Agus", "Indah", "Heru", "Kiki", "Bagus", "Yuli", "Budi", "Carlie", "Linda", "Putri"};
    int point[10] = {100, 50, 110, 120, 80, 90, 140, 95, 160, 115};
    cout << "Daftar Player dan Nilai" << endl;
    for (int a = 0; a < 10; a++)
    {
        cout << "Hasil permainan terakhir : " << nmplayer[a] << " " << point[a] << endl;
        /**disini code utk mengatur (menyimpan/menghapus) nama player dan nilainya
            1. Lakukan Penambahan Data Dibelakang
            2. Sorting Data secara DESCENDING
            3. Hapus Data paling belakang, jika data yg ada > maksimal
            4. Tampilkan Data
            **/
        // Convert string ke *char
        char *c = const_cast<char *>(nmplayer[a].c_str());
        tambah_belakang(c, point[a]);
        // sorting
        sort(V.begin(), V.end(), [](player a, player b)
             { return a.nilai > b.nilai; });
        // hapus data, jika data yg ada > maksimal
        if (a >= maksimal)
        {
            hapus_belakang();
        }
        tampil();
        getch();
    }
    return 0;
}
