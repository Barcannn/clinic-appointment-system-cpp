#include <iostream>
#include <vector>
#include <string>

// Randevu bilgilerini tutan sınıf
class Appointment {

private:
std::string patientName;
std::string doctorName;
std::string appointmentDate;
std::string timeSlot;
bool isActive;
public:

Appointment(std::string pName, std::string dName, std::string date, std::string slot)
: patientName(pName), doctorName(dName), appointmentDate(date),  timeSlot(slot), isActive(true) {}
void display() const{
    std::cout << "Hasta: " << patientName
              << " | Doktor: " << doctorName
              << " | Tarih: " << appointmentDate
             << " | Saat: " << timeSlot << std::endl;

}

std::string getTimeSlot() const { return timeSlot; }
std::string getDoctorName() const { return doctorName;}
std::string getDate() const { return appointmentDate;
}
bool getIsActive() const {
  return isActive;
}
void cancel() {
  isActive = false;
}
};
 //Randevu yönetimini üstlenen sınıf 
 class AppointmentManager {
    private:
    std::vector<Appointment> appointments;
    std::vector<std::string> availableSlots = {"09:00", "10:00", "11:00", "14:00", "15:00"};

      public:
              void showAvailableSlots(const std::string& doctor, const std::string& date) const {
                std::cout << "\n---" << doctor 
                << " | Tarih: " << date
                << " icin bos saatler ---\n";
                for (const auto& slot : availableSlots) {
                  if (!isSlotTaken(doctor, date, slot)) {
                    std::cout << " - " << slot << "\n";
                  }
                }
              }
              void showAppointmentHours() const {
                std::cout << "\n----- Genel Randevu Saatleri ----- \n";
                for (const auto& slot : availableSlots) {
                  std::cout << "- " << slot << " \n";
                }
              }
              void showDoctors() const {
                std::cout << "\n--- Doktorlar Listesi ---\n";
                std::cout << "DR.AHMET --- Kulak Burun Bogaz\n";
                std::cout << "DR.AYSE --- Sinir Hastalıklari\n";
                std::cout << "DR.FEDAİ --- Gögüs Hastalıklari\n";
                std::cout << "DR.GONUL --- Dis HEKİMİ\n";
                std::cout << "DR.CAKI --- Uroloji\n";
              }
              
void showDoctorSchedule() const {
  if(appointments.empty()) {
    std::cout << "\n Henuz kayitli randevu yok. \n";
    return;
  }
  std::cout << "\n--- Doktorlarin Randevu Saatleri ---\n";
  for (const auto& app : appointments) {
    std::cout << "Doktor: " << app.getDoctorName()
    << " | Tarih: " << app.getDate()
    << " | Saat: " << app.getTimeSlot() << "\n";
  }
}

 


bool isSlotTaken(const std::string& doctor, const std::string& date, const std::string& slot) const {
for (const auto& app : appointments){
if (app.getDoctorName() == doctor &&
app.getDate() == date &&
 app.getTimeSlot() == slot &&
 app.getIsActive())
 {
return true; // Aynı doktora aynı saatte randevu var
}

}
return false;


}
void bookAppointment(){
std::string pName, dName, date, slot;

std::cout << "HASTA Adı: ";
std::cin.ignore();
std::getline(std::cin, pName);


std::cout << "DOKTOR Adı (ÖRN: DR. AHMET, DR. AYSE, DR.FEDAİ, DR.GONUL, DR.CAKİ): ";
std::getline(std::cin, dName);
std::cout << "Secmek istediginiz tarih (DD-MM-YYYY): ";
std::getline(std::cin, date);
showAvailableSlots(dName, date);


std::cout << "Seçmek istediginiz saat dilimi: ";
std::cin >> slot;
 if(isSlotTaken(dName, date, slot)){
 std::cout << "\n[HATA] Bu saatte Doktor " << dName << " zaten dolu!\n";
 }
 else {
 appointments.push_back(Appointment(pName, dName, date, slot));
 std::cout << "\n[BASARILI] Randevunuz basarıyla olusturuldu.\n";

 }
 }
 void cancelAppointment() {
  std::string dName, date, slot;
  std::cout << " Iptal etmek Istediginiz randevunun DOKTOR ADI: ";
  std::cin.ignore();
  std::getline(std::cin, dName);
  std::cout << " IPTAL ETMEK ISTEDIGINIZ randevunun tarihi (DD-MM-YYYY): ";
  std::getline(std::cin, date);
  std::cout << "Iptal etmek istediginiz randevunun saati: ";
  std::cin >> slot;
  for (auto& app : appointments){
    if (app.getDoctorName() == dName &&
    app.getDate() == date &&
    app.getTimeSlot() == slot &&
    app.getIsActive()) {
      app.cancel();
      std::cout << "\n[BASARILI] Randevu iptal edildi.\n";
      return;    }
  }
  std::cout << " \n[HATA] Aktif randevu bulunamadi.\n";
 } // cancelAppointment burada bitiyor

void viewAppointments() const {
if (appointments.empty()) {
std::cout << "\nHENUZ KAYITLI RANDEVU YOK.\n";
return;
}
std::cout << "\n----- Guncel Randevu Listesi -----.\n";
for (const auto& app: appointments) {
app.display();
}

}
};
int main() {
AppointmentManager manager;
int choice;

do {
std::cout << "\n===== RANDEVU SISTEMI =====\n";
std::cout << "1. Randevu Al:\n";
std::cout << "2. Randevulari Listele:\n";
std::cout << "3. Doktorlarin Randevu Saatlerini Gor:\n";
std::cout << "4. Genel Randevu Saatlerini Gor:\n";
std::cout << "5. Doktorlari Listele:\n";
std::cout << "6. Randevu IPTAL et:\n";
std::cout << "7. CIKIS YAPIN:\n";
std::cout << "     Seciminiz:     ";
std::cin >> choice;


switch (choice) {
case 1: manager.bookAppointment(); break;
case 2: manager.viewAppointments(); break;
case 3: manager.showDoctorSchedule(); break;
case 4: manager.showAppointmentHours();break;
case 5: manager.showDoctors(); break;
case 6: manager.cancelAppointment(); break;
case 7: std::cout << " Sistemden cıkılıyor....\n"; break;
default: std::cout << " Geçersiz secim! Tekrar Deneyin.\n";
}
}while (choice !=7);
return 0;
}


