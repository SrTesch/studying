package view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
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
import model.EFormaPagamento;
import model.EMotivoPagamento;
import model.Locacao;
import model.Pagamento;

public class DevolucaoView extends JFrame implements Serializable {
    @Serial
    private static final long serialVersionUID = -5267237249152806686L;

    private final JTextField textFieldValorPago;
    private final JComboBox<EFormaPagamento> comboBox;
    private final JTextField textFieldDescricao;
    private final JComboBox<Locacao> comboBoxLocacao;

    public DevolucaoView() {
        setTitle("Devolucao");
        setBounds(433, 164, 500, 500);
        JPanel contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        JPanel panel = new JPanel();
        contentPane.add(panel, BorderLayout.NORTH);

        JLabel lblNewLabel = new JLabel("Realizar Devolucao");
        lblNewLabel.setForeground(Color.DARK_GRAY);
        lblNewLabel.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
        panel.add(lblNewLabel);

        JPanel panel_1 = new JPanel();
        contentPane.add(panel_1, BorderLayout.CENTER);
        GridBagLayout gbl_panel_1 = new GridBagLayout();
        gbl_panel_1.columnWidths = new int[] { 0, 0, 0 };
        gbl_panel_1.rowHeights = new int[] { 0, 0, 0, 0, 0, 0, 0 };
        gbl_panel_1.columnWeights = new double[] { 1.0, 1.0, Double.MIN_VALUE };
        gbl_panel_1.rowWeights = new double[] { 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE };
        panel_1.setLayout(gbl_panel_1);

        JLabel lblNewLabel_1 = new JLabel("Locacao:");
        lblNewLabel_1.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblNewLabel_1 = new GridBagConstraints();
        gbc_lblNewLabel_1.insets = new Insets(0, 0, 5, 5);
        gbc_lblNewLabel_1.anchor = GridBagConstraints.EAST;
        gbc_lblNewLabel_1.gridx = 0;
        gbc_lblNewLabel_1.gridy = 0;
        panel_1.add(lblNewLabel_1, gbc_lblNewLabel_1);

        comboBoxLocacao = new JComboBox<>(MainController.getServicosController().getDefaultComboBoxModelForLocacoes());
        GridBagConstraints gbc_comboBoxLocacao = new GridBagConstraints();
        gbc_comboBoxLocacao.insets = new Insets(0, 0, 5, 0);
        gbc_comboBoxLocacao.fill = GridBagConstraints.HORIZONTAL;
        gbc_comboBoxLocacao.gridx = 1;
        gbc_comboBoxLocacao.gridy = 0;
        panel_1.add(comboBoxLocacao, gbc_comboBoxLocacao);

        JLabel lblData = new JLabel("Data Devolucao:");
        lblData.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblData = new GridBagConstraints();
        gbc_lblData.insets = new Insets(0, 0, 5, 5);
        gbc_lblData.anchor = GridBagConstraints.EAST;
        gbc_lblData.gridx = 0;
        gbc_lblData.gridy = 1;
        panel_1.add(lblData, gbc_lblData);

        JTextField textFieldData = new JTextField();
        Date dDevolucao = new Date();
        textFieldData.setText(dDevolucao.toString());
        textFieldData.setEditable(false);
        textFieldData.setBackground(Color.LIGHT_GRAY);
        GridBagConstraints gbc_textFieldData = new GridBagConstraints();
        gbc_textFieldData.insets = new Insets(0, 0, 5, 0);
        gbc_textFieldData.fill = GridBagConstraints.HORIZONTAL;
        gbc_textFieldData.gridx = 1;
        gbc_textFieldData.gridy = 1;
        panel_1.add(textFieldData, gbc_textFieldData);
        textFieldData.setColumns(10);

        JLabel lblKmFinal = new JLabel("Km Final:");
        lblKmFinal.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblKmFinal = new GridBagConstraints();
        gbc_lblKmFinal.anchor = GridBagConstraints.EAST;
        gbc_lblKmFinal.insets = new Insets(0, 0, 5, 5);
        gbc_lblKmFinal.gridx = 0;
        gbc_lblKmFinal.gridy = 2;
        panel_1.add(lblKmFinal, gbc_lblKmFinal);

        JTextField textKm = new JTextField();
        GridBagConstraints gbc_textKm = new GridBagConstraints();
        gbc_textKm.insets = new Insets(0, 0, 5, 0);
        gbc_textKm.fill = GridBagConstraints.HORIZONTAL;
        gbc_textKm.gridx = 1;
        gbc_textKm.gridy = 2;
        panel_1.add(textKm, gbc_textKm);
        textKm.setColumns(10);

        JLabel lblValorPago = new JLabel("Valor Pago:");
        lblValorPago.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblValorPago = new GridBagConstraints();
        gbc_lblValorPago.anchor = GridBagConstraints.EAST;
        gbc_lblValorPago.insets = (new Insets(0, 0, 5, 5));
        gbc_lblValorPago.gridx = 0;
        gbc_lblValorPago.gridy = 3;
        panel_1.add(lblValorPago, gbc_lblValorPago);

        textFieldValorPago = new JTextField();
        GridBagConstraints gbc_textFieldValorPago = new GridBagConstraints();
        gbc_textFieldValorPago.insets = new Insets(0, 0, 5, 0);
        gbc_textFieldValorPago.fill = GridBagConstraints.HORIZONTAL;
        gbc_textFieldValorPago.gridx = 1;
        gbc_textFieldValorPago.gridy = 3;
        panel_1.add(textFieldValorPago, gbc_textFieldValorPago);
        textFieldValorPago.setColumns(10);

        JLabel lblFormaPagamento = new JLabel("Forma de Pagamento:");
        lblFormaPagamento.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblFormaPagamento = new GridBagConstraints();
        gbc_lblFormaPagamento.anchor = GridBagConstraints.EAST;
        gbc_lblFormaPagamento.insets = new Insets(0, 0, 5, 5);
        gbc_lblFormaPagamento.gridx = 0;
        gbc_lblFormaPagamento.gridy = 4;
        panel_1.add(lblFormaPagamento, gbc_lblFormaPagamento);

        comboBox = new JComboBox<>(EFormaPagamento.values());
        GridBagConstraints gbc_comboBox = new GridBagConstraints();
        gbc_comboBox.insets = new Insets(0, 0, 5, 0);
        gbc_comboBox.fill = GridBagConstraints.HORIZONTAL;
        gbc_comboBox.gridx = 1;
        gbc_comboBox.gridy = 4;
        panel_1.add(comboBox, gbc_comboBox);

        JLabel lblDescricao = new JLabel("Descricao:");
        lblDescricao.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblDescricao = new GridBagConstraints();
        gbc_lblDescricao.anchor = GridBagConstraints.EAST;
        gbc_lblDescricao.insets = new Insets(0, 0, 5, 5);
        gbc_lblDescricao.gridx = 0;
        gbc_lblDescricao.gridy = 5;
        panel_1.add(lblDescricao, gbc_lblDescricao);

        textFieldDescricao = new JTextField();
        GridBagConstraints gbc_textFieldDescricao = new GridBagConstraints();
        gbc_textFieldDescricao.insets = new Insets(0, 0, 5, 0);
        gbc_textFieldDescricao.fill = GridBagConstraints.HORIZONTAL;
        gbc_textFieldDescricao.gridx = 1;
        gbc_textFieldDescricao.gridy = 5;
        panel_1.add(textFieldDescricao, gbc_textFieldDescricao);

        JButton btnSalvar = new JButton("Salvar");
        btnSalvar.addActionListener(e -> actionSalvar());
        btnSalvar.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        GridBagConstraints gbc_btnSalvar = new GridBagConstraints();
        gbc_btnSalvar.insets = new Insets(0, 0, 5, 0);
        gbc_btnSalvar.gridwidth = 2;
        gbc_btnSalvar.gridx = 0;
        gbc_btnSalvar.gridy = 6;
        panel_1.add(btnSalvar, gbc_btnSalvar);
    }

    private void actionSalvar() {
        ServicosController servicosController = MainController.getServicosController();
        double valor = Double.parseDouble(textFieldValorPago.getText());
        int km = Integer.parseInt(textKm.getText());
        String descricao = textFieldDescricao.getText();
        Date date = new Date();
        var formaPagamento = (EFormaPagamento) comboBox.getSelectedItem();
        Pagamento pagamento = new Pagamento(formaPagamento, date, valor, EMotivoPagamento.LOCACAO, descricao);
        Locacao locacao = (Locacao) comboBoxLocacao.getSelectedItem();

        servicosController.addDevolucao(locacao, km, pagamento);

        JOptionPane.showMessageDialog(this, "Cadastrado com Sucesso");
        this.dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
    }
}
