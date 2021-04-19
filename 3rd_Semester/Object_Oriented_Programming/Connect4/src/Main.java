public class Main {

    public static void main(String[] args) {

        Connect4 connect4 = new Connect4();
        //connect4.setAvailableDisks('R', 'Y');
        connect4.readPlayerNames();
        connect4.readDiscs();
        connect4.readBoardSize();
        connect4.run();

    }
}
