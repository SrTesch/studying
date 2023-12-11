package controller;

import java.io.Serial;
import java.io.Serializable;
import java.util.*;
import javax.swing.ComboBoxModel;
import javax.swing.DefaultComboBoxModel;
import model.*;

public class ServicosController implements Serializable {
    @Serial
    private static final long serialVersionUID = 5453432785989660583L;

    private static int devolucoesKey = 0;

    private final Map<UUID, Reserva> reservas;
    private final Map<UUID, Locacao> locacoes;
    private final Map<Integer, Devolucao> devolucoes;

    public ServicosController() {
        reservas = new TreeMap<>();
        locacoes = new TreeMap<>();
        devolucoes = new TreeMap<>();
    }

    public void addReserva(Categoria categoria, Date inicioLocacao, Date finalLocacao, Cliente cliente, List<Seguro> seguros) {
        UUID uuid = UUID.randomUUID();
        Reserva reserva = new Reserva(uuid, categoria, inicioLocacao, finalLocacao, cliente);
        reserva.addSeguros(seguros);
        reservas.put(reserva.getUuid(), reserva);
        MainController.save();
    }

    public void addLocacao(String reservaUUID, Veiculo veiculo, int km) {
        UUID key = UUID.fromString(reservaUUID);
        Reserva reserva = reservas.get(key);
        Locacao locacao = new Locacao(reserva, veiculo, km);
        locacoes.put(key, locacao);
        MainController.save();
    }

    public Locacao getLocacao(String uuid) {
        UUID key = UUID.fromString(uuid);
        return locacoes.get(key);
    }

    public void addDevolucao(Locacao locacao, int km, Pagamento pagamento) {
        Devolucao devolucao = new Devolucao(km, pagamento);
        locacao.setDevolucao(devolucao);
        devolucoes.put(devolucoesKey, devolucao);
        devolucoesKey++;
        MainController.save();
    }

    public ComboBoxModel<String> getDefaultComboBoxModelForReservas() {
        DefaultComboBoxModel<String> model = new DefaultComboBoxModel<>(reservas.keySet().stream().map(UUID::toString).toArray(String[]::new));
        return model;
    }

    public DefaultComboBoxModel<Locacao> getDefaultComboBoxModelForLocacoes() {
        DefaultComboBoxModel<Locacao> model = new DefaultComboBoxModel<>(locacoes.values().toArray(new Locacao[0]));
        return model;
    }

    public double getTotalDiarias(Locacao locacao) {
        Date inicio = locacao.getReserva().getInicioLocacao();
        Date fim = locacao.getReserva().getFinalLocacao();
        int periodoLocacao = (int) ((fim.getTime() - inicio.getTime()) / (1000 * 60 * 60 * 24));
        return periodoLocacao * locacao.getReserva().getValorTarifa();
    }

    public double getTotalLocacao(Locacao locacao) {
        double valorTotal = locacao.getReserva().getValorTarifa();
        double valorTarifaDiaria = locacao.getReserva().getCategoria().getTarifaDiaria();
        int periodoLocacao = locacao.getReserva().getPeridoLocacao();
        List<Seguro> seguros = locacao.getReserva().getSeguros();

        for (Seguro seguro : seguros) {
            valorTotal += periodoLocacao * seguro.getPercentualTarifa() * valorTarifaDiaria;
        }

        return valorTotal;
    }

    public double getTotalSeguros(Locacao locacao) {
        double valorTarifaDiaria = locacao.getReserva().getCategoria().getTarifaDiaria();
        int periodoLocacao = locacao.getReserva().getPeridoLocacao();
        List<Seguro> seguros = locacao.getReserva().getSeguros();
        return seguros.stream().mapToDouble(seguro -> periodoLocacao * seguro.getPercentualTarifa() * valorTarifaDiaria).sum();
    }

    public List<String> getListaFormatedReservas() {
        return formatReservaList(reservas.values());
    }

    public List<String> getListaFormatedLocacoes() {
        return formatLocacaoList(locacoes.values());
    }

    public Reserva getReservaByUUID(String reservaUUID) {
        UUID key = UUID.fromString(reservaUUID);
        return reservas.get(key);
    }

    private List<String> formatReservaList(Collection<Reserva> reservas) {
        return reservas.stream().map(Reserva::getFormattedInfo).toList();
    }

    private List<String> formatLocacaoList(Collection<Locacao> locacoes) {
        return locacoes.stream().map(Locacao::getFormattedInfo).toList();
    }
}
