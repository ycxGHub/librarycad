package cn.shiftcmd.libcad;

/**
 * author：yichangxiang
 * email：ycxadr@163.com
 * createdAt:2020/09/08
 **/
public class DxfWriter {
    enum Version {
        UNKNOWNV(0),     /*!< UNKNOWN VERSION. */
        AC1006(1),       /*!< R10. */
        AC1009(2),     /*!< R11 & R12. */
        AC1012(3),       /*!< R13. */
        AC1014(4),       /*!< R14. */
        AC1015(5),     /*!< ACAD 2000. */
        AC1018(6),    /*!< ACAD 2004. */
        AC1021(7),      /*!< ACAD 2007. */
        AC1024(8),      /*!< ACAD 2010. */
        AC1027(9);     /*!< ACAD 2013. */
        int value;

        Version(int v) {
            this.value = v;
        }
    }

    private long nativeId;
    private String filePath;
    private Version version = Version.AC1021;

    static {
        System.loadLibrary("drw-jni");
    }


    public DxfWriter(String file) {
        nativeId = createNativeObject();
        filePath = file;
    }

    public DxfWriter(String file, Version version) {
        nativeId = createNativeObject();
        filePath = file;
        this.version = version;
    }

    public void writeCoord(Coordinate p) {
        writePoint(nativeId, p.toDoubleArray());
    }

    public void writeText(Coordinate p1, Coordinate p2, String text) {
        writeText(nativeId, p1.toDoubleArray(), p2.toDoubleArray(), text);
    }

    public void writeLine(Coordinate p1, Coordinate p2, double lineW) {
        writeLine(nativeId, p1.toDoubleArray(), p2.toDoubleArray(), lineW);
    }

    public void writeCircle(Coordinate p, double radius) {
        writeCircle(nativeId,p.toDoubleArray(),radius);
    }

    public void writeToFile() {
        writeToFile(nativeId, filePath, version.value);
    }

    public void clearAll() {
        if (nativeId != -1) {
            nativeId = clear(nativeId);
        }
    }


    private native long createNativeObject();

    private native void writePoint(long addr, double[] p);

    private native void writeText(long addr, double[] p1, double[] p2, String text);

    private native void writeLine(long addr, double[] p1, double[] p2, double lineW);

    private native void writeCircle(long addr, double[] p, double radius);

    private native void writeToFile(long addr, String file, int version);

    private native long clear(long addr);
}
