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
// Runs a game of Tic-Tac-Toe between two computer programs.

#include <iostream>
#include <string>
#include <vector>
#include "sandbox.h"
#include "string_util.h"

int main(int argc, char *argv[]) {
  std::vector<std::string> tokens;
  StringUtil::Tokenize("   Able was I  ere I saw Elba. ", " .", tokens);
  for (int i = 0; i < tokens.size(); ++i) {
    std::cout << tokens[i] << std::endl;
  }
  //Sandbox sandbox("");
  //sandbox.Init();
  //sandbox.Kill();
  return 0;
}
