package model;

import util.IFormatter;

import java.io.Serial;
import java.io.Serializable;

public class PessoaJuridica extends Cliente implements Serializable, IFormatter {
    @Serial
    private static final long serialVersionUID = 9134452354819055383L;

    private final String cnpj;
    private String nomePessoaContato;

    public PessoaJuridica(String cnpj) {
        super();
        this.cnpj = cnpj;
    }

    public PessoaJuridica(String nome, String email, String telefone, Endereco endereco, String cnpj, String nomePessoaContato) {
        super(nome, email, telefone, endereco);
        this.cnpj = cnpj;
        this.nomePessoaContato = nomePessoaContato;
    }

    public String getCnpj() {
        return cnpj;
    }

    public void setNomePessoaContato(String nomePessoaContato) {
        this.nomePessoaContato = nomePessoaContato;
    }

    @Override
    public String getNomeContato() {
        return nomePessoaContato;
    }

    @Override
    public String getFormattedInfo() {
        return String.format("CNPJ: %s | Nome: %s | Telefone: %s | Pessoa para contato: %s | Endereco: %s",
                getCnpj(), getNome(), getTelefone(), getNomeContato(), getEndereco());
    }
}
