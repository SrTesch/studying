package tarefa3;

public class Cliente extends Pessoa{
	private boolean platinum = false;
	
	public Cliente(long cpf, String nome, long telefone, String email, boolean plat) {
		super(cpf, nome, telefone, email);
		this.platinum = plat;
	}
	
	public boolean isPlatinum() {
		return platinum;
	}
	
	public void setPlatinum(boolean plat) {
		this.platinum = plat;
	}
}
