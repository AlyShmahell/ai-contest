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
// The sandbox is a wrapper that can be used to invoke untrusted code securely.

#ifndef TIC_TAC_TOE_ENGINE_SANDBOX_H_
#define TIC_TAC_TOE_ENGINE_SANDBOX_H_

#include <string>

class Sandbox {
 public:
  // Sets up the sandbox, but does not invoke it. This constructor sets up a
  // sandbox with no security at all. The spawned process can do whatever it
  // wants. To actually kick off the command, call the Init() method.
  Sandbox(const std::string& command);

  // Destructor. Destroys the spawned process.
  ~Sandbox();

  // The Init() method actually sets up the sandbox and invokes the command
  // inside it. Returns 1 on success, 0 on failure.
  int Init();

  // Destroys the spawned process.
  void Kill();

  // Writes the given string to the stdin channel of the spawned process,
  // followed by a single newline character (\n).
  void WriteLine(const std::string& message);

  // Attempts to read a line from the stdout channel of the spawned process.
  // This method does not block.
  //
  // If a complete line of the program's output is available, it is placed
  // into the buf variable and the method returns the number of characters
  // read. The terminating newline character is not included in buf, but is
  // included in the returned character count.
  //
  // If a complete line of the program's output is not yet available, the
  // method returns zero, and the length of buf will be zero.
  //
  // How can you tell the difference between a blank line being read, and no
  // line being available? If the first case, the return value is nonzero. In
  // the second case, the return value is zero.
  int ReadLine(std::string& buf);

  // Reads a line from the spawned program's stderr channel. Works just the
  // same as the ReadLine method, except for stderr instead of stdout.
  int ReadErrorLine(std::string& buf);

 private:
  // Used to store characters that are read from the spawed program's stdout
  // and stderr channels.
  std::string program_stdout_;
  std::string program_stderr_;

  // The shell command to be invoked inside this sandbox.
  std::string command_;
};

#endif
