package kdTree;

public class Reader {
	public static void main(String[] arg)
	{
		TwoDimObj d2 = new TwoDimObj();
		KdTree tree = new KdTree();
        KDTreeUtil utl = new KDTreeUtil();

		for (int i = 0; i <20; i++)
		{
		    d2 = TwoDimObj.getPoint();
		    d2.PrintPoint();
		    utl.addNodes(d2);

		    try {
				Thread.sleep(5);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		utl.GetXsortedlist();
	    utl.GetYsortedlist();


		for (int i = 0; i < 10 && (utl.isEmpty() == false); i++)
		{
			if (i % 2 == 0)
			{
				int itr = (int)java.lang.Math.pow(2,i);

				for(int j = 0; j < itr && (utl.isEmpty() == false);j++)
				{
					tree.AddNode(utl.getMidPointX());
				}
			}
			else
			{
				int itr = (int) java.lang.Math.pow(2,i);
				for(int j = 0; j <itr && (utl.isEmpty() == false);j++)
				{
					tree.AddNode(utl.getMidPointY());
				}
			}
		}


		System.out.println("---------------------------------------------");
		tree.Traverse();
	}

}
