## Prototype of DC Motor Speed Control by Temperature Sensor

**Project ini dibuat dalam mata kuliah Dasar Teknik Tenaga Listrik pada November 2022 dengan dosen pembina Ferdyanto, S.T., M.T.**

Simulasi dibuat melalui [Tinkercad](https://www.tinkercad.com/things/6zNUALPcnB8-dc-motor-speed-control-by-temperature-sensor) dan secara langsung dipaparkan kepada dosen.

## Tujuan
 Tujuan dari proyek ini adalah secara otomatis menyesuaikan kecepatan kipas dengan suhu yang terdeteksi. Untuk membuat proyek ini, kecepatan motor servo diubah menjadi PWM agar dapat disesuaikan dengan suhu yang terdeteksi.
## Cara Kerja
 1. Sensor Suhu bekerja secara realtime untuk mendeteksi suhu sekitar. Suhu ditetapkan dengan batas minimal 25C, maksimal 35C.
 2. Sensor akan melakukan delay/konfigurasi otomatis selama 0.2 detik untuk melakukan kerjanya.
 3. Saat terdeteksi Suhu diantara 25 - 35, kecepatan servo akan diatur dari 0-100%
 4. Saat terdeteksi Suhu dibawah nilai minimal maka kipas akan mati dan Suhu diatas nilai maksimal maka kecepatan servo akan selalu 100%
