## Summary:

* CMake is responsible for project configuration and generating build system files, while Ninja and Make are responsible for executing the build process based on those generated files to produce the final executable binary files.

## questions:

1. The paths used by target_sources and target_include_directories are relative, not absolute. What file or  folder are they relative to?

* The paths specified (e.g., "src/hello.cpp" and "include") are relative to the location of the CMakeLists.txt file, which is typically located in the project's root directory.

2. What are some differences between cmake and ninja?

* Cmake is about project configuration, generates the files for ninja.
* cmake is cross platform build system generator wheres as ninja is a build tool.

3. Why is it important to run cmake in its own directory?

* running CMake in its own directory, separate from your source code, helps maintain project cleanliness, and reduces the risk of accidental interference between source code and build.
