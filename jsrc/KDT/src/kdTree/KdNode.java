package kdTree;

public class KdNode {

	KdNode left, right;
	TwoDimObj value;

	public TwoDimObj getValue() {
		return value;
	}
	public void setValue(TwoDimObj value) {
		this.value = value;
	}
	/**
	 * Constructor for KdNode.
	 */
	public KdNode(TwoDimObj o) {
		// TODO Auto-generated constructor stub
		this.value = o;
	}

}
