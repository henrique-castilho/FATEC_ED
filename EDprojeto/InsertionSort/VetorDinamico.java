import java.util.Random;

public class VetorDinamico {
    private int qtde;
    private int cap;
    private int[] elementos;

    public static final int CAP_MINIMA = 4;

    VetorDinamico() {
        cap = CAP_MINIMA;
        qtde = 0;
        elementos = new int[CAP_MINIMA];
    }

    VetorDinamico(int cap) {
        this.cap = cap;
        qtde = 0;
        elementos = new int[cap];
    }

    boolean estaCheio() {
        return qtde == cap;
    }

    void redimensionar() {
        int[] auxiliar = new int[cap * 2];
        cap *= 2;

        for (int i = 0; i < qtde; i++) {
            auxiliar[i] = elementos[i];
        }

        elementos = auxiliar;
    }

    void adicionar(int elemento) {
        if (estaCheio()) {
            redimensionar();
        }

        elementos[qtde] = elemento;
        qtde++;
    }

    void adicinarSemRepeticao(int e) {
        if (!existe(e)) {
            adicionar(e);
        }
    }

    boolean existe(int e) {
        for (int i = 0; i < qtde; i++) {
            if (e == elementos[i]) {
                return true;
            }
        }
        return false;
    }

    int tamanho() {
        return qtde;
    }

    void removerNoFinal() {
        qtde -= 1;
    }

    boolean estaVazio() {
        return qtde == 0;
    }

    boolean estaUmQuartoCheio() {
        return qtde == (cap / 4);
    }

    void reduzirTamanho() {
        if (!estaVazio()) {
            removerNoFinal();

            if (cap > 4 && estaUmQuartoCheio()) {
                cap /= 2;
            }
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder("");

        sb.append("Qtde: ").append(qtde);
        sb.append("\n");
        sb.append("Cap: ").append(cap);
        sb.append("\n");
        sb.append(qtde > 0 ? "Elementos: " : "");
        for (int i = 0; i < qtde; i++) {
            sb.append(elementos[i]).append(" ");
        }

        return sb.toString();
    }

    public void insertionSort() {
        int n = qtde;
        for (int i = 1; i < n; ++i) {
            int chave = elementos[i];
            int j = i - 1;

            while (j >= 0 && elementos[j] > chave) {
                elementos[j + 1] = elementos[j];
                j = j - 1;
            }
            elementos[j + 1] = chave;
        }
    }

    public void gera_elementos() {
        Random random = new Random();
        while (!estaCheio())
            adicionar(random.nextInt(cap * 10));
    }
}
