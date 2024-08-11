#include <simpleexample.hpp>
#include <iostream>
#include <thread>
#include <atomic>
#include <map>
#include <mutex>

#define FIX_BAD_CODE

static std::map<std::string, int> g_map;

static int check_thread(void)
{
    std::mutex mx;
    std::thread t([&]{
#ifdef FIX_BAD_CODE
        std::lock_guard<std::mutex> lock(mx);
#endif
        g_map["foo"] = 42;
    });
    {
#ifdef FIX_BAD_CODE
        std::lock_guard<std::mutex> lock(mx);
#endif
        g_map["foo"] = 43;
    }
    t.join();
    return g_map["foo"];
}

static void check_sanitizer(int argc)
{
    // undefined
    int k = 0x7fffffff;
#ifdef FIX_BAD_CODE
    argc = 0;
#endif
    k += argc;
    std::cout << k << "\n";

    // leak
    auto p = malloc(7);
#ifdef FIX_BAD_CODE
    free(p);
#endif
    p = 0; // The memory is leaked here.

    // address
    char *x = (char*)malloc(10 * sizeof(char*));
#ifndef FIX_BAD_CODE
    free(x);
#endif
    std::cout << x[5] << "\n";
#ifdef FIX_BAD_CODE
    free(x);
#endif

    // thread
    auto ret = check_thread();
    std::cout << ret << "\n";
}

int main(int argc, char **argv) {
    check_sanitizer(argc);
    if(argc != 1) {
        std::cout << argv[0] << " takes no arguments.\n";
        return 1;
    }
    simpleexample::Simpleexample c;
    return c.get_number() != 6;
}
