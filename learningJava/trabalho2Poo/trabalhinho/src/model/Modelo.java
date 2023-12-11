package model;

import java.io.Serial;
import java.io.Serializable;

public class Modelo implements Serializable {
    @Serial
    private static final long serialVersionUID = 2134452354819066383L;

    private final String nome;
    private final String ano;
    private final String fabricante;

    public Modelo(String nome, String ano, String fabricante) {
        this.nome = nome;
        this.ano = ano;
        this.fabricante = fabricante;
    }

    public String getNome() {
        return nome;
    }

    public String getAno() {
        return ano;
    }

    public String getFabricante() {
        return fabricante;
    }

    @Override
    public String toString() {
        return nome + " " + fabricante + " " + ano;
    }
}
