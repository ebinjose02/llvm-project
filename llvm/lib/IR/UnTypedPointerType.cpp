// UntypedPointerType.cpp
#include "llvm/IR/UnTypedPointerType.h"
#include "LLVMContextImpl.h"

using namespace llvm;

// Factory method: get an untyped pointer for a given context and address space.
UntypedPointerType *UntypedPointerType::get(LLVMContext &C, unsigned AddressSpace) {
  LLVMContextImpl *CImpl = C.pImpl;
  // Assume CImpl->UntypedPointerTypes is a map from unsigned to UntypedPointerType*
  UntypedPointerType *&Entry = CImpl->UntypedPointerTypes[AddressSpace];
  if (!Entry)
    Entry = new (CImpl->Alloc) UntypedPointerType(C, AddressSpace);
  return Entry;
}

UntypedPointerType::UntypedPointerType(LLVMContext &C, unsigned AddrSpace)
    : Type(C, UnTypedPointerTyID) {  // UntypedPointerTyID is a new unique TypeID.
  setSubclassData(AddrSpace);
}
