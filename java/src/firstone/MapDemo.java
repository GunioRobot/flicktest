package firstone;

public class MapDemo {
	private int myvar = 0;
//	private int j = 1;
//	private int k = 2;
	private int[] arrvar;

	public MapDemo() {
		// TODO Auto-generated constructor stub
		int i = 0;
		arrvar = new int[10];
		for (i = 0; i < 10; i++)
		{
			arrvar[i] = i;
		}
		myvar = 10;
		
	}
	public MapDemo(int value) {
		// TODO Auto-generated constructor stub
		int i = 0;
		myvar = value;
		arrvar = new int[10];
		for (i = 0; i < arrvar.length; i++)
		{
			arrvar[i] = i*2;
		}
	}
	public void printMembers()	{
		int i = 0;
		System.out.println("myvar = "+myvar);
		for (i = 0; i < arrvar.length; i++)
		{
			System.out.println("array = "+arrvar[i]);
		}
	
	}

}
