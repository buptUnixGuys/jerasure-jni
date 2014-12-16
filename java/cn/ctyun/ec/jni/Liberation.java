package cn.ctyun.ec.jni;


/**
 * This class provides access to the functions described in liberation.h.
 *
 * See the documentation of Jerasure for a description of functionality and parameters.
 *
 * @author Jos van der Til
 * @version 1.0
 * @since 1.0
 */
public class Liberation {
    public static native int[] liberation_coding_bitmatrix(int k, int w);
    public static native int[] liber8tion_coding_bitmatrix(int k);
    public static native int[] blaum_roth_coding_bitmatrix(int k, int w);
    
    public static native long my_liberation_coding_bitmatrix(int k, int w);
    public static native long my_liber8tion_coding_bitmatrix(int k);
    public static native long my_blaum_roth_coding_bitmatrix(int k, int w);
}

