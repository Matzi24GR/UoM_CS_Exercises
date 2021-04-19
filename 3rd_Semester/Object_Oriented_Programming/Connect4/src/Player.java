public class Player {

    private String name;
    private char disc;

    public Player(String name){
        this.name = name;
    }

    public Player(String name, char disc){
        this.name = name;
        this.disc = disc;
    }


    public String getName() {
        return name;
    }

    public void setDisc(char disc) {
        this.disc = disc;
    }

    public char getDisc() {
        return disc;
    }
}
