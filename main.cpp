/*
 Asep Trisna Setiawan
 Kecepatan awal V0: 50 m/s
 Sudut :30°

*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI = 3.14, g = 9.80;

int main()
{
    double sudut, Vo, Vxo, Vyo, t, x, y, y_max, x_max, ty_max, tx_max;
    cout << fixed;
    cout << setprecision(2);
    do{
    cout << "Masukan Kecepatan Awal (Vo) m/s: ";
    cin >> Vo;
    }

    while (Vo < 0);
    do
    {
    cout << "Masukan Sudut Elevasi: ";
    cin >> sudut;
    }

    while ((sudut < 1) || (sudut > 89));
    Vxo = Vo * cos (sudut * PI / 180);
    Vyo = Vo * sin (sudut * PI / 180);
    ty_max = (Vyo / g);
    y_max = (Vyo * ty_max) - (0.5 * g * (ty_max * ty_max));
    x_max = (Vo * Vo) * (sin (2 * (sudut * PI / 180))) / g;
    tx_max = (x_max / Vxo);

    cout << "Kecepatan awal pada sumbu X = Vx(o) = " << Vxo << " m/s " << endl;
    cout << "Kecepatan awal pada sumbu Y = Vy(o) = " << Vyo << " m/s " << endl;
    cout << "Ketinggian Max = y(max) = " << y_max << " meter " << endl;
    cout << "Waktu yang ditempuh pada ketinggian = t y(max) = " << ty_max << " detik " << endl;
    cout << "Jarak max = x(max) = " << x_max << " meter " << endl;
    cout << "Waktu pada Jarak Max = t x(max) = " << tx_max << " detik " << endl;

    char ulangi = 'y';
    while (ulangi == 'y') {
        do
        {
        cout << endl << "Masukan Waktu yang diamati (detik): ";
        cin >> t;
        } while ((t < 0) || (t>tx_max));

        for (int i = 0; i <= t; i++) {
            x = (Vxo * i);
            y = (Vyo * i) - (0.5 * g * (i * i));
            if (y < 0) {
                y = 0;
            }
            cout << "(x, y)[" << i << "] = (" << x << ", " << y << ")" << endl;
            if (y == 0 && i != 0) {
                break;
            }
        }
            cout << endl << "Maka pada waktu " << t << " detik, posisi : " << endl;
            cout << "x = " << x << " meter " << endl;
            cout << "y = " << y << " meter " << endl;

        printf ("Apakah ingin menginput waktu pengamatan lain?\n");
        printf ("Jawab (y/t):");
        cin >> ulangi;
    }

    return 0;
}
