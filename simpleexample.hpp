#pragma once
#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_SIMPLEEXAMPLE
    #define SIMPLEEXAMPLE_PUBLIC __declspec(dllexport)
  #else
    #define SIMPLEEXAMPLE_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_SIMPLEEXAMPLE
      #define SIMPLEEXAMPLE_PUBLIC __attribute__ ((visibility ("default")))
  #else
      #define SIMPLEEXAMPLE_PUBLIC
  #endif
#endif

namespace simpleexample {

class SIMPLEEXAMPLE_PUBLIC Simpleexample {

public:
  Simpleexample();
  int get_number() const;

private:

  int number;

};

}

