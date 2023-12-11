package model;

import util.IFormatter;

import java.io.Serial;
import java.io.Serializable;
import java.util.*;

public class Reserva implements Serializable, IFormatter {
    @Serial
    private static final long serialVersionUID = 8251858530671683555L;

    private final UUID uuid;
    private final Categoria categoria;
    private final Date inicioLocacao;
    private final Date finalLocacao;
    private final double valorTarifa;
    private final int periodoLocacao;

    private final List<Seguro> seguros = new ArrayList<>();

    private final Cliente cliente;

    public Reserva(UUID uuid,Categoria categoria, Date inicioLocacao, Date finalLocacao,Cliente cliente) {
        this.uuid = uuid;
        this.categoria = categoria;
        this.inicioLocacao = inicioLocacao;
        this.finalLocacao = finalLocacao;

        periodoLocacao = (int) ((finalLocacao.getTime() - inicioLocacao.getTime()) / (1000 * 60 * 60 * 24));

        this.valorTarifa = categoria.getTarifaDiaria() * periodoLocacao;
        this.cliente = cliente;
    }

    public int getPeridoLocacao() {
        int periodoLocacao;
        periodoLocacao = (int) ((finalLocacao.getTime() - inicioLocacao.getTime()) / (1000 * 60 * 60 * 24));
        return periodoLocacao;
    }

    public void addSeguro(Seguro seguro) {
        seguros.add(seguro);
    }

    public void removeSeguro(Seguro seguro) {
        seguros.remove(seguro);
    }

    public UUID getUuid() {
        return uuid;
    }

    public Categoria getCategoria() {
        return categoria;
    }

    public Date getInicioLocacao() {
        return inicioLocacao;
    }

    public Date getFinalLocacao() {
        return finalLocacao;
    }

    public double getValorTarifa() {
        return valorTarifa;
    }

    public List<Seguro> getSeguros() {
        return seguros;
    }

    public Cliente getCliente() {
        return cliente;
    }

    @Override
    public String getFormattedInfo() {
        return String.format("%s, %s, %s, %s", uuid, categoria,
                inicioLocacao, finalLocacao);
    }

    @Override
    public String toString(){
        return getUuid().toString();
    }

}
