from Human import *

class Mahasiswa(Human):
    '''
    Kelas untuk menampung data2 Mahasiswa
    terdiri dari Nama, Nim, Prodi, dan Fakultas
    Masing2 dapat diset menggunakan setter
    Masing2 dapat diambil menggunakan getter
    '''
    
    def __init__(self, name, nim, gender, prodi, fakultas, nik):
        self._name = name
        self._nim = nim
        self._gender = gender
        self._prodi = prodi
        self._fakultas = fakultas
        self._nik = nik
    
    #Setter
    
    def setNim(self, nim):
        self._nim = nim
    
    def setProdi(self, prodi):
        self._prodi = prodi
        
    def setFac(self, fakultas):
        self.fakultas = fakultas
    
    #getter
    
    def getNim(self):
        return self._nim
    
    def getProdi(self):
        return self._prodi
    
    def getFac(self):
        return self._fakultas