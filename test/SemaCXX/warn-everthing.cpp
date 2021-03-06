// RUN: %clang_cc1 -Weverything -fsyntax-only %s -verify

// This previously crashed due to a bug in the CFG.  Exercising all
// warnings helps check CFG construction.
class PR12271 {
public:
  PR12271();
  ~PR12271();
};

void testPR12271() { // expected-warning {{no previous prototype for function 'testPR12271'}}
  PR12271 a[1][1]; // expected-warning {{unused variable 'a'}}
}
