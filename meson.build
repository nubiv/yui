project('yui', 'cpp', version: '0.0', default_options: ['buildtype=release', 'debug=false', 'optimization=3'])

imgui_dir = join_paths('..', 'imgui')

inc_dir = include_directories(join_paths(imgui_dir, 'backends'), imgui_dir)

src = [
    'src/main.cpp',
    'src/implot.cpp',
    'src/implot_items.cpp',
    'src/scraper.cpp',
    'src/plot_data.cpp',
    join_paths(imgui_dir, 'imgui.cpp'),
    join_paths(imgui_dir, 'imgui_draw.cpp'),
    join_paths(imgui_dir, 'imgui_tables.cpp'),
    join_paths(imgui_dir, 'imgui_demo.cpp'),
    join_paths(imgui_dir, 'imgui_widgets.cpp'),
    join_paths(imgui_dir, 'backends', 'imgui_impl_glfw.cpp'), 
    join_paths(imgui_dir, 'backends', 'imgui_impl_opengl3.cpp') 
]

cpp_args = ['-std=c++11', '-I'+imgui_dir, '-I'+join_paths(imgui_dir, 'backends')]
cpp_args += ['-g', '-Wall', '-Wformat']
libs = []
linux_gl_libs = '-lGL'

os = host_machine.system()
if os == 'darwin' 
  message('macOS')

  modules = ['OpenGL', 'Cocoa', 'IOKit', 'CoreVideo']
  foreach module_name : modules 
      libs += dependency('appleframeworks', modules : module_name)
  endforeach

  cpp = meson.get_compiler('cpp')
  glfw = cpp.find_library('glfw', dirs: '/opt/homebrew/lib', required: true)
  curl = cpp.find_library('curl', dirs: '/opt/homebrew/opt/curl/lib', required: true)
  libs += glfw
  libs += curl

  cpp_args += ['-I/usr/local/inclue', '-I/opt/local/include', '-I/opt/homebrew/include']
  c_args = cpp_args
endif

if os == 'linux' 
  message('Linux')

  # Need to add glfw3+curl libs for linux

  cpp_args += ['pkg-config', '--cflags', 'glfw3']
  c_args = cpp_args
endif

if os == 'windows' 
  message('Windows')

  # Need to add glfw3+curl libs for windows

  cpp_args += ['pkg-config', '--cflags', 'glfw3']
  c_args = cpp_args
endif

executable('yui', src, cpp_args: cpp_args, c_args: c_args, include_directories : inc_dir, dependencies: libs)