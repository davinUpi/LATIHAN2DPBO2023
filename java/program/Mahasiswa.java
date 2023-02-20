

public class Mahasiswa extends Human {
    
    /*
     * Kelas yang berisi data2 mahasiswa.
     * Terdiri ddari atribut name, nim, prodi, fakultas
     * Masing2 atribut dapat diset dan diambil menggunakan methode
     */
    private String nim;
    private String prodi;
    private String fakultas;
    protected Human m_human;

    public Mahasiswa(String name, String nim, String prodi, String fakultas, String nik, GENDER gender) {
        super(name, nik, gender);
        this.name = name;
        this.nim = nim;
        this.prodi = prodi;
        this.fakultas = fakultas;
    }

    // Setter
    public void setNim(String nim)
    {
        this.nim = nim;
    }

    public void setProdi(String prodi) {
        this.prodi = prodi;
    }

    public void setFakultas(String fakultas) {
        this.fakultas = fakultas;
    }

    // Getter
    public String getNim()
    {
        return this.nim;
    }

    public String getProdi()
    {
        return this.prodi;
    }

    public String getFakultas() {
        return this.fakultas;
    }
}
