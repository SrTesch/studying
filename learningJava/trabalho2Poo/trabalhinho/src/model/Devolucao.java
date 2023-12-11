package model;

import java.io.Serial;
import java.io.Serializable;
import java.util.Date;

public class Devolucao implements Serializable {
    @Serial
    private static final long serialVersionUID = -7212899883439330664L;

    private final Date data;
    private final int km;
    private Pagamento pagamento;

    public Devolucao(int km, Pagamento pagamento) {
        this.data = new Date();
        this.km = km;
        this.pagamento = pagamento;
    }

    public Date getData() {
        return data;
    }

    public int getKm() {
        return km;
    }

    public Pagamento getPagamento() {
        return pagamento;
    }
}
