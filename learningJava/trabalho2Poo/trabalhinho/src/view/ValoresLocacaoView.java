package view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.border.EmptyBorder;
import controller.MainController;
import controller.ServicosController;
import model.Locacao;
import java.io.Serial;
import java.io.Serializable;

public class ValoresLocacaoView extends JFrame implements Serializable {
    @Serial
    private static final long serialVersionUID = 8735540393348987223L;

    private final JComboBox<Locacao> comboBox;
    private final JTextArea textArea;

    public ValoresLocacaoView() {
        setTitle("Valores");
        setBounds(433, 164, 500, 500);
        JPanel contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        JPanel panel = new JPanel();
        contentPane.add(panel, BorderLayout.NORTH);

        JLabel lbl = new JLabel("Valores Da Locacao");
        lbl.setForeground(Color.DARK_GRAY);
        lbl.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
        panel.add(lbl);

        JPanel panel_1 = new JPanel();
        contentPane.add(panel_1, BorderLayout.CENTER);
        GridBagLayout gbl_panel_1 = new GridBagLayout();
        gbl_panel_1.columnWidths = new int[] { 0, 0, 0 };
        gbl_panel_1.rowHeights = new int[] { 0, 0, 0, 0, 0, 0, 0 };
        gbl_panel_1.columnWeights = new double[] { 1.0, 1.0, Double.MIN_VALUE };
        gbl_panel_1.rowWeights = new double[] { 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE };
        panel_1.setLayout(gbl_panel_1);

        JLabel lblNewLabel = new JLabel("Reserva da Locacao:");
        lblNewLabel.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblNewLabel = new GridBagConstraints();
        gbc_lblNewLabel.insets = new Insets(0, 0, 5, 5);
        gbc_lblNewLabel.anchor = GridBagConstraints.EAST;
        gbc_lblNewLabel.gridx = 0;
        gbc_lblNewLabel.gridy = 0;
        panel_1.add(lblNewLabel, gbc_lblNewLabel);

        comboBox = new JComboBox<>(MainController.getServicosController().getDefaultComboBoxModelForLocacoes());

        GridBagConstraints gbc_comboBox = new GridBagConstraints();
        gbc_comboBox.insets = new Insets(0, 0, 5, 0);
        gbc_comboBox.fill = GridBagConstraints.HORIZONTAL;
        gbc_comboBox.gridx = 1;
        gbc_comboBox.gridy = 0;
        panel_1.add(comboBox, gbc_comboBox);

        JButton btnTotalDiarias = criarBotao("Total das Diarias", this::actionTotalDiarias);
        textArea = new JTextArea();
        GridBagConstraints gbc_textArea = new GridBagConstraints();
        gbc_textArea.gridheight = 4;
        gbc_textArea.insets = new Insets(0, 0, 5, 5);
        gbc_textArea.fill = GridBagConstraints.BOTH;
        gbc_textArea.gridx = 0;
        gbc_textArea.gridy = 2;
        panel_1.add(textArea, gbc_textArea);
        btnTotalDiarias.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        GridBagConstraints gbc_btnTotalDiarias = new GridBagConstraints();
        gbc_btnTotalDiarias.insets = new Insets(0, 0, 5, 0);
        gbc_btnTotalDiarias.gridx = 1;
        gbc_btnTotalDiarias.gridy = 2;
        panel_1.add(btnTotalDiarias, gbc_btnTotalDiarias);

        JButton btnTotalSeguros = criarBotao("Total dos Seguros", this::actionTotalSeguros);
        JButton btnTotalLocacao = criarBotao("Total da Locacao", this::actionTotalLocacao);

        GridBagConstraints gbc_btnTotalSeguros = new GridBagConstraints();
        gbc_btnTotalSeguros.insets = new Insets(0, 0, 5, 0);
        gbc_btnTotalSeguros.gridx = 1;
        gbc_btnTotalSeguros.gridy = 4;
        panel_1.add(btnTotalSeguros, gbc_btnTotalSeguros);

        btnTotalLocacao.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        GridBagConstraints gbc_btnTotalLocacao = new GridBagConstraints();
        gbc_btnTotalLocacao.gridx = 1;
        gbc_btnTotalLocacao.gridy = 5;
        panel_1.add(btnTotalLocacao, gbc_btnTotalLocacao);
    }
    private JButton criarBotao(String texto, ActionListener actionListener) {
        JButton botao = new JButton(texto);
        botao.addActionListener(actionListener);
        botao.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        botao.setBackground(Color.BLUE);
        botao.setForeground(Color.WHITE);
        return botao;
    }
    protected void actionTotalDiarias(ActionEvent e) {
        ServicosController servicosController = MainController.getServicosController();
        Locacao locacao = (Locacao) comboBox.getSelectedItem();
        double valor = servicosController.getTotalDiarias(locacao);
        textArea.append(String.format("%s\n", valor));
    }
    private void actionTotalSeguros(ActionEvent e) {
        ServicosController servicosController = MainController.getServicosController();
        Locacao locacao = (Locacao) comboBox.getSelectedItem();
        double valor = servicosController.getTotalSeguros(locacao);
        textArea.append(String.format("%s\n", valor));
    }
    private void actionTotalLocacao(ActionEvent e) {
        ServicosController locacaoController = MainController.getServicosController();
        Locacao locacao = (Locacao) comboBox.getSelectedItem();
        double valor = locacaoController.getTotalLocacao(locacao);
        textArea.append(String.format("%s\n", valor));
    }
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            ValoresLocacaoView valoresLocacaoView = new ValoresLocacaoView();
            valoresLocacaoView.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            valoresLocacaoView.setVisible(true);
        });
    }
}