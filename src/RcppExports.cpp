// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

void listenOn(const char* path, const Rcpp::Function callback);
RcppExport SEXP _latercallback_listenOn(SEXP s_path, SEXP s_callback) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const char * >::type path(s_path);
    Rcpp::traits::input_parameter< const Rcpp::Function >::type callback(s_callback);
    listenOn(path, callback);
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_latercallback_listenOn", (DL_FUNC) &_latercallback_listenOn, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_latercallback(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
