package exception;

import java.io.Serial;
import java.io.Serializable;

public class ValidadeCNHException extends Exception implements Serializable {
    @Serial
    private static final long serialVersionUID = -9134452354819066380L;

    public ValidadeCNHException(String message) {
        super(message);
    }
}
