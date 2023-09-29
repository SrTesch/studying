import java.util.ArrayList;

public class Veiculo {
    private final String placa;
    private final int ano;
    private String cor;
    private final Modelo modelo;
    private ArrayList<OrdemServico> servicos = new ArrayList<>();

    public Veiculo(String placa, int ano, String cor, Modelo modelo) {
        this.placa = placa;
        this.ano = ano;
        this.cor = cor;
        this.modelo = modelo;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public void novoServico(OrdemServico servico) {
        this.servicos.add(servico);
    }

    protected String getModelo() {
        return this.modelo.getNome();
    }
}
