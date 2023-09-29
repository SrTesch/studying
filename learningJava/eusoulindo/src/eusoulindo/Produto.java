package eusoulindo;
public class Produto {
    private final long codBarras;
    private final String nome;
    private double preco;

    public Produto(long codBarras, String nome, double preco) {
        this.codBarras = codBarras;
        this.nome = nome;
        this.preco = preco;
    }

    public long getCodBarras() {
        return codBarras;
    }

    public String getNome() {
        return nome;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }
}
