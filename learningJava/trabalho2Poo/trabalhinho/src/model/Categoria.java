package model;

import java.io.Serial;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Categoria implements Serializable {
    @Serial
    private static final long serialVersionUID = 1134452354819066383L;

    private final String nome;
    private double tarifaDiaria;
    private final List<Veiculo> veiculos = new ArrayList<>();
    private final List<Seguro> seguros = new ArrayList<>();

    public Categoria(String nome, double tarifaDiaria) {
        this.nome = nome;
        this.tarifaDiaria = tarifaDiaria;
    }

    public void setTarifaDiaria(double tarifaDiaria) {
        this.tarifaDiaria = tarifaDiaria;
    }

    public String getNome() {
        return nome;
    }

    public double getTarifaDiaria() {
        return tarifaDiaria;
    }

    public List<Veiculo> getVeiculos() {
        return veiculos;
    }

    public void addVeiculo(String placa, String anoFabricacao, String cor, Modelo modelo, EStatusVeiculo status, double quilometragem) {
        Veiculo veiculo = new Veiculo(placa, anoFabricacao, cor, modelo, status, quilometragem);
        veiculos.add(veiculo);
    }

    public void addVeiculo(Veiculo veiculo) {
        veiculos.add(veiculo);
    }

    public void removeVeiculo(Veiculo veiculo) {
        veiculos.remove(veiculo);
    }

    public void removeVeiculo(int index) {
        veiculos.remove(index);
    }

    public Veiculo getVeiculo(int index) {
        return veiculos.get(index);
    }

    public void addSeguro(Seguro seguro) {
        seguros.add(seguro);
    }

    public List<Seguro> getSeguros() {
        return seguros;
    }

    @Override
    public String toString() {
        return nome;
    }
}
