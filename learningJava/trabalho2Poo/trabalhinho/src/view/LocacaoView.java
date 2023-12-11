import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.WindowEvent;
import java.io.Serial;
import java.io.Serializable;
import java.util.Date;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import controller.MainController;
import controller.ServicosController;
import model.Reserva;
import model.Veiculo;

public class LocacaoView extends JFrame implements Serializable {
    @Serial
    private static final long serialVersionUID = -7220244303135066346L;

    private final JTextField textKmInicial;
    private final JComboBox<String> comboBoxReserva;
    private JComboBox<Veiculo> comboBoxVeiculos;

    public LocacaoView() {
        setTitle("Locacao");
        setBounds(433, 164, 500, 500);
        JPanel contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        JPanel panel = new JPanel();
        contentPane.add(panel, BorderLayout.NORTH);

        JLabel lblCadastroLocacao = new JLabel("Cadastro Locacao");
        lblCadastroLocacao.setForeground(Color.BLUE); // Altere a cor conforme necessário
        lblCadastroLocacao.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
        panel.add(lblCadastroLocacao);

        JPanel panel_1 = new JPanel();
        contentPane.add(panel_1, BorderLayout.CENTER);
        GridBagLayout gbl_panel_1 = new GridBagLayout();
        gbl_panel_1.columnWidths = new int[] { 0, 0, 0, 0 };
        gbl_panel_1.rowHeights = new int[] { 0, 0, 0, 0, 0, 0, 0, 0 };
        gbl_panel_1.columnWeights = new double[] { 0.0, 0.0, 1.0, Double.MIN_VALUE };
        gbl_panel_1.rowWeights = new double[] { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE };
        panel_1.setLayout(gbl_panel_1);

        JLabel lblReserva = new JLabel("Reserva:");
        lblReserva.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblReserva = new GridBagConstraints();
        gbc_lblReserva.insets = new Insets(0, 0, 5, 5);
        gbc_lblReserva.anchor = GridBagConstraints.EAST;
        gbc_lblReserva.gridx = 1;
        gbc_lblReserva.gridy = 0;
        panel_1.add(lblReserva, gbc_lblReserva);

        comboBoxReserva = new JComboBox<>(MainController.getServicosController().getDefaultComboBoxModelForReservas());
        GridBagConstraints gbc_comboBox = new GridBagConstraints();
        gbc_comboBox.insets = new Insets(0, 0, 5, 0);
        gbc_comboBox.fill = GridBagConstraints.HORIZONTAL;
        gbc_comboBox.gridx = 2;
        gbc_comboBox.gridy = 0;
        panel_1.add(comboBoxReserva, gbc_comboBox);

        JLabel lblVeiculo = new JLabel("Veiculo:");
        lblVeiculo.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblVeiculo = new GridBagConstraints();
        gbc_lblVeiculo.anchor = GridBagConstraints.EAST;
        gbc_lblVeiculo.insets = new Insets(0, 0, 5, 5);
        gbc_lblVeiculo.gridx = 1;
        gbc_lblVeiculo.gridy = 1;
        panel_1.add(lblVeiculo, gbc_lblVeiculo);

        comboBoxReserva.addActionListener(e -> {
            panel_1.remove(comboBoxVeiculos);
            String reservaUUID = (String) comboBoxReserva.getSelectedItem();
            Reserva reserva = MainController.getServicosController().getReservaByUUID(reservaUUID);

            comboBoxVeiculos = new JComboBox<>(
                    MainController
                            .getCatalogoController()
                            .getDefaultComboBoxModelForVeiculoFromCategoria(reserva.getCategoria())
            );

            GridBagConstraints gbc_comboBox_1 = new GridBagConstraints();
            gbc_comboBox_1.insets = new Insets(0, 0, 5, 0);
            gbc_comboBox_1.fill = GridBagConstraints.HORIZONTAL;
            gbc_comboBox_1.gridx = 2;
            gbc_comboBox_1.gridy = 1;
            panel_1.add(comboBoxVeiculos, gbc_comboBox_1);
        });

        String reservaUUID = (String) comboBoxReserva.getSelectedItem();
        Reserva reserva = MainController.getServicosController().getReservaByUUID(reservaUUID);

        comboBoxVeiculos = new JComboBox<>(
                MainController
                        .getCatalogoController()
                        .getDefaultComboBoxModelForVeiculoFromCategoria(reserva.getCategoria())
        );

        GridBagConstraints gbc_comboBox_1 = new GridBagConstraints();
        gbc_comboBox_1.insets = new Insets(0, 0, 5, 0);
        gbc_comboBox_1.fill = GridBagConstraints.HORIZONTAL;
        gbc_comboBox_1.gridx = 2;
        gbc_comboBox_1.gridy = 1;
        panel_1.add(comboBoxVeiculos, gbc_comboBox_1);

        JLabel lblDataRetirada = new JLabel("Data Retirada:");
        lblDataRetirada.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblDataRetirada = new GridBagConstraints();
        gbc_lblDataRetirada.anchor = GridBagConstraints.EAST;
        gbc_lblDataRetirada.insets = new Insets(0, 0, 5, 5);
        gbc_lblDataRetirada.gridx = 1;
        gbc_lblDataRetirada.gridy = 2;
        panel_1.add(lblDataRetirada, gbc_lblDataRetirada);

        JTextField textDataRetirada = new JTextField();
        textDataRetirada.setBackground(Color.LIGHT_GRAY);
        textDataRetirada.setEditable(false);
        Date dRetirada = new Date();
        textDataRetirada.setText(dRetirada.toString());
        GridBagConstraints gbc_textDataRetirada = new GridBagConstraints();
        gbc_textDataRetirada.insets = new Insets(0, 0, 5, 0);
        gbc_textDataRetirada.fill = GridBagConstraints.HORIZONTAL;
        gbc_textDataRetirada.gridx = 2;
        gbc_textDataRetirada.gridy = 2;
        panel_1.add(textDataRetirada, gbc_textDataRetirada);
        textDataRetirada.setColumns(10);

        JLabel lblKmInicial = new JLabel("Km Inicial:");
        lblKmInicial.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblKmInicial = new GridBagConstraints();
        gbc_lblKmInicial.anchor = GridBagConstraints.EAST;
        gbc_lblKmInicial.insets = new Insets(0, 0, 5, 5);
        gbc_lblKmInicial.gridx = 1;
        gbc_lblKmInicial.gridy = 3;
        panel_1.add(lblKmInicial, gbc_lblKmInicial);

        textKmInicial = new JTextField();
        GridBagConstraints gbc_textKmInicial = new GridBagConstraints();
        gbc_textKmInicial.insets = new Insets(0, 0, 5, 0);
        gbc_textKmInicial.fill = GridBagConstraints.HORIZONTAL;
        gbc_textKmInicial.gridx = 2;
        gbc_textKmInicial.gridy = 3;
        panel_1.add(textKmInicial, gbc_textKmInicial);
        textKmInicial.setColumns(10);

        JButton btnSalvar = new JButton("Salvar");
        btnSalvar.addActionListener(this::actionSalvar);
        btnSalvar.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        btnSalvar.setBackground(Color.GREEN); // Altere a cor conforme necessário
        GridBagConstraints gbc_btnSalvar = new GridBagConstraints();
        gbc_btnSalvar.insets = new Insets(0, 0, 5, 0);
        gbc_btnSalvar.gridwidth = 5;
        gbc_btnSalvar.gridx = 0;
        gbc_btnSalvar.gridy = 5;
        panel_1.add(btnSalvar, gbc_btnSalvar);
    }

    protected void actionSalvar(ActionEvent e) {
        ServicosController servicosController = MainController.getServicosController();

        try {
            String reserva = (String) comboBoxReserva.getSelectedItem();
            Veiculo veiculo = (Veiculo) comboBoxVeiculos.getSelectedItem();

            int km = Integer.parseInt(textKmInicial.getText());

            servicosController.addLocacao(reserva, veiculo, km);
            JOptionPane.showMessageDialog(this, "Cadastrado com Sucesso");

            this.dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(this, ex.getMessage());
            textKmInicial.setText("");
        }
    }
}