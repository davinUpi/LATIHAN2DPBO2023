from Mahasiswa import *

class Civitas(Mahasiswa):
    
    def __init__(self, name, nim, gender, university, prodi, fakultas, nik, email):
        self._name = name
        self._nim = nim
        self._gender = gender
        self._prodi = prodi
        self._fakultas = fakultas
        self._nik = nik
        self._university = university
        self._email = email
    
    def setUniversity(self, university):
        self._university = university
    
    def setEmail(self, email):
        self._email = email
    
    def getUniversity(self):
        return self._university
    
    def getEmail(self):
        return self._email