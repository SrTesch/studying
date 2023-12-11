package util;

import exception.CEPException;
import exception.NumeroEnderecoException;
import exception.RuaException;

public class EnderecoValidator {
    public static void validateRua(String rua) throws RuaException {
        if (rua.matches(".*\\d.*")) {
            throw new RuaException("Nome de rua invalido");
        }
    }

    public static void validateNumero(String numero) throws NumeroEnderecoException {
        try {
            Integer.parseInt(numero);
        } catch (Exception e) {
            throw new NumeroEnderecoException("Numero da rua invalido");
        }
    }

    public static void validateCEP(String cep) throws CEPException {
        try {
            Integer.parseInt(cep);
        } catch (Exception e) {
            throw new CEPException("CEP invalido");
        }

        if (cep.length() != 8) {
            throw new CEPException("CEP invalido");
        }
    }
}
