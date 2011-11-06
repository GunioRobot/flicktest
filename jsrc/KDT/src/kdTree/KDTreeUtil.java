package kdTree;

import java.util.ArrayList;
import java.util.Collections;

public class KDTreeUtil {
	ArrayList<TwoDimObj> orig = new ArrayList<TwoDimObj>();
	ArrayList<TwoDimObj> xarr;
	ArrayList<TwoDimObj> yarr;
	Integer totalNodes = 0;
	
	public boolean isEmpty()
	{
		if (xarr.size() == 0)
			return true;
		else
			return false;
	}
	public void addNodes(TwoDimObj obj)
	{
		obj.index = totalNodes;
		orig.add(obj);
		this.totalNodes++;
    }
	public void GetXsortedlist()
	{
		xarr = new ArrayList(orig);
		Collections.sort(xarr, new Compare2DonX()); 
	}
	public void GetYsortedlist()
	{
		yarr = new ArrayList(orig);
		Collections.sort(yarr, new Compare2DonY()); 
	}	
	public TwoDimObj getMidPointX()
	{
		TwoDimObj pt = this.xarr.remove(this.xarr.size()/2);
		yarr.remove(pt);
		//System.out.print("x size "+this.xarr.size());
		//System.out.print("y size "+this.yarr.size());
		System.out.println("rx:x " +pt.x+"y "+pt.y);
		return pt;
	}
	public TwoDimObj getMidPointY()
	{
		TwoDimObj pt = this.yarr.remove(this.xarr.size()/2);
		xarr.remove(pt);
		//System.out.println("y size "+this.yarr.size());
		//System.out.println("x size "+this.xarr.size());
		System.out.println("ry:x " +pt.x+"y "+pt.y);
		return pt;
	}
}
