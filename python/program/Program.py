import os.path
from Civitas import Civitas
from Human import GENDER


class Program:
    '''
    Kelas untuk menampung status program
    
    start:
        Di saat program baru dijalankan. Akan mengambil
        data2 civitas yang tersimpan di dalam file
        
    run:
        Di saat program berjalan. Akan menerima masukan
        berupa Query. Tidak akan berhenti hingga disuruh
        berhenti dengan query tertentu (exit)
    
    exit:
        Ketika program disuruh berhenti. Akan menyimpan
        civitas2 yang tersimpan dalam list(?) ke sebuah
        file
    '''
    
    def __init__(self):
        self.__listCivitas = []
        # Untuk menampung civitas
        
        self.__path = 'civitas.dat'
        # alamat file yang digunakan untuk penyimpanan
    
    def start(self):
        '''
        Di saat program baru dijalankan. Akan mengambil
        data2 civitas yang tersimpan di dalam file
        '''
        if os.path.exists(self.__path) is True:
            file = open(self.__path, 'r')
            content = file.readlines()
            for line in content:
                name, nim, gender, university, prodi, fakultas, nik, email = line.split()
                
                if gender.lower() == "laki-laki":
                    gender = GENDER.MALE
                elif gender.lower() == "perempuan":
                    gender = GENDER.FEMALE
                else:
                    gender = GENDER.ATTACK_HELICOTER
                    
                newCivitas = Civitas(name, nim, gender, university, prodi, fakultas, nik, email)
                self.__listCivitas.append(newCivitas)
            file.close()
    
    def run(self):
        '''
        Di saat program berjalan. Akan menerima masukan
        berupa Query. Tidak akan berhenti hingga disuruh
        berhenti dengan query tertentu (exit)
        '''
        run = True
        while run :
            query = input().split()
            
            if query[0].lower() == 'exit':
                run = False
            elif query[0].lower() == 'add':
                '''
                Query penambahan civitas
                '''
                if len(query) == 9:
                    name, gender, nim, university, prodi, fakultas, nik, email = query[1:9]
                
                    if gender.lower() == "laki-laki":
                        gender = GENDER.MALE
                    elif gender.lower() == "perempuan":
                        gender = GENDER.FEMALE
                    else:
                        gender = GENDER.ATTACK_HELICOTER
                        
                    newCivitas = Civitas(name, nim, gender, university, prodi, fakultas, nik, email)
                    self.__listCivitas.append(newCivitas)
                
                else:
                    print('Query is incomplete or excessive!')
                    
            elif query[0].lower() == 'print':
                for civitas in self.__listCivitas:
                    
                    gender = ""
                    if civitas.getGender() == GENDER.MALE:
                        gender = "Laki-laki"
                    elif civitas.getGender() == GENDER.FEMALE:
                        gender = "Perempuan"
                    else:
                        gender = "Attack_Helicopter"
                    
                    print(civitas.getName())
                    print(gender)
                    print(civitas.getNim())
                    print(civitas.getUniversity())
                    print(civitas.getProdi())
                    print(civitas.getFac())
                    print(civitas.getNik())
                    print(civitas.getEmail())
                    print("")
            elif query[0].lower() == 'change':
                '''
                Query pengubahan nilai suatu atribut civitas tujuan.
                Akan dilakukan pencarian civitas yang dituju, baru mengubah
                atribut yang dituju
                '''
                if len(query) == 6:
                    if query[3].lower() == 'where':
                        changeType, changeVal = query[1:3]
                        searchType, searchVal = query[4:6]
                        index = -1
                        
                        for civitas in self.__listCivitas:
                            '''
                            Mencari civitas di dalam list
                            '''
                            
                            if searchType.lower() == 'nama':
                                if civitas.getName().lower() == searchVal:
                                    index = self.__listCivitas.index(civitas)
                                    break
                            
                            elif searchType.lower() == 'nim':
                                if civitas.getNim() == searchVal:
                                    index = self.__listCivitas.index(civitas)
                                    break
                                
                            elif searchType.lower() == 'prodi':
                                if civitas.getProdi().lower() == searchVal:
                                    index = self.__listCivitas.index(civitas)
                                    break
                            
                            elif searchType.lower() == 'fakultas':
                                if civitas.getFac().lower() == searchVal:
                                    index = self.__listCivitas.index(civitas)
                                    break
                            
                            elif searchType.lower() == 'universitas':
                                if civitas.getFac().lower() == searchVal:
                                    index = self.__listCivitas.index(university)
                                    break
                            
                            elif searchType.lower() == 'email':
                                if civitas.getFac().lower() == searchVal:
                                    index = self.__listCivitas.index(email)
                                    break
                            
                            elif searchType.lower() == 'nik':
                                if civitas.getFac().lower() == searchVal:
                                    index = self.__listCivitas.index(nik)
                                    break
                            
                            elif searchType.lower() == 'gender':
                                
                                if searchVal.lower() == "laki-laki":
                                    searchVal = GENDER.MALE
                                elif searchVal.lower() == "perempuan":
                                    searchVal = GENDER.FEMALE
                                else:
                                    searchVal = GENDER.ATTACK_HELICOTER
                                
                                if civitas.getFac().lower() == searchVal:
                                    index = self.__listCivitas.index(gender)
                                    break
                            
                        if index != -1:
                            '''
                            Bila ketemu, ubahlah nila atribut yang dituju
                            '''
                            if changeType.lower() == 'nama':
                                self.__listCivitas[index].setName(changeVal)
                            
                            elif changeType.lower() == 'nim':
                                self.__listCivitas[index].setNim(changeVal)
                            
                            elif changeType.lower() == 'prodi':
                                self.__listCivitas[index].setProdi(changeVal)
                            
                            elif changeType.lower() == 'fakultas':
                                self.__listCivitas[index].setFac(changeVal)
                            
                            elif changeType.lower() == 'universitas':
                                self.__listCivitas[index].setFac(university)
                            
                            elif changeType.lower() == 'email':
                                self.__listCivitas[index].setFac(email)
                            
                            elif changeType.lower() == 'nik':
                                self.__listCivitas[index].setFac(nik)
                            
                            elif changeType.lower() == 'gender':
                                
                                if changeVal.lower() == "laki-laki":
                                    changeVal = GENDER.MALE
                                elif changeVal.lower() == "perempuan":
                                    changeVal = GENDER.FEMALE
                                else:
                                    changeVal = GENDER.ATTACK_HELICOTER
                                
                                self.__listCivitas[index].setFac(gender)
                            
                        else:
                            print('civitas not found!')
                            
                    else:
                        print('Incomplete query')
                        
            elif query[0].lower() == 'delete':
                '''
                Query menghapus civitas yang inngin dihapus.
                Akan dilakukan pencarian di dalam list
                '''
                if len(query) == 3:
                    searchType, searchVal = query[1:3]
                    index = -1
                    searchVal = searchVal.lower()
                    
                    for civitas in self.__listCivitas:
                        if searchType.lower() == 'nama':
                                if civitas.getName().lower() == searchVal:
                                    index = self.__listCivitas.index(civitas)
                                    break
                            
                                elif searchType.lower() == 'nim':
                                    if civitas.getNim() == searchVal:
                                        index = self.__listCivitas.index(civitas)
                                        break
                                    
                                elif searchType.lower() == 'prodi':
                                    if civitas.getProdi().lower() == searchVal:
                                        index = self.__listCivitas.index(civitas)
                                        break
                                
                                elif searchType.lower() == 'fakultas':
                                    if civitas.getFac().lower() == searchVal:
                                        index = self.__listCivitas.index(civitas)
                                        break
                                
                                elif searchType.lower() == 'universitas':
                                    if civitas.getFac().lower() == searchVal:
                                        index = self.__listCivitas.index(university)
                                        break
                                
                                elif searchType.lower() == 'email':
                                    if civitas.getFac().lower() == searchVal:
                                        index = self.__listCivitas.index(email)
                                        break
                                
                                elif searchType.lower() == 'nik':
                                    if civitas.getFac().lower() == searchVal:
                                        index = self.__listCivitas.index(nik)
                                        break
                                
                                elif searchType.lower() == 'gender':
                                    
                                    if searchVal.lower() == "laki-laki":
                                        searchVal = GENDER.MALE
                                    elif searchVal.lower() == "perempuan":
                                        searchVal = GENDER.FEMALE
                                    else:
                                        searchVal = GENDER.ATTACK_HELICOTER
                                    
                                    if civitas.getFac().lower() == searchVal:
                                        index = self.__listCivitas.index(gender)
                                        break
                    
                    if index != -1:
                        self.__listCivitas.pop(index)
                    else:
                        print('civitas not found!')
                
            elif query[0].lower() == 'help' or '?':
                print("Queries and how to use them:")
                print("ADD:")
                print("ADD {nama} {nim} {jenis_kelamin} {universitas} {prodi} {fakultas} {nik} {email_universitas}")
                print("CHANGE:")
                print("CHANGE {change attribute} {change value} where {search attribute} {search value}")
                print("DELETE:")
                print("DELETE {search attribute} {search value}")
                print("PRINT: print")
    def exit(self):
        file = open(self.__path, 'w')
        for civitas in self.__listCivitas:
            gender = ""
            if civitas.getGender() == GENDER.MALE:
                gender = "Laki-laki"
            elif civitas.getGender() == GENDER.FEMALE:
                gender = "Perempuan"
            else:
                gender = "Attack_Helicopter"
            file.write(civitas.getName() + ' ' +  gender + ' ' + civitas.getNim() + ' ' + civitas.getUniversity() +  ' ' + civitas.getProdi() + ' ' + civitas.getFac() + ' ' + civitas.getNik() + ' ' + civitas.getEmail() +'\n')
        
        file.close()