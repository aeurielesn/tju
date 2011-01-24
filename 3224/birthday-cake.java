import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BigInteger n = BigInteger.ZERO, m = BigInteger.ZERO;
		Scanner entrada = new Scanner(System.in);
		int T = entrada.nextInt();
		for (int i = 0; i < T; i++) {
			n = entrada.nextBigInteger();
			m = entrada.nextBigInteger();
			System.out.println(""+n.multiply(m).subtract(BigInteger.ONE));
		}
	}

}
