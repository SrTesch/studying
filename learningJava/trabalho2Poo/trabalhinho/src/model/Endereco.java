package model;

import java.io.Serial;
import java.io.Serializable;

public class Endereco implements Serializable {
    @Serial
    private static final long serialVersionUID = 3134452354819066383L;

    private String rua;
    private String numero;
    private String cep;

    public Endereco(String rua, String numero, String cep) {
        this.rua = rua;
        this.numero = numero;
        this.cep = cep;
    }

    public String getRua() {
        return rua;
    }

    public void setRua(String rua) {
        this.rua = rua;
    }

    public String getNumero() {
        return numero;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }

    public String getCep() {
        return cep;
    }

    public void setCep(String cep) {
        this.cep = cep;
    }

    @Override
    public String toString() {
        return rua + ", " + numero + ", " + cep;
    }
}
