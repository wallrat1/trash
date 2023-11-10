import java.util.ArrayList;
import java.util.List;
public class Game {
    public static String name ="Magic carnage of chainsaw";
    private static List<Player> players = new ArrayList<>();
    public static void addPlayer(String name) {
        players.add(new Player(name));
    }
    public static List<Player> getPlayers() {
        return players;
    }
    public static Player getOnePlayer(int i) {
        return Game.getPlayers().get(i);
    }

}
