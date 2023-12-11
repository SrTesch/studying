import java.awt.EventQueue;
import javax.swing.UnsupportedLookAndFeelException;
import controller.MainController;
import view.MainView;

public class Main {
    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            try {
                loadLooks();
                MainController.load();
                MainView frame = new MainView();
                frame.setVisible(true);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    private static void loadLooks() throws UnsupportedLookAndFeelException, ClassNotFoundException, InstantiationException, IllegalAccessException {
        for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
            if ("Nimbus".equals(info.getName())) {
                javax.swing.UIManager.setLookAndFeel(info.getClassName());
                break;
            }
        }
    }
}
