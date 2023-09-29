public class Item {
    private final ETipoItem tipo;
    private final long codigo;
    private final String descricao;
    private double preco;

    public Item(ETipoItem tipo, long codigo, String descricao, double preco) {
        this.tipo = tipo;
        this.codigo = codigo;
        this.descricao = descricao;
        this.preco = preco;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public ETipoItem getTipo() {
        return tipo;
    }

    public long getCodigo() {
        return codigo;
    }

    public String getDescricao() {
        return descricao;
    }
}
