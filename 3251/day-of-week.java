import java.util.GregorianCalendar;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		int day = entrada.nextInt();
		int month = entrada.nextInt();
		GregorianCalendar calendar = new GregorianCalendar(2009,month-1,day);
		String days[]={"", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
		System.out.println(""+days[calendar.get(GregorianCalendar.DAY_OF_WEEK)]);
	}

}
