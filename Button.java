public class Button {
    int id;
    String instructions;
    Player player;

    void run(){
        System.out.println("The button " + id + " is running: " + instructions);
    }

    void changeInstructions(){
        // Change instructions
    }

    Button(int id, String instructions, Player player){
        this.id = id;
        this.instructions = instructions;
        this.player = player;
    }
}