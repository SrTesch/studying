package exception;

import java.io.Serial;
import java.io.Serializable;

public class CPFException extends Exception implements Serializable {
    @Serial
    private static final long serialVersionUID = -9134452354819066333L;

    public CPFException(String message) {
        super(message);
    }
}
