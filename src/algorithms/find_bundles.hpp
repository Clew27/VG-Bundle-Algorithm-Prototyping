#ifndef VG_ALGORITHMS_FIND_BALANCED_BUNDLE_HPP_INCLUDED
#define VG_ALGORITHMS_FIND_BALANCED_BUNDLE_HPP_INCLUDED

// #define DEBUG_FIND_BUNDLES

#include <vector>

#include "bundle.hpp"
#include "handle.hpp"

/// Locates all bundles in a given graph.
/// Walks in both directions of a node to check. Nodes that have been
/// walked in a particular direction will be cached. 
/// Returns all bundles that have been found. The return format will
/// be a vector of pairs of vectors containing handles. Each pair
/// will denote the left side and the right side of a bundle.
std::vector<Bundle*> find_bundles(const handlegraph::HandleGraph& g, 
        bool is_balanced);

/// Determines if the given handle is part of a bundle. go_left = false.
/// Returns (true, bundle) if it's in a bundle
/// Otherwise returns (false, bundle) if it's not in a bundle
std::pair<bool, Bundle*> find_bundle(const handlegraph::handle_t& handle, 
        const handlegraph::HandleGraph& g, bool is_balanced);

#endif /* VG_ALGORITHMS_FIND_BALANCED_BUNDLE_HPP_INCLUDED */
