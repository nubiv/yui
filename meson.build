project('yui', 'objcpp', 'cpp', default_options: ['cpp_std=c++11'])

imgui_dir = join_paths('..', 'imgui')

inc_dir = include_directories(join_paths(imgui_dir, 'backends'), imgui_dir)

src = [
    join_paths(imgui_dir, 'imgui.cpp'),
    join_paths(imgui_dir, 'imgui_draw.cpp'),
    join_paths(imgui_dir, 'imgui_tables.cpp'),
    join_paths(imgui_dir, 'imgui_demo.cpp'),
    join_paths(imgui_dir, 'imgui_widgets.cpp'),
    join_paths(imgui_dir, 'backends', 'imgui_impl_glfw.cpp'), 
    join_paths(imgui_dir, 'backends', 'imgui_impl_metal.mm'), 
    'src/main.mm',
]

deps = []
modules = ['Metal', 'MetalKit', 'Cocoa', 'IOKit', 'CoreVideo', 'QuartzCore']
foreach module_name : modules 
    deps += dependency('appleframeworks', modules : module_name)
endforeach

cpp = meson.get_compiler('cpp')
glfw = cpp.find_library('glfw', dirs: '/opt/homebrew/lib', required: true)
deps += glfw

cpp_args = ['-std=c++11', '-I/usr/local/include', '-I/opt/homebrew/include']
cpp_args += ['-Wall', '-Wformat']
c_args = cpp_args
objcpp_args = cpp_args
objcpp_args += ['-fobjc-weak', '-fobjc-arc']

executable('yui', src, cpp_args: cpp_args, c_args: c_args, objcpp_args: objcpp_args, include_directories : inc_dir, dependencies: deps)