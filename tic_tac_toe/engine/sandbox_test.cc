// Copyright 2010 owners of the AI Challenge project
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not
// use this file except in compliance with the License. You may obtain a copy
// of the License at http://www.apache.org/licenses/LICENSE-2.0 . Unless
// required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
//
// Author: Jeff Cameron (jeff@jpcameron.com)
//
// A basic test of the sandboxing system.

#include <iostream>
#include "tic_tac_toe/engine/sandbox.h"

int main(int argc, char *argv[]) {
  Sandbox sandbox("./sum");
  sandbox.Init();
  sandbox.WriteLine("1 2 3");
  std::string line;
  int result = sandbox.ReadLine(line, 1000);
  std::cout << "Received (" << result << "): " << line << std::endl;
  sandbox.Kill();
  return 0;
}
