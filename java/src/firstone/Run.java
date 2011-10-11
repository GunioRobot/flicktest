/**
import java.util.list;
 * 
 */
package firstone;

/**
 * @author jchandar
 *
 */
public class Run {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MapDemo md;
		System.out.print("hello world\n");
		md = new MapDemo();
		md.printMembers();
		
		MapDemo md1 = new MapDemo(50);		
		md1.printMembers();
		md1.Demo();
		
		ListDemo ld = new ListDemo();
		ld.arrayDemo();
		ld.LlDemo();
		
		DateDemo dd = new DateDemo();
		dd.Demo();
		
		System.out.println(Palindrom.isPalindrom("12321"));
		System.out.println(Palindrom.isPalindrom("ab"));
		System.out.println(Palindrom.isPalindrom("abc"));
		System.out.println(Palindrom.isPalindrom("123456789876543212"));
		
	}

}
