package eusoulindo;
import java.util.ArrayList;
import java.util.Date;

public class Pedido {
    private int numPedidos = 0;
    private final int numero;
    private final Date data;
    private ArrayList<ItemPedido> itens = new ArrayList<>();
    private final Cliente cliente;

    public Pedido(Cliente cliente) {
        this.numero = ++numPedidos;
        this.cliente = cliente;
        this.data = new Date();
    }

    public Cliente getCliente() {
        return cliente;
    }

    public Date getData() {
        return data;
    }

    public int getNumero() {
        return numero;
    }

    public int getNumPedidos() {
        return numPedidos;
    }

    public double getTotal() {
        double total = 0;
        for (ItemPedido item : itens) {
            total += item.getQuantidade() * item.getProduto().getPreco();
        }

        return total;
    }

    public String listar() {
        StringBuilder sb = new StringBuilder();

        sb.append("\nNumero Pedido: ").append(getNumero());
        sb.append("\nCliente: ").append(getCliente().getCpf()).append(" - ").append(getCliente().getNome());

        sb.append("\nItems --------------");
        for (ItemPedido item : itens) {
            sb.append("\n");
            sb.append("\t").append(item.getProduto().getCodBarras());
            sb.append("\t").append(item.getProduto().getNome());
            sb.append("\t").append(item.getQuantidade());
            sb.append("\t").append(item.getProduto().getPreco());
        }

        sb.append("\n TOTAL: R$ ").append(getTotal());

        return sb.toString();
    }

    public void removeItem(int index){
        itens.remove(index);
    }

    public void addItem(Produto produto, int quantidade) {
        itens.add(new ItemPedido(produto, quantidade));
    }
}
