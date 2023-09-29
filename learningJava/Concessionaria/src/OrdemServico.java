import java.util.ArrayList;
import java.util.Date;

public class OrdemServico {
    public static int contador = 0;
    private final int numero;
    private final Date data;
    private final int kmAtual;
    private String descricao;
    private final Cliente cliente;
    private final Veiculo veiculo;
    private Pagamento pagamento; // composição
    private ArrayList<ItemOS> itens = new ArrayList<>(); // composição

    public OrdemServico(int numero, Date data, int kmAtual, String descricao, Cliente cliente, Veiculo veiculo) {
        this.numero = numero;
        this.data = data;
        this.kmAtual = kmAtual;
        this.descricao = descricao;
        this.cliente = cliente;
        this.veiculo = veiculo;

        this.veiculo.novoServico(this);
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public int getNumero() {
        return numero;
    }

    public Date getData() {
        return data;
    }

    public int getKmAtual() {
        return kmAtual;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public Veiculo getVeiculo() {
        return veiculo;
    }

    public Pagamento getPagamento() {
        return pagamento;
    }

    public void setPagamento(Pagamento pagamento) {
        this.pagamento = pagamento;
    }

    public ArrayList<ItemOS> getItens() {
        return itens;
    }

    public void addItem(Item i, int qtde) {
        this.itens.add(new ItemOS(qtde, i.getPreco(), i));
    }

    public double getTotalOS() {

    }

    public double getTotalServicos() {

    }

    public double getTotalPecas() {

    }

    public StringBuilder listaOS() {

    }
}
