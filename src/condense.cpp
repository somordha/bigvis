#include <Rcpp.h>
#include <bigvis.h>
#include "group.hpp"
#include "summary.hpp"

template<typename Stat>
List condense(const BinnedVectors& group, const NumericVector& z, 
                        const NumericVector& weight, const Stat& stat) {
  int n_obs = group.size();
  int n_bins = group.nbins();

  const NumericVector& weight_ = (weight.size() > 0) ? weight : 
    rep(NumericVector::create(1), n_obs);
  const NumericVector& z_ = (z.size() > 0) ? z : 
    rep(NumericVector::create(1), n_obs);

  // Push values into summaries
  std::vector<Stat> stats(n_bins + 1, stat);
  for(int i = 0; i < n_obs; ++i) {
    int bin = group.bin_i(i);
    stats.at(bin).push(z_[i], weight_[i]);      
  }

  // Compute values from summaries and determine bins
  int n_stats = stats[0].size();
  int n_groups = group.ngroups();
  NumericMatrix out(n_bins, n_stats), bin(n_bins, n_groups);

  for (int i = 0; i < n_bins; ++i) {
    for (int j = 0; j < n_stats; ++j) {
      out(i, j) = stats[i].compute(j);
    }

    std::vector<double> bins = group.unbin(i);
    for (int j = 0; j < n_groups; ++j) {
      bin(i, j) = bins[j];
    }
  }

  // Name 
  CharacterVector out_cols(n_stats), bin_cols(n_groups);
  for (int j = 0; j < n_stats; ++j) {
    out_cols[j] = stats[0].name(j);
  }
  for (int j = 0; j < n_groups; ++j) {
    bin_cols[j] = group.name(j);
  }
  out.attr("dimnames") = List::create(CharacterVector::create(), out_cols);
  bin.attr("dimnames") = List::create(CharacterVector::create(), bin_cols);

  return List::create(out, bin);
}