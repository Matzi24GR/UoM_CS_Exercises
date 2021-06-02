import java.util.ArrayList;

public class Evaluator {


    private final Board board;
    private final char[][] boardArray;
    private final char disk;
    private ResultBoard resultBoard;

    public Evaluator(Board board) {
        this.board = board;
        this.boardArray = board.getBoardArray();
        this.disk = board.getDiskAt( board.getLastMove() );
        resultBoard = new ResultBoard(board);
    }

    public ResultBoard getResultBoard() {
        return resultBoard;
    }

    public boolean check(ArrayList<Location> line) {
        ArrayList<Location> array = new ArrayList<>();

        boolean found = false;
        for (Location cell: line) {

            if ( board.getDiskAt(cell) == disk ){
                array.add(cell);
            } else {
                array = new ArrayList<>();
            }

            if ( array.size() >= 4 ) {
                found = true;
                resultBoard.setWinningDisks(array);
                //resultBoard.setWinningDisks(array, disk);
            }

        }
        return found;
    }

}
