// Deklarasi pin tiap arah
int utara[]   = {2, 3, 4};
int timur[]   = {5, 6, 7};
int selatan[] = {8, 9, 10};
int barat[]   = {11, 12, 13};

// Index: 0=Merah, 1=Kuning, 2=Hijau

void setup() {
  // Set semua pin sebagai OUTPUT
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

// Fungsi untuk mematikan semua lampu
void semuaMerah() {
  for (int i = 2; i <= 13; i++) {
    digitalWrite(i, LOW);
  }
  
  // Nyalakan semua merah
  digitalWrite(2, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);
}

// Fungsi aktifkan satu simpang
void aktifkanSimpang(int merahPin, int kuningPin, int hijauPin) {

  semuaMerah(); // default semua merah

  // Hijau ON
  digitalWrite(merahPin, LOW);
  digitalWrite(hijauPin, HIGH);
  delay(5000);

  // Hijau OFF
  digitalWrite(hijauPin, LOW);

  // Kuning kedip 3x (total ±2 detik)
  for (int i = 0; i < 3; i++) {
    digitalWrite(kuningPin, HIGH);
    delay(300);
    digitalWrite(kuningPin, LOW);
    delay(300);
  }

  // Kuning ON sebentar
  digitalWrite(kuningPin, HIGH);
  delay(2000);
  digitalWrite(kuningPin, LOW);

  // Kembali merah
  digitalWrite(merahPin, HIGH);
}

void loop() {
  aktifkanSimpang(2, 3, 4);    // Utara
  aktifkanSimpang(5, 6, 7);    // Timur
  aktifkanSimpang(8, 9, 10);   // Selatan
  aktifkanSimpang(11, 12, 13); // Barat
}