package model;

import util.IFormatter;

import java.io.Serial;
import java.io.Serializable;

public class Veiculo implements Serializable, IFormatter {
    @Serial
    private static final long serialVersionUID = -9134452354339066383L;

    private final String placa;
    private final String anoFabricacao;
    private final String cor;
    private final Modelo modelo;
    private EStatusVeiculo status;
    private double quilometragem;
    private Categoria categoria;

    public Veiculo(String placa, String anoFabricacao, String cor, Modelo modelo) {
        this.placa = placa;
        this.anoFabricacao = anoFabricacao;
        this.cor = cor;
        this.modelo = modelo;
    }

    public Veiculo(String placa, String anoFabricacao, String cor, Modelo modelo, EStatusVeiculo status, double quilometragem) {
        this.placa = placa;
        this.anoFabricacao = anoFabricacao;
        this.cor = cor;
        this.modelo = modelo;
        this.status = status;
        this.quilometragem = quilometragem;
    }

    public String getPlaca() {
        return placa;
    }

    public String getAnoFabricacao() {
        return anoFabricacao;
    }

    public String getCor() {
        return cor;
    }

    public Modelo getModelo() {
        return modelo;
    }

    public EStatusVeiculo getStatus() {
        return status;
    }

    public void setStatus(EStatusVeiculo status) {
        this.status = status;
    }

    public double getQuilometragem() {
        return quilometragem;
    }

    public void setQuilometragem(double quilometragem) {
        this.quilometragem = quilometragem;
    }

    public void setCategoria(Categoria categoria) {
        this.categoria = categoria;
    }

    public Categoria getCategoria() {
        return categoria;
    }

    @Override
    public String getFormattedInfo() {
        return String.format("%s, %s, %s, %s, %s, %s", placa, modelo, cor,
                anoFabricacao, status, categoria);
    }

    @Override
    public String toString() {
        return placa;
    }
}
