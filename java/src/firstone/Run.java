/**
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
		

	}

}
