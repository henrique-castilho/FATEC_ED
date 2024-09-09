import java.util.Date;
import java.util.Scanner;
public class TesteOrdenacao {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("escolha o tamanho do vetor, 0 enccerra: ");
        int cap = scanner.nextInt();
        VetorDinamico v;
        while (cap > 0) {
            for (int cont = 0; cont < 20; cont++){
            v = new VetorDinamico(cap);
            v.gera_elementos();
            long ini = (int) new Date().getTime();
            v.bubbleSort();
            long fim = (int) new Date().getTime();
            //System.out.println("vetor ordenado" + v);
            System.out.println("bubble demorou: " + (fim - ini) + " ms");
            }
            System.out.println("escolha o tamanho do vetor, 0 encerra: ");
            cap = scanner.nextInt();
        }
        scanner.close();
    }   
}
