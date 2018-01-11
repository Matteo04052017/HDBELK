file(REMOVE_RECURSE
  "../lib/libhdb++ELK.pdb"
  "../lib/libhdb++ELK.so"
  "../lib/libhdb++ELK.so.7.0.1"
  "../lib/libhdb++ELK.so.7"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/shared_library.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
