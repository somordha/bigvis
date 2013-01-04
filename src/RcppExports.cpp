// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// bin_1d
IntegerVector bin_1d(NumericVector x, NumericVector breaks);
RcppExport SEXP bigvis_bin_1d(SEXP xSEXP, SEXP breaksSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    NumericVector x = Rcpp::as<NumericVector >(xSEXP);
    NumericVector breaks = Rcpp::as<NumericVector >(breaksSEXP);
    IntegerVector __result = bin_1d(x, breaks);
    return Rcpp::wrap(__result);
END_RCPP
}
// bin_1d_fixed
std::vector<int> bin_1d_fixed(NumericVector x, double width, double origin);
RcppExport SEXP bigvis_bin_1d_fixed(SEXP xSEXP, SEXP widthSEXP, SEXP originSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    NumericVector x = Rcpp::as<NumericVector >(xSEXP);
    double width = Rcpp::as<double >(widthSEXP);
    double origin = Rcpp::as<double >(originSEXP);
    std::vector<int> __result = bin_1d_fixed(x, width, origin);
    return Rcpp::wrap(__result);
END_RCPP
}
// convolve_1d
NumericVector convolve_1d(NumericVector x, NumericVector kernel);
RcppExport SEXP bigvis_convolve_1d(SEXP xSEXP, SEXP kernelSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    NumericVector x = Rcpp::as<NumericVector >(xSEXP);
    NumericVector kernel = Rcpp::as<NumericVector >(kernelSEXP);
    NumericVector __result = convolve_1d(x, kernel);
    return Rcpp::wrap(__result);
END_RCPP
}
// convolve_2d
NumericMatrix convolve_2d(NumericMatrix sample, NumericMatrix kernel);
RcppExport SEXP bigvis_convolve_2d(SEXP sampleSEXP, SEXP kernelSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    NumericMatrix sample = Rcpp::as<NumericMatrix >(sampleSEXP);
    NumericMatrix kernel = Rcpp::as<NumericMatrix >(kernelSEXP);
    NumericMatrix __result = convolve_2d(sample, kernel);
    return Rcpp::wrap(__result);
END_RCPP
}