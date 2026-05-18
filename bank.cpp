#include <iostream>
using namespace std;

// ── Abstract Base Class ──────────────────────────────────────────
class RekeningBank {
protected:
    string namaNasabah;
    double saldo;

public:
    RekeningBank(string nama, double saldoAwal)
        : namaNasabah(nama), saldo(saldoAwal) {}

    virtual void potongAdmin() = 0;  // pure virtual

    void tampilInfo() {
        cout << "Nasabah : " << namaNasabah << endl;
        cout << "Saldo   : Rp " << saldo << endl;
    }

    virtual ~RekeningBank() {}
};

// ── Rekening Syariah ─────────────────────────────────────────────
class RekeningSymariah : public RekeningBank {
public:
    RekeningSymariah(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        cout << "[Syariah] Tidak ada potongan admin." << endl;
    }
};

// ── Rekening Konvensional ────────────────────────────────────────
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "[Konvensional] Dipotong Rp 15.000. Saldo sekarang: Rp "
             << saldo << endl;
    }
};

// ── Rekening Premium (BARU) ──────────────────────────────────────
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "[Premium] Saldo di atas Rp 10.000.000, "
                 << "bebas biaya admin." << endl;
        } else {
            saldo -= 50000;
            cout << "[Premium] Saldo <= Rp 10.000.000, "
                 << "dipotong Rp 50.000. Saldo sekarang: Rp "
                 << saldo << endl;
        }
    }
};

// ── Proses Akhir Bulan (via base class pointer) ──────────────────
void prosesAkhirBulan(RekeningBank* rekening) {
    rekening->tampilInfo();
    rekening->potongAdmin();
    cout << "--------------------------------" << endl;
}

// ── Main ─────────────────────────────────────────────────────────
int main() {
    RekeningBank* daftarRekening[] = {
        new RekeningSymariah      ("Ahmad Fauzi",   5000000),
        new RekeningKonvensional  ("Budi Santoso",  3000000),
        new RekeningPremium       ("Citra Dewi",   15000000),  // bebas admin
        new RekeningPremium       ("Deni Kurniawan", 8000000)  // kena potong
    };

    cout << "===== PROSES AKHIR BULAN - BANK GIBRAN JAYA =====" << endl;
    cout << endl;

    for (RekeningBank* rek : daftarRekening) {
        prosesAkhirBulan(rek);
        delete rek;
    }

    return 0;
}