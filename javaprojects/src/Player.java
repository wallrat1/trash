import java.util.ArrayList;
import java.util.List;
public class Player {
    private String name="";
    public String getName() {
        return name;
    }
    private List<Unit> units =new ArrayList<>();
    public Player (String name) {
        this.name = name;
    }
    public void addUnit(char unit) {
        switch (unit) {
            case('K'): units.add(new Unit()); break;
            case('W'): units.add(new Wizard()); break;
            case('A'): units.add(new Assasin()); break;
        }
    }
    public Unit getOneUnit(int i) {
        return getUnits().get(i);
    }
    public List<Unit> getUnits() {
        return units;
    }
    public void HealDeadUnits() {
        for(int i =0; i<3;i++) {
            getOneUnit(i).Heal();
        }
    }
    public boolean AllIsDead() {
        for (int i = 0; i<3;i++) {
            if (!getOneUnit(i).isDead()) {return false;}
        }
        return true;
    }


}
