package view;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowEvent;
import java.io.Serial;
import java.io.Serializable;

import controller.CatalogoController;
import controller.MainController;

public class CategoriaView extends JFrame implements Serializable {
    @Serial
    private static final long serialVersionUID = -5659880888694503154L;

    private final JTextField textNome;
    private final JTextField textTarifaDiaria;

    public CategoriaView() {
        initializeUI();
    }

    private void initializeUI() {
        setTitle("Categoria");
        setBounds(433, 164, 500, 500);
        JPanel contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        JPanel panel = createHeaderPanel();
        contentPane.add(panel, BorderLayout.NORTH);

        JPanel panel_1 = createMainPanel();
        contentPane.add(panel_1, BorderLayout.CENTER);
    }

    private JPanel createHeaderPanel() {
        JPanel panel = new JPanel();
        panel.setBackground(new Color(105, 105, 105));
        JLabel lblNewLabel = new JLabel("Adicionar Categoria");
        lblNewLabel.setForeground(Color.WHITE);
        lblNewLabel.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
        panel.add(lblNewLabel);
        return panel;
    }

    private JPanel createMainPanel() {
        JPanel panel_1 = new JPanel();
        panel_1.setBackground(new Color(240, 240, 240));
        GridBagLayout gbl_panel_1 = new GridBagLayout();
        gbl_panel_1.columnWidths = new int[]{0, 0, 0, 0};
        gbl_panel_1.rowHeights = new int[]{0, 0, 0, 0, 0, 0, 0, 0};
        gbl_panel_1.columnWeights = new double[]{0.0, 1.0, 1.0, Double.MIN_VALUE};
        gbl_panel_1.rowWeights = new double[]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, Double.MIN_VALUE};
        panel_1.setLayout(gbl_panel_1);

        GridBagConstraints gbc_nome = createLabelAndTextField("Nome:", 1);
        panel_1.add(gbc_nome.label, gbc_nome.constraints);
        panel_1.add(gbc_nome.textField, gbc_nome.textConstraints);

        GridBagConstraints gbc_tarifa = createLabelAndTextField("Tarifa Diaria:", 3);
        panel_1.add(gbc_tarifa.label, gbc_tarifa.constraints);
        panel_1.add(gbc_tarifa.textField, gbc_tarifa.textConstraints);

        JButton btnSalvar = createSalvarButton();
        GridBagConstraints gbc_btnSalvar = new GridBagConstraints();
        gbc_btnSalvar.insets = new Insets(0, 0, 5, 0);
        gbc_btnSalvar.gridx = 2;
        gbc_btnSalvar.gridy = 4;
        panel_1.add(btnSalvar, gbc_btnSalvar);

        return panel_1;
    }

    private GridBagConstraints createLabelAndTextField(String labelText, int gridY) {
        JLabel label = new JLabel(labelText);
        label.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));

        JTextField textField = new JTextField();
        GridBagConstraints gbc_label = new GridBagConstraints();
        gbc_label.insets = new Insets(0, 0, 5, 5);
        gbc_label.anchor = GridBagConstraints.EAST;
        gbc_label.gridx = 1;
        gbc_label.gridy = gridY;

        GridBagConstraints gbc_textField = new GridBagConstraints();
        gbc_textField.insets = new Insets(0, 0, 5, 0);
        gbc_textField.fill = GridBagConstraints.HORIZONTAL;
        gbc_textField.gridx = 2;
        gbc_textField.gridy = gridY;
        textField.setColumns(10);

        return new GridBagConstraintsWrapper(label, gbc_label, textField, gbc_textField);
    }

    private JButton createSalvarButton() {
        JButton btnSalvar = new JButton("SALVAR");
        btnSalvar.setBackground(Color.LIGHT_GRAY);
        btnSalvar.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));
        btnSalvar.addActionListener(e -> actionSalvar());
        return btnSalvar;
    }

    protected void actionSalvar() {
        CatalogoController catalogoController = MainController.getCatalogoController();

        String nome = textNome.getText();
        double tarifaDiaria;

        try {
            tarifaDiaria = Double.parseDouble(textTarifaDiaria.getText());
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Por favor, insira um valor válido para a tarifa diária.", "Erro", JOptionPane.ERROR_MESSAGE);
            return;
        }

        catalogoController.addCategoria(nome, tarifaDiaria);
        JOptionPane.showMessageDialog(this, "Cadastrado com Sucesso");
        this.dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
    }

    private static class GridBagConstraintsWrapper {
        final JLabel label;
        final GridBagConstraints constraints;
        final JTextField textField;
        final GridBagConstraints textConstraints;

        public GridBagConstraintsWrapper(JLabel label, GridBagConstraints constraints, JTextField textField, GridBagConstraints textConstraints) {
            this.label = label;
            this.constraints = constraints;
            this.textField = textField;
            this.textConstraints = textConstraints;
        }
    }
}