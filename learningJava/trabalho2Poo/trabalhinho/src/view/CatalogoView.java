package view;

import java.awt.*;
import java.io.Serial;
import java.io.Serializable;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JButton;

public class CatalogoView extends JFrame implements Serializable {
    @Serial
    private static final long serialVersionUID = 4675757454208436636L;

    /**
     * Create the frame.
     */
    public CatalogoView() {
        setTitle("Catálogo");
        setBounds(433, 164, 500, 500);
        JPanel contentPane = new JPanel();
        contentPane.setBackground(new Color(240, 240, 240)); // Cor de fundo diferente
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        JPanel panel = new JPanel();
        panel.setBackground(new Color(105, 105, 105)); // Cor de fundo do painel superior
        contentPane.add(panel, BorderLayout.NORTH);

        JLabel lblNewLabel = new JLabel("Menu Catálogo");
        lblNewLabel.setForeground(Color.WHITE);
        lblNewLabel.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
        panel.add(lblNewLabel);

        JPanel panel_1 = new JPanel();
        panel_1.setBackground(new Color(240, 240, 240)); // Cor de fundo do painel central
        contentPane.add(panel_1, BorderLayout.CENTER);

        JButton btnCategoria = new JButton("Categorias");
        btnCategoria.addActionListener(e -> actionCategoriaView());
        btnCategoria.setFont(new Font("Comic Sans MS", Font.PLAIN, 18));
        panel_1.add(btnCategoria);

        JButton btnVeiculo = new JButton("Veículos");
        btnVeiculo.addActionListener(e -> actionVeiculoView());
        btnVeiculo.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        panel_1.add(btnVeiculo);

        JButton btnSeguro = new JButton("Seguros");
        btnSeguro.addActionListener(e -> actionSeguroView());
        btnSeguro.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        panel_1.add(btnSeguro);
    }

    private void actionCategoriaView() {
        CategoriaView categoriaView = new CategoriaView();
        categoriaView.setVisible(true);
    }

    private void actionVeiculoView() {
        VeiculoView veiculoView = new VeiculoView();
        veiculoView.setVisible(true);
    }

    private void actionSeguroView() {
        SeguroView seguroView = new SeguroView();
        seguroView.setVisible(true);
    }
}
