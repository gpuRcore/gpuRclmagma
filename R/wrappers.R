
#' @useDynLib gpuRclmagma
#' @importFrom Rcpp evalCpp
NULL


#' @import assertive
#' @import gpuRclblas

# GPU Matrix Multiplication
amd_chol <- function(A){

	type <- typeof(A)

	# C <- amdMatrix(nrow=nrow(A), ncol=ncol(A), type=type, ctx_id = A@.context_index)
	C <- deepcopy(A)

	switch(type,
		   integer = {
		   	stop("integer not currently implemented")
		   },
		   float = {cpp_amdMatrix_magma_chol(C@address,
		   								  6L,
		   								  A@.context_index - 1)
		   },
		   double = {
		   	cpp_amdMatrix_magma_chol(C@address,
		   							 8L,
		   							 A@.context_index - 1)
		   },
		   stop("type not recognized")
	)

	zeros <- which(lower.tri(C[]))
	C[zeros] <- 0

	return(C)
}

