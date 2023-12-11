package util;

import exception.CNHException;
import exception.CPFException;
import exception.EmailException;
import exception.ValidadeCNHException;

import java.util.Date;
import java.util.regex.Pattern;

public class ClienteValidator {
    public static void validateCPF(String cpf) throws CPFException {
        if (cpf.length() != 11) {
            throw new CPFException("CPF Invalido");
        }
    }

    public static void validateEmail(String email) throws EmailException {
        var regexPattern = "^(.+)@(\\S+)$";
        var doesMatch = Pattern.compile(regexPattern).matcher(email).matches();
        if (!doesMatch) {
            throw new EmailException("Email invalido");
        }
    }

    public static void validateCNH(String cnh) throws CNHException {
        if (cnh.length() != 12) {
            throw new CNHException("CNH invalido");
        }
    }

    public static void validateValidadeCNH(Date validadeCNH) throws ValidadeCNHException {
        Date today = new Date();
        if (validadeCNH.before(today)) {
            throw new ValidadeCNHException("CNH expirado");
        }
    }
}
