package controller;

import exception.*;
import model.*;
import util.ClienteValidator;
import util.EnderecoValidator;

import javax.swing.*;
import java.io.Serial;
import java.io.Serializable;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class ClienteController implements Serializable {
    @Serial
    private static final long serialVersionUID = -8994132440460635970L;

    private final Map<String, PessoaFisica> pessoasF;
    private final Map<String, PessoaJuridica> pessoasJ;

    public ClienteController() {
        pessoasF = new TreeMap<>();
        pessoasJ = new TreeMap<>();
    }

    public void addPessoaFisica(String nome, String email, String telefone, String cpf,
                                String numCNH, String validadeCNH, String rua, String numero, String cep)
            throws CNHException, CPFException, EmailException, ValidadeCNHException, CEPException,
            NumeroEnderecoException, RuaException {
        try {
            Date dateValidadeCNH = new SimpleDateFormat("dd/MM/yyyy").parse(validadeCNH);
            ClienteValidator.validateCNH(numCNH);
            ClienteValidator.validateCPF(cpf);
            ClienteValidator.validateEmail(email);
            ClienteValidator.validateValidadeCNH(dateValidadeCNH);
            EnderecoValidator.validateRua(rua);
            EnderecoValidator.validateNumero(numero);
            EnderecoValidator.validateCEP(cep);

            var endereco = new Endereco(rua, numero, cep);
            var cliente = new PessoaFisica(nome, email, telefone, endereco, cpf, numCNH, dateValidadeCNH);
            pessoasF.put(cpf, cliente);
            MainController.save();
        } catch (ParseException e) {
            throw new ValidadeCNHException("Erro ao converter a data");
        }
    }

    public void addPessoaJuridica(String nome, String email, String telefone, String cnpj,
                                  String nomePessoaContato, String rua, String numero, String cep)
            throws EmailException, NumeroEnderecoException, CEPException, RuaException {
        ClienteValidator.validateEmail(email);
        EnderecoValidator.validateCEP(cep);
        EnderecoValidator.validateRua(rua);
        EnderecoValidator.validateNumero(numero);

        var endereco = new Endereco(rua, numero, cep);
        var cliente = new PessoaJuridica(nome, email, telefone, endereco, cnpj, nomePessoaContato);
        pessoasJ.put(cnpj, cliente);
        MainController.save();
    }

    public Set<String> getListaPessoasF() {
        return pessoasF.keySet();
    }

    public Set<String> getListaPessoasJ() {
        return pessoasJ.keySet();
    }

    public List<String> getListaFormatedPessoasF() {
        return formatClienteList(pessoasF.values());
    }

    public List<String> getListaFormatedPessoasJ() {
        return formatClienteList(pessoasJ.values());
    }

    private List<String> formatClienteList(Collection<? extends Cliente> clientes) {
        List<String> lista = new ArrayList<>();
        for (Cliente cliente : clientes) {
            lista.add(cliente.getFormattedInfo());
        }
        return lista;
    }

    public DefaultComboBoxModel<Cliente> getDefaultComboBoxModelForCliente() {
        DefaultComboBoxModel<Cliente> model = new DefaultComboBoxModel<>();
        pessoasF.values().forEach(model::addElement);
        pessoasJ.values().forEach(model::addElement);
        return model;
    }
}
