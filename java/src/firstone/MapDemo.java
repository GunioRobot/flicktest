package firstone;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;


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
			System.out.print(" a = "+arrvar[i]);
		}
	
	}
	public void Demo()
	{
		Map<String, Integer> m = new HashMap<String, Integer>();
		m.put("one", new Integer(1));
		m.put("two", new Integer(2));
		System.out.println(m);
		m.put("two", new Integer(3));
		System.out.println("contain "+m.containsKey("one"));
		System.out.println("get "+m.get("one"));
		
		for (String key : m.keySet())
		{
			System.out.println("key "+key);
		}
		
		for (Map.Entry<String, Integer> e: m.entrySet())
		{
			System.out.println("key "+e.getKey());
			System.out.println("value "+e.getValue());
		}
		
	}

}
