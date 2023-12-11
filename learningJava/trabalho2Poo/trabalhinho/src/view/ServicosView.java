package view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.Serial;
import java.io.Serializable;

public class ServicosView extends JFrame implements Serializable {
    @Serial
    private static final long serialVersionUID = -4719141453780206841L;

    public ServicosView() {
        setTitle("Servicos");
        setBounds(433, 164, 500, 500);
        JPanel contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        JPanel panel = new JPanel();
        contentPane.add(panel, BorderLayout.NORTH);

        JLabel lblNewLabel = new JLabel("Menu Servicos");
        lblNewLabel.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
        lblNewLabel.setForeground(Color.BLUE); // Cor do título
        panel.add(lblNewLabel);

        JPanel panel_1 = new JPanel();
        contentPane.add(panel_1, BorderLayout.CENTER);
        GridBagLayout gbl_panel_1 = new GridBagLayout();
        gbl_panel_1.columnWidths = new int[] { 0, 0, 0, 0, 0, 0, 0 };
        gbl_panel_1.rowHeights = new int[] { 0, 0, 0, 0, 0, 0, 0, 0 };
        gbl_panel_1.columnWeights = new double[] { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE };
        gbl_panel_1.rowWeights = new double[] { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE };
        panel_1.setLayout(gbl_panel_1);

        JButton btnFazerReserva = criarBotao("Fazer Reserva", this::actionReservaView);
        GridBagConstraints gbc_btnFazerReserva = new GridBagConstraints();
        gbc_btnFazerReserva.anchor = GridBagConstraints.WEST;
        gbc_btnFazerReserva.insets = new Insets(0, 0, 5, 5);
        gbc_btnFazerReserva.gridx = 1;
        gbc_btnFazerReserva.gridy = 1;
        panel_1.add(btnFazerReserva, gbc_btnFazerReserva);

        JButton btnFazerLocacao = criarBotao("Fazer Locacao", this::actionLocacaoView);
        GridBagConstraints gbc_btnFazerLocacao = new GridBagConstraints();
        gbc_btnFazerLocacao.anchor = GridBagConstraints.WEST;
        gbc_btnFazerLocacao.insets = new Insets(0, 0, 5, 5);
        gbc_btnFazerLocacao.gridx = 1;
        gbc_btnFazerLocacao.gridy = 2;
        panel_1.add(btnFazerLocacao, gbc_btnFazerLocacao);

        JButton btnValoresLocacao = criarBotao("Valores Da Locacao", this::actionValoresLocacaoView);
        GridBagConstraints gbc_btnValoresLocacao = new GridBagConstraints();
        gbc_btnValoresLocacao.anchor = GridBagConstraints.WEST;
        gbc_btnValoresLocacao.insets = new Insets(0, 0, 5, 5);
        gbc_btnValoresLocacao.gridx = 1;
        gbc_btnValoresLocacao.gridy = 3;
        panel_1.add(btnValoresLocacao, gbc_btnValoresLocacao);

        JButton btnRealizarDevolucao = criarBotao("Realizar Devolucao", this::actionDevolucaoView);
        GridBagConstraints gbc_btnRealizarDevolucao = new GridBagConstraints();
        gbc_btnRealizarDevolucao.anchor = GridBagConstraints.WEST;
        gbc_btnRealizarDevolucao.insets = new Insets(0, 0, 5, 5);
        gbc_btnRealizarDevolucao.gridx = 1;
        gbc_btnRealizarDevolucao.gridy = 4;
        panel_1.add(btnRealizarDevolucao, gbc_btnRealizarDevolucao);
    }
    private JButton criarBotao(String texto, ActionListener actionListener) {
        JButton botao = new JButton(texto);
        botao.addActionListener(actionListener);
        botao.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        botao.setBackground(Color.GREEN);
        botao.setForeground(Color.WHITE);
        return botao;
    }
    private void actionLocacaoView(ActionEvent e) {
        LocacaoView locacaoView = new LocacaoView();
        locacaoView.setVisible(true);
    }
    private void actionReservaView(ActionEvent e) {
        ReservaView reservaView = new ReservaView();
        reservaView.setVisible(true);
    }
    private void actionValoresLocacaoView(ActionEvent e) {
        ValoresLocacaoView valoresLocacaoView = new ValoresLocacaoView();
        valoresLocacaoView.setVisible(true);
    }
    private void actionDevolucaoView(ActionEvent e) {
        DevolucaoView devolucaoView = new DevolucaoView();
        devolucaoView.setVisible(true);
    }
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            ServicosView servicosView = new ServicosView();
            servicosView.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            servicosView.setVisible(true);
        });
    }
}