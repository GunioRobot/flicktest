package kdTree;

import java.util.Comparator;

public class Compare2DonX implements Comparator<TwoDimObj>{

	@Override
	public int compare(TwoDimObj pt1, TwoDimObj pt2)
	{
		return pt1.getX() - pt2.getX();
	}

}
