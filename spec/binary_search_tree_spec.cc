#include <iostream>

#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

#include "binary_search_tree.h"

using std::cout;
using ccspec::core::Reporter;
using ccspec::core::describe;
using ccspec::core::formatters::DocumentationFormatter;
using ccspec::core::it;
using ccspec::matchers::be;
using ccspec::expect;

auto bst_spec = describe("BinarySearchTree", [] {
});

int main() {
  DocumentationFormatter formatter(cout);
  Reporter reporter(&formatter);
  bool succeeded = bst_spec->run(reporter);
  delete bst_spec;
  return !succeeded;
}
