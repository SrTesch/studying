package tarefa3;

public class Funcionario extends Pessoa{
	private final int matricula;
	private boolean disponivel;
	
	public Funcionario(long cpf, String nome, long telefone, String email, int matricula, boolean disp) {
		super(cpf, nome, telefone, email);
		this.matricula = matricula;
		this.disponivel = disp;
	}
	
	public int getMatricula() {
		return matricula;
	}
	
	public boolean isDisponivel() {
		return disponivel;
	}
	public void setDisponivel(boolean disp) {
		this.disponivel = disp;
	}
}
