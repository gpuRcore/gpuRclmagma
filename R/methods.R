#' @import methods

# @export
# setMethod("%*%", signature(x="amdMatrix", y = "amdMatrix"),
#           function(x,y)
#           {
#               if( dim(x)[2] != dim(y)[1]){
#                   stop("Non-conformant matrices")
#               }
#
#               # type <- typeof(x)
#               #
#               # C <- amdMatrix(nrow=nrow(x), ncol=ncol(y), type=type, ctx_id = x@.context_index)
#               #
#               # if(!deviceHasDouble()){
#               #   stop("Selected GPU does not support double precision")
#               # }else{
#               #   cpp_amdMatrix_dgemm(x@address, y@address, C@address, x@.context_index)
#               # }
#
#               return(amd_Mat_mult(x, y))
#           },
#           valueClass = "amdMatrix"
# )


