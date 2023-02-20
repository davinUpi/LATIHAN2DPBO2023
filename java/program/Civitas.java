public class Civitas extends Mahasiswa {

    protected String university;
    protected String email;
    
    Civitas(String name, String nim, String prodi, String fakultas, String nik, GENDER gender, String university, String email){
        super(name, nim, prodi, fakultas, nik, gender);
        this.university = university;
        this.email = email;
    }

    public void setUniversity(String university) {
        this.university = university;
    }
    public void setEmail(String email) {
        this.email = email;
    }

    public String getUniversity() {
        return university;
    }
    public String getEmail() {
        return email;
    }

}
