#include "types.h"
#include "data.h"

int main(int argc, char *argv[]) {
    int i, j;
    int16_t *coeff_p = coeff;
    pixel *dst_ref_p = dst_ref;
    
    for (i = 0; i < sizeof(mode)/2; i ++) {
        int size  = mode[i][0];
        int is_dst   = mode[i][1];
        
        if(size == 4 && is_dst) {
            transform_4x4_luma_add(dst, coeff_p, 4 * sizeof(pixel), 8);
            for (j = 0; j < size*size; j++) {
                if(dst[j]!=dst_ref_p[j])
                    printf("%d %d\n", dst[j], dst_ref_p[j]);
            }
        }
        if(size == 4 && !is_dst) {
            transform_4x4_add(dst, coeff_p, 4 * sizeof(pixel), 8);
            for (j = 0; j < size*size; j++) {
                if(dst[j]!=dst_ref_p[j])
                    printf("%d %d\n", dst[j], dst_ref_p[j]);
            }
        }
        if(size == 8) {
            transform_8x8_add(dst, coeff_p, 8 * sizeof(pixel), 8);
            for (j = 0; j < size*size; j++) {
                if(dst[j]!=dst_ref_p[j])
                    printf("%d %d\n", dst[j], dst_ref_p[j]);
            }
        }
        if(size == 16) {
            transform_16x16_add(dst, coeff_p, 16 * sizeof(pixel), 8);
            for (j = 0; j < size*size; j++) {
                if(dst[j]!=dst_ref_p[j])
                    printf("%d %d\n", dst[j], dst_ref_p[j]);
            }
        }
        if(size == 32) {
            transform_32x32_add(dst, coeff_p, 32 * sizeof(pixel), 8);
        }
        dst_ref_p += size * size;
        coeff_p += size * size;
    }
    
    printf("OK\n");
    
    
}