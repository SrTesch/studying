package model;

import java.io.Serial;
import java.io.Serializable;
import java.util.Date;

public class Pagamento implements Serializable {
    @Serial
    private static final long serialVersionUID = -9134452354819066322L;

    private final EFormaPagamento forma;
    private final Date data;
    private final double valor;
    private final EMotivoPagamento motivo;
    private final String descricao;

    public Pagamento(EFormaPagamento forma, Date data, double valor, EMotivoPagamento motivo, String descricao) {
        this.forma = forma;
        this.data = data;
        this.valor = valor;
        this.motivo = motivo;
        this.descricao = descricao;
    }

    public EFormaPagamento getForma() {
        return forma;
    }

    public Date getData() {
        return data;
    }

    public double getValor() {
        return valor;
    }

    public EMotivoPagamento getMotivo() {
        return motivo;
    }

    public String getDescricao() {
        return descricao;
    }
}
