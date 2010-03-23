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

#include "sandbox.h"
#include <string>
#include <vector>
#include "string_util.h"

Sandbox::Sandbox(const std::string& command) {
  command_ = command;
}

Sandbox::~Sandbox() {
  Kill();
}

int Sandbox::Init() {
  std::vector<std::string> tokens;
  StringUtil::Tokenize(command_, " ", tokens);
  char *argv[20];
  for (int i = 0; i < tokens.size(); ++i) {
    argv[i] = tokens[i].c_str();
  }
  argv[tokens.size()] = NULL;
  int child_pid = fork();
  if (child_pid == -1) {
    return 0;
  } else if (child_pid == 0) {
    execlp("cat", "cat", "a", NULL);
  } else {
    return 1;
  }
}

void Sandbox::Kill() {
  
}

void Sandbox::WriteLine(const std::string& message) {
  
}

int Sandbox::ReadLine(std::string& buf) {
  return 0;
}

int Sandbox::ReadErrorLine(std::string& buf) {
  return 0;
}
