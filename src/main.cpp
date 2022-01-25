#include <iostream>
#include "av_project/environments/Simple2DEnv.h"

int main(int argc, char *argv[]) {
  auto env = AV::Simple2DEnv::create();
  env->run();
}
