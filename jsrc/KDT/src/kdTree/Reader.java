package kdTree;

public class Reader {
	public static void main(String[] arg)
	{
		TwoDimObj d2 = new TwoDimObj();
		KdTree tree = new KdTree();
		
		for (int i = 0; i <20; i++)
		{
		    d2 =GetNew2DObj.getPoint();
		    d2.PrintPoint();
		    tree.AddNode(d2);
		    
		    try {
				Thread.sleep(5);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}    
		}
		System.out.println("---------------------------------------------");
		tree.Traverse();
	}

}
