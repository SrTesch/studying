package eusoulindo;

public class Cliente {
    private final long cpf;
    private String nome;
    private String email;

    public Cliente(long cpf, String nome, String email) {
        this.cpf = cpf;
        this.nome = nome;
        this.email = email;
    }

    public long getCpf() {
        return cpf;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEmail() {
        return email;
    }

    public String getNome() {
        return nome;
    }
}
