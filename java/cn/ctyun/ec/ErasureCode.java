package cn.ctyun.ec;

import java.nio.ByteBuffer;

import cn.ctyun.ec.jni.Jerasure;
import cn.ctyun.ec.jni.ReedSolomon;

public class ErasureCode {
    int k;
    int m;
    int w = 8;
    int[] rsMatrix;
    long rsMatrixId;

    static{
        System.loadLibrary("Jerasure.jni");
    }
    
    /**use k data blocks to produce m parity blocks
     * parameters subject to k+m<=2^w (w=8),size%8==0;
     * @param k
     * @param m
     */
    public ErasureCode(int k , int m){
        if(k<=0 || m<=0 || k + m > Math.pow(2, w)){
            throw new IllegalArgumentException("k>=0 and m>=0 and k+m<=2^w");
        }
        this.k = k;
        this.m = m;
        rsMatrixId = ReedSolomon.my_reed_sol_vandermonde_coding_matrix(k, m, w);
    }
    
    public void encode(ByteBuffer[] data, ByteBuffer[] coding){
        assert data != null && data.length == k;
        assert coding != null && coding.length == m;
        int blocksize = data[0].limit() - data[0].position();
        assert (blocksize % 8 != 0);

        Jerasure.my_jerasure_matrix_encode(k, m, w, rsMatrixId, data, coding, blocksize);
    }
    
    public boolean decode(ByteBuffer[] data, ByteBuffer[] coding, int[] erasures){
        assert data != null && data.length == k;
        assert coding != null && coding.length == m;
        int blocksize = data[0].limit() - data[0].position();
        assert (blocksize % 8 != 0);

        boolean res = Jerasure.my_jerasure_matrix_decode(k, m, w, rsMatrixId, true, erasures, data, coding, blocksize);
        return res;
    }
    
    
    public static void main(String[] args) {}

}
