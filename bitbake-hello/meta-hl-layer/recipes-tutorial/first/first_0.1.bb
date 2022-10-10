DESCRIPTION = "I am the first recipe"
PR = "r1"

do_build () {
  echo "first: some shell script running as build"
  env
  a_err_marker
  echo "       tail line of do_build()"
}

