package tarefa3;
import java.util.ArrayList;

public class Veiculo {
	private final String placa;
	private final int ano;
	private String cor;
	private final Modelo modelo;
	private ArrayList<OrdemServico> servicos = new ArrayList<>();
	private Cliente proprietario;
	
	public Veiculo(String placa, int ano, String cor, Modelo modelo, Cliente prop) {
		this.placa = placa;
		this.ano = ano;
		this.cor = cor;
		this.modelo = modelo;
		this.proprietario = prop;
	}
	
	public String getPlaca() {
		return placa;
	}
	
	public int getAno() {
		return ano;
	}
	
	public String getCor() {
		return cor;
	}
	
	protected String getModelo() {
		return this.modelo.getNome();
	}
	
	public void newServico(OrdemServico servico) {
		this.servicos.add(servico);
	}
	
	public Cliente getProprietario() {
		return proprietario;
	}
	
	public void setPlatinumCliente(boolean plat) {
		this.proprietario.setPlatinum(plat);
	}
	
	public void setNomeCliente(String nome) {
		this.proprietario.setNome(nome);
	}
}
