//===-- gen/llvmcompat.h - LLVM API compatibilty shims ----------*- C++ -*-===//
//
//                         LDC – the LLVM D compiler
//
// This file is distributed under the BSD-style LDC license. See the LICENSE
// file for details.
//
//===----------------------------------------------------------------------===//
//
// Provides a central place to handle API changes between supported LLVM
// versions.
//
//===----------------------------------------------------------------------===//


#ifdef _MSC_VER
#pragma once
#endif

#ifndef LDC_LLVMCOMPAT_H
#define LDC_LLVMCOMPAT_H

#include "llvm/ADT/Triple.h"
#include <string>

#if !defined(LDC_LLVM_VER)
#error "Please specify value for LDC_LLVM_VER."
#endif

#if LDC_LLVM_VER == 300
namespace llvm {
    class Module;
    class Function;

    namespace sys {
        std::string getDefaultTargetTriple();
    }

    Triple Triple__get32BitArchVariant(const std::string&_this);
    Triple Triple__get64BitArchVariant(const std::string& _this);

    // From Transforms/Utils/ModuleUtils
    void appendToGlobalCtors(Module &M, Function *F, int Priority);
    void appendToGlobalDtors(Module &M, Function *F, int Priority);
}
#endif

#if LDC_LLVM_VER >= 302
#define ADDRESS_SPACE 0
#define HAS_ATTRIBUTES(x) (x).hasAttributes()
#else
#define ADDRESS_SPACE
#define HAS_ATTRIBUTES(x) (x)
#endif

#endif
