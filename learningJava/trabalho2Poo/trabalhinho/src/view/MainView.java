import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.io.Serial;
import java.io.Serializable;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

public class MainView extends JFrame implements Serializable {
    @Serial
    private static final long serialVersionUID = 517294119658988912L;

    public MainView() {
        setTitle("Locadora de veículos");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(433, 164, 500, 500);

        JPanel contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        JPanel menuPanel = new JPanel();
        contentPane.add(menuPanel, BorderLayout.NORTH);

        JLabel menuLabel = new JLabel("Menu Principal");
        menuLabel.setForeground(Color.BLUE); // Altere a cor conforme necessário
        menuLabel.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
        menuPanel.add(menuLabel);

        JPanel buttonsPanel = new JPanel();
        contentPane.add(buttonsPanel, BorderLayout.CENTER);

        initCatalogoButton(buttonsPanel);
        initServicosButton(buttonsPanel);
        initClientesButton(buttonsPanel);
        initListagemButton(buttonsPanel);
    }
    private void initCatalogoButton(JPanel panel) {
        JButton btnCatalogo = new JButton("Catálogo");
        btnCatalogo.addActionListener(this::actionCatalogoView);
        btnCatalogo.setFont(new Font("Comic Sans MS", Font.PLAIN, 18));
        btnCatalogo.setBackground(Color.GREEN); // Altere a cor conforme necessário
        GridBagConstraints gbc_btnCatalogo = new GridBagConstraints();
        gbc_btnCatalogo.anchor = GridBagConstraints.WEST;
        gbc_btnCatalogo.insets = new Insets(0, 0, 5, 5);
        gbc_btnCatalogo.gridx = 1;
        gbc_btnCatalogo.gridy = 0;
        panel.add(btnCatalogo, gbc_btnCatalogo);
    }
    private void initServicosButton(JPanel panel) {
        JButton btnServicos = new JButton("Serviços");
        btnServicos.addActionListener(this::actionServicosView);
        btnServicos.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        btnServicos.setBackground(Color.YELLOW); // Altere a cor conforme necessário
        GridBagConstraints gbc_btnServicos = new GridBagConstraints();
        gbc_btnServicos.anchor = GridBagConstraints.NORTHWEST;
        gbc_btnServicos.insets = new Insets(0, 0, 5, 5);
        gbc_btnServicos.gridx = 2;
        gbc_btnServicos.gridy = 0;
        panel.add(btnServicos, gbc_btnServicos);
    }
    private void initClientesButton(JPanel panel) {
        JButton btnClientes = new JButton("Clientes");
        btnClientes.addActionListener(this::actionClienteView);
        btnClientes.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        btnClientes.setBackground(Color.ORANGE); // Altere a cor conforme necessário
        GridBagConstraints gbc_btnClientes = new GridBagConstraints();
        gbc_btnClientes.insets = new Insets(0, 0, 5, 0);
        gbc_btnClientes.anchor = GridBagConstraints.NORTHWEST;
        gbc_btnClientes.gridx = 3;
        gbc_btnClientes.gridy = 0;
        panel.add(btnClientes, gbc_btnClientes);
    }
    private void initListagemButton(JPanel panel) {
        JButton btnListagem = new JButton("Listagem");
        btnListagem.addActionListener(this::actionListagemView);
        btnListagem.setFont(new Font("Comic Sans MS", Font.PLAIN, 18));
        btnListagem.setBackground(Color.RED); // Altere a cor conforme necessário
        GridBagConstraints gbc_btnListagem = new GridBagConstraints();
        gbc_btnListagem.insets = new Insets(0, 0, 5, 5);
        gbc_btnListagem.gridx = 1;
        gbc_btnListagem.gridy = 1;
        panel.add(btnListagem, gbc_btnListagem);
    }
    private void actionCatalogoView(ActionEvent e) {
        CatalogoView catalogoView = new CatalogoView();
        catalogoView.setVisible(true);
    }
    private void actionServicosView(ActionEvent e) {
        ServicosView servicosView = new ServicosView();
        servicosView.setVisible(true);
    }
    private void actionClienteView(ActionEvent e) {
        ClienteView clienteView = new ClienteView();
        clienteView.setVisible(true);
    }
    private void actionListagemView(ActionEvent e) {
        ListagemView listagemView = new ListagemView();
        listagemView.setVisible(true);
    }
}
