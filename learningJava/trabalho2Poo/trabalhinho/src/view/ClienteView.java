package view;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.WindowEvent;
import java.io.Serial;
import java.io.Serializable;

import controller.ClienteController;
import controller.MainController;
import exception.*;

public class ClienteView extends JFrame implements Serializable {
    @Serial
    private static final long serialVersionUID = 7169403174654824820L;

    private JTextField[] textFieldsPessoaFisica;
    private JTextField[] textFieldsPessoaJuridica;

    public ClienteView() {
        setTitle("Cadastro de Clientes");
        setBounds(433, 164, 500, 500);
        JPanel contentPanel = new JPanel();
        contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
        setContentPane(contentPanel);

        GridBagLayout gridBagLayout = new GridBagLayout();
        gridBagLayout.columnWidths = new int[]{424, 0};
        gridBagLayout.rowHeights = new int[]{20, 241, 0};
        gridBagLayout.columnWeights = new double[]{0.0, Double.MIN_VALUE};
        gridBagLayout.rowWeights = new double[]{0.0, 0.0, Double.MIN_VALUE};
        contentPanel.setLayout(gridBagLayout);

        JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
        GridBagConstraints gbc_tabbedPane = new GridBagConstraints();
        gbc_tabbedPane.fill = GridBagConstraints.BOTH;
        gbc_tabbedPane.gridx = 0;
        gbc_tabbedPane.gridy = 1;
        contentPanel.add(tabbedPane, gbc_tabbedPane);

        showPessoaFisicaTabContent(tabbedPane);
        showPessoaJuridicaTabContent(tabbedPane);
    }

    private void showPessoaFisicaTabContent(JTabbedPane tabbedPane) {
        JPanel panel = new JPanel();
        tabbedPane.addTab("Pessoa Fisica", null, panel, null);
        GridBagLayout gbl_panel_1 = new GridBagLayout();
        gbl_panel_1.columnWidths = new int[]{46, 0, 0, 0};
        gbl_panel_1.rowHeights = new int[]{14, 0, 0, 0, 0, 0, 0, 0};
        gbl_panel_1.columnWeights = new double[]{0.0, 0.0, 1.0, Double.MIN_VALUE};
        gbl_panel_1.rowWeights = new double[]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
        panel.setLayout(gbl_panel_1);

        JButton btnSalvar = createCommonButton("Salvar", e -> actionSalvar());
        GridBagConstraints gbc_btnSalvar = new GridBagConstraints();
        gbc_btnSalvar.insets = new Insets(0, 0, 5, 5);
        gbc_btnSalvar.gridx = 0;
        gbc_btnSalvar.gridy = 1;
        panel.add(btnSalvar, gbc_btnSalvar);

        String[] labels = {"Nome:", "Telefone:", "Email:", "CPF:", "CNH:", "Validade CNH:", "Rua:", "Numero:", "CEP:"};
        textFieldsPessoaFisica = createTextFields(labels, panel, 2);
    }

    private void showPessoaJuridicaTabContent(JTabbedPane tabbedPane) {
        JPanel panel = new JPanel();
        tabbedPane.addTab("Pessoa Juridica", null, panel, null);
        GridBagLayout gbl_panel_2 = new GridBagLayout();
        gbl_panel_2.columnWidths = new int[]{0, 0, 0, 0};
        gbl_panel_2.rowHeights = new int[]{0, 0, 0, 0, 0, 0, 0, 0};
        gbl_panel_2.columnWeights = new double[]{0.0, 0.0, 1.0, Double.MIN_VALUE};
        gbl_panel_2.rowWeights = new double[]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
        panel.setLayout(gbl_panel_2);

        JButton btnSalvar = createCommonButton("Salvar", e -> actionSalvar());
        GridBagConstraints gbc_btnSalvar = new GridBagConstraints();
        gbc_btnSalvar.insets = new Insets(0, 0, 5, 5);
        gbc_btnSalvar.gridx = 0;
        gbc_btnSalvar.gridy = 1;
        panel.add(btnSalvar, gbc_btnSalvar);

        String[] labels = {"Nome:", "Telefone:", "Email:", "CNPJ:", "Contato:", "Rua:", "Numero:", "CEP:"};
        textFieldsPessoaJuridica = createTextFields(labels, panel, 2);
    }

