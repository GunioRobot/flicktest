package kdTree;

import java.util.Random;

public class TwoDimObj {
	
	 int index;
	 int x;
	 int y;
	
	public Integer getX()
	{
		return this.x;
	}
	
	public Integer getY()
	{
		return this.y;
	}
	
	public TwoDimObj() {
		// TODO Auto-generated constructor stub
	}
	
	public TwoDimObj(Integer x, Integer y) {
		// TODO Auto-generated constructor stub
		this.x = x;
		this.y = y;
	}

	public boolean placeRight(TwoDimObj cons)
	{
		if (cons.x < this.x)
			return true; //right
		else
			return false;//left
	}
	public  boolean placeTop(TwoDimObj cons)
	{
		if (cons.y < this.y)
			return true; //top
		else
			return false;//bottom
	}
	public void PrintPoint()
	{
		System.out.println("x "+this.x +" y "+this.y);
	}
	/* generate new random 2D point
	 * with limit of 1000 on each dimension
	 */
	static TwoDimObj getPoint()
	{
		Random r = new Random();
		TwoDimObj o = new TwoDimObj(r.nextInt(1000), r.nextInt(1000));
		return o;
	}
}
