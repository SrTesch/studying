package exception;

import java.io.Serial;
import java.io.Serializable;

public class CategoriaException extends Exception implements Serializable {
    @Serial
    private static final long serialVersionUID = 9130002354819066383L;

    public CategoriaException(String message) {
        super(message);
    }
}
