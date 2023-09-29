import java.util.ArrayList;

public class Categoria {
    private final String nome;
    private ArrayList<Item> itens = new ArrayList<>();

    public Categoria(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void addItem(Item item){
        this.itens.add(item);
    }

    protected StringBuilder listaItens() {
        StringBuilder sb = new StringBuilder();

        sb.append("\nCategoria:" + this.nome);
        sb.append("\nItems -----------------");

        for (Item item : itens) {
            sb.append("\n");
            sb.append("\t" + item.getCodigo() + " - " + item.getTipo() + " - " + item.getPreco() + " - " + item.getDescricao());
        }

        return sb;
    }
}
