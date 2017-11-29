/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef MODULES_PLANNING_LATTICE_BEHAVIOR_DECIDER_FEASIBLE_REGION_H_
#define MODULES_PLANNING_LATTICE_BEHAVIOR_DECIDER_FEASIBLE_REGION_H_

#include <array>

#include "modules/common/proto/pnc_point.pb.h"

namespace apollo {
namespace planning {

class FeasibleRegion {
 public:
  FeasibleRegion(const std::array<double, 3>& init_s,
      const double speed_limit);

  double SUpper(const double t) const;

  double SLower(const double t) const;

  double VUpper(const double t) const;

  double VLower(const double t) const;

 private:
  void Setup(const std::array<double, 3>& init_s, const double speed_limit);

  std::array<double, 3> init_s_;
  double speed_limit_;
  double t_at_zero_speed_;
  double s_at_zero_speed_;
  double t_at_speed_limit_;
  double s_at_speed_limit_;
};

}  // namespace planning
}  // namespace apollo

#endif  // MODULES_PLANNING_LATTICE_BEHAVIOR_DECIDER_FEASIBLE_REGION_H_