import java.util.Date;
import java.util.Scanner;

public class TesteSelection {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Escolha o tamanho do vetor, 0 encerra: ");
        int cap = scanner.nextInt();
        VetorDinamico v; 
        while (cap > 0) {
            for (int cont = 0; cont < 20; cont++) {
                v = new VetorDinamico(cap);
                v.gera_elementos();
                long ini = new Date().getTime();
                v.selectionSort(); // Usando o selection sort da classe VetorDinamico
                long fim = new Date().getTime();
                // System.out.println("Vetor ordenado: " + v);
                System.out.println("Selection sort demorou: " + (fim - ini) + " ms");
            }
            System.out.println("Escolha o tamanho do vetor, 0 encerra: ");
            cap = scanner.nextInt();
        }
        scanner.close();
    }
}
