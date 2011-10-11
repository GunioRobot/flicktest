package kdTree;
import java.util.Random;

public class GetNew2DObj {
	static TwoDimObj getPoint()
	{
		Random r = new Random();
		TwoDimObj o = new TwoDimObj(r.nextInt(1000), r.nextInt(1000));
		return o;
	}
}
