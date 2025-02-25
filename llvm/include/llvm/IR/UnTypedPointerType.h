// UntypedPointerType.h
#ifndef LLVM_IR_UNTYPEDPOINTERTYPE_H
#define LLVM_IR_UNTYPEDPOINTERTYPE_H

#include "llvm/IR/Type.h"

namespace llvm {

/// This class represents an untyped pointer (opaque pointer) used for targets
/// like SPIR-V with the KHR_untyped_pointers extension. Unlike TypedPointerType,
/// it does not track an element type.
class UntypedPointerType : public Type {
  explicit UntypedPointerType(LLVMContext &C, unsigned AddrSpace);

public:
  UntypedPointerType(const UntypedPointerType &) = delete;
  UntypedPointerType &operator=(const UntypedPointerType &) = delete;

  /// Create an untyped pointer in the given address space.
  static UntypedPointerType *get(LLVMContext &C, unsigned AddressSpace);

  /// Return the address space of the pointer type.
  unsigned getAddressSpace() const { return getSubclassData(); }

  /// Since this is untyped, return nullptr.
  Type *getElementType() const { return nullptr; }

  static bool classof(const Type *T) {
    return T->getTypeID() == UnTypedPointerTyID;
  }
};

} // end namespace llvm

#endif // LLVM_IR_UNTYPEDPOINTERTYPE_H
