package view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;

import javax.swing.*;
import javax.swing.border.EmptyBorder;

import controller.CatalogoController;
import controller.MainController;
import model.Categoria;

import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.io.Serial;
import java.io.Serializable;

public class SeguroView extends JFrame implements Serializable {

    @Serial
    private static final long serialVersionUID = 7830737240824488429L;

    private final JTextField textTipo;
    private final JTextField textPercTarifa;
    private final JComboBox<Categoria> comboBoxCategoria;

    public SeguroView() {
        setTitle("Seguro");
        setBounds(433, 164, 500, 500);
        JPanel contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        JPanel panel = new JPanel();
        contentPane.add(panel, BorderLayout.NORTH);

        JLabel lblNewLabel = new JLabel("Cadastrar Seguro");
        lblNewLabel.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
        lblNewLabel.setForeground(Color.BLUE); // Cor do título
        panel.add(lblNewLabel);

        JPanel panel_1 = new JPanel();
        contentPane.add(panel_1, BorderLayout.CENTER);
        GridBagLayout gbl_panel_1 = new GridBagLayout();
        gbl_panel_1.columnWidths = new int[] { 0, 0, 0, 0, 0, 0, 0, 0 };
        gbl_panel_1.rowHeights = new int[] { 0, 0, 0, 0, 0, 0, 0, 0 };
        gbl_panel_1.columnWeights = new double[] { 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, Double.MIN_VALUE };
        gbl_panel_1.rowWeights = new double[] { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE };
        panel_1.setLayout(gbl_panel_1);

        JLabel lblTipo = new JLabel("Tipo seguro:");
        lblTipo.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblTipo = new GridBagConstraints();
        gbc_lblTipo.anchor = GridBagConstraints.EAST;
        gbc_lblTipo.insets = new Insets(0, 0, 5, 5);
        gbc_lblTipo.gridx = 1;
        gbc_lblTipo.gridy = 2;
        panel_1.add(lblTipo, gbc_lblTipo);

        textTipo = new JTextField();
        GridBagConstraints gbc_textTipo = new GridBagConstraints();
        gbc_textTipo.insets = new Insets(0, 0, 5, 0);
        gbc_textTipo.gridwidth = 5;
        gbc_textTipo.fill = GridBagConstraints.HORIZONTAL;
        gbc_textTipo.gridx = 2;
        gbc_textTipo.gridy = 2;
        panel_1.add(textTipo, gbc_textTipo);
        textTipo.setColumns(10);

        JLabel lblPTarifa = new JLabel("Percentual Tarifa:");
        lblPTarifa.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblPTarifa = new GridBagConstraints();
        gbc_lblPTarifa.anchor = GridBagConstraints.EAST;
        gbc_lblPTarifa.insets = new Insets(0, 0, 5, 5);
        gbc_lblPTarifa.gridx = 1;
        gbc_lblPTarifa.gridy = 3;
        panel_1.add(lblPTarifa, gbc_lblPTarifa);

        textPercTarifa = new JTextField();
        GridBagConstraints gbc_textPercTarifa = new GridBagConstraints();
        gbc_textPercTarifa.insets = new Insets(0, 0, 5, 0);
        gbc_textPercTarifa.gridwidth = 5;
        gbc_textPercTarifa.fill = GridBagConstraints.HORIZONTAL;
        gbc_textPercTarifa.gridx = 2;
        gbc_textPercTarifa.gridy = 3;
        panel_1.add(textPercTarifa, gbc_textPercTarifa);
        textPercTarifa.setColumns(10);

        JLabel lblCategoria = new JLabel("Categoria");
        lblCategoria.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblCategoria = new GridBagConstraints();
        gbc_lblCategoria.insets = new Insets(0, 0, 0, 5);
        gbc_lblCategoria.anchor = GridBagConstraints.EAST;
        gbc_lblCategoria.gridx = 1;
        gbc_lblCategoria.gridy = 4;
        panel_1.add(lblCategoria, gbc_lblCategoria);

        comboBoxCategoria = new JComboBox<>(MainController.getCatalogoController().getDefaultComboBoxModelForCategoria());

        GridBagConstraints gbc_comboBoxCategoria = new GridBagConstraints();
        gbc_comboBoxCategoria.fill = GridBagConstraints.HORIZONTAL;
        gbc_comboBoxCategoria.gridx = 2;
        gbc_comboBoxCategoria.gridy = 4;
        panel_1.add(comboBoxCategoria, gbc_comboBoxCategoria);

        JButton btnSalvar = new JButton("Salvar");
        btnSalvar.addActionListener(this::actionSalvar);
        btnSalvar.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        btnSalvar.setBackground(Color.GREEN); // Cor de fundo do botão
        btnSalvar.setForeground(Color.WHITE); // Cor do texto do botão
        GridBagConstraints gbc_btnSalvar = new GridBagConstraints();
        gbc_btnSalvar.insets = new Insets(0, 0, 5, 0);
        gbc_btnSalvar.gridwidth = 8;
        gbc_btnSalvar.gridx = 0;
        gbc_btnSalvar.gridy = 6;
        panel_1.add(btnSalvar, gbc_btnSalvar);
    }

    private void actionSalvar(ActionEvent e) {
        CatalogoController catalogoController = MainController.getCatalogoController();
        String tipo = textTipo.getText();
        Categoria categoria = (Categoria) comboBoxCategoria.getSelectedItem();
        double percTarifa = Double.parseDouble(textPercTarifa.getText());
        catalogoController.addSeguro(categoria.getNome(), tipo, percTarifa);
        JOptionPane.showMessageDialog(this, "Cadastrado com Sucesso");
        this.dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            SeguroView seguroView = new SeguroView();
            seguroView.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            seguroView.setVisible(true);
        });
    }
}