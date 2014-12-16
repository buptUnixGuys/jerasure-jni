package cn.ctyun.ec.jni;

import java.nio.ByteBuffer;


/**
 * This class provides access to the functions described in reed_sol.h.
 *
 * See the documentation of Jerasure for a description of functionality and parameters.
 *
 * @author Jos van der Til
 * @version 1.0
 * @since 1.0
 */
public class ReedSolomon {
    public static native int[] reed_sol_vandermonde_coding_matrix(int k, int m, int w);
    public static native int[] reed_sol_extended_vandermonde_matrix(int rows, int cols, int w);
    public static native int[] reed_sol_big_vandermonde_distribution_matrix(int rows, int cols, int w);

    public static native boolean reed_sol_r6_encode(int k, int w, ByteBuffer[] data_ptrs, ByteBuffer[] coding_ptrs, int size);
    public static native int[] reed_sol_r6_coding_matrix(int k, int w);

    public static native void reed_sol_galois_w08_region_multby_2(ByteBuffer region, int nbytes);
    public static native void reed_sol_galois_w16_region_multby_2(ByteBuffer region, int nbytes);
    public static native void reed_sol_galois_w32_region_multby_2(ByteBuffer region, int nbytes);
    
    public static native long my_reed_sol_vandermonde_coding_matrix(int k, int m, int w);
    public static native long my_reed_sol_extended_vandermonde_matrix(int rows, int cols, int w);
    public static native long my_reed_sol_big_vandermonde_distribution_matrix(int rows, int cols, int w);
    public static native long my_reed_sol_r6_coding_matrix(int k, int w);
}
