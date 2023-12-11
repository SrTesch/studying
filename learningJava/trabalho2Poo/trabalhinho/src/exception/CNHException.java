package exception;

import java.io.Serial;
import java.io.Serializable;

public class CNHException extends Exception implements Serializable {
    @Serial
    private static final long serialVersionUID = 9134452354819066383L;
    public CNHException(String message) {
        super(message);
    }
}
