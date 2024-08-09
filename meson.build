project('SimpleExample', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_SIMPLEEXAMPLE']

shlib = shared_library('simpleexample', 'simpleexample.cpp',
  install : true,
  cpp_args : lib_args,
  gnu_symbol_visibility : 'hidden',
)

test_exe = executable('simpleexample_test', 'simpleexample_test.cpp',
  link_with : shlib)
test('simpleexample', test_exe)

# Make this library usable as a Meson subproject.
simpleexample_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with : shlib)

# Make this library usable from the system's
# package manager.
install_headers('simpleexample.hpp', subdir : 'simpleexample')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'SimpleExample',
  filebase : 'simpleexample',
  description : 'Meson sample project.',
  subdirs : 'simpleexample',
  libraries : shlib,
  version : '0.1',
)
