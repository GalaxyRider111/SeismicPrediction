# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/galaxy/SeismicPrediction/PaGUI/build/_deps/raygui-src"
  "/home/galaxy/SeismicPrediction/PaGUI/build/_deps/raygui-build"
  "/home/galaxy/SeismicPrediction/PaGUI/build/_deps/raygui-subbuild/raygui-populate-prefix"
  "/home/galaxy/SeismicPrediction/PaGUI/build/_deps/raygui-subbuild/raygui-populate-prefix/tmp"
  "/home/galaxy/SeismicPrediction/PaGUI/build/_deps/raygui-subbuild/raygui-populate-prefix/src/raygui-populate-stamp"
  "/home/galaxy/SeismicPrediction/PaGUI/build/_deps/raygui-subbuild/raygui-populate-prefix/src"
  "/home/galaxy/SeismicPrediction/PaGUI/build/_deps/raygui-subbuild/raygui-populate-prefix/src/raygui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/galaxy/SeismicPrediction/PaGUI/build/_deps/raygui-subbuild/raygui-populate-prefix/src/raygui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/galaxy/SeismicPrediction/PaGUI/build/_deps/raygui-subbuild/raygui-populate-prefix/src/raygui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
