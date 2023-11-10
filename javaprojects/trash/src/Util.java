import java.util.Scanner;
public class Util {
    static Scanner in = new Scanner(System.in);
    public static int getTarget() {
        int target = 0;
        do {
            System.out.println("Введите число от 1 до 3 (номер цели, которую хотите атаковать)");
            target = in.nextInt();
        } while(target<1 || target>3 );
        return target-1;
    }
    public static void PlayerHod(Player player) {
        System.out.println("**********Ход игрока: "+player.getName()+"**********");
    }
    public static void NumberRound() {
        System.out.println("Раунд номер "+Counter.getNumberRound());
    }
    public static void Winner(Player player) {
        System.out.println(player.getName()+" ПОБЕДИЛ!!!!");
    }
    public static void Hello() {
        System.out.println("Welcom to " + Game.name + " !!!!!!");
    }
    public static void InputPlayer() {
        System.out.println("Player1: ");
        Game.addPlayer(in.next());
        System.out.println("Player2: ");
        Game.addPlayer(in.next());
    }
    public static void InputUnit(int i,int j) {
        System.out.println(Game.getOnePlayer(i).getName()+", Выберите героя номер "+(j)+" ");
        char unit = '*';
        do {
            System.out.println("W - маг, K - рыцарь, A - ассасин");
             unit = in.next().charAt(0);

        } while (unit!='W' && unit!='K' && unit!='A');
        Game.getPlayers().get(i).addUnit(unit);

    }
    public static void UnitInfo(Unit unit) {
        System.out.println(unit.toString());
    }
    public static void ListUnitInfo(Player player) {
        for(Unit elem : player.getUnits()) {
            System.out.println(elem.toString());
        }
    }

}
