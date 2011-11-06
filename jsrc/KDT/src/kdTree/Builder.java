package kdTree;

/**
 * @author jchandar
 *
 */
public class Builder {
	
	int rightorleft = 0; //0 - left 1 - right
	
	/**
	 * adds node to tree identified by root.    
	                          
	@param  root  root of the tree. 
	 *  
	                          
	@param  o Object to be added
	 *  
	                          
	@return      void
	                         
	 */	
	public void AddNode(KdNode root, TwoDimObj o)
	{
		KdNode troot = null;
		troot = FindTwoDPath(root, o);
		
		if (rightorleft == 0)
		{
			troot.left = new KdNode(o);
			System.out.println("added left");
		}
		else
		{
			troot.right = new KdNode(o);
			System.out.println("added right");
		}
		return;
	}
	/**
	 * Find the parent where node will be inserted.    
	                          
	@param  root  root of the tree. Can be NULL for first call
	 *  
	                          
	@param  o Object to be added
	 *  
	                          
	@return      parent node where node will added
	                         
	 */
	private KdNode FindTwoDPath(KdNode root, TwoDimObj o)
	{
		KdNode troot = root;
		KdNode yroot = null;
		KdNode xroot = null;
		TwoDimObj rvalue;
		
    	while(troot != null)
    	{		
    		//search on Y axis
    		rvalue = troot.value;
    		if (o.placeRight(rvalue))
    		{
    			yroot = troot.right;
    			rightorleft = 1;
    		}
    		else
    		{
    			yroot = troot.left;
    			rightorleft = 0;
    		}
    		
    		if (yroot != null)
    		{	
    			//search X axis
    		  rvalue = yroot.value;
    		
    		  if (o.placeTop(rvalue))
    		  {
    			  xroot = yroot.right;
    			  rightorleft = 1;
    		  }
    		  else
    		  {
                  xroot = yroot.left;
                  rightorleft = 0;
    		  }
    		  
    		  if (xroot!=null)
    		  {
    			  troot = xroot; 		  
    		  }
    		  else
    		  {
    			  //return Y parent
    			  System.out.println("Y parent "+yroot.value.y);
    			  return yroot;
    		  }
    		}
    		else
    		{
    			//return X parent
    			System.out.println("X parent "+troot.value.x);
    			return troot;
    		}
    	}
		return null;
	}
}
