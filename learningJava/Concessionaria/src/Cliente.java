public class Cliente extends Pessoa {
    private boolean platinum = false;

    public Cliente(long cpf, String nome, long telefone, String email, boolean platinum) {
        super(cpf, nome, telefone, email);
        this.platinum = platinum;
    }

    public boolean isPlatinum() {
        return platinum;
    }

    public void setPlatinum(boolean platinum) {
        this.platinum = platinum;
    }
}
