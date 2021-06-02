import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class InfectionPage extends JFrame{

    private final LoginPage loginPage;

    private final JPanel panel;
    private final JLabel titleText, titleText2;
    private final JTextArea listText;
    private final JButton backButton;

    private final User user;

    public InfectionPage(LoginPage loginPage, User user) {

        this.loginPage = loginPage;
        this.user = user;

        // Components
        titleText = new JLabel(user.getName() + " has been infected");

        titleText2 = new JLabel("The following users have to be tested");

        listText= new JTextArea();
        String infectedString = "";
        for (User infectedUser: user.getPossiblyInfectedUsers() ) {
            infectedString += infectedUser.getName() + "\n";
        }
        listText.setText(infectedString);
        listText.setEditable(false);

        backButton = new JButton("Back to Login Screen");
        backButton.setMaximumSize(new Dimension(Integer.MAX_VALUE, 100));
        backButton.addActionListener(new BackButtonListener());

        // Ordering
        panel = new JPanel();
        panel.add(titleText);
        panel.add(titleText2);
        panel.add(Box.createVerticalStrut(20));
        panel.add(listText);
        panel.add(Box.createVerticalStrut(40));
        panel.add(backButton);

        // Window Setup
        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));
        panel.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        this.setContentPane(panel);

        this.setVisible(true);
        this.setSize(400,400);
        this.setLocationRelativeTo(null);
        this.setTitle("Πιθανή Μετάδοση Ιού");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    class BackButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            loginPage.setVisible(true);
            InfectionPage.this.dispose();
        }
    }

}
