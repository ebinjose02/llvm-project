// RUN: %clang_cc1 %s -std=c89 -emit-llvm -o -
// PR2797

void
func_48 (signed char p_49)
{
  signed char l_340;
  func_44 (1&((1 ^ 1 == (lshift_u_s (1)) != (l_340 < 1)) & 1L));
}
