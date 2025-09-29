#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cout << "Masukkan detik ke-: ";
    cin >> t;

    // durasi lampu: Kuning = 3, Merah = 80, Hijau = 20
    vector<int> durasi = {3, 80, 20};
    vector<string> warna = {"KUNING", "MERAH", "HIJAU"};

    int total = 103;              // total siklus
    int x = (t - 45) % total;     // offset mulai dari detik 45 (kuning)
    if (x < 0) x += total;

    int idx = 0;
    while (x >= durasi[idx]) {
        x -= durasi[idx];
        idx = (idx + 1) % 3;
    }

    cout << "Lampu: " << warna[idx] << endl;
    return 0;
}