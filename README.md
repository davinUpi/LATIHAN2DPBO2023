# LATIHAN2DPBO2023
“LATIHAN2DPBO2023”

Penjelasan desain kelas

1. Kelas Main
  
    Menampung seluruh aplikasi. Menggunakan kelas App
    
 2. kelas App
 
    Menampung bagian utama aplikasi. Menggunakan kelas Human, Mahasiswa, Civitas. Memiliki private attribute path ke file dan juga listCivitas
    
    Terdiri dari 3 metode utama: start, run, exit;
    
      a) start <br>
        Metode yang memuat data-data dari file.
        
      b) run <br>
        Metode yang memuat pemrosesan query dan CRUD. Penjelasan lebih detail di bawah.
        
      c) exit <br>
        MEtode yang memasukkan data-data ke dalam file
  
 3. Kelas Human
  
    Menampung protected attribute name, gender, dan nik. Metode terdiri dari konstruktor, setter, dan getter.
    
    Terdapat juga enum GENDER yang berisikan jenis kelamin
 
  4. Kelas Mahasiswa
  
     Menampung protected attribute nim, prodi, fakultas. Metode terdiri dari konstruktor, getter, dan setter. Extend kelas Human
     
  5. Kelas Civitas
  
     Menampung pricate universitas dan email. Metode terdiri dari konstruktor, getter, dan setter. Extend kelas Mahasiswa
