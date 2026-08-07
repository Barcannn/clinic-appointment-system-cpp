#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Appointment {

    private:
    int id;
    std::string hastaAdi;
    std::string doktorAdi;
    std::string tarih;
    std::string saat;
    bool aktif;
    
    public:
   
    Appointment(int pId, std::string hasta, std::string doktor, std::string pTarih, std::string pSaat){
        id = pId;
        hastaAdi = hasta;
        doktorAdi =doktor;
        tarih = pTarih;
        saat = pSaat;
        aktif = true;
        }

    
    int getId() const { return id; }
    bool isAktif() const { return aktif;}
    void iptalEt(){
        aktif = false;
    }
    void bilgiYazdir() const {
        std::cout <<"ID: " << id
        << " | Hasta: " <<hastaAdi
        << " | Doktor: " <<doktorAdi
        << " | Tarih: " << tarih
        << " | Saat: " << saat
        << " | Durum: " << (aktif ? "Aktif" : "Pasif/Iptal")
        << std :: endl;
        
        }
    };
    class AppointmentManager {
        private:
        std::vector<Appointment> randevular;
        int sonrakiId = 1;
        

        public:
        void randevuOlustur(std::string hasta,
                            std::string doktor,
                            std::string tarih,
                            std::string saat){
                                randevular.emplace_back(sonrakiId, hasta, doktor, tarih, saat);
                                sonrakiId++;
                                std::cout << "[SISTEM] Randevu olusturdu.\n";
                                }
        void randevuIptalEt(int randevuId){
            for (auto& randevu : randevular){
                if (randevu.getId() == randevuId){
                if (!randevu.isAktif()) {
                    std::cout << " [UYARI] Bu randevu zaten daha önce iptal edilmiş.\n";
                    return;
                    }
                    randevu.iptalEt();
                    std::cout << "[SISTEM] ID " << randevuId << "olan randevu iptal edildi.\n";
                    return;
                    }
}
std::cout << "[HATA] ID " << randevuId << " olan randevu bulunamadı!\n";
}
void randevulariYazdir() const {
    if (randevular.empty()) {
        std::cout << "[SISTEM] Kayitli randevu bulunmuyor.\n";
        return;
    
    }
    std::cout << "\n----- TUM RANDEVU LISTESI ---\n";
    for (const auto& randevu : randevular){
        randevu.bilgiYazdir();
    }
    std::cout << "------------------\n";

}
};
int main () {
    AppointmentManager yonetici;

    yonetici.randevuOlustur("Ahmet Yilmaz","Dr. Ayse Demir","10-06-2026","14:30");
    yonetici.randevuOlustur("Cevat Agır","Dr. Erdal Ercin","11-06-2026","16.30");
    yonetici.randevuOlustur("Veysel Sun","Dr. Fedai Barcan","13-06-2026","13.30");

    yonetici.randevulariYazdir();

    yonetici.randevuIptalEt(2);

    yonetici.randevulariYazdir();
    return 0;
    }
