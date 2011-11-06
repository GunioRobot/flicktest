package kdTree;



public class KdTree {
	
	KdNode root;
	Integer totalNodes = 0;
	Builder b;
	
	
	public boolean isTreeEmpty()
	{
		if (root == null)
			return true;
		else
			return false;
	}
	
	public void AddNode(TwoDimObj o)
	{
		if (isTreeEmpty())
		{
			// first node
			root = new KdNode(o);
			b     = new Builder();
		}
		else
		{
			//children
			b.AddNode(this.root, o);
		}
		
		o.index = totalNodes;
		
		
		this.totalNodes++;
	}
	public void Traverse()
	{
		inOrderTraverse(this.root);
	}
	
	private void inOrderTraverse(KdNode r)
	{
		if (r!=null)
		{
			inOrderTraverse(r.left);
			r.value.PrintPoint();
			inOrderTraverse(r.right);	
		}
		else
			return;
	}
	
	
}
