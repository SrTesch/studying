import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.WindowEvent;
import java.io.Serial;
import java.io.Serializable;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.DateTimeException;
import java.util.Date;
import java.util.List;
import java.util.Vector;
import java.util.concurrent.atomic.AtomicReference;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import controller.MainController;
import controller.ServicosController;
import model.Categoria;
import model.Cliente;
import model.Seguro;

public class ReservaView extends JFrame implements Serializable {
    @Serial
    private static final long serialVersionUID = -8123454427135734983L;

    private final JTextField textDataInicio;
    private final JTextField textDataFim;
    private final JComboBox<Categoria> comboBoxCategoriaVeiculo;
    private JList<Seguro> listSeguro;
    private final JComboBox<Cliente> comboBoxCliente;

    public ReservaView() {
        setTitle("Reserva");
        setBounds(433, 164, 500, 500);
        JPanel contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));
        setContentPane(contentPane);

        JPanel panel = new JPanel();
        contentPane.add(panel, BorderLayout.NORTH);

        JLabel lblNewLabel = new JLabel("Cadastro Reserva");
        lblNewLabel.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
        lblNewLabel.setForeground(Color.DARK_GRAY);
        panel.add(lblNewLabel);

        JPanel panel_1 = new JPanel();
        contentPane.add(panel_1, BorderLayout.CENTER);
        GridBagConstraints gbc_listSeguro;

        JButton btnSalvar = new JButton("Salvar");
        btnSalvar.addActionListener(this::actionSalvar);
        btnSalvar.setFont(new Font("Comic Sans MS", Font.BOLD | Font.ITALIC, 14));
        GridBagConstraints gbc_btnSalvar = new GridBagConstraints();
        gbc_btnSalvar.insets = new Insets(0, 0, 5, 0);
        gbc_btnSalvar.gridx = 2;
        gbc_btnSalvar.gridy = 6;
        panel_1.add(btnSalvar, gbc_btnSalvar);

        JLabel lblCategoriaVeiculo = new JLabel("Categoria do Veiculo");
        lblCategoriaVeiculo.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblCategoriaVeiculo = new GridBagConstraints();
        gbc_lblCategoriaVeiculo.anchor = GridBagConstraints.EAST;
        gbc_lblCategoriaVeiculo.insets = new Insets(0, 0, 5, 5);
        gbc_lblCategoriaVeiculo.gridx = 1;
        gbc_lblCategoriaVeiculo.gridy = 1;
        panel_1.add(lblCategoriaVeiculo, gbc_lblCategoriaVeiculo);

        comboBoxCategoriaVeiculo = new JComboBox<>(MainController.getCatalogoController().getDefaultComboBoxModelForCategoria());
        GridBagConstraints gbc_comboBoxCategoriaVeiculo = new GridBagConstraints();
        gbc_comboBoxCategoriaVeiculo.insets = new Insets(0, 0, 5, 0);
        gbc_comboBoxCategoriaVeiculo.fill = GridBagConstraints.HORIZONTAL;
        gbc_comboBoxCategoriaVeiculo.gridx = 2;
        gbc_comboBoxCategoriaVeiculo.gridy = 1;
        panel_1.add(comboBoxCategoriaVeiculo, gbc_comboBoxCategoriaVeiculo);

        JLabel lblNewLabel_1 = new JLabel("Datas no formato:");
        lblNewLabel_1.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
        GridBagConstraints gbc_lblNewLabel_1 = new GridBagConstraints();
        gbc_lblNewLabel_1.anchor = GridBagConstraints.SOUTH;
        gbc_lblNewLabel_1.insets = new Insets(0, 0, 5, 5);
        gbc_lblNewLabel_1.gridx = 0;
        gbc_lblNewLabel_1.gridy = 2;
        panel_1.add(lblNewLabel_1, gbc_lblNewLabel_1);

        JLabel lblDataInicio = new JLabel("Data de Inicio:");
        lblDataInicio.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblDataInicio = new GridBagConstraints();
        gbc_lblDataInicio.anchor = GridBagConstraints.EAST;
        gbc_lblDataInicio.insets = new Insets(0, 0, 5, 5);
        gbc_lblDataInicio.gridx = 1;
        gbc_lblDataInicio.gridy = 2;
        panel_1.add(lblDataInicio, gbc_lblDataInicio);

        textDataInicio = new JTextField();
        GridBagConstraints gbc_textDataInicio = new GridBagConstraints();
        gbc_textDataInicio.insets = new Insets(0, 0, 5, 0);
        gbc_textDataInicio.fill = GridBagConstraints.HORIZONTAL;
        gbc_textDataInicio.gridx = 2;
        gbc_textDataInicio.gridy = 2;
        panel_1.add(textDataInicio, gbc_textDataInicio);
        textDataInicio.setColumns(10);

        JLabel lblNewLabel_2 = new JLabel("(DD/MM/YYYY)");
        lblNewLabel_2.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
        GridBagConstraints gbc_lblNewLabel_2 = new GridBagConstraints();
        gbc_lblNewLabel_2.anchor = GridBagConstraints.NORTH;
        gbc_lblNewLabel_2.insets = new Insets(0, 0, 5, 5);
        gbc_lblNewLabel_2.gridx = 0;
        gbc_lblNewLabel_2.gridy = 3;
        panel_1.add(lblNewLabel_2, gbc_lblNewLabel_2);

        JLabel lblDataFim = new JLabel("Data de Fim:");
        lblDataFim.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblDataFim = new GridBagConstraints();
        gbc_lblDataFim.anchor = GridBagConstraints.EAST;
        gbc_lblDataFim.insets = new Insets(0, 0, 5, 5);
        gbc_lblDataFim.gridx = 1;
        gbc_lblDataFim.gridy = 3;
        panel_1.add(lblDataFim, gbc_lblDataFim);

        textDataFim = new JTextField();
        GridBagConstraints gbc_textDataFim = new GridBagConstraints();
        gbc_textDataFim.insets = new Insets(0, 0, 5, 0);
        gbc_textDataFim.fill = GridBagConstraints.HORIZONTAL;
        gbc_textDataFim.gridx = 2;
        gbc_textDataFim.gridy = 3;
        panel_1.add(textDataFim, gbc_textDataFim);
        textDataFim.setColumns(10);

        JLabel lblSeguros = new JLabel("Seguros:");
        lblSeguros.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblSeguros = new GridBagConstraints();
        gbc_lblSeguros.anchor = GridBagConstraints.EAST;
        gbc_lblSeguros.insets = new Insets(0, 0, 5, 5);
        gbc_lblSeguros.gridx = 1;
        gbc_lblSeguros.gridy = 4;
        panel_1.add(lblSeguros, gbc_lblSeguros);

        AtomicReference<Categoria> categoria = new AtomicReference<>((Categoria) comboBoxCategoriaVeiculo.getSelectedItem());

        var catalogoController = MainController.getCatalogoController();
        listSeguro = new JList<>(new Vector<>(catalogoController.getSegurosByCategoria(categoria.get().getNome())));

        gbc_listSeguro = new GridBagConstraints();
        gbc_listSeguro.insets = new Insets(0, 0, 5, 0);
        gbc_listSeguro.fill = GridBagConstraints.BOTH;
        gbc_listSeguro.gridx = 2;
        gbc_listSeguro.gridy = 4;
        panel_1.add(listSeguro, gbc_listSeguro);

        comboBoxCategoriaVeiculo.addActionListener(e -> {
            panel_1.remove(listSeguro);
            categoria.set((Categoria) comboBoxCategoriaVeiculo.getSelectedItem());
            listSeguro = new JList<>(new Vector<>(catalogoController.getSegurosByCategoria(categoria.get().getNome())));
            panel_1.add(listSeguro, gbc_listSeguro);
        });

        JLabel lblCliente = new JLabel("Cliente:");
        lblCliente.setFont(new Font("Comic Sans MS", Font.PLAIN, 20));
        GridBagConstraints gbc_lblCliente = new GridBagConstraints();
        gbc_lblCliente.insets = new Insets(0, 0, 0, 5);
        gbc_lblCliente.anchor = GridBagConstraints.EAST;
        gbc_lblCliente.gridx = 1;
        gbc_lblCliente.gridy = 6;
        panel_1.add(lblCliente, gbc_lblCliente);

        comboBoxCliente = new JComboBox<>(MainController.getClienteController().getDefaultComboBoxModelForCliente());

        GridBagConstraints gbc_comboBoxCliente = new GridBagConstraints();
        gbc_comboBoxCliente.fill = GridBagConstraints.HORIZONTAL;
        gbc_comboBoxCliente.gridx = 2;
        gbc_comboBoxCliente.gridy = 6;
        panel_1.add(comboBoxCliente, gbc_comboBoxCliente);
    }

    private void actionSalvar() {
        ServicosController servicosController = MainController.getServicosController();

        Categoria categoria = (Categoria) comboBoxCategoriaVeiculo.getSelectedItem();
        Date dInicio;
        List<Seguro> seguros = listSeguro.getSelectedValuesList();
        Cliente cliente = (Cliente) comboBoxCliente.getSelectedItem();
        Date dFim;

        try {
            dInicio = new SimpleDateFormat("dd/MM/yyyy").parse(textDataInicio.getText());
            dFim = new SimpleDateFormat("dd/MM/yyyy").parse(textDataFim.getText());

            if (dInicio.after(dFim)) {
                throw new DateTimeException("Data de fim precisa ser menor que a de inicio");
            }

            JOptionPane.showMessageDialog(this, "Cadastrado com Sucesso");
            servicosController.addReserva(categoria, dInicio, dFim, cliente, seguros);
            this.dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
        } catch (ParseException e) {
            JOptionPane.showMessageDialog(this, String.format("Data invalida. Favor inserir no formato dd/mm/aaaa!"),
                    "Data invalida", JOptionPane.INFORMATION_MESSAGE);
        } catch (DateTimeException e) {
            JOptionPane.showMessageDialog(this, e.getMessage());
            textDataInicio.setText("");
            textDataFim.setText("");
        }
    }

}
        
