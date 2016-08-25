#define __CL_ENABLE_EXCEPTIONS

#include "gpuR/dynEigenMat.hpp"

// clMAGMA headers
#include "magma.h"

#include <string>

using namespace Rcpp;

void
cpp_amdMatrix_dpotrf(
	SEXP ptrA_,
  int ctx_id)
{
    XPtr<dynEigenMat<double> > ptrA(ptrA_);

    // move data to device
    viennacl::matrix<double> vcl_A = ptrA->device_data(ctx_id);

    // total number of elements
    // const int N = Am.n_elem;
    const int N = vcl_A.internal_size2();

    // Get command queue and use the first device
    cl_command_queue queue = vcl_A.handle().opencl_handle().context().get_queue().handle().get();

    // declare OpenCL objects
    int info;

    // initialize magma environment
    magma_init();

    /* Prepare OpenCL memory objects and place matrices inside them. */
    // Get memory buffers
    const cl_mem *bufA = &vcl_A.handle().opencl_handle().get();

    /* Call clblas extended function. Perform gemm */
    magma_dpotrf_gpu(MagmaLower, N,
                    *bufA, 0, vcl_A.internal_size2(),
                    queue, &info);
    if (info < 0) {
        stop("magma_dpotrs_gpu failed");
    }

    magma_finalize();

    // Copy back to host
    ptrA->to_host(vcl_A);
}


void
cpp_amdMatrix_spotrf(SEXP ptrA_,
                    int ctx_id)
{

    XPtr<dynEigenMat<float> > ptrA(ptrA_);

    // move data to device
    viennacl::matrix<float> vcl_A = ptrA->device_data(ctx_id);

    // Order of matrix
    const int N = vcl_A.size2();

    // Get command queue and use the first device
    cl_command_queue queue = vcl_A.handle().opencl_handle().context().get_queue().handle().get();

    // declare OpenCL objects
    int info;

    /* Prepare OpenCL memory objects and place matrices inside them. */
    // Get memory buffers
    const cl_mem *bufA = &vcl_A.handle().opencl_handle().get();

    /* Call clblas extended function. Perform cholesky decomp */
    magma_spotrf_gpu(MagmaLower, N,
                     *bufA, 0, vcl_A.internal_size2(),
                     queue, &info);
    if (info < 0) {
    	stop("magma_spotrf_gpu failed");
    }

    // Copy back to host
    ptrA->to_host(vcl_A);
}


//[[Rcpp::export]]
void
cpp_amdMatrix_magma_chol(
    SEXP ptrA,
    const int type_flag,
    int ctx_id)
{

    switch(type_flag) {
        case 6:
        	cpp_amdMatrix_spotrf(ptrA, ctx_id);
            return;
        case 8:
        	cpp_amdMatrix_dpotrf(ptrA, ctx_id);
            return;
        default:
            throw Rcpp::exception("unknown type detected for amdMatrix object!");
    }
}
