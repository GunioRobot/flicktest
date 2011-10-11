package kdTree;

public class TwoDimObj {
	
	Integer x;
	Integer y;
	
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
}
