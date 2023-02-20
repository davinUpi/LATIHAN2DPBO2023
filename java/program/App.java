import java.util.LinkedList;
import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.FileNotFoundException;
import java.io.IOException;

enum ATTRIBUTETYPE{
    /*
     * enum untuk jenis2 atribut.
     * Digunakan untuk pencarian
     */
    NAME,
    GENDER,
    NIM,
    UNIVERSITY,
    PRODI,
    FAKULTAS,
    NIK,
    EMAIL
}

public class App {
    /*
     * Kelas untuk kondisi program
     * start:
     *  Ketika program mulai, load data2 dari file ke dalam list
     * 
     * run:
     *  Ketika program berjalan, menerima query pengguna.
     * 
     * exit:
     *  Ketika program selesai. Memasukan data2 dalam list
     * ke sebuah file.
     */
    private LinkedList<Civitas> listCivitas;
    /// List yang digunakan untuk menampung objek Civitas

    private String filePath;
    /// Alamat file penyimpanan

    App()
    {
        this.filePath = "Civitas.dat";
        this.listCivitas = new LinkedList<Civitas>();

    }
    
    public void start(){
        //
        ///metoda akan di eksekusi jika program baru di mulai
        //
        File file = new File("Civitas.dat");
        
        if (file.isFile()){
            //
            ///jika file tidak null maka data di Civitas.dat akan dimasukan pada listCivitas
            //
            try {
                Scanner fileReader = new Scanner(file);
                while (fileReader.hasNextLine()){
                    String data = fileReader.nextLine();
                    int state = 0;

                    String name = "";
                    GENDER gender = GENDER.MBT_LEOPARD;
                    String nim = "";
                    String universitas = "";
                    String prodi = "";
                    String fakultas = "";
                    String nik = "";
                    String email = "";

                    for (String val : data.split(" ")){
                        //
                        /// Mengambil data2 dari file
                        //
                        switch (state) {
                            case 0:
                                name = val;
                                state = 1;
                                break;
                            
                            case 1:
                                if(val.toLowerCase() == "laki-laki") gender = GENDER.MALE;
                                else if(val.toLowerCase() == "perempuan") gender = GENDER.FEMALE;
                                else gender = GENDER.MBT_LEOPARD;
                                state = 2;
                                break;

                            case 2:
                                nim = val;
                                state = 3;
                                break;

                            case 3:
                                universitas = val;
                                state = 4;
                                break;

                            case 4:
                                prodi = val;
                                state = 5;
                                break;
                            case 5:
                                fakultas = val;
                                state = 6;
                                break;
                            case 6:
                                nik = val;
                                state = 7;
                                break;
                            case 7:
                                email = val;
                                state = 8;
                            break;
                        }
                    }

                    if (state == 8){
                        
                        //
                        /// Bila semua data yang diperlukan sudah terambil, isntansiasi dan masukkan
                        /// objek Civitas ke dalam list
                        //
                        Civitas newcivit = new Civitas(name, nim, prodi, fakultas, nik, gender, universitas, email);
                        listCivitas.add(newcivit);
                    }
                }

                fileReader.close();
            }
            catch (FileNotFoundException e){
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
        }
    }
    
    public void run(){
        //
        ///metoda akan di eksekusi selama program berjalan
        //
        Scanner inputReader = new Scanner(System.in);
        Boolean shouldRun = true;
        while (shouldRun){

            String input = inputReader.nextLine();
            String query[] = input.split(" ");
            
            if (query[0].equalsIgnoreCase("exit")){
                //
                ///jika input exit maka loop akan berhenti
                //
                shouldRun = false;
            }
            
            else if (query[0].equalsIgnoreCase("add")){
                //
                ///jika input add maka akan tambahkan Civitas baru
                //
                if (query.length == 9)
                {
                    String name = "";
                    GENDER gender = GENDER.MBT_LEOPARD;
                    String nim = "";
                    String universitas = "";
                    String prodi = "";
                    String fakultas = "";
                    String nik = "";
                    String email = "";

                    for(int i = 1; i < 9; i++)
                    {
                        switch(i)
                        {
                            case 1:
                            name = query[i];
                            break;
                            case 2:

                            if(query[i].toLowerCase() == "laki-laki") gender = GENDER.MALE;
                            else if (query[i].toLowerCase() == "perempuan") gender = GENDER.FEMALE;

                            break;
                            case 3:
                            nim = query[i];
                            break;
                            case 4:
                            universitas = query[i];
                            break;
                            case 5:
                            prodi = query[i];
                            break;
                            case 6:
                            fakultas = query[i];
                            break;
                            case 7:
                            nik = query[i];
                            break;
                            case 8:
                            email = query[i];
                            break;
                        }
                    }

                    listCivitas.add(new Civitas(name, nim, prodi, fakultas, nik, gender, universitas, email));
                }
            }
            
            else if (query[0].equalsIgnoreCase("change")){
                //
                ///jika input change maka akan mengubah nilai sautu atribut
                /// dari Civitas tujuan
                //

                if(query.length == 6)
                {
                    ATTRIBUTETYPE searchType = null, changeType = null;
                    /// Variabel untuk mencari atribut yang dituju

                    String searchVal = "", changeVal = "";
                    /// nilai sebuah atribut

                    int i = 1;
                    String err = "";
                    while((i < 6) && (err == ""))
                    {
                        //
                        /// Memecah dan megecek input apakah sesuai dengan query
                        //
                        switch(i)
                        {
                            case 1:
                            if(query[i].equalsIgnoreCase("nama")) changeType = ATTRIBUTETYPE.NAME;
                            else if (query[i].equalsIgnoreCase("nim")) changeType = ATTRIBUTETYPE.NIM;
                            else if (query[i].equalsIgnoreCase("prodi")) changeType = ATTRIBUTETYPE.PRODI;
                            else if (query[i].equalsIgnoreCase("fakultas")) changeType = ATTRIBUTETYPE.FAKULTAS;
                            else if (query[i].equalsIgnoreCase("nik")) changeType = ATTRIBUTETYPE.NIK;
                            else if (query[i].equalsIgnoreCase("email")) changeType = ATTRIBUTETYPE.EMAIL;
                            else if (query[i].equalsIgnoreCase("universitas")) changeType = ATTRIBUTETYPE.UNIVERSITY;
                            else if (query[i].equalsIgnoreCase("gender")) changeType = ATTRIBUTETYPE.GENDER;
                            else err = "Attribut type not found!";
                            break;
                            
                            case 2:
                            changeVal = query[i];
                            break;

                            case 3:
                            if(!query[i].equalsIgnoreCase("where")) err = "Syntax error!";
                            break;
                            
                            case 4:
                            if(query[i].equalsIgnoreCase("nama")) searchType = ATTRIBUTETYPE.NAME;
                            else if (query[i].equalsIgnoreCase("nim")) searchType = ATTRIBUTETYPE.NIM;
                            else if (query[i].equalsIgnoreCase("prodi")) searchType = ATTRIBUTETYPE.PRODI;
                            else if (query[i].equalsIgnoreCase("fakultas")) searchType = ATTRIBUTETYPE.FAKULTAS;
                            else if (query[i].equalsIgnoreCase("nik")) searchType = ATTRIBUTETYPE.NIK;
                            else if (query[i].equalsIgnoreCase("email")) searchType = ATTRIBUTETYPE.EMAIL;
                            else if (query[i].equalsIgnoreCase("universitas")) searchType = ATTRIBUTETYPE.UNIVERSITY;
                            else if (query[i].equalsIgnoreCase("gender")) searchType = ATTRIBUTETYPE.GENDER;
                            else err = "Attribut type not found!";
                            break;

                            case 5:
                            searchVal = query[i];
                            break;
                        }

                        i++;
                    }
                    if (err == "")
                    //
                    /// Jika tidak ada error dalam query, cari Civitas yang dituju lalu
                    /// ubah nilai atribut yang ditujunya bila ketemu.
                    //
                    {
                        Civitas changeCivitas = null;
                        for(Civitas civit : listCivitas){

                            if (searchType == ATTRIBUTETYPE.NAME){
                                if(civit.getName().equalsIgnoreCase(searchVal)) changeCivitas = civit;
                            }
                            else if (searchType == ATTRIBUTETYPE.NIM){
                                if(civit.getNim().equalsIgnoreCase(searchVal)) changeCivitas = civit;
                            }
                            else if (searchType == ATTRIBUTETYPE.PRODI){
                                if (civit.getProdi().equalsIgnoreCase(searchVal)) changeCivitas = civit;
                            }
                            else if (searchType == ATTRIBUTETYPE.FAKULTAS){
                                if (civit.getFakultas().equalsIgnoreCase(searchVal)) changeCivitas = civit;
                            }
                            else if (searchType == ATTRIBUTETYPE.UNIVERSITY){
                                if (civit.getFakultas().equalsIgnoreCase(searchVal)) changeCivitas = civit;
                            }
                            else if (searchType == ATTRIBUTETYPE.NIK){
                                if (civit.getFakultas().equalsIgnoreCase(searchVal)) changeCivitas = civit;
                            }
                            else if (searchType == ATTRIBUTETYPE.EMAIL){
                                if (civit.getFakultas().equalsIgnoreCase(searchVal)) changeCivitas = civit;
                            }
                            else if (searchType == ATTRIBUTETYPE.GENDER){
                                if (civit.getFakultas().equalsIgnoreCase(searchVal)) changeCivitas = civit;
                            }
                        }

                        if(changeCivitas != null)
                        {
                            if (changeType == ATTRIBUTETYPE.NAME) changeCivitas.setName(changeVal);
                            else if(changeType == ATTRIBUTETYPE.NIM) changeCivitas.setNim(changeVal);
                            else if(changeType == ATTRIBUTETYPE.PRODI) changeCivitas.setProdi(changeVal);
                            else if(changeType == ATTRIBUTETYPE.FAKULTAS) changeCivitas.setFakultas(changeVal);
                            else if(changeType == ATTRIBUTETYPE.UNIVERSITY) changeCivitas.setUniversity(changeVal);
                            else if(changeType == ATTRIBUTETYPE.NIK) changeCivitas.setNik(changeVal);
                            else if(changeType == ATTRIBUTETYPE.EMAIL) changeCivitas.setEmail(changeVal);
                            else if(changeType == ATTRIBUTETYPE.GENDER){
                                GENDER gender;
                                if(changeVal.toLowerCase() == "laki-laki") gender = GENDER.MALE;
                                else if(changeVal.toLowerCase() == "perempuan") gender = GENDER.FEMALE;
                                else gender = GENDER.MBT_LEOPARD;

                                changeCivitas.setGender(gender);
                            }
                        }
                    }
                    else{
                        System.out.println(err);
                    }
                }
                else{
                    System.out.println("Syntax error!");
                }
            }
            
            else if (query[0].equalsIgnoreCase("delete")){
                //
                ///jika input delete maka akan menghapus Civitas yang dimaksud
                //
                if(query.length == 3)
                {
                    ATTRIBUTETYPE searchType = null;
                    String searchVal = "";

                    int i = 1;
                    String err = "";
                    while((i < 3) && (err == ""))
                    {
                        switch(i)
                        {
                            case 1:
                            if(query[i].equalsIgnoreCase("nama")) searchType = ATTRIBUTETYPE.NAME;
                            else if (query[i].equalsIgnoreCase("nim")) searchType = ATTRIBUTETYPE.NIM;
                            else if (query[i].equalsIgnoreCase("prodi")) searchType = ATTRIBUTETYPE.PRODI;
                            else if (query[i].equalsIgnoreCase("fakultas")) searchType = ATTRIBUTETYPE.FAKULTAS;
                            else if (query[i].equalsIgnoreCase("nik")) searchType = ATTRIBUTETYPE.NIK;
                            else if (query[i].equalsIgnoreCase("email")) searchType = ATTRIBUTETYPE.EMAIL;
                            else if (query[i].equalsIgnoreCase("universitas")) searchType = ATTRIBUTETYPE.UNIVERSITY;
                            else if (query[i].equalsIgnoreCase("gender")) searchType = ATTRIBUTETYPE.GENDER;
                            else err = "Attribut type not found!";
                            break;
                            case 2:
                            searchVal = query[i];
                            break;

                        }

                        i++;
                    }

                    if (err == "")
                    {
                        Civitas delcivit = null;
                        for(Civitas civit : listCivitas){

                            if (searchType == ATTRIBUTETYPE.NAME){
                                if(civit.getName().equalsIgnoreCase(searchVal)) delcivit = civit;
                            }
                            else if (searchType == ATTRIBUTETYPE.NIM){
                                if(civit.getNim().equalsIgnoreCase(searchVal)) delcivit = civit;
                            }
                            else if (searchType == ATTRIBUTETYPE.PRODI){
                                if (civit.getProdi().equalsIgnoreCase(searchVal)) delcivit = civit;

                            }
                            else if (searchType == ATTRIBUTETYPE.FAKULTAS){
                                if (civit.getFakultas().equalsIgnoreCase(searchVal)) delcivit = civit;
                            }
                            else if (searchType == ATTRIBUTETYPE.UNIVERSITY){
                                if (civit.getUniversity().equalsIgnoreCase(searchVal)) delcivit = civit;
                            }
                            else if (searchType == ATTRIBUTETYPE.NIK){
                                if (civit.getNik().equalsIgnoreCase(searchVal)) delcivit = civit;
                            }
                            else if (searchType == ATTRIBUTETYPE.EMAIL){
                                if (civit.getEmail().equalsIgnoreCase(searchVal)) delcivit = civit;
                            }
                            else if (searchType == ATTRIBUTETYPE.GENDER){
                                GENDER gender;
                                if(searchVal.toLowerCase() == "laki-laki") gender = GENDER.MALE;
                                else if(searchVal.toLowerCase() == "perempuan") gender = GENDER.FEMALE;
                                else gender = GENDER.MBT_LEOPARD;

                                if (civit.getGender() == gender) delcivit = civit;
                            }
                        }

                        if(delcivit != null)
                        {
                            listCivitas.removeFirstOccurrence(delcivit);
                        }
                    }
                    else{
                        System.out.println(err);
                    }
                }
                
            }
            
            else if(query[0].equalsIgnoreCase("print")){
                for (Civitas i : this.listCivitas){
                    String gender = "";
                    if(i.getGender() == GENDER.MALE) gender = "Laki-laki";
                    else if(i.getGender() == GENDER.FEMALE) gender = "Perempuan";
                    else gender = "MBT Leopard";

                    System.out.println(i.getName());
                    System.out.println(gender);
                    System.out.println(i.getNim());
                    System.out.println(i.getUniversity());
                    System.out.println(i.getProdi());
                    System.out.println(i.getFakultas());
                    System.out.println(i.getNik());
                    System.out.println(i.getEmail());
                    System.out.println();
                }
            }
            else{
                System.out.println("Syntax error!");
            }
        }
        inputReader.close();
    }
    
    public void exit() {
        //
        /// metode akan dieksekusi jika program keluar.
        /// Menyimpan data2 dalam list ke sebuah file
        //
        try {
            File file = new File("Civitas.dat");
            if(!file.exists()){
                file.createNewFile();
            }

            try {
                FileWriter fileWriter = new FileWriter(file);
                for(Civitas i : this.listCivitas){
                    String gender = "";
                    if(i.getGender() == GENDER.MALE) gender = "Laki-laki";
                    else if(i.getGender() == GENDER.FEMALE) gender = "Perempuan";
                    else gender = "MBT_Leopard";
                    try {
                        fileWriter.write
                        (
                            i.getName() + " " +
                            gender + " " +
                            i.getNim() + " " +
                            i.getUniversity() + " " +
                            i.getProdi() + " " +
                            i.getFakultas() + " " +
                            i.getNik() + " " +
                            i.getEmail() + "\n"
                            );
                    } catch (IOException e){
                        e.printStackTrace();
                    }
                }
                fileWriter.close();
            } catch (IOException e){
                e.printStackTrace();
            }

        }catch (IOException e){
            System.out.println("Error");
            e.printStackTrace();
        }
    }

    // path setter and getter

    public void setFilePath(String filePath) {
        this.filePath = filePath;
    }

    public String getFilePath() {
        return filePath;
    }

}
