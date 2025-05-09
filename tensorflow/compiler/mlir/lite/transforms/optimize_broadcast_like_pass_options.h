
/* Copyright 2025 The TensorFlow Authors. All Rights Reserved.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_COMPILER_MLIR_LITE_TRANSFORMS_OPTIMIZE_BROADCAST_LIKE_PASS_OPTIONS_H_
#define TENSORFLOW_COMPILER_MLIR_LITE_TRANSFORMS_OPTIMIZE_BROADCAST_LIKE_PASS_OPTIONS_H_

#include "llvm/Support/CommandLine.h"
#include "mlir/Pass/PassOptions.h"  // from @llvm-project

namespace mlir {
namespace TFL {

////////////////////////////////////////////////////////////////////////////////
// Pass Options
////////////////////////////////////////////////////////////////////////////////

struct OptimizeBroadcastLikePassOptions : public mlir::detail::PassOptions {
  mlir::detail::PassOptions::Option<bool> unsafe_fuse_dynamic_shaped_broadcast{
      *this, "unsafe-fuse-dynamic-shaped-broadcast",
      llvm::cl::desc(
          "Enable fusion of dynamic shaped broadcast ops. It helps fusing "
          "implicit broadcasting ops when output shape has dynamic dimensions, "
          "but it may cause incorrect results when broadcasting ops are "
          "introduced by explicit broadcasting in the source model."),
      llvm::cl::init(false)};
};

}  // namespace TFL
}  // namespace mlir

#endif  // TENSORFLOW_COMPILER_MLIR_LITE_TRANSFORMS_OPTIMIZE_BROADCAST_LIKE_PASS_OPTIONS_H_
