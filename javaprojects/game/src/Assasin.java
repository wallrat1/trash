public class Assasin extends Unit {
    public Assasin() {
        this.health = 75;
        this.defence=90;
        this.name = "Assasin";
        this.power = 15;
    }
    @Override
    public String toString() {
        return "Assasin" + " health=" + health + ", defence=" + defence +", power ="+power;
    }
}
