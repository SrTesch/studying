package view;

import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.Serial;
import java.io.Serializable;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;
import javax.swing.JTextArea;
import javax.swing.border.EmptyBorder;

import controller.CatalogoController;
import controller.ClienteController;
import controller.MainController;
import controller.ServicosController;

public class ListagemView extends JFrame implements Serializable {
    @Serial
    private static final long serialVersionUID = -1218917724844736173L;

    private final JTextArea textAreaCategoria;
    private final JTextArea textAreaVeiculo;
    private final JTextArea textAreaSeguro;
    private final JTextArea textAreaPessoaF;
    private final JTextArea textAreaPessoaJ;
    private final JTextArea textAreaReservas;
    private final JTextArea textAreaLocacoes;

    public ListagemView() {
        setTitle("Listagem");
        setBounds(433, 164, 700, 500);
        JPanel contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
        contentPane.add(tabbedPane, BorderLayout.CENTER);

        JTabbedPane tabbedPane_1 = new JTabbedPane(JTabbedPane.TOP);
        tabbedPane.addTab("Catalogo", null, tabbedPane_1, null);

        JPanel panel_6 = new JPanel();
        tabbedPane_1.addTab("Categorias", null, panel_6, null);
        GridBagLayout gbl_panel_6 = new GridBagLayout();
        gbl_panel_6.columnWidths = new int[] { 0, 0 };
        gbl_panel_6.rowHeights = new int[] { 0, 0, 0 };
        gbl_panel_6.columnWeights = new double[] { 1.0, Double.MIN_VALUE };
        gbl_panel_6.rowWeights = new double[] { 0.0, 1.0, Double.MIN_VALUE };
        panel_6.setLayout(gbl_panel_6);

        JButton btnListarCategoria = new JButton("Listar");
        btnListarCategoria.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                actionListarCategorias();
            }
        });
        btnListarCategoria.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        GridBagConstraints gbc_btnListarCategoria = new GridBagConstraints();
        gbc_btnListarCategoria.insets = new Insets(0, 0, 5, 0);
        gbc_btnListarCategoria.gridx = 0;
        gbc_btnListarCategoria.gridy = 0;
        panel_6.add(btnListarCategoria, gbc_btnListarCategoria);

        textAreaCategoria = new JTextArea();
        GridBagConstraints gbc_textAreaCategoria = new GridBagConstraints();
        gbc_textAreaCategoria.fill = GridBagConstraints.BOTH;
        gbc_textAreaCategoria.gridx = 0;
        gbc_textAreaCategoria.gridy = 1;
        panel_6.add(textAreaCategoria, gbc_textAreaCategoria);

        JPanel panel_7 = new JPanel();
        tabbedPane_1.addTab("Veiculos", null, panel_7, null);
        GridBagLayout gbl_panel_7 = new GridBagLayout();
        gbl_panel_7.columnWidths = new int[] { 0, 0, 0 };
        gbl_panel_7.rowHeights = new int[] { 0, 0, 0 };
        gbl_panel_7.columnWeights = new double[] { 1.0, 0.0, Double.MIN_VALUE };
        gbl_panel_7.rowWeights = new double[] { 0.0, 1.0, Double.MIN_VALUE };
        panel_7.setLayout(gbl_panel_7);

        JButton btnListagemVeiculos = new JButton("Listar");
        btnListagemVeiculos.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                actionListarVeiculos();
            }
        });
        btnListagemVeiculos.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        GridBagConstraints gbc_btnListagemVeiculos = new GridBagConstraints();
        gbc_btnListagemVeiculos.gridwidth = 2;
        gbc_btnListagemVeiculos.insets = new Insets(0, 0, 5, 5);
        gbc_btnListagemVeiculos.gridx = 0;
        gbc_btnListagemVeiculos.gridy = 0;
        panel_7.add(btnListagemVeiculos, gbc_btnListagemVeiculos);

        textAreaVeiculo = new JTextArea();
        GridBagConstraints gbc_textAreaVeiculos = new GridBagConstraints();
        gbc_textAreaVeiculos.gridwidth = 2;
        gbc_textAreaVeiculos.insets = new Insets(0, 0, 0, 5);
        gbc_textAreaVeiculos.fill = GridBagConstraints.BOTH;
        gbc_textAreaVeiculos.gridx = 0;
        gbc_textAreaVeiculos.gridy = 1;
        panel_7.add(textAreaVeiculo, gbc_textAreaVeiculos);

        JPanel panel_8 = new JPanel();
        tabbedPane_1.addTab("Seguros", null, panel_8, null);
        GridBagLayout gbl_panel_8 = new GridBagLayout();
        gbl_panel_8.columnWidths = new int[] { 0, 0 };
        gbl_panel_8.rowHeights = new int[] { 0, 0, 0 };
        gbl_panel_8.columnWeights = new double[] { 1.0, Double.MIN_VALUE };
        gbl_panel_8.rowWeights = new double[] { 0.0, 1.0, Double.MIN_VALUE };
        panel_8.setLayout(gbl_panel_8);

        JButton btnListarSeguros = new JButton("Listar");
        btnListarSeguros.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                actionListarSeguros();
            }
        });
        btnListarSeguros.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        GridBagConstraints gbc_btnListarSeguros = new GridBagConstraints();
        gbc_btnListarSeguros.insets = new Insets(0, 0, 5, 0);
        gbc_btnListarSeguros.gridx = 0;
        gbc_btnListarSeguros.gridy = 0;
        panel_8.add(btnListarSeguros, gbc_btnListarSeguros);

        textAreaSeguro = new JTextArea();
        GridBagConstraints gbc_textAreaSeguro = new GridBagConstraints();
        gbc_textAreaSeguro.fill = GridBagConstraints.BOTH;
        gbc_textAreaSeguro.gridx = 0;
        gbc_textAreaSeguro.gridy = 1;
        panel_8.add(textAreaSeguro, gbc_textAreaSeguro);

        JTabbedPane tabbedPane_6 = new JTabbedPane(JTabbedPane.TOP);
        tabbedPane.addTab("Pessoas", null, tabbedPane_6, null);

        JPanel panel_3 = new JPanel();
        tabbedPane_6.addTab("Pessoas Fisica", null, panel_3, null);
        GridBagLayout gbl_panel_3 = new GridBagLayout();
        gbl_panel_3.columnWidths = new int[] { 0, 0 };
        gbl_panel_3.rowHeights = new int[] { 0, 0, 0 };
        gbl_panel_3.columnWeights = new double[] { 1.0, Double.MIN_VALUE };
        gbl_panel_3.rowWeights = new double[] { 0.0, 1.0, Double.MIN_VALUE };
        panel_3.setLayout(gbl_panel_3);

        JButton btnListarPessoaF = new JButton("Listar");
        btnListarPessoaF.addActionListener(e -> actionListarPessoaF());
        btnListarPessoaF.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        GridBagConstraints gbc_btnListarPessoaF = new GridBagConstraints();
        gbc_btnListarPessoaF.insets = new Insets(0, 0, 5, 0);
        gbc_btnListarPessoaF.gridx = 0;
        gbc_btnListarPessoaF.gridy = 0;
        panel_3.add(btnListarPessoaF, gbc_btnListarPessoaF);

        textAreaPessoaF = new JTextArea();
        GridBagConstraints gbc_textAreaPessoaF = new GridBagConstraints();
        gbc_textAreaPessoaF.fill = GridBagConstraints.BOTH;
        gbc_textAreaPessoaF.gridx = 0;
        gbc_textAreaPessoaF.gridy = 1;
        panel_3.add(textAreaPessoaF, gbc_textAreaPessoaF);

        JPanel panel_4 = new JPanel();
        tabbedPane_6.addTab("Pessoas Juridica", null, panel_4, null);
        GridBagLayout gbl_panel_4 = new GridBagLayout();
        gbl_panel_4.columnWidths = new int[] { 0, 0 };
        gbl_panel_4.rowHeights = new int[] { 0, 0, 0 };
        gbl_panel_4.columnWeights = new double[] { 1.0, Double.MIN_VALUE };
        gbl_panel_4.rowWeights = new double[] { 0.0, 1.0, Double.MIN_VALUE };
        panel_4.setLayout(gbl_panel_4);

        JButton btnListarPessoaJ = new JButton("Listar");
        btnListarPessoaJ.addActionListener(e -> actionListarPessoaJ());
        btnListarPessoaJ.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        GridBagConstraints gbc_btnListarPessoaJ = new GridBagConstraints();
        gbc_btnListarPessoaJ.insets = new Insets(0, 0, 5, 0);
        gbc_btnListarPessoaJ.gridx = 0;
        gbc_btnListarPessoaJ.gridy = 0;
        panel_4.add(btnListarPessoaJ, gbc_btnListarPessoaJ);

        textAreaPessoaJ = new JTextArea();
        GridBagConstraints gbc_textAreaPessoaJ = new GridBagConstraints();
        gbc_textAreaPessoaJ.fill = GridBagConstraints.BOTH;
        gbc_textAreaPessoaJ.gridx = 0;
        gbc_textAreaPessoaJ.gridy = 1;
        panel_4.add(textAreaPessoaJ, gbc_textAreaPessoaJ);

        JTabbedPane tabbedPane_10 = new JTabbedPane(JTabbedPane.TOP);
        tabbedPane.addTab("Locacao/Reservas", null, tabbedPane_10, null);

        JPanel panel_1 = new JPanel();
        tabbedPane_10.addTab("Reservas", null, panel_1, null);
        GridBagLayout gbl_panel_1 = new GridBagLayout();
        gbl_panel_1.columnWidths = new int[] { 0, 0 };
        gbl_panel_1.rowHeights = new int[] { 0, 0, 0 };
        gbl_panel_1.columnWeights = new double[] { 1.0, Double.MIN_VALUE };
        gbl_panel_1.rowWeights = new double[] { 0.0, 1.0, Double.MIN_VALUE };
        panel_1.setLayout(gbl_panel_1);

        JButton btnListarReservas = new JButton("Listar");
        btnListarReservas.addActionListener(e -> actionListarReservas());
        btnListarReservas.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        GridBagConstraints gbc_btnListarReservas = new GridBagConstraints();
        gbc_btnListarReservas.insets = new Insets(0, 0, 5, 0);
        gbc_btnListarReservas.gridx = 0;
        gbc_btnListarReservas.gridy = 0;
        panel_1.add(btnListarReservas, gbc_btnListarReservas);

        textAreaReservas = new JTextArea();
        GridBagConstraints gbc_textAreaReservas = new GridBagConstraints();
        gbc_textAreaReservas.fill = GridBagConstraints.BOTH;
        gbc_textAreaReservas.gridx = 0;
        gbc_textAreaReservas.gridy = 1;
        panel_1.add(textAreaReservas, gbc_textAreaReservas);

        JPanel panel_2 = new JPanel();
        tabbedPane_10.addTab("Locacoes", null, panel_2, null);
        GridBagLayout gbl_panel_2 = new GridBagLayout();
        gbl_panel_2.columnWidths = new int[] { 0, 0 };
        gbl_panel_2.rowHeights = new int[] { 0, 0, 0 };
        gbl_panel_2.columnWeights = new double[] { 1.0, Double.MIN_VALUE };
        gbl_panel_2.rowWeights = new double[] { 0.0, 1.0, Double.MIN_VALUE };
        panel_2.setLayout(gbl_panel_2);

        JButton btnListarLocacoes = new JButton("Listar");
        btnListarLocacoes.addActionListener(e -> actionListarLocacoes());
        btnListarLocacoes.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        GridBagConstraints gbc_btnListarLocacoes = new GridBagConstraints();
        gbc_btnListarLocacoes.insets = new Insets(0, 0, 5, 0);
        gbc_btnListarLocacoes.gridx = 0;
        gbc_btnListarLocacoes.gridy = 0;
        panel_2.add(btnListarLocacoes, gbc_btnListarLocacoes);

        textAreaLocacoes = new JTextArea();
        GridBagConstraints gbc_textAreaLocacoes = new GridBagConstraints();
        gbc_textAreaLocacoes.fill = GridBagConstraints.BOTH;
        gbc_textAreaLocacoes.gridx = 0;
        gbc_textAreaLocacoes.gridy = 1;
        panel_2.add(textAreaLocacoes, gbc_textAreaLocacoes);
    }

    private void actionListarCategorias() {
        CatalogoController controller = MainController.getCatalogoController();

        textAreaCategoria.setText(null);
        for (String nomeCategoria : controller.getListaFormatedCategorias()) {
            textAreaCategoria.append(String.format("%s\n", nomeCategoria));
        }
    }

    private void actionListarVeiculos() {

        CatalogoController controller = MainController.getCatalogoController();

        textAreaVeiculo.setText(null);
        for (String nomeVeiculo : controller.getListaFormatedVeiculos()) {
            textAreaVeiculo.append(String.format("%s\n", nomeVeiculo));
        }
    }

    private void actionListarSeguros() {

        CatalogoController controller = MainController.getCatalogoController();

        textAreaSeguro.setText(null);
        for (String coberturaSeguro : controller.getListaFormatedSeguros()) {
            textAreaSeguro.append(String.format("%s\n", coberturaSeguro));
        }
    }

    private void actionListarPessoaF() {

        ClienteController controller = MainController.getClienteController();
        textAreaPessoaF.setText(null);
        for (String cpfPessoa : controller.getListaFormatedPessoasF()) {
            textAreaPessoaF.append(String.format("%s\n", cpfPessoa));
        }
    }

    private void actionListarPessoaJ() {

        ClienteController controller = MainController.getClienteController();

        textAreaPessoaJ.setText(null);
        for (String cnpjPessoa : controller.getListaFormatedPessoasJ()) {
            textAreaPessoaJ.append(String.format("%s\n", cnpjPessoa));
        }
    }

    private void actionListarReservas() {

        ServicosController controller = MainController.getServicosController();

        textAreaReservas.setText(null);
        for (String formatedReserva : controller.getListaFormatedReservas()) {
            textAreaReservas.append(String.format("%s\n", formatedReserva));
        }

    }

    private void actionListarLocacoes() {
        ServicosController controller = MainController.getServicosController();

        textAreaLocacoes.setText(null);
        for (String formatedLocacao : controller.getListaFormatedLocacoes()) {
            textAreaLocacoes.append(String.format("%s\n", formatedLocacao));
        }
    }
}