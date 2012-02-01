package kdTree;

import java.util.Comparator;

public class Compare2DonY implements Comparator<TwoDimObj>{
	@Override
	public int compare(TwoDimObj pt1, TwoDimObj pt2)
	{
		return pt1.getY() - pt2.getY();
	}


}
