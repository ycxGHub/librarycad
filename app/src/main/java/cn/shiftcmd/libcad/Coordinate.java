package cn.shiftcmd.libcad;

/**
 * author：yichangxiang
 * email：ycxadr@163.com
 * createdAt:2020/09/08
 **/
public class Coordinate {
    public double x, y, z;

    public Coordinate(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public Coordinate middleOf(Coordinate another) {
        return new Coordinate((x+another.x)/2.0,(y+another.y)/2.0,(z+another.z)/2.0);
    }

    public double[] toDoubleArray() {
        return new double[]{x, y, z};
    }
}
