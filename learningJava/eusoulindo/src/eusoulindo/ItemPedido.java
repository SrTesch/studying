package eusoulindo;

public class ItemPedido {
    private int quantidade;
    private final Produto produto;

    public ItemPedido(Produto produto, int quantidade) {
        super();
        this.quantidade = quantidade;
        this.produto = produto;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public Produto getProduto() {
        return produto;
    }
}
