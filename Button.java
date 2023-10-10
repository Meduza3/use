public class Button {
    int id;
    String instructions;
    Player player;

    void run(){
        System.out.println("The button " + id + " is running: " + instructions);

        String[] actions = instructions.split("\\s+");
        if(actions[0].equals("MOVE")){
            player.x_pos = player.x_pos + Integer.parseInt(actions[1]);
        } else if(actions[0].equals("SHOOT")){
            System.out.println("Shoot!");
        }

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