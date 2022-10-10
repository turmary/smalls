addtask build

mybuild_do_build () {
  bbnote "(mybuild.bbclass): running  mybuild_do_build."
  bbnote "(mybuild.bbclass): Argument ${MYBUILD_ARG}"
}

MYBUILD_VAR1 = "my-build-var-001 from (mybuild.bbclass)"

EXPORT_FUNCTIONS do_build

