import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Player player = new Player();

        System.out.println("Input what instruction you want for button 0: ");
        String instructions0 = scanner.nextLine();
        Button button0 = new Button(0, instructions0, player);

        System.out.println("Input what instruction you want for button 1: ");
        String instructions1 = scanner.nextLine();
        Button button1 = new Button(1, instructions1, player);

        System.out.println("Input what instruction you want for button 2: ");
        String instructions2 = scanner.nextLine();
        Button button2 = new Button(2, instructions2, player);

        System.out.println("Fight!");
        
        while(true) {
            System.out.print("Waiting for input... Got: ");
            String firstInput = scanner.nextLine();

            if (firstInput.equals("0")) {
                button0.run();
            } else if (firstInput.equals("1")) {
                button1.run();
            } else if (firstInput.equals("2")){
                button2.run();
            } else {
                break;
            }
            System.out.println("The player is at " + player.x_pos);
        }
    }

}
