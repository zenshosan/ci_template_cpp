project('SimpleExamplePackageTest', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_SIMPLEEXAMPLE']

message('host_machine.system:', host_machine.system())
if host_machine.system() == 'windows'
  #simpleexample_dep = dependency('include')
  #my_lib = static_library()
  #simpleexample_dep = declare_dependency(link_with : my_lib, include_directories : my_inc)

  inst_dir_rel = get_option('package_install_dir')
  #inst_dir_rel = 'build_rel/usrlocal'

  #inst_dir_abs = '/'.join(meson.current_source_dir(), inst_dir_rel)
  inst_dir_abs = meson.current_source_dir() / '..' / inst_dir_rel
  message('inst_dir_rel:', inst_dir_rel)
  message('inst_dir_abs:', inst_dir_abs)

  #my_inc = include_directories('/'.join(env['MY_INSTALL_DIR'], 'include'))
  #my_inc = include_directories('/'.join(meson.current_source_dir(), '..', 'build_rel', 'usrlocal', 'include'))

  my_inc = include_directories('..' / inst_dir_rel / 'include')

  cc = meson.get_compiler('cpp')
  simpleexample_dep = declare_dependency(
    #dependencies : cc.find_library('simpleexample', dirs : '/'.join('..' / 'build_rel' / 'usrlocal' / 'bin')),
    dependencies : cc.find_library('simpleexample', dirs : inst_dir_abs / 'lib'),
    include_directories : my_inc)

  meson.override_dependency('simpleexample', simpleexample_dep)
else
  simpleexample_dep = dependency('simpleexample')
endif

test2_exe = executable('simpleexample_package_test', 'simpleexample_test.cpp',
  dependencies: simpleexample_dep)

test('simpleexamplepackagetest', test2_exe)
