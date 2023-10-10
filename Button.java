public class Button {
    int id;
    String instructions;
    Player player;

    void run(){
        System.out.println("The button " + id + " is running: " + instructions);


        String[] actions = instructions.split("\\s+");
        for(int i = 0; i < actions.length; i++) {

            if(actions[i].equals("MOVE")){

                player.x_pos = player.x_pos + Integer.parseInt(actions[i+1]);
                System.out.println("Evaluating \"MOVE " + Integer.parseInt(actions[i+1]) + "\" Moving player");
                i++;
                

            } else if(actions[i].equals("SHOOT")){

                System.out.println("Evaluating \"SHOOT\": Shooting!");

            }
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