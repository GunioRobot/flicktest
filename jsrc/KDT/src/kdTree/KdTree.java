package kdTree;

public class KdTree {
	
	KdNode root;
	Integer totalNodes;
	Builder b;
	
	public boolean isEmpty()
	{
		if (root == null)
			return true;
		else
			return false;
	}
	
	public void AddNode(TwoDimObj o)
	{
		if (isEmpty())
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
	}
	public void Traverse()
	{
		inOrderTraverse(this.root);
	}
	
	public void inOrderTraverse(KdNode r)
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
