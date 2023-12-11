package model;

import util.IFormatter;

import java.io.Serial;
import java.io.Serializable;
import java.util.Date;
import java.util.List;

public class Locacao implements Serializable, IFormatter {
    @Serial
    private static final long serialVersionUID = 4995870241515199121L;

    private final Reserva reserva;
    private Veiculo veiculo;
    private final Date data;
    private final int km;
    private Devolucao devolucao;

    public Locacao(Reserva reserva, Veiculo veiculo, int km) {
        this.reserva = reserva;
        this.veiculo = veiculo;
        this.data = new Date();
        this.km = km;
    }

    public double totalDiarias() {
        double valorTotal = 0;
        valorTotal += reserva.getValorTarifa();
        return valorTotal;
    }

    public double totalSeguros() {
        double valorTotal = 0;
        double valorTarifaDiaria = reserva.getCategoria().getTarifaDiaria();
        int periodoLocacao = reserva.getPeridoLocacao();
        List<Seguro> seguros = reserva.getSeguros();

        for (Seguro seguro : seguros) {
            valorTotal += periodoLocacao * seguro.getPercentualTarifa() * valorTarifaDiaria;
        }

        return valorTotal;
    }

    public StringBuilder listar() {
        StringBuilder sb = new StringBuilder();

        sb.append("Km: ").append(getKm()).append(" Data: ").append(getData()).append(" Veiculo: ")
                .append(getVeiculo()).append(getVeiculo().getCor())
                .append(getVeiculo().getModelo()).append(getVeiculo().getPlaca());
        sb.append("\n");

        sb.append("Cliente: ").append(reserva.getCliente().getNomeContato() + ' ').append(" Telefone: ")
                .append(reserva.getCliente().getTelefone() + ' ').append(" Cep Endereco: ")
                .append(reserva.getCliente().getEndereco().getRua() + ' ').append(" Email: ")
                .append(reserva.getCliente().getEmail() + ' ');
        sb.append("\n");

        List<Seguro> seguros = reserva.getSeguros();

        sb.append("\n");

        sb.append("Seguros: ");
        for (Seguro seguro : seguros) {
            sb.append(" Nome do Seguro: ").append(seguro.getTipo()).append(" Percentual de Tarifa: ")
                    .append(seguro.getPercentualTarifa()).append(" Cobertura: ");

        }
        sb.append("\n");
        sb.append("\n");
        return sb;

    }

    public Veiculo getVeiculo() {
        return veiculo;
    }

    public void setVeiculo(Veiculo veiculo) {
        this.veiculo = veiculo;
    }

    public Date getData() {
        return data;
    }

    public long getKm() {
        return km;
    }

    public Reserva getReserva() {
        return reserva;
    }

    public Devolucao getDevolucao() {
        return devolucao;
    }

    public void setDevolucao(Devolucao devolucao) {
        this.devolucao = devolucao;
    }

    @Override
    public String getFormattedInfo() {
        return String.format("%s, %s, %s, %s", reserva, veiculo, data, km);
    }

    @Override
    public String toString() {
        return "locacao: " + reserva.toString();
    }
}
