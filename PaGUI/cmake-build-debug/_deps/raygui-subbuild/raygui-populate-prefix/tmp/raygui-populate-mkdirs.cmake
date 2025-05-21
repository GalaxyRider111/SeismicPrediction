# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "D:/SeismicPrediction/PaGUI/cmake-build-debug/_deps/raygui-src")
  file(MAKE_DIRECTORY "D:/SeismicPrediction/PaGUI/cmake-build-debug/_deps/raygui-src")
endif()
file(MAKE_DIRECTORY
  "D:/SeismicPrediction/PaGUI/cmake-build-debug/_deps/raygui-build"
  "D:/SeismicPrediction/PaGUI/cmake-build-debug/_deps/raygui-subbuild/raygui-populate-prefix"
  "D:/SeismicPrediction/PaGUI/cmake-build-debug/_deps/raygui-subbuild/raygui-populate-prefix/tmp"
  "D:/SeismicPrediction/PaGUI/cmake-build-debug/_deps/raygui-subbuild/raygui-populate-prefix/src/raygui-populate-stamp"
  "D:/SeismicPrediction/PaGUI/cmake-build-debug/_deps/raygui-subbuild/raygui-populate-prefix/src"
  "D:/SeismicPrediction/PaGUI/cmake-build-debug/_deps/raygui-subbuild/raygui-populate-prefix/src/raygui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/SeismicPrediction/PaGUI/cmake-build-debug/_deps/raygui-subbuild/raygui-populate-prefix/src/raygui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/SeismicPrediction/PaGUI/cmake-build-debug/_deps/raygui-subbuild/raygui-populate-prefix/src/raygui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
