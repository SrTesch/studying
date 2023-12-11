package exception;

import java.io.Serial;
import java.io.Serializable;

public class EmailException extends Exception implements Serializable {
    @Serial
    private static final long serialVersionUID = -9134452354819066310L;

    public EmailException(String message) {
        super(message);
    }
}
