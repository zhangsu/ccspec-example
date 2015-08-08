#include <iostream>

#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

#include "binary_search_tree.h"

using std::cout;
using std::ostringstream;
using ccspec::core::Reporter;
using ccspec::core::describe;
using ccspec::core::formatters::DocumentationFormatter;
using ccspec::core::it;
using ccspec::matchers::be;
using ccspec::matchers::eq;
using ccspec::expect;

auto bst_spec = describe("BinarySearchTree", [] {
  describe("#add", [] {
    it("returns back the instance", [] {
      BinarySearchTree bst;
      BinarySearchTree& bst2 = bst.add(5);
      expect(bst2).to(be(bst));
    });

    it("can build an arbitrary tree", [] {
      BinarySearchTree bst;
      bst.add(3).add(4).add(5).add(0).add(2).add(1);
      ostringstream oss;
      oss << bst;
      expect(oss.str()).to(eq(
          "    5\n"
          "  4\n"
          "3\n"
          "    2\n"
          "      1\n"
          "  0\n"
          ""));
    });
  });
});

int main() {
  DocumentationFormatter formatter(cout);
  Reporter reporter(&formatter);
  bool succeeded = bst_spec->run(reporter);
  delete bst_spec;
  return !succeeded;
}
