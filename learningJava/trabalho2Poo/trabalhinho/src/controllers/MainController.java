package controller;

import java.io.Serial;
import java.io.Serializable;
import persistence.Serializer;

public class MainController implements Serializable {
    @Serial
    private static final long serialVersionUID = 6341528978400871936L;

    private static MainController instance;

    private final ClienteController clienteController;
    private final CatalogoController catalogoController;
    private final ServicosController servicosController;

    private MainController() {
        // instanciar os demais controladores
        clienteController = new ClienteController();
        catalogoController = new CatalogoController();
        servicosController = new ServicosController();
    }

    public static MainController getInstance() {
        if (instance == null) {
            instance = new MainController();
        }
        return instance;
    }

    public static void load() {
        instance = Serializer.readFile();

        if (instance == null) {
            instance = new MainController();
        }
    }

    public static void save() {
        Serializer.writeFile(instance);
    }

    public static ClienteController getClienteController() {
        return getInstance().clienteController;
    }

    public static CatalogoController getCatalogoController() {
        return getInstance().catalogoController;
    }

    public static ServicosController getServicosController() {
        return getInstance().servicosController;
    }
}
