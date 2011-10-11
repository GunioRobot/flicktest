package kdTree;

public class KdNode {
	
	KdNode left, right;
	TwoDimObj value;
	
	public KdNode(TwoDimObj o) {
		// TODO Auto-generated constructor stub
		this.value = o;
	}
	
	public void ChangeValue(TwoDimObj o)
	{
		this.value = o;
	}
	public TwoDimObj GetValue()
	{
		return this.value;
	}
	
	
}
