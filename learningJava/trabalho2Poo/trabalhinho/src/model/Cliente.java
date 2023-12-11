package model;

import java.io.Serial;
import java.io.Serializable;

public abstract class Cliente implements Serializable {
    @Serial
    private static final long serialVersionUID = -9134453334819066383L;

    private String nome;
    private String email;
    private String telefone;
    private Endereco endereco;

    public Cliente() {}

    public Cliente(String nome, String telefone, Endereco endereco) {
        this.nome = nome;
        this.telefone = telefone;
        this.endereco = endereco;
    }

    public Cliente(String nome, String email, String telefone, Endereco endereco) {
        this.nome = nome;
        this.email = email;
        this.telefone = telefone;
        this.endereco = endereco;
    }

    public abstract String getNomeContato();

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public Endereco getEndereco() {
        return endereco;
    }

    public void setEndereco(Endereco endereco) {
        this.endereco = endereco;
    }

    @Override
    public String toString() {
        return nome;
    }
}