    private JButton createCommonButton(String label, java.awt.event.ActionListener actionListener) {
        JButton btn = new JButton(label);
        btn.addActionListener(actionListener);
        btn.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        return btn;
    }

    private JTextField[] createTextFields(String[] labels, JPanel panel, int gridX) {
        JTextField[] textFields = new JTextField[labels.length];

        for (int i = 0; i < labels.length; i++) {
            JLabel lbl = new JLabel(labels[i]);
            lbl.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
            GridBagConstraints gbc_lbl = new GridBagConstraints();
            gbc_lbl.anchor = GridBagConstraints.EAST;
            gbc_lbl.insets = new Insets(0, 0, 5, 5);
            gbc_lbl.gridx = 1;
            gbc_lbl.gridy = i + 1;
            panel.add(lbl, gbc_lbl);

            textFields[i] = new JTextField();
            GridBagConstraints gbc_textField = new GridBagConstraints();
            gbc_textField.fill = GridBagConstraints.HORIZONTAL;
            gbc_textField.insets = new Insets(0, 0, 5, 0);
            gbc_textField.gridx = gridX;
            gbc_textField.gridy = i + 1;
            panel.add(textFields[i], gbc_textField);
            textFields[i].setColumns(10);
        }

        return textFields;
    }

    private void actionSalvar() {
        try {
            ClienteController clienteController = MainController.getClienteController();

            if (tabbedPane.getSelectedIndex() == 0) {
                salvarPessoaFisica(clienteController);
            } else {
                salvarPessoaJuridica(clienteController);
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, e.getMessage());
        }
    }

    private void salvarPessoaFisica(ClienteController clienteController) {
        try {
            String nome = textFieldsPessoaFisica[0].getText();
            String telefone = textFieldsPessoaFisica[1].getText();
            String email = textFieldsPessoaFisica[2].getText();
            String cpf = textFieldsPessoaFisica[3].getText();
            String numCNH = textFieldsPessoaFisica[4].getText();
            String validadeCNH = textFieldsPessoaFisica[5].getText();
            String rua = textFieldsPessoaFisica[6].getText();
            String numero = textFieldsPessoaFisica[7].getText();
            String cep = textFieldsPessoaFisica[8].getText();

            clienteController.cadastrarPessoaFisica(nome, telefone, email, cpf, numCNH, validadeCNH, rua, numero, cep);
            JOptionPane.showMessageDialog(this, "Pessoa Física cadastrada com sucesso!");
        } catch (CampoVazioException | FormatoInvalidoException | ClienteExistenteException e) {
            JOptionPane.showMessageDialog(this, e.getMessage());
        }
    }

    private void salvarPessoaJuridica(ClienteController clienteController) {
        try {
            String nome = textFieldsPessoaJuridica[0].getText();
            String telefone = textFieldsPessoaJuridica[1].getText();
            String email = textFieldsPessoaJuridica[2].getText();
            String cnpj = textFieldsPessoaJuridica[3].getText();
            String contato = textFieldsPessoaJuridica[4].getText();
            String rua = textFieldsPessoaJuridica[5].getText();
            String numero = textFieldsPessoaJuridica[6].getText();
            String cep = textFieldsPessoaJuridica[7].getText();

            clienteController.cadastrarPessoaJuridica(nome, telefone, email, cnpj, contato, rua, numero, cep);
            JOptionPane.showMessageDialog(this, "Pessoa Jurídica cadastrada com sucesso!");
        } catch (CampoVazioException | FormatoInvalidoException | ClienteExistenteException e) {
            JOptionPane.showMessageDialog(this, e.getMessage());
        }
    }

    public void windowClosing(WindowEvent e) {
        int escolha = JOptionPane.showConfirmDialog(null, "Deseja realmente fechar a aplicação?", "Fechar",
                JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
        if (escolha == JOptionPane.YES_OPTION) {
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        }
    }
}
