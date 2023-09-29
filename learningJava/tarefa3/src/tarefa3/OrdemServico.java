package tarefa3;
import java.util.Date;

public class OrdemServico {
	public static int contador = 0;
	private final int numero;
	private final Date data;
	private final int kmAtual;
	private String descricao;
	private final Veiculo veiculo;
	private Funcionario consultor;
	private final Cliente cliente;
	public OrdemServico(int numero, Date data, int kmAtual, String descricao, Veiculo veiculo, Funcionario consultor, Cliente cliente) {
		this.numero = numero;
		this.data = data;
		this.kmAtual = kmAtual;
		this.descricao = descricao;
		this.veiculo = veiculo;
		this.consultor = consultor;
		this.cliente = cliente;
	}
	public int getContador() {
		return contador;
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
	
	public String getDescricao() {
		return descricao;
	}
	
	public void setDescricao(String texto) {
		this.descricao = texto;
	}
	
	public Funcionario getConsultor() {
		return consultor;
	}
	
	public Veiculo getVeiculo() {
		return veiculo;
	}
	
	public Cliente getCliente() {
		return cliente;
	}
}
