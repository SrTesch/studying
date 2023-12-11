package view;

import java.awt.BorderLayout;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import controller.CatalogoController;
import controller.MainController;
import exception.CategoriaException;
import model.Categoria;
import model.Cliente;
import model.EStatusVeiculo;

import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Font;
import javax.swing.JTextField;
import java.awt.Insets;

import javax.swing.JComboBox;
import javax.swing.JButton;
import java.awt.event.WindowEvent;
import java.io.Serial;
import java.io.Serializable;

public class VeiculoView extends JFrame implements Serializable {
    @Serial
    private static final long serialVersionUID = 3843837048162952463L;

    private final JTextField textPlaca;
    private final JTextField textCor;
    private final JTextField textAno;
    private final JTextField textKm;
    private final JComboBox<EStatusVeiculo> comboBoxStatusVeiculo;
    private final JTextField textModelo;
    private final JTextField textAnoModelo;
    private final JTextField textFabricanteModelo;
    private final JComboBox<Categoria> comboBoxCategoria;

    public VeiculoView() {
        setTitle("Veiculo");
        setBounds(433, 164, 500, 500);
        JPanel contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        JPanel panel = new JPanel();
        contentPane.add(panel, BorderLayout.NORTH);

        JLabel lblNewLabel = new JLabel("Cadastrar Veiculo");
        lblNewLabel.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
        panel.add(lblNewLabel);

        JPanel panel_1 = new JPanel();
        contentPane.add(panel_1, BorderLayout.CENTER);
        GridBagLayout gbl_panel_1 = new GridBagLayout();
        gbl_panel_1.columnWidths = new int[] { 0, 0, 0, 0 };
        gbl_panel_1.rowHeights = new int[] { 0, 0, 0, 0, 0, 0, 0, 0 };
        gbl_panel_1.columnWeights = new double[] { 0.0, 0.0, 1.0, Double.MIN_VALUE };
        gbl_panel_1.rowWeights = new double[] { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE };
        panel_1.setLayout(gbl_panel_1);

        JLabel lblPlaca = new JLabel("Placa:");
        lblPlaca.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblPlaca = new GridBagConstraints();
        gbc_lblPlaca.insets = new Insets(0, 0, 5, 5);
        gbc_lblPlaca.anchor = GridBagConstraints.EAST;
        gbc_lblPlaca.gridx = 1;
        gbc_lblPlaca.gridy = 0;
        panel_1.add(lblPlaca, gbc_lblPlaca);

        textPlaca = new JTextField();
        GridBagConstraints gbc_textPlaca = new GridBagConstraints();
        gbc_textPlaca.insets = new Insets(0, 0, 5, 0);
        gbc_textPlaca.fill = GridBagConstraints.HORIZONTAL;
        gbc_textPlaca.gridx = 2;
        gbc_textPlaca.gridy = 0;
        panel_1.add(textPlaca, gbc_textPlaca);
        textPlaca.setColumns(10);

        JLabel lblCor = new JLabel("Cor:");
        lblCor.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblCor = new GridBagConstraints();
        gbc_lblCor.anchor = GridBagConstraints.EAST;
        gbc_lblCor.insets = new Insets(0, 0, 5, 5);
        gbc_lblCor.gridx = 1;
        gbc_lblCor.gridy = 2;
        panel_1.add(lblCor, gbc_lblCor);

        textCor = new JTextField();
        GridBagConstraints gbc_textCor = new GridBagConstraints();
        gbc_textCor.insets = new Insets(0, 0, 5, 0);
        gbc_textCor.fill = GridBagConstraints.HORIZONTAL;
        gbc_textCor.gridx = 2;
        gbc_textCor.gridy = 2;
        panel_1.add(textCor, gbc_textCor);
        textCor.setColumns(10);

        JLabel lblAno = new JLabel("Ano:");
        lblAno.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblAno = new GridBagConstraints();
        gbc_lblAno.anchor = GridBagConstraints.EAST;
        gbc_lblAno.insets = new Insets(0, 0, 5, 5);
        gbc_lblAno.gridx = 1;
        gbc_lblAno.gridy = 3;
        panel_1.add(lblAno, gbc_lblAno);

        textAno = new JTextField();
        GridBagConstraints gbc_textAno = new GridBagConstraints();
        gbc_textAno.insets = new Insets(0, 0, 5, 0);
        gbc_textAno.fill = GridBagConstraints.HORIZONTAL;
        gbc_textAno.gridx = 2;
        gbc_textAno.gridy = 3;
        panel_1.add(textAno, gbc_textAno);
        textAno.setColumns(10);

        JLabel lblKm = new JLabel("Quilometragem:");
        lblKm.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblKm = new GridBagConstraints();
        gbc_lblKm.anchor = GridBagConstraints.EAST;
        gbc_lblKm.insets = new Insets(0, 0, 5, 5);
        gbc_lblKm.gridx = 1;
        gbc_lblKm.gridy = 4;
        panel_1.add(lblKm, gbc_lblKm);

        textKm = new JTextField();
        GridBagConstraints gbc_textKm = new GridBagConstraints();
        gbc_textKm.insets = new Insets(0, 0, 5, 0);
        gbc_textKm.fill = GridBagConstraints.HORIZONTAL;
        gbc_textKm.gridx = 2;
        gbc_textKm.gridy = 4;
        panel_1.add(textKm, gbc_textKm);
        textKm.setColumns(10);

        JLabel lblStatus = new JLabel("Status:");
        lblStatus.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblStatus = new GridBagConstraints();
        gbc_lblStatus.anchor = GridBagConstraints.EAST;
        gbc_lblStatus.insets = new Insets(0, 0, 5, 5);
        gbc_lblStatus.gridx = 1;
        gbc_lblStatus.gridy = 5;
        panel_1.add(lblStatus, gbc_lblStatus);

        comboBoxStatusVeiculo = new JComboBox<>(EStatusVeiculo.values());
        GridBagConstraints gbc_comboBox = new GridBagConstraints();
        gbc_comboBox.insets = new Insets(0, 0, 5, 0);
        gbc_comboBox.fill = GridBagConstraints.HORIZONTAL;
        gbc_comboBox.gridx = 2;
        gbc_comboBox.gridy = 5;
        panel_1.add(comboBoxStatusVeiculo, gbc_comboBox);

        JLabel lblModelo = new JLabel("Nome modelo:");
        lblModelo.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblModelo = new GridBagConstraints();
        gbc_lblModelo.anchor = GridBagConstraints.EAST;
        gbc_lblModelo.insets = new Insets(0, 0, 5, 5);
        gbc_lblModelo.gridx = 1;
        gbc_lblModelo.gridy = 6;
        panel_1.add(lblModelo, gbc_lblModelo);

        textModelo = new JTextField();
        GridBagConstraints gbc_textModelo = new GridBagConstraints();
        gbc_textModelo.insets = new Insets(0, 0, 5, 0);
        gbc_textModelo.fill = GridBagConstraints.HORIZONTAL;
        gbc_textModelo.gridx = 2;
        gbc_textModelo.gridy = 6;
        panel_1.add(textModelo, gbc_textModelo);
        textModelo.setColumns(10);

        JLabel lblAnoModelo = new JLabel("Ano modelo:");
        lblAnoModelo.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblAnoModelo = new GridBagConstraints();
        gbc_lblAnoModelo.anchor = GridBagConstraints.EAST;
        gbc_lblAnoModelo.insets = new Insets(0, 0, 5, 5);
        gbc_lblAnoModelo.gridx = 1;
        gbc_lblAnoModelo.gridy = 7;
        panel_1.add(lblAnoModelo, gbc_lblAnoModelo);

        textAnoModelo = new JTextField();
        GridBagConstraints gbc_textAnoModelo = new GridBagConstraints();
        gbc_textAnoModelo.insets = new Insets(0, 0, 5, 0);
        gbc_textAnoModelo.fill = GridBagConstraints.HORIZONTAL;
        gbc_textAnoModelo.gridx = 2;
        gbc_textAnoModelo.gridy = 7;
        panel_1.add(textAnoModelo, gbc_textAnoModelo);
        textAnoModelo.setColumns(10);


        JLabel lblFabricanteModelo = new JLabel("Fabricante modelo:");
        lblFabricanteModelo.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblFabricanteModelo = new GridBagConstraints();
        gbc_lblFabricanteModelo.anchor = GridBagConstraints.EAST;
        gbc_lblFabricanteModelo.insets = new Insets(0, 0, 5, 5);
        gbc_lblFabricanteModelo.gridx = 1;
        gbc_lblFabricanteModelo.gridy = 8;
        panel_1.add(lblFabricanteModelo, gbc_lblFabricanteModelo);

        textFabricanteModelo = new JTextField();
        GridBagConstraints gbc_textFabricanteModelo = new GridBagConstraints();
        gbc_textFabricanteModelo.insets = new Insets(0, 0, 5, 0);
        gbc_textFabricanteModelo.fill = GridBagConstraints.HORIZONTAL;
        gbc_textFabricanteModelo.gridx = 2;
        gbc_textFabricanteModelo.gridy = 8;
        panel_1.add(textFabricanteModelo, gbc_textFabricanteModelo);
        textFabricanteModelo.setColumns(10);

        JLabel lblCategoria = new JLabel("Categoria");
        lblCategoria.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblCategoria = new GridBagConstraints();
        gbc_lblCategoria.insets = new Insets(0, 0, 0, 5);
        gbc_lblCategoria.anchor = GridBagConstraints.EAST;
        gbc_lblCategoria.gridx = 1;
        gbc_lblCategoria.gridy = 9;
        panel_1.add(lblCategoria, gbc_lblCategoria);

        comboBoxCategoria = new JComboBox<>(MainController.getCatalogoController().getDefaultComboBoxModelForCategoria());

        GridBagConstraints gbc_comboBoxCategoria = new GridBagConstraints();
        gbc_comboBoxCategoria.fill = GridBagConstraints.HORIZONTAL;
        gbc_comboBoxCategoria.gridx = 2;
        gbc_comboBoxCategoria.gridy = 9;
        panel_1.add(comboBoxCategoria, gbc_comboBoxCategoria);

        JButton btnSalvar = new JButton("Salvar");
        btnSalvar.addActionListener(e -> actionSalvar());
        btnSalvar.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        GridBagConstraints gbc_btnSalvar = new GridBagConstraints();
        gbc_btnSalvar.insets = new Insets(0, 0, 5, 0);
        gbc_btnSalvar.gridx = 2;
        gbc_btnSalvar.gridy = 10;
        panel_1.add(btnSalvar, gbc_btnSalvar);
    }

    protected void actionSalvar() {
        try {
            CatalogoController catalogoController = MainController.getCatalogoController();
            String placa = textPlaca.getText();
            String cor = textCor.getText();
            String ano = textAno.getText();
            EStatusVeiculo status = (EStatusVeiculo) comboBoxStatusVeiculo.getSelectedItem();
            String nomeModelo = textModelo.getText();
            String anoModelo = textAnoModelo.getText();
            String fabricante = textFabricanteModelo.getText();
            double km = Double.parseDouble(textKm.getText());
            Categoria categoria = (Categoria) comboBoxCategoria.getSelectedItem();

            catalogoController.addVeiculo(placa, ano, cor, nomeModelo, anoModelo, fabricante, categoria, status, km);
            JOptionPane.showMessageDialog(this, "Cadastrado com Sucesso");
            this.dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
        } catch (CategoriaException e) {
            JOptionPane.showMessageDialog(this, e.getMessage());
        }
    }
}
