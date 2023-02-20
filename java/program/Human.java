enum GENDER{
    MALE,
    FEMALE,
    MBT_LEOPARD
};

public class Human{

    protected String name;
    protected String nik;
    protected GENDER gender;

    Human(String name, String nik, GENDER gender){
        this.name = name;
        this.nik = nik;
        this.gender = gender;
    }

    public String getName() {
        return name;
    }

    public String getNik() {
        return nik;
    }

    public GENDER getGender() {
        return gender;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setNik(String nik) {
        this.nik = nik;
    }

    public void setGender(GENDER gender) {
        this.gender = gender;
    }

};