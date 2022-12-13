import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Objects;

public class MainPage extends JFrame {

    private final JPanel panel;
    private final JTextField amountField;
    private final JButton withdrawButton, depositButton;
    private final JLabel userLabel, balanceLabel, amountLabel;

    private String username;

    public MainPage(String username) {
        this.username = username;

        // Components
        userLabel = new JLabel("Welcome, " + username);

        balanceLabel = new JLabel("Balance: ");

        amountLabel = new JLabel("Amount");

        amountField = new JTextField("");
        amountField.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));

        withdrawButton = new JButton("Withdraw");
        withdrawButton.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));
        withdrawButton.addActionListener(new MainPage.WithdrawButtonListener());

        depositButton = new JButton("Deposit");
        depositButton.setMaximumSize(new Dimension(Integer.MAX_VALUE, 50));
        depositButton.addActionListener(new MainPage.DepositButtonListener());

        // Ordering
        panel = new JPanel();
        panel.add(userLabel);
        panel.add(Box.createVerticalStrut(5));
        panel.add(balanceLabel);
        panel.add(Box.createVerticalStrut(50));
        panel.add(amountLabel);
        panel.add(Box.createVerticalStrut(5));
        panel.add(amountField);
        panel.add(Box.createVerticalStrut(5));
        panel.add(withdrawButton);
        panel.add(Box.createVerticalStrut(15));
        panel.add(depositButton);

        // Window Setup
        this.setContentPane(panel);
        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));
        panel.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));

        this.setVisible(true);
        this.setSize(450,500);
        this.setLocationRelativeTo(null);
        this.setTitle("Bank System");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setBalance();

    }

    Double getAmount() {
        return Double.parseDouble(amountField.getText());
    }

    void setBalance() {
        try {
            Registry registry = LocateRegistry.getRegistry(BankClient.HOST, BankClient.PORT);
            String rmiObjectName = "Bank";
            BankRPC ref = new BankRPC();
            String result = ref.balance();
            balanceLabel.setText("Balance: " + result);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    class WithdrawButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            try {
                Registry registry = LocateRegistry.getRegistry(BankClient.HOST, BankClient.PORT);
                String rmiObjectName = "Bank";
                BankRPC ref = new BankRPC();
                String result = ref.withdraw(getAmount());
                if (Objects.equals(result, "OK")) {
                    JOptionPane.showMessageDialog(null, "Transaction Successful");
                    setBalance();
                } else {
                    JOptionPane.showMessageDialog(null, result);
                }
            } catch (Exception e) {
                System.out.println(e);
            }

        }
    }


    class DepositButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            try {
                Registry registry = LocateRegistry.getRegistry(BankClient.HOST, BankClient.PORT);
                String rmiObjectName = "Bank";
                BankRPC ref = new BankRPC();
                String result = ref.deposit(getAmount());
                if (Objects.equals(result, "OK")) {
                    JOptionPane.showMessageDialog(null, "Transaction Successful");
                    setBalance();
                } else {
                    JOptionPane.showMessageDialog(null, result);
                }
            } catch (Exception e) {
                System.out.println(e);
            }

        }
    }

}