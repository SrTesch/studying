package model;

import util.IFormatter;

import java.io.Serial;
import java.io.Serializable;
import java.util.Date;

public class PessoaFisica extends Cliente implements Serializable, IFormatter {
    @Serial
    private static final long serialVersionUID = -9131152354819066384L;
    private final String cpf;
    private String numCNH;
    private Date validadeCNH;

    public PessoaFisica(String cpf) {
        super();
        this.cpf = cpf;
    }

    public PessoaFisica(String nome, String email, String telefone, Endereco endereco, String cpf, String numCNH, Date validadeCNH) {
        super(nome, email, telefone, endereco);
        this.cpf = cpf;
        this.numCNH = numCNH;
        this.validadeCNH = validadeCNH;
    }

    public String getCpf() {
        return cpf;
    }

    public String getNumCNH() {
        return numCNH;
    }

    public void setNumCNH(String numCNH) {
        this.numCNH = numCNH;
    }

    public Date getValidadeCNH() {
        return validadeCNH;
    }

    public void setValidadeCNH(Date validadeCNH) {
        this.validadeCNH = validadeCNH;
    }

    @Override
    public String getNomeContato() {
        return getNome();
    }

    @Override
    public String getFormattedInfo() {
        return String.format("CPF: %s | Nome: %s | Telefone: %s | Endereco: %s",
                getCpf(), getNome(), getTelefone(), getEndereco());
    }
}
