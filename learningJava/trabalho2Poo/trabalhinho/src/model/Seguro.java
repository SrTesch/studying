package model;

import java.io.Serial;
import java.io.Serializable;

public class Seguro implements Serializable {
    @Serial
    private static final long serialVersionUID = -944452354819066383L;

    private final String tipo;
    private final double percentualTarifa;

    public Seguro(String tipo, double percentualTarifa) {
        this.tipo = tipo;
        this.percentualTarifa = percentualTarifa;
    }

    public String getTipo() {
        return tipo;
    }

    public double getPercentualTarifa() {
        return percentualTarifa;
    }

    @Override
    public String toString() {
        return tipo;
    }
}
