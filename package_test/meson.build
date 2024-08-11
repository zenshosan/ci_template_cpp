project('SimpleExamplePackageTest', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_SIMPLEEXAMPLE']

message('host_machine.system:', host_machine.system())

# build: コンパイラが動くマシン
# host: コンパイルさらたコードが動くマシン
# target: クロスコンパイラをコンパイルする場合に、クロスコンパイラがどのマシンのコードを出力するか
#    machine A:(build)  Bで動作するC向けのクロスコンパイラXをコンパイルする
#    machine B:(host)   Xを使ってCで動作するコードYをコンパイルする
#    machine C:(target) Yが動作する
if host_machine.system() == 'windows'
  inst_dir_rel = get_option('package_install_dir')
  inst_dir_abs = meson.current_source_dir() / '..' / inst_dir_rel
  message('inst_dir_rel:', inst_dir_rel)
  message('inst_dir_abs:', inst_dir_abs)

  cc = meson.get_compiler('cpp')
  simpleexample_dep = declare_dependency(
    dependencies : cc.find_library('simpleexample', dirs : inst_dir_abs / 'lib'),
    include_directories : include_directories('..' / inst_dir_rel / 'include' / 'simpleexample'))

  meson.override_dependency('simpleexample', simpleexample_dep)
else
  simpleexample_dep = dependency('simpleexample')
endif

test2_exe = executable(
  'simpleexample_package_test', 'simpleexample_test.cpp',
  dependencies: simpleexample_dep)
test('simpleexamplepackagetest', test2_exe)
