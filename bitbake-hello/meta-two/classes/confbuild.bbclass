inherit mybuild

confbuild_do_configure () {
  echo "running configbuild_do_configure (in confbuild.bbclass)."
}

addtask do_configure before do_build

EXPORT_FUNCTIONS do_configure

